class Histogram{
  int numBins = 10;
  int numSeq;
  float *binValues;
  float *binFrequencies;

  public:

    float getBinValues(int x){ return binValues[x]; }
    float getBinFrequencies(int x){ return binFrequencies[x]; }

    void setBinValues(float a, int x);
    void setBinFrequencies(float a, int x);

    void values(int a,float *p,int n);
    void frequencies(int a,float *p,int n);

    //void Normalisation(int n, float *A);

};
