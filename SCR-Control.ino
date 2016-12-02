#include "MessageManager.h";
#include "Lane.h";

const int MAX_LANES = 2;
Lane* lanes[MAX_LANES];

enum RACESTATUS { RACESTARTED, RACESTOPPED };
RACESTATUS raceStatus;

void startRace() {
  for (int i = 0; i < MAX_LANES; i++) {
    lanes[i]->setLastSensorTime(millis());
    lanes[i]->setOverSensor(false);
  }
  MessageManager.write("RACESTARTED");
  raceStatus = RACESTARTED;
  
}

void stopRace() {
  MessageManager.write("RACESTOPPED");
  raceStatus = RACESTOPPED;
}

void setMinLapTime(int minLapTime) {
  for(int i = 0; i < MAX_LANES; i++) {
    lanes[i]->setMinLapTime(minLapTime);
  }
}

void setSensorPin(int lane, int sensorPin) {
  lanes[lane]->setSensorPin(sensorPin);
}

void messageCallback(char* msg) {
  char* cmd = strtok(msg, ":");
  if (strcmp(cmd, "STARTRACE") == 0) {
    startRace();
  } else if (strcmp(cmd, "STOPRACE") == 0) {
    stopRace();
  } else if (strcmp(cmd, "SETMLT") == 0) {
    char* lapTime = strtok(NULL, cmd);
    setMinLapTime(atoi(lapTime));
  } else if (strcmp(cmd, "SETSP") == 0) {
    char* lane = strtok(NULL, cmd);
    char* sensorPin = strtok(NULL, cmd);
    setSensorPin(atoi(lane), atoi(sensorPin));
  }
}

void setup() {
  MessageManager.setBaudRate(57600);
  MessageManager.setCallbackFunction(messageCallback);
  raceStatus = RACESTOPPED;
  for(int i = 0; i < MAX_LANES; i++) {
    lanes[i] = new Lane(i);
    lanes[i]->setSensorPin(-1);
    lanes[i]->setMinLapTime(1000);  
  }
 }

void loop() {

  MessageManager.update();
  if (raceStatus == RACESTARTED) {
    for(int i = 0; i < MAX_LANES;i++) {
      lanes[i]->update();
    }
  }
   
}
