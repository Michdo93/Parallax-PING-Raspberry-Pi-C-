#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>
#include "libSonar.h"

using namespace std;

int signal = 19;

int main()
{
    if (gpioInitialise() == -1)
        return -1;

    Sonar sonar;
    sonar.init(signal);

    while(1){
        cout << "Distance is " << sonar.distance() << " cm." << endl;
        usleep(1000000);
    }
}
