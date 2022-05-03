#include<iostream>
#include<bits/stdc++.h>

class Histogram{
  double *binValues;
  double *binFrequencies;

  public:
    Histogram(int x);
    //Histogram(const Histogram &h);
    double getBinValues(int x){ return binValues[x]; }
    double getBinFrequencies(int x){ return binFrequencies[x]; }

    void setBinValues(double a, int x);
    void setBinFrequencies(double a, int x);

    //double max(double a, double b);
    //double absolute(double n);

    friend void distance(Histogram &u, Histogram &v,int n);
};
