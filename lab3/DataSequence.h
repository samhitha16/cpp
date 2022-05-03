#include "FiveNumberSummary.h"
#include <bits/stdc++.h>

class DataSequence{

public:

    int n;
    float *seq;
    FiveNumberSummary fns;

    DataSequence();
    DataSequence(int _n);
    ~DataSequence();

    float getSequence(int i){ return seq[i];}
    int getN(){ return n;}
    void sort();
    void setSequence(float a, int i);
    void setN(int x);
    void calMin();
    void calLQ();
    void calMedian();
    void calUQ();
    void calMax();

    void update(float a);

};
