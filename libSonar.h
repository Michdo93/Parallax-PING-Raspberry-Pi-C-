#ifndef DEF_SONAR
#define DEF_SONAR

class Sonar
{
  public:
    Sonar();
    void init(const int &signal);
    double distance();
    double speed();

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
