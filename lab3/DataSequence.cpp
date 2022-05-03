#include "DataSequence.h"

DataSequence::DataSequence(){
  n = 10;
  seq = new float(n);
}

DataSequence::DataSequence(int _n){
  n = _n;
  seq = new float(n);
}

DataSequence::~DataSequence(){
  delete seq;
}

void DataSequence::sort(){
  std::sort(seq,seq+n);
}

void DataSequence::setSequence(float a,int i){
  seq[i] = a;
}

void DataSequence::setN(int x){
  n = x;
}

void DataSequence::calMin(){
  fns.setMin(seq[0]);
}

void DataSequence::calLQ(){
    int i = 0;
    while(getSequence(i) <= fns.getMedian()){
      i++;
    }
    if(i%2 == 0){
      int x = i/2;
      float y = (seq[x-1]+seq[x])/2.0;
      fns.setLQ(y);
    }
    else if(i%2 == 1){
      fns.setLQ(seq[i/2]);
    }
  }

void DataSequence::calMedian(){
  if(n%2 == 0){
    int x = n/2;
    float y = (seq[x-1]+seq[x])/2.0;
    fns.setMedian(y);
  }
  else if(n%2 == 1){
    fns.setMedian(seq[n/2]);
  }
}

void DataSequence::calUQ(){
  int u;
  int i = n/2;
  //std::cout<<i;
  while(getSequence(i) >= fns.getMedian()){
    i++;
  }
  //std::cout<<i;
  u = i - n/2 ;
  //std::cout<<u;
  if(u%2 == 0){
    int x = u/2;
    float y = (seq[x-1+n/2]+seq[x+n/2])/2.0;
    fns.setUQ(y);
  }
  else if(u%2 == 1){
    fns.setUQ(seq[u/2 + n/2]);
  }
}

void DataSequence::calMax(){
  fns.setMax(seq[n-1]);
}

void DataSequence::update(float a){
  if(a < fns.getMin()){
    fns.setMin(a);
  }
  if(a > fns.getMax()){
    fns.setMax(a);
  }
  int c = n;
  setSequence(a,c);
  c++;
  std::sort(seq,seq+c);
  calLQ();
  calMedian();
  calUQ();

}
