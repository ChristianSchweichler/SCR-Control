# include "Lane.h"

Lane::Lane(int nr) {
  this->nr = nr;
  setSensorPin(-1);
  lastSensorTime = 0;
  overSensor = false; 
}

void Lane::setSensorPin(int sensorPin) {
  this->sensorPin = sensorPin;
}

void Lane::setMinLapTime(unsigned long minLapTime) {
  this->minLapTime = minLapTime;
}

void Lane::setLastSensorTime(unsigned long lastSensorTime) {
  this->lastSensorTime = lastSensorTime;
}
    
int Lane::getSensorPin() {
  return sensorPin;
}

unsigned long Lane::getMinLapTime() {
  return minLapTime;
}
    
unsigned long Lane::getLastSensorTime() {
  return lastSensorTime;
}

void Lane::setOverSensor(boolean overSensor) {
  this->overSensor = overSensor;
}

boolean Lane::isOverSensor() {
  return overSensor;
}

void Lane::update() {
  unsigned long now;
  unsigned long lapTime;
  int sensorValue;
  if (sensorPin >= 0) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue < threshold && overSensor == false) {
      now = millis();
      lapTime = now - lastSensorTime;
      if (lapTime > minLapTime) {
        overSensor = true;
        lastSensorTime = now;
        MessageManager.sendLapTimeMessage(nr, lapTime);
      }
    }
    if (sensorValue >= threshold && overSensor == true) {
      overSensor = false;
    }
  }
}

