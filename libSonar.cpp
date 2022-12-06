#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>
#include "libSonar.h"

Sonar::Sonar(){}

void Sonar::init(const uint8_t &signal)
{
    this->signal=signal;
    gpioSetMode(si, PI_OUTPUT);
    double timeout = 0.05;
}

double Sonar::distance()
{
    double pulseEnd = 0;
    double pulseStart = 0;
  
    gpioSetMode(signal, PI_OUTPUT);
    gpioSetMode(signal, PI_LOW);
  
    gpioDelay(10000);

    gpioSetMode(signal, PI_HIGH);

    gpioDelay(10);
  
    gpioSetMode(signal, PI_LOW);
    gpioSetMode(signal, PI_INPUT);

    double timeoutStart = time_time();

    while(gpioRead(signal) == PI_LOW) {
        pulseStart = time_time();
      
        if(pulseStart - timeoutStart > this->timeout) {
            return -1;
        }
    }

    while(gpioRead(signal) == PI_HIGH) {
        pulseEnd = time_time();
      
        if(pulseStart - timeoutStart > this->timeout) {
            return -1;
        }
    }

    if(pulseStart != 0 and pulseEnd != 0) {
        double pulseDuration = pulseEnd - pulseStart;
        double distanceCalculated = (pulseDuration * 34300) / 2;
      
        if(distanceCalculated >= 0) {
            return distanceCalculated;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

double Sonar::speed()
{
    double distance1 = distance();    
    usleep(1000000);
    double distance2 = distance();
    
    double speedMeasured = (distance2 - distance1) / 1.0;
    
    return speedMeasured;
}

Sonar::~Sonar()
{
    gpioTerminate();
}
