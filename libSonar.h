#ifndef DEF_SONAR
#define DEF_SONAR

class Sonar
{
  public:
    Sonar();
    void init(int signal);
    double distance();

  private:
    int signal;
    double timeout;
    double pulse_end;
    double pulse_start;
    double timeout_start;
    double pulse_duration;
    double distanceCalculated;
};

#endif
