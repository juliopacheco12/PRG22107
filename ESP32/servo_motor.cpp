#include "servo_motor.h"

  motor_servo::motor_servo(int interval){
    updateInterval = interval;
    increment = 1;
  }
  
  void motor_servo::Attach(int pin){
    servo.attach(pin);
    }
  
  void motor_servo::Deatach(){
    servo.detach();
  }

  void motor_servo::Update()
   {
    if((millis() - lastUpdate) > updateInterval)  // momento para atualizar
    {
      lastUpdate = millis();
      //pos += increment;
      //servo.write(pos);
      //Serial.println(pos);

      for(pos=0;pos<90;pos++){
         servo.write(pos);
         delay(interval);
      }
      for(pos=90;pos>=0;pos--){
         servo.write(pos);
         delay(interval);
      }
      return;
    }
  }
