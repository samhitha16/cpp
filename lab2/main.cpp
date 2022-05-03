#include<iostream>
#include<string>
#include <bits/stdc++.h>
#include"DataSequence.h"
#include"Histogram.h"

static inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

int main(){
  std :: cout.precision(4);
  std::cout<<std::fixed;
  int n;
  int m = 0;
  float *sequence;
  sequence = new float[n];
  for(int i = 0; i<n; i++){
    sequence[i] = 0;
  }
  int flag1 = 0;
  std::string input;
  std::string delim = " -1 ";
  std::string d = ",";
  std::string de = " -1";

  getline(std::cin,input);
  auto start = 0U;
  auto end = input.find(delim);

  if(end != std::string::npos){
    n = stoi(input.substr(start, end - start));
    start = end + delim.length();
  }
  if(end != std::string::npos){
    for(int i = 0; i<n-1; i++){
      end = input.find(d,start);
      if(end > input.length()){
        flag1 = 1;
      }
      sequence[i] = stof(input.substr(start, end - start));
      start = end + d.length();
    }
    end = input.find(delim,start);
    sequence[n-1] = stof(input.substr(start, end - start));
  }
  if(end != std::string::npos){
    start = end + delim.length();
    end = input.find(de,start);
    m = stoi(input.substr(start, end - start));
    end = end + de.length();
  }

    for(int i = 0; i<n; i++){
      if(sequence[i]<=0){
        flag1 = 1;
      }
    }

    if(n>0  && m>0 && flag1 == 0){
      DataSequence d(n, sequence);
      std::cout<<truncfunc(d.Minimum());
      std::cout<<" ";
      std::cout<<-1;
      std::cout<<" ";
      std::cout<<truncfunc(d.Mean());
      std::cout<<" ";
      std::cout<<-1;
      std::cout<<" ";
      std::cout<<truncfunc(d.Median());
      std::cout<<" ";
      std::cout<<-1;
      std::cout<<" ";
      std::cout<<truncfunc(d.Maximum());
      std::cout<<" ";
      std::cout<<-1;
      std::cout<<"\n";
      std::sort(sequence,sequence+n);
      Histogram h;
      h.values(m,sequence,n);
      h.frequencies(m,sequence,n);
      for(int i = 0; i<m; i++){
        std::cout<<truncfunc(h.getBinValues(i));
        std::cout<<",";
      }
      std::cout<<truncfunc(h.getBinValues(m));
      std::cout<<" ";
      std::cout<<-1;
      std::cout<<"\n";
      std::cout<<std::defaultfloat;
      for(int i = 0; i<m-1; i++){
        std::cout<<h.getBinFrequencies(i);
        std::cout<<",";
      }
      std::cout<<h.getBinFrequencies(m-1);
      std::cout<<" ";
      std::cout<<-1;
    }
    else{
      std::cout<<-1;
    }

    //std::cout<<truncfunc(4.99967)<<std::endl;
  return 0;
}
