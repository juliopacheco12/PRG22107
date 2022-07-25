#include "pwm.h"
#include "servo_motor.h"
#include "sensor_dist.h"

pwm pwm_df(18, 4, 19, 5);
pwm pwm_ef(22, 2, 23, 3);
sensor_dist sen1(12);
motor_servo mot1(30);

int i;
char msg;
void setup() {
  Serial.begin(115200);
  pwm_df.Attach();
  pwm_ef.Attach();
  mot1.Attach(4);
}

void loop() {

  int last_dir = 1;
  int duty = 1024;
  int sensor_estado = 0;

  
  if(sensor_estado = sen1.estado_sensor()==1){
    mot1.Update();
  }
  if (Serial.available()) {

    //read serial as a character
    char ser = Serial.read();

    switch (ser) {
      case 'f':
        last_dir = 1;
        pwm_df.movimenta(duty, last_dir);
        pwm_ef.movimenta(duty, last_dir);
        break;

      case 'd':
        pwm_df.movimenta(duty, last_dir);
        pwm_ef.movimenta(duty / 3, last_dir);
        break;

      case 'e':
        pwm_df.movimenta(duty / 3, last_dir);
        pwm_ef.movimenta(duty, last_dir);
        break;

      case 'r':
        last_dir = 2;
        pwm_df.movimenta(duty, last_dir);
        pwm_ef.movimenta(duty, last_dir);
        break;

        case 'p':
        pwm_df.movimenta(0, last_dir);
        pwm_ef.movimenta(0, last_dir);
        break;
        
      case 't':
      mot1.Update();
        break;
    }
  }
}
