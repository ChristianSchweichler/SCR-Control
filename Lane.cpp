# include "Lane.h"

Lane::Lane() {
  
}

void Lane::setSensorPin(int sensorPin) {
  this->sensorPin = sensorPin;
}

void Lane::setMinLapTime(int minLapTime) {
  this->minLapTime = minLapTime;
}
    
int Lane::getSensorPin() {
  return sensorPin;
}

int Lane::getMinLapTime() {
  return minLapTime;
}
    
int Lane::getLastSensorTime() {
  return lastSensorTime;
}

