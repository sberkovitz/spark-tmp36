#ifndef TMP36_H
#include "tmp36.h"

tmp36::tmp36(uint16_t pin) {
    _pin = pin;
    _readAttempts = 5;
    _readDelay = 100;
}

tmp36::tmp36(uint16_t pin, int readAttempts, long readDelay) {
    _pin = pin;
    _readAttempts = readAttempts;
    _readDelay = readDelay;
}

bool tmp36::init() {
    pinMode(_pin, INPUT);
    return true;
}

double tmp36::getTemperature() {
    double reading = 0;
    double voltage = 0.0;
    double temperature;

    for(int i = 0; i < _readAttempts; i++){    
        reading += (int)analogRead(_pin);
        delay(_readDelay);
    }
    
    reading = reading / _readAttempts;

    // The returned value from the Core is going to be in the range from 0 to 4095
    // with 3.3v being the max
    voltage = (reading * 3.3) / 4095;

    // tmp36 has an offset of 500mV
    temperature = (voltage - 0.5) * 100;
    
    return temperature;
}
#endif

