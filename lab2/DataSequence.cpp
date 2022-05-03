#include"DataSequence.h"
#include <bits/stdc++.h>

DataSequence::DataSequence(int g, float *p){
  n = g ;
  data = new float[g];
  for(int i = 0; i<g; i++){
    data[i] = p[i];
  }
  std::sort(data, data+n);
}

DataSequence::~DataSequence(){
  delete[] data;
  n = 0;
}

DataSequence::DataSequence(const DataSequence &d){
  n = d.n;
  data = d.data;
}

void DataSequence::SetData(int y,float p){ data[y] = p; }
void DataSequence::SetNum(int x){ n = x; }


float DataSequence::Minimum(){ return data[0];}

float DataSequence::Mean(){
  float sum = 0;
  for(int i = 0; i<n; i++){
    sum += data[i];
  }
  return sum/n;
}

float DataSequence::Median(){
  if(n%2 == 0){
    int a = n/2;
    return (data[a-1]+data[a])/2;
  }
  else if(n%2 == 1){
    return data[n/2];
  }
  else{
    return 0;
  }
}

float DataSequence::Maximum(){ return data[n-1];}
