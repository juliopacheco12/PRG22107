#include "Arduino.h"


class sensor_dist{
  private:
  int sensorPin;
  int estado;

  public:
  sensor_dist(int Pin);
  int estado_sensor();
};
