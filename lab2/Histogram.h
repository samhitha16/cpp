#include<iostream>

class Histogram{
  float *binValues;
  float *binFrequencies;

  public:

    float getBinValues(int x){ return binValues[x]; }
    float getBinFrequencies(int x){ return binFrequencies[x]; }

    void setBinValues(float a, int x);
    void setBinFrequencies(float a, int x);

    void values(int a,float *p,int n);
    void frequencies(int a,float *p,int n);
};
