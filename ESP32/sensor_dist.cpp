#include "Arduino.h"
#include "sensor_dist.h" 

sensor_dist::sensor_dist(int Pin){
    sensorPin = Pin;
    pinMode(sensorPin,INPUT);
  }
  
  int sensor_dist::estado_sensor(){
    if(digitalRead(sensorPin)==LOW){
      return 1;
    }
    else
    return 0;
  }
