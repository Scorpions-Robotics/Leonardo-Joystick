#include <Joystick.h>

Joystick_ Joystick;

const int analogConstants[2] = {A0, A1};

void setup() {
  for(int i = 0; i<=13; i++){
    pinMode(i, INPUT_PULLUP);
  }
  
  Joystick.begin();
}

// Last state of the button
int lastButtonState[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int lastAnalogValue[2] = {0,0};

void loop() {

  for(int i = 0; i<14; i++){
    int currentState = !digitalRead(i);
    if(currentState!=lastButtonState[i]){
      lastButtonState[i] = currentState;
    }
    Joystick.setButton(i, lastButtonState[i]);
  }

  /*
  for(int i = 0; i<2; i++){
    int currentAnalogValue = analogRead(analogConstants[i]);
    if(currentAnalogValue!=lastAnalogValue[i]){
      lastAnalogValue[i] = currentAnalogValue;
    }
  }
  Joystick.setXAxis(lastAnalogValue[0]);
  */
  
  delay(50);
}
