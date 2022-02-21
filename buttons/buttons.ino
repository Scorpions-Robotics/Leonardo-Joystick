#include <Joystick.h>

Joystick_ Joystick{JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, JOYSTICK_DEFAULT_BUTTON_COUNT, JOYSTICK_DEFAULT_HATSWITCH_COUNT, true, true, true, true, true, true, false, false, false, false, false};

const int analogConstants[] = {A0, A1, A2, A3, A4, A5};

void setup() {
  for(int i = 0; i<=13; i++){
    pinMode(i, INPUT_PULLUP);
  }
  
  Joystick.begin();
}

// Last state of the button
int lastButtonState[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int lastAnalogValue[6] = {0,0, 0, 0, 0, 0};

void loop() {

  for(int i = 0; i<13; i++){
    int currentState = !digitalRead(i);
    if(currentState!=lastButtonState[i]){
      lastButtonState[i] = currentState;
    }
    Joystick.setButton(i, lastButtonState[i]);
  }

  
  for(int i = 0; i<sizeof(analogConstants)/2; i++){
    int currentAnalogValue = analogRead(analogConstants[i]);
    if(currentAnalogValue!=lastAnalogValue[i]){
      lastAnalogValue[i] = currentAnalogValue;
    }
  }
  Joystick.setXAxis(lastAnalogValue[0]);
  Joystick.setYAxis(lastAnalogValue[1]);
  Joystick.setZAxis(lastAnalogValue[2]);
  Joystick.setRxAxis(lastAnalogValue[3]);
  Joystick.setRyAxis(lastAnalogValue[4]);
  Joystick.setRzAxis(lastAnalogValue[5]);
  
  
  delay(50);
}
