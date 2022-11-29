#ifndef DEF_SONAR
#define DEF_SONAR

class Sonar
{
  public:
    Sonar();
    void init(int signal);
    double distance();
    double speed();

  private:
    int signal;
    double timeout;
    double pulse_end;
    double pulse_start;
    double timeout_start;
    double pulse_duration;
    double distanceCalculated;
    double distance1;
    double distance2;
    double speedMeasured;
};

#endif
