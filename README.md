# Simple Serial

A library to help use Serial in Arduino, when you want to get values in a semi-tokenized way.

Think of it like being able to search for key/value pairs being sent to an Arduino.

## Example

```
#include <SimpleSerial.h>

/**
 * Test this code by sending thing string in the serial monitor:
 * 
 *  foo:bar;test:nothing;str:hello;num:5;
 *  
 */

SimpleSerial communicator = SimpleSerial(9600);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  communicator.check(onData);
}

void onData(char * characters) {
  String strVal = communicator.getValue("str", characters);
  int intVal = communicator.getInt("num", characters);
  Serial.println(strVal);
  Serial.println(intVal);
}
```

## API
`SimpleSerial(int baudRate);`
Constructor with baud rate for serial

`void check(void (*onData)(char *));`
This method is **required** and is the ability to check for Serial communication. Provided with a callback that only gets fired with new data

`String getValue(String key, char * chars);`
This method returns the value of a given key

`int getInt(String key, char * chars);`
This method returns the value of a given key and is casted to int

`void setDelimiter(String _del);`
Sets the delimiter to check for. *default ";"*

`void setSeperator(String _sep);`
Sets the seperator to check for. *default ":"*

