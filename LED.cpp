/*  LED Arduino Library
    This library has 2 main functions:
    1. Abstraction layer for initialization and negative logic,
    2. various behaviour configured in the calling code statid/dynamic and digital/PWM
    (c) Adrian Salanti / Aquamarine Solutions
    Code under BSD-4-Clause license */

#include <LED.h>

LED::LED ( byte pLEDPin, boolean pNeg ) {
    LEDPin = pLEDPin;
    neg = pNeg;
    pinMode( LEDPin, OUTPUT);
    digitalWrite( LEDPin, neg);
}
LED::LED( byte pLEDPin, boolean pNeg, byte pStepsCount, LEDDigitalStep *pDS, byte pStepSetsCount, LEDStepSet *pDSS ){
    LEDPin = pLEDPin;
    neg = pNeg;
    pinMode( LEDPin, OUTPUT);
    stepsCount = pStepsCount;
    DS = pDS;
    stepSetsCount = pStepSetsCount;
    DSS = pDSS;
}
LED::LED( byte pLEDPin, boolean pNeg, byte pStepsCount, LEDPWMStep *pPS, byte pStepSetsCount, LEDStepSet *pDSS ){
    LEDPin = pLEDPin;
    neg = pNeg;
    pinMode( LEDPin, OUTPUT);
    stepsCount = pStepsCount;
    PS = pPS;
    stepSetsCount = pStepSetsCount;
    DSS = pDSS;
}        
void LED::State(boolean pState){
    digitalWrite( LEDPin, neg != pState);
}
void LED::ProcessDigital(){
    if (StartRestart){
        StartRestart = false;
        previousMillis = millis();
        currentStep = DSS[CurrentStepSet].StartIx;
        digitalWrite(LEDPin,neg!=DS[currentStep].State);
        return;
    }
    if (millis()-previousMillis>DS[currentStep].Duration){
        previousMillis = millis();
        currentStep++;
        if(currentStep>DSS[CurrentStepSet].EndIx){
            currentStep = DSS[CurrentStepSet].StartIx;
            iterationCounter++;
        }
        if(iterationCounter>=DSS[CurrentStepSet].Count){
            CurrentStepSet = DSS[CurrentStepSet].NextStepSet;
            currentStep = DSS[CurrentStepSet].StartIx;
            iterationCounter = 0;
        }
        digitalWrite(LEDPin,neg!=DS[currentStep].State);
    }
}
void LED::ProcessPWM(){
    if (StartRestart){
        StartRestart = false;
        previousMillis = millis();
        currentStep = DSS[CurrentStepSet].StartIx;
    }
    if (millis()-previousMillis>PS[currentStep].Duration){
        previousMillis = millis();
        currentStep++;
        if(currentStep>DSS[CurrentStepSet].EndIx){
            currentStep = DSS[CurrentStepSet].StartIx;
            iterationCounter++;
        }
        if(iterationCounter>=DSS[CurrentStepSet].Count){
            CurrentStepSet = DSS[CurrentStepSet].NextStepSet;
            currentStep = DSS[CurrentStepSet].StartIx;
            iterationCounter = 0;
        }

    }
    byte analogValue = (( (int)PS[currentStep].EndValue - (int)PS[currentStep].StartValue ) * (long)(millis()-previousMillis) / PS[currentStep].Duration + PS[currentStep].StartValue );
    analogWrite(LEDPin, (neg?255-analogValue:analogValue));
}
void LED::PWM(byte pValue){
    analogWrite(LEDPin, (neg?255-pValue:pValue));
}