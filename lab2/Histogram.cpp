#include"Histogram.h"

void Histogram::setBinValues(float a, int x){ binValues[x] = a; }
void Histogram::setBinFrequencies(float a, int x){ binFrequencies[x] = a; }

void Histogram::values(int a,float *p,int n){
  if(n ==1){
    float y = 1.0/a;
    binValues = new float[a+1];
    float w = p[0] - 0.5;
    for(int i = 0; i<a+1; i++){
      binValues[i] = w + i*y;
    }
  }
  else{
    float x = (p[n-1] - p[0])/a;
    binValues = new float[a+1];
    for(int i = 0; i<a+1; i++){
      binValues[i] = p[0] + i*x;
    }
  }

}

void Histogram::frequencies(int a,float *p,int n){
  binFrequencies = new float[a];
  for(int i = 0; i<a; i++){
    int c = 0;
    for(int j = 0; j<n; j++){
      if(getBinValues(i) <= p[j] && p[j] < getBinValues(i+1)){
        c++;
      }
    }
    binFrequencies[i] = c;
  }
  if(n != 1){
    binFrequencies[a-1]++;
  }

}
