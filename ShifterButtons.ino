#include <Joystick.h>

#include <Joystick.h>
//Define inputs
#define joyButton1 9
#define joyButton2 8

Joystick_ Joystick(0x15, JOYSTICK_TYPE_JOYSTICK, 2, 0, false, false, false, false, false,false, false, false, false, false, false );
const bool initAutoSendState = true;

  int lastButton1State = 0;
  int lastButton2State = 0;


void setup()  {
  //put setup code here
  pinMode(joyButton1, INPUT_PULLUP);
  pinMode(joyButton2, INPUT_PULLUP);

  Joystick.begin();

}


void loop() {
  // Put main code here. 
  int currentButton1State = !digitalRead(joyButton1);
  if(currentButton1State != lastButton1State) {
      Joystick.setButton (0, currentButton1State);
      lastButton1State = currentButton1State;
    }

  int currentButton2State = !digitalRead(joyButton2);
  if(currentButton2State != lastButton2State) {
      Joystick.setButton (1, currentButton2State);
      lastButton2State = currentButton2State;
    }

  //Pole Delay/Debounce
  delay(10);

}