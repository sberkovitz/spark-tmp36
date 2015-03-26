/* 
 * File:   tmp36.h
 * Author: steven
 *
 * Created on March 25, 2015, 9:05 PM
 */

#ifndef TMP36_H
#define	TMP36_H

#include "application.h"

class tmp36 {
public:
    tmp36(uint16_t pin);
    tmp36(uint16_t pin, int readAttempts, long readDelay);
    bool init();
    double getTemperature();

private:
    uint16_t _pin;
    int _readAttempts;
    long _readDelay;
};

#endif	/* TMP36_H */