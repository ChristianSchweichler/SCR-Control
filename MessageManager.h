#ifndef _MessageManager_h
#define _MessageManager_h

#include "Arduino.h"

class _MessageManager {
		
	typedef void (*callback_function)(char*);
	
	public:
		_MessageManager();
		void setBaudRate(long baudRate);
		void setCallbackFunction(callback_function callbackFunction);
    void update();
    void write(char* msg);

  private:
    byte inputBufferIndex;
    char inputBuffer[64];
	  callback_function callbackFunction;
    void resetInputBuffer();
    
};

extern _MessageManager MessageManager;

#endif
