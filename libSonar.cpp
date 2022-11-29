#include <iostream>
#include <stdio.h>
#include <pigpio.h>
#include "libSonar.h"
#include <unistd.h>

Sonar::Sonar(){}

void Sonar::init(int signal)
{
    this->signal=signal;
    gpioSetMode(si, PI_OUTPUT);
    double timeout = 0.05;
}

double Sonar::distance()
{
    double pulse_end = 0;
    double pulse_start = 0;
  
    gpioSetMode(signal, PI_OUTPUT);
    gpioSetMode(signal, PI_LOW);
  
    gpioDelay(10000);

    gpioSetMode(signal, PI_HIGH);

    gpioDelay(10);
  
    gpioSetMode(signal, PI_LOW);
    gpioSetMode(signal, PI_INPUT);

    double timeout_start = time_time();

    while(gpioRead(signal) == PI_LOW) {
        pulse_start = time_time();
      
        if(pulse_start - timeout_start > this->timeout) {
            return -1;
        }
    }

    while(gpioRead(signal) == PI_HIGH) {
        pulse_end = time_time();
      
        if(pulse_start - timeout_start > this->timeout) {
            return -1;
        }
    }

    if(pulse_start != 0 and pulse_end != 0) {
        double pulse_duration = pulse_end - pulse_start;
        double distanceCalculated = (pulse_duration * 34300) / 2;
      
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
