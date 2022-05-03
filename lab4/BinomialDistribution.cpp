#include"BinomialDistribution.h"

/*BinomialDistribution::Histogram(int x){
  binValues = new double[x-1];
  binFrequencies = new double[x];
}*/

BinomialDistribution::BinomialDistribution(int a, float b){
  n = a;
  p = b;
  //Histogram x(int n+1);
}

int BinomialDistribution::fact(int x){
  int r = 1;
  for (int i = 2; i <= n; i++)
      r = r * i;
  return r;
}

int BinomialDistribution::nCr(int y, int z){
  return fact(y)/(fact(z)*fact(y-z));
}

void BinomialDistribution::set(){
  for(int k = 0; k<n+1; k++){
    setBinFrequencies((nCr(n,k)*pow(p,k)*pow(1-p,n-k)),k);
  }
}
