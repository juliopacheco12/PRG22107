#include "Arduino.h"
#include "pwm.h" 

  pwm::pwm(int frentePin,int canal_f ,int rePin, int canal_r){
    pwm_frentePin = frentePin;
    canal_frente = canal_f;
    canal_re = canal_r;
    pwm_rePin = rePin;
    duty = 0;
    

    pinMode(pwm_frentePin, OUTPUT);
    pinMode(pwm_rePin, OUTPUT);
  }

  void pwm::Attach(){
    ledcSetup(canal_frente,1000,10);
    ledcSetup(canal_re,1000,10);
    ledcAttachPin(pwm_frentePin,canal_frente);
    ledcAttachPin(pwm_rePin,canal_re);
  }
  void pwm::movimenta(int duty, int dir){
    switch(dir){

      case 1: //movimento da roda para frente
      ledcWrite(canal_frente,duty);
      ledcWrite(canal_re,0);
      break;

      case 2: //movimento da roda para tras
      ledcWrite(canal_frente,0);
      ledcWrite(canal_re,duty);
      break;
    }
  }
