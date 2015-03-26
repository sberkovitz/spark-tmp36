# spark-tmp36
Small library for the Spark Core to take an averaged reading from a TMP36 temperature sensor.

Usage:

Use default constructor which takes just the pin and uses default retries/delays

```tmp36 mySensor = tmp36(A0);```

Or specify the retry and delay

```tmp36 mySensor = tmp36(A0, 5, 100); // 5 reads with 100ms delay```

```
//
// application.cpp
//
#include "application.h"
#include "tmp36.h"

double temperature = 0.0;

tmp36 mySensor = tmp36(A1);

SYSTEM_MODE(AUTOMATIC);

void setup() {
    Spark.variable("temperature", &temperature, DOUBLE);

    // Connect the temperature sensor to A1 which will configure it as an input
    mySensor.init();
}

void loop() {    
    // Calculate the temperature and update our static variable
    temperature = mySensor.getTemperature();
}
 ```