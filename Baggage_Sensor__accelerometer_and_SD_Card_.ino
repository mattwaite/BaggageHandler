/*
  SD card datalogger
 
 This example shows how to log data from three analog sensors 
 to an SD card using the SD library.
 	
 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 	 
 */

#include <SD.h>

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
const int chipSelect = 4;

const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage

int analogValue0 = 0;
int analogValue1 = 0;
int analogValue2 = 0;

void setup()
{
  analogReference(EXTERNAL);
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop()
{
  
  int analogValue0 = analogRead(A0);
   //  Serial.println(analogValue);    // For debugging
     
      int analogValue1 = analogRead(A1);
   //  Serial.println(analogValue);    // For debugging
     
     int analogValue2 = analogRead(A2);
   //  Serial.println(analogValue);    // For debugging


  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog6.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.print(analogValue0);
    dataFile.print("\t");
    dataFile.print(analogValue1);
    dataFile.print("\t");
    dataFile.print(analogValue2);
    dataFile.println();
    dataFile.close();
    /*  // print to the serial port too:
    Serial.print(analogValue0);
    Serial.print("\t");
    Serial.print(analogValue1);
    Serial.print("\t");
    Serial.print(analogValue2);
    Serial.println();
   */
     delay(100);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}









