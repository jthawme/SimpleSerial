#ifndef SimpleSerial_h
#define SimpleSerial_h

#include "Arduino.h"

class SimpleSerial
{
  public:
    SimpleSerial();
    SimpleSerial(int baudRate);

    void check(void (*onData)(char *));

    /**
     * A method to get value from Serial received characters
     * 
     * @param {String} key The key to look for
     * @param {char *} chars Characters from Serial
     * @return {String}
     */
    String getValue(String key, char * chars);

    /**
     * A method to get value from Serial received characters casted to int
     * 
     * @param {String} key The key to look for
     * @param {char *} chars Characters from Serial
     * @return {int}
     */
    int getInt(String key, char * chars);

    void setDelimiter(String _del);
    void setSeperator(String _sep);
  private:
    void receiveData();

    const byte numChars = 32;
    char receivedChars[32];

    bool newData = false;
    char endMarker = '\n';

    String delimiter = ";";
    String seperator = ":";
};

#endif