#include "MessageManager.h"

_MessageManager::_MessageManager() {
	setBaudRate(57600);
  inputBufferIndex = 0;
}
 
void _MessageManager::setBaudRate(long baudRate) {
	Serial.begin(baudRate);
}

void _MessageManager::update() {
  char input;
  while(Serial.available() > 0) {
    input = Serial.read();
    if(input == '[') {
      resetInputBuffer();
    } else if(input == ']') {
      callbackFunction(inputBuffer);
      resetInputBuffer();
    } else {
     inputBuffer[inputBufferIndex++] = input;
    }
  }
}
 
void _MessageManager::resetInputBuffer() {
	memset(&inputBuffer[0], 0, sizeof(inputBuffer));
  inputBufferIndex = 0;
}

void _MessageManager::setCallbackFunction(callback_function callbackFunction) {
	this->callbackFunction = callbackFunction;
}

_MessageManager MessageManager;
