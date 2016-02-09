/******************************************************************************
Basic_Passthrough_Hardware.ino
Basic Hardware Serial GPS Passthrough
By Jim Lindblom @ SparkFun Electronics
February 9, 2016
https://github.com/sparkfun/GPS_Shield

This example uses an Arduino's hardware serial port -- on pins 0 and 1 -- to
communicate with the GPS module. 

Hardware serial should work on any Arduino's with a free hardware serial 
UART on pins 0/1. That includes Arduino Leonardo, Zero, Due, and SparkFun's
SAMD21 Dev Board.

After uploading the code, open your serial monitor, set it to 9600 baud, and
watch the GPS module's NMEA strings begin to flow by. See if you can pick
out the latitude and longitude.

Development/hardware environment specifics:
Arduino IDE 1.6.7
GPS Logger Shield v2.0 - Make sure the UART switch is set to HW-UART
Arduino Leonardo, Arduino Zero, Arduino Due, SparkFun SAMD21 Dev Board, etc
******************************************************************************/

#define GPS_BAUD_RATE 9600 // The GPS Shield module defaults to 9600 baud

// Define the serial monitor port. On the Leonardo this is 'Serial'
//  but on other boards this may be 'SerialUSB'
#define SerialMonitor Serial // e.g. Arduino Leonardo
// Define the harware serial port on pins 0/1. On the Leonardo this is 'Serial1'
//  but on other boards this may be 'Serial'
#define gpsPort Serial1 // e.g. Arduino Leonardo
// See https://www.arduino.cc/en/Reference/Serial to find out which Serial ports
//  you should use in the defines above.

void setup() 
{
  SerialMonitor.begin(9600); // Initialize the serial monitor port at 9600 baud
  gpsPort.begin(GPS_BAUD_RATE); // The GPS module's default baud is 9600
}

void loop() 
{
  if (gpsPort.available()) // If GPS data is available
    SerialMonitor.write(gpsPort.read()); // Send it to the serial monitor
  if (SerialMonitor.available()) // If data is sent to the serial monitor
    gpsPort.write(SerialMonitor.read()); // send it to the GPS module
}