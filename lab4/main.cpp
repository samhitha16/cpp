#include<iostream>
#include"BinomialDistribution.h"

int main(){
  int e;
  float f;
  float g;

  std::cin>>e;
  std::cin>>f;
  std::cin>>g;

  Histogram a(e+1);
  BinomialDistribution w1(e,f);
  w1.set();

  Histogram b(e+1);
  BinomialDistribution w2(e,g);
  w2.set();

  distance(a, b,e);

  return 0;
}
