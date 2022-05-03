#include"Histogram.h"

static inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }


Histogram::Histogram(int x){
  binValues = new double[x-1];
  binFrequencies = new double[x];
}

/*Histogram::Histogram(const Histogram &h){
  binFrequencies = h.binFrequencies;
}*/

void Histogram::setBinValues(double a, int x){ binValues[x] = a; }
void Histogram::setBinFrequencies(double a, int x){ binFrequencies[x] = a; }

void distance(Histogram &u, Histogram &v, int n){

  double MD = 0;
  for(int i=0; i<n; i++){
    MD += fabs(u.binFrequencies[i] - v.binFrequencies[i]);
  }
  std::cout<<truncfunc(MD);//Manhattan Distance

  double ED = 0;
  for(int i = 0; i<n; i++){
    ED += pow(fabs(u.binFrequencies[i] - v.binFrequencies[i]),2);
  }
  std::cout<<truncfunc(sqrt(ED));//Euclidean Distance

  double C[n+1];
  double CD = 0;
  for(int i=0; i<n; i++){
    C[i] = fabs(u.binFrequencies[i] - v.binFrequencies[i]);
  }
  CD = C[0];
  for(int i=0; i<n; i++){
    CD = std::max(CD,C[i]);
  }

  std::cout<<truncfunc(CD);//Chebyshev Distance

  double KLD = 0;
  for(int i = 0; i<n; i++){
    KLD += (u.binFrequencies[i]*(log(u.binFrequencies[i]/v.binFrequencies[i])));
  }
  std::cout<<truncfunc(KLD);//KL Divergence

  double JSD = 0;
  float M[n+1];
  for(int i = 0; i<n; i++){
    M[i] = ((u.binFrequencies[i]+v.binFrequencies[i])*0.5);
  }
  JSD = (0.5*KLdivergence(n,A,M))+(0.5*KLdivergence(n,B,M));
  return JSD;
  std::cout<<truncfunc(JSD);
}
