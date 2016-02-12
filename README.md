# Simple auto watering system
## Introduction 
   This is a simple system to watering your plants when you are on holidays or just because you're lazy
   as me and you don't want to check your plants every day.
   Basically this system is for a Bonzaï tree who need to be constantly wet but delays can be adjust for your needs. 
   
   A sensor check the soil moisture and when it's dry a pump is switched on.
   The pump is switched off when the sensor is wet. 
   To avoid an overfill or sensor error, the time to fill is blocked to 40 seconds.

## Material
* 1 Arduino Uno
* 1 PowerSupply 9V 2A
* 1 Potentiometer 10k
* 1 Hygrometer Sensor - Don't use the cheapest one. 
With a bad sensor you will have some overfill problem.

* 1 Relay
* 1 DC pump
* PVC tubes

## Test it
In arduino code, set the delay value in line 92 to 0 - default: delay(18000000) 
Open a serial monitor and with potentiometer adjust the "dry" value. Test it with your plant.
 
## Installation
Upload .ino code into the Arduino.





