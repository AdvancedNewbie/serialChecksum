#include "serialChecksum.h"

serialChecksum serialCheck;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
//  Serial.println("Listening!");
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    serialCheck.inputString = inputString;
    Serial.print("Message: ");
    Serial.print(serialCheck.message());
    Serial.print(" Received Checksum: ");
    Serial.print(serialCheck.recv_checksum());
    Serial.print(" Calculated Checksum: ");
    Serial.print(serialCheck.checksum());

    if (serialCheck.isGood() == false) {
      Serial.println(" Checksum MISMATCH!");
    } else {
      Serial.println(" Checksum MATCH!");
    }
    
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}


/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}


