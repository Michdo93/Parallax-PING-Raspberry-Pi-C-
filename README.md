# Parallax PING))) Raspberry Pi C++
This class allows you to get datas from the Parallax PING))) sensor easily in C++!

## Installation

You have to download and install the [pigpio](https://abyz.me.uk/rpi/pigpio/) library:

```
sudo apt-get install pigpio
```

To start the pigpio daemon run

```
sudo systemctl start pigpiod
sudo systemctl enable pigpiod
```

## Usage

For running the library you can create an example like this:

```
#include <iostream>
#include <stdio.h>
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
    }
}

```
