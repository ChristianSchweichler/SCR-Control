#ifndef _Lane_h
#define _Lane_h

#include "Arduino.h"

class Lane {

  public:
    Lane();
    void setSensorPin(int sensorPin);
    void setMinLapTime(int minLapTime);
    int getSensorPin();
    int getMinLapTime();
    int getLastSensorTime();
    void update();
    
  private:
    int sensorPin;
    int minLapTime;
    int lastSensorTime;
  
};

#endif
