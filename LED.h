/*  LED Arduino Library
    This library has 2 main functions:
    1. Abstraction layer for initialization and negative logic,
    2. various behaviour configured in the calling code statid/dynamic and digital/PWM
    (c) Adrian Salanti / Aquamarine Solutions
    Code under BSD-4-Clause license */

#ifndef LED_h
#define LED_h
#include <Arduino.h>

typedef struct LEDDigitalStep{
    boolean State;
    unsigned int Duration;
};
typedef struct LEDPWMStep{
    byte StartValue;
    byte EndValue;
    unsigned int Duration;
};
typedef struct LEDStepSet{
    byte StartIx;
    byte EndIx;
    byte Count;
    byte NextStepSet;
};

class LED {
public:
    LED( byte pLEDPin, boolean pNeg );
    LED( byte pLEDPin, boolean pNeg, byte StepsCount, LEDDigitalStep *pDS, byte StepSetsCount, LEDStepSet *pDSS );        
    LED( byte pLEDPin, boolean pNeg, byte StepsCount, LEDPWMStep *pPS, byte StepSetsCount, LEDStepSet *pDSS );        
    void State(boolean pState);
    void ProcessDigital();
    void ProcessPWM();
    void PWM(byte pValue);
    byte CurrentStepSet = 0;
    boolean StartRestart = true;
private:
    byte LEDPin;
    boolean neg;
    unsigned long previousMillis = 0;
    byte iterationCounter = 0,
        stepsCount = 0,
        currentStep = 0,
        stepSetsCount = 0;
    LEDDigitalStep *DS;
    LEDPWMStep *PS;
    LEDStepSet *DSS;
};
#endif