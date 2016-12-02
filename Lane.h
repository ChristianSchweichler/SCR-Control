#ifndef _Lane_h
#define _Lane_h

#include "Arduino.h"
#include "MessageManager.h";

class Lane {

  public:
    Lane(int nr);
    void setSensorPin(int sensorPin);
    void setMinLapTime(unsigned long minLapTime);
    void setLastSensorTime(unsigned long lastSensorTime);
    void setOverSensor(boolean overSensor);
    int getSensorPin();
    boolean isOverSensor();
    unsigned long getMinLapTime();
    unsigned long getLastSensorTime();
    void update();
    
  private:
    int nr;
    int sensorPin;
    boolean overSensor;
    unsigned long minLapTime;
    unsigned long lastSensorTime;
    static const int threshold = 800;
};

#endif
