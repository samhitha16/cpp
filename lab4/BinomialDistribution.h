#include<iostream>
#include<bits/stdc++.h>
#include"Histogram.h"

class BinomialDistribution : public Histogram{
  int n;
  float p;
public:
  BinomialDistribution(int a, float b);
  int fact(int x);
  int nCr(int y, int z);
  void set();
};
