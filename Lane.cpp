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

void Lane::update() {
  long now;
  long lapTime;
  
  if (analogRead(sensorPin) > threshold) {
    now = millis();
    lapTime = now - lastSensorTime;
    if (now - lastSensorTime > minLapTime) {
      lastSensorTime = now;
      MessageManager.write(lapTime);
    }
  }
}

