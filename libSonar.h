#ifndef DEF_SONAR
#define DEF_SONAR

class Sonar
{
  public:
    Sonar();
    void init(const uint8_t &signal);
    double distance();
    double speed();
    ~Sonar();

  private:
    int signal;
    double timeout;
    double pulseEnd;
    double pulseStart;
    double timeoutStart;
    double pulseDuration;
    double distanceCalculated;
    double distance1;
    double distance2;
    double speedMeasured;
};

#endif
