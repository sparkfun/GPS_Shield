SparkFun GPS Logger Shield Firmware
===================================

* **Examples** - Arduino examples
    * Basic_Passthrough_Software - GPS NMEA string passthough from GPS module to the Arduino serial monitor. Uses software serial on pins 8/9 to communicate with the GPS module, leaving the hardware UART on pins 0/1 free for serial monitoring. Good for an Arduino Uno, Pro, and RedBoard.
	* Basic_Passthrough_Hardware - GPS NMEA string passthough from GPS module to the Arduino serial monitor. Uses a hardware serial UART on pins 0/1 to communicate with the GPS module. Good for an Arduino Leonardo or Zero.
	* TinyGPSPlus_GPS_Shield - Uses the [TinyGPS++ Arduino Library](https://github.com/mikalhart/TinyGPSPlus/releases) to parse NMEA strings, and prints position, speed, time, date, and other information to the serial monitor.
	* CSV_Logger_TinyGPSPlus - Logs pertinent GPS data to a &micro;SD card. Uses the [TinyGPS++ Arduino Library](https://github.com/mikalhart/TinyGPSPlus/releases) to parse NMEA strings, and Arduino's built-in SD library to create and write to files on an SD card.