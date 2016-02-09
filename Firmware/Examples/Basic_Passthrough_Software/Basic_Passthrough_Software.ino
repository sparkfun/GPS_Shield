/******************************************************************************
Basic_Passthrough_Software.ino
Basic Software Serial GPS Passthrough
By Jim Lindblom @ SparkFun Electronics
February 9, 2016
https://github.com/sparkfun/GPS_Shield

This example uses SoftwareSerial to communicate with the GPS module on
pins 8 and 9. SoftwareSerial should work on most Arduinos, but it's a
necessity on Arduino Mega's, Arduino Uno's, RedBoard's and any other Arduino
based around an ATmega328P.

After uploading the code, open your serial monitor, set it to 9600 baud, and
watch the GPS module's NMEA strings begin to flow by. See if you can pick
out the latitude and longitude.

Resources:
SoftwareSerial Library (included with Arduino)

Development/hardware environment specifics:
Arduino IDE 1.6.7
GPS Logger Shield v2.0 - Make sure the UART switch is set to SW-UART
Arduino Uno, RedBoard, Pro, Mega, etc.
******************************************************************************/

#include <SoftwareSerial.h> // Include the SoftwareSerial library
#define ARDUINO_GPS_RX 9 // Arduino RX pin connected to GPS TX
#define ARDUINO_GPS_TX 8 // Arduino TX pin connected to GPS RX
#define GPS_BAUD_RATE 9600 // The GPS Shield module defaults to 9600 baud
// Create a SoftwareSerial object called gps:
SoftwareSerial gpsPort(ARDUINO_GPS_TX, ARDUINO_GPS_RX);

// We'll also define a more descriptive moniker for the Serial Monitor port.
// This is the hardware serial port on pins 0/1.
#define SerialMonitor Serial

void setup() 
{
  gpsPort.begin(GPS_BAUD_RATE);
  SerialMonitor.begin(9600);
}

void loop() 
{
  if (gpsPort.available()) // If GPS data is available
    SerialMonitor.write(gpsPort.read()); // Read it and print to SerialMonitor
  if (SerialMonitor.available()) // If SerialMonitor data is available
    gpsPort.write(SerialMonitor.read()); // Read it and send to GPS
}