#include "Arduino.h"
#include "SimpleSerial.h"

SimpleSerial::SimpleSerial() {}

SimpleSerial::SimpleSerial(int baudRate) {
    Serial.begin(baudRate);
}

void SimpleSerial::check(void (*onData)(char *)) {
  receiveData();

  if (newData) {
    onData(receivedChars);
    newData = false;
  }
}

void SimpleSerial::setDelimiter(String _del) {
  delimiter = _del;
}

void SimpleSerial::setSeperator(String _sep) {
  seperator = _sep;
}

void SimpleSerial::receiveData() {
  static byte ndx = 0;
  char rc;

  // if (Serial.available() > 0) {
  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (rc != endMarker) {
      receivedChars[ndx] = rc;
      ndx++;

      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    } else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
      newData = true;
    }
  }
}

String SimpleSerial::getValue(String key, char * chars) {
  String str(chars);
  
  int keyIndex = str.indexOf(key);

  if (keyIndex < 0) {
    return "";
  }

  int seperatorIndex = str.indexOf(seperator, keyIndex);

  if (seperatorIndex < 0) {
    return "";
  }

  int delimiterIndex = str.indexOf(delimiter, seperatorIndex);

  if (delimiterIndex < 0) {
    delimiterIndex = str.length();
  }

  return str.substring(seperatorIndex + 1, delimiterIndex);
}

int SimpleSerial::getInt(String key, char * chars) {
  String val = getValue(key, chars);

  if (val) {
    return val.toInt();
  } else {
    return -1;
  }
}