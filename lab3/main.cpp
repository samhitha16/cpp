#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include <vector>
#include "DataSequence.h"
#include "Histogram.h"
static inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

int main(){
  int flag1 = 0;
  int flag2 = 0;
  int i = 1;

  std::string input;
  std::string delim = " -1 ";
  std::string s1 = "N,";
  std::string s2 = "A,";
  std::string de = ",";
  std::string del = " ";
  std::string c[10];
  getline(std::cin,input);
  auto start = 0U;
  auto end = input.find(delim);
  c[0] = input.substr(start,end - start);
  while(end != std::string::npos){

    start = end + delim.length();
    end = input.find(delim,start);
    c[i] = input.substr(start,end - start);
    i++;
  }

  for(int j = 0; j<i; j++){
    if(s1.compare(c[j].substr(0,2)) == 0){
      flag1++;
    }
    else if(s2.compare(c[j].substr(0,2)) == 0){
      flag2++;
    }
  }

  std::vector <DataSequence> DSVector(flag1);
  int k = 0;
  for(int j = 0; j<i; j++){
    if(s1.compare(c[j].substr(0,2)) == 0){
      DSVector[k].setN(std::stoi(c[j].substr(2,1)));
      int l = 0;
      auto start1 = 0U;
      auto end1 = c[j].find(del);
      start1 = end1 + del.length();
      while(end1 != std::string::npos){
        end1 = c[j].find(de,start1);
        DSVector[k].setSequence(std::stof(c[j].substr(start1, end1 - start1)), l);
        start1 = end1 + de.length();
        l++;
      }
      k++;
    }
    else if(s2.compare(c[j].substr(0,2)) == 0){
      auto start2 = 0U;
      auto end2 = c[j].find(de,start2);
      start2 = end2 + de.length();
      end2 = c[j].find(de,start2);
      int x = std::stoi(c[j].substr(start2,end2-start2));
      start2 = end2 + de.length();
      end2 = c[j].find(de,start2);
      DSVector[x].setN((DSVector[x].getN())+1);
      DSVector[x].setSequence(std::stof(c[j].substr(start2,end2-start2)),(DSVector[x].getN())-1);
    }
  }


  for(int w = 0; w<flag1; w++){
    DSVector[w].sort();
    DSVector[w].calMin();
    DSVector[w].calMedian();
    DSVector[w].calLQ();

    DSVector[w].calUQ();
    DSVector[w].calMax();

    std::cout<<truncfunc(DSVector[w].fns.getMin());
    std::cout<<",";
    std::cout<<truncfunc(DSVector[w].fns.getLQ());
    std::cout<<",";
    std::cout<<truncfunc(DSVector[w].fns.getMedian());
    std::cout<<",";
    std::cout<<truncfunc(DSVector[w].fns.getUQ());
    std::cout<<",";
    std::cout<<truncfunc(DSVector[w].fns.getMax());
    std::cout<<" ";
    Histogram h;
    int n = DSVector[w].getN();
    float s[n];
    for(int v = 0; v<n; v++){
      s[v] = DSVector[0].getSequence(v);
    }
    std::sort(s,s+n);
    h.values(10,s,n);
    for(int z = 0; z<10; z++){
      std::cout<<truncfunc(h.getBinValues(z));
    }
    std::cout<<truncfunc(h.getBinValues(10));
    std::cout<<" ";
    h.frequencies(10,s,n);
    for (int z = 0; z<9; z++){
      std::cout<<truncfunc(h.getBinFrequencies(z));
      std::cout<<",";
    }
    std::cout<<truncfunc(h.getBinFrequencies(9));
    std::cout<<" -1 ";

  }




  return 0;
}
