# Thermometer and humidity display
This project displays the temperature and humidity readings from a DHT22 sensor
on a 128x64 OLED display. What makes this project different from similar
projects is a progress bar at the bottom of the display showing you how long
until the readings are refreshed.

In addition the project will spin up a webserver which serves simple configuration page. This page will allow you to change the sensor refresh rate from 2 seconds to anything up to 2 minutes. Changes to the refresh rate will go into effect after the next scheduled sensor reading. This is done to ensure the sensor is not asked for values in an interval shorter than 2 seconds.

## Used hardware
- 1x ESP32 WROOM 4Mb Devkit V1
- 1x DHT-22 sensor
- 1x OLED display, 128 by 64 pixels, I2C compatible

## Required libraries
See the platformIO ini file for the required libraries.

## Setup
The components are wired up as follows:

### DHT-22 sensor
The DHT-22 sensor has its data pin connected to pin 4 on the ESP32 board.

### OLED display
The SLC pin of the display is connected to pin 21 on the ESP32 board. The SDA pin of the display is connected to pin 22 on the ESP32 board.

# License
This project is released under the [MIT](https://choosealicense.com/licenses/mit/) license.