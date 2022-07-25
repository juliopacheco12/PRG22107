#include "Arduino.h"
#include <ESP32Servo.h>

class motor_servo{
  private:
  Servo servo;
  int pos;
  int increment;
  int updateInterval;
  unsigned long lastUpdate;

 public:
  motor_servo(int interval);
  void Attach(int pin);
  void Deatach();
  void Update();
};
