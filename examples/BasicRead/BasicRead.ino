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
