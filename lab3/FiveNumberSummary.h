class FiveNumberSummary{

  float minimum;
  float lowerquartile;
  float median;
  float upperquartile;
  float maximum;

  public:

    float getMin(){ return minimum;}
    float getLQ(){ return lowerquartile;}
    float getMedian(){ return median;}
    float getUQ(){ return upperquartile;}
    float getMax(){ return maximum;}

    void setMin(float a);
    void setLQ(float b);
    void setMedian(float c);
    void setUQ(float d);
    void setMax(float e);
    

};
