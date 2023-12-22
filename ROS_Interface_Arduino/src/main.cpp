#include <Arduino.h>
#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"
#include "ApplicationFunctionSet_xxx0.cpp"

DeviceDriverSet_Motor AppMotor;
Application_xxx Application_ConquerorCarxxx0;

// put function declarations here:
ConquerorCarMotionControl translator(int);
int keyboardtrans(int);
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  AppMotor.DeviceDriverSet_Motor_Init();
  Serial.begin(9600); // Start Communikation
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp =8;
   Serial.println("Standardfall");
  if (Serial.available() > 0) { // Überprüfen, ob Daten verfügbar sind
    char receivedChar = Serial.read(); // Einlesen des empfangenen Zeichens
    
    if (isDigit(receivedChar)) { // Überprüfen, ob das Zeichen eine Ziffer ist
      temp=keyboardtrans(receivedChar - '0');
    }
  }
  ApplicationFunctionSet_ConquerorCarMotionControl(translator(temp), 255 /*speed*/);
  delay(1000);
}

// put function definitions here:
ConquerorCarMotionControl translator(int x){
  /*
  * s0 s1 s2
  * s7 WF s3
  * s6 s5 s4
  */
  switch (x)
  {
  case /* constant-expression */0:
    /* code */
    return LeftForward;
  case /* constant-expression */1:
    /* code */
    return Forward;

  case /* constant-expression */2:
    /* code */
    return RightForward;

  case /* constant-expression */3:
    /* code */
    return Right;

  case /* constant-expression */4:
    /* code */
    return RightBackward;

  case /* constant-expression */5:
    /* code */
    return Backward;

  case /* constant-expression */6:
    /* code */
    return LeftBackward;

  case /* constant-expression */7:
    /* code */
  return  Left;

  default:
    return stop_it;
  }
}
int keyboardtrans(int x){
  /*
  * s0  s1    s2
  * s7  WF    s3
  * s6  s5    s4
  */
                      
  switch (x)
  {
  case /* constant-expression */7:
    /* code */
    return 0;
  case /* constant-expression */8:
    /* code */
    return 1;

  case /* constant-expression */9:
    /* code */
    return 2;

  case /* constant-expression */6:
    /* code */
    return 3;

  case /* constant-expression */3:
    /* code */
    return 4;

  case /* constant-expression */2:
    /* code */
    return 5;

  case /* constant-expression */1:
    /* code */
    return 6;

  case /* constant-expression */4:
    /* code */
  return 7;
  
  default:
    return 8;
  }
}

int myFunction(int x, int y) {
  return x + y;
}