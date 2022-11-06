/*  LED Arduino Library Sample
    This library has 2 main functions:
    1. Abstraction layer for initialization and negative logic,
    2. various behaviour configured in the calling code statid/dynamic and digital/PWM
    (c) Adrian Salanti / Aquamarine Solutions
    Code under BSD-4-Clause license */

//includes
// debug #include <TimedPushButton.h>
#include <LED.h>

//config
#include "Config.h"

//init
#if LED_BEHAVIOUR == LED_BEHAVIOUR_DIGITAL_STATIC
  LED L( LED_PIN, LED_NEGATIVE_LOGIC );
#elif LED_BEHAVIOUR == LED_BEHAVIOUR_DIGITAL_VARIABLE
  #define LED_STEPS_COUNT 4
  #define LED_STEP_SETS_COUNT 2
  LEDDigitalStep DS[] = {{true,2900},{false,100},{false,900},{true,100}};
  LEDStepSet DSS[] = {{0,1,3,1},{2,3,5,0}};
  LED L( LED_PIN, LED_NEGATIVE_LOGIC, LED_STEPS_COUNT, DS, LED_STEP_SETS_COUNT, DSS);
  // void OnChangeTest(bool pState){
  //   L.CurrentStepSet = (pState?1:0);
  //   L.StartRestart=true;
  // }
#elif LED_BEHAVIOUR == LED_BEHAVIOUR_PWM_STATIC
  LED L( LED_PIN, LED_NEGATIVE_LOGIC );
  // void OnChangeTest(bool pState){
  //   L.PWM((pState?255:128));
  // }
#elif LED_BEHAVIOUR == LED_BEHAVIOUR_PWM_VARIABLE
  #define LED_STEPS_COUNT 4
  #define LED_STEP_SETS_COUNT 2
  LEDPWMStep PS[] = {{3,60,2000},{60,3,500},{0,0,900},{120,120,100}};
  LEDStepSet DSS[] = {{0,1,3,1},{2,3,4,0}};
  LED L( LED_PIN, LED_NEGATIVE_LOGIC, LED_STEPS_COUNT, PS, LED_STEP_SETS_COUNT, DSS);
  // void OnChangeTest(bool pState){
  //   L.CurrentStepSet = (pState?1:0);
  //   L.StartRestart=true;
  // }
#endif


// void OnDepressTest(unsigned long pDuration){
//   Serial.print("OnDepressTest:");
//   Serial.println(pDuration);
// }

//TimedPushButton TPB( CONTACT_PIN, CONTACT_NEGATIVE_LOGIC, INTERNAL_PULLUP, DEBOUNCE_INTERVAL);

void setup() {
//  Serial.begin(SERIAL_SPEED);
//   TPB.OnChange (OnChangeTest);
//   TPB.OnDepress (OnDepressTest);  
}

void loop() {

#if LED_BEHAVIOUR == LED_BEHAVIOUR_DIGITAL_STATIC
  L.State(true);
  delay(2000);
  L.State(false);
  delay(1000);
#elif LED_BEHAVIOUR == LED_BEHAVIOUR_DIGITAL_VARIABLE
  L.ProcessDigital();
  // #define LED_STEPS_COUNT 4
  // #define LED_STEP_SETS_COUNT 2
  // LEDDigitalStep DS[] = {{true,2900},{false,100},{false,900},{true,100}};
  // LEDStepSet DSS[] = {{0,1,10,0},{2,3,20,1}};
  // LED L( LED_PIN, LED_NEGATIVE_LOGIC, LED_STEPS_COUNT, DS, LED_STEP_SETS_COUNT, DSS);
  // void OnChangeTest(bool pState){
  //   L.CurrentStepSet = (pState?1:0);
  //   L.StartRestart=true;
  // }
#elif LED_BEHAVIOUR == LED_BEHAVIOUR_PWM_STATIC
  L.PWM(255);
  delay(2000);
  L.PWM(128);
  delay(1000);
  // LED L( LED_PIN, LED_NEGATIVE_LOGIC );
  // void OnChangeTest(bool pState){
  //   L.PWM((pState?255:128));
  // }
#elif LED_BEHAVIOUR == LED_BEHAVIOUR_PWM_VARIABLE
  L.ProcessPWM();
  // #define LED_STEPS_COUNT 4
  // #define LED_STEP_SETS_COUNT 2
  // LEDPWMStep PS[] = {{3,60,2000},{60,3,500},{0,0,900},{120,120,100}};
  // LEDStepSet DSS[] = {{0,1,10,0},{2,3,20,1}};
  // LED L( LED_PIN, LED_NEGATIVE_LOGIC, LED_STEPS_COUNT, PS, LED_STEP_SETS_COUNT, DSS);
  // void OnChangeTest(bool pState){
  //   L.CurrentStepSet = (pState?1:0);
  //   L.StartRestart=true;
  // }
#endif





  //Serial.println("loop");
//   TPB.Process();
//   #if LED_BEHAVIOUR == LED_BEHAVIOUR_DIGITAL_VARIABLE
//     L.ProcessDigital();
//   #elif LED_BEHAVIOUR == LED_BEHAVIOUR_PWM_VARIABLE
//     L.ProcessPWM();
//     //delay(100);
//   #endif
}
