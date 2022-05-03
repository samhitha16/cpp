#ifndef DataSequence_H_
#define DataSequence_H_

#include<iostream>

class DataSequence{
  int n;
  float *data;

  public:
    DataSequence(int g, float *p);
    ~DataSequence();
    DataSequence(const DataSequence &d);

    float GetData(int y){ return data[y];}
    int GetNum(){ return n;}

    void SetData(int y, float p);
    void SetNum(int x);

    float Minimum();
    float Mean();
    float Median();
    float Maximum();

};
#endif
