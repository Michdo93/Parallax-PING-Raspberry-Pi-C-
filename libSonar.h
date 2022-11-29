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
    double startTime;
    double arrivalTime;
    double timeElapsed;
    double distanceCalculated;
};

#endif
