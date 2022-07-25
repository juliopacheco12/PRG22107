#include "Arduino.h"

class pwm{
  private:
  int pwm_frentePin;
  int pwm_rePin;
  int duty;
  int canal_frente;
  int canal_re;

  public:
  pwm(int frentePin,int canal_f ,int rePin, int canal_r);
  void Attach();
  void movimenta(int duty, int dir);
//  void direcao(int duty, int dir, int last_dir);

};
