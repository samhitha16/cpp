#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

float absolute(float n){
  if(n>=0){
    return n;
  }
  else{
    return n*-1;
  }
}

float max(float a, float b){
  if(a>=b){
    return a;
  }
  else{
    return b;
  }
}

void Normalisation(int n, float* A, float* B){
  float a = 0;
  float b = 0;
  for(int i=0; i<n; i++){
    a += A[i];
    b += B[i];
  }
  for(int i=0; i<n; i++){
    A[i] = A[i]/a;
    B[i] = B[i]/b;
  }
}

float ManhattanDistance(int n, float* A, float* B){
  float sum = 0;
  for(int i=0; i<n; i++){
    sum += absolute(B[i] - A[i]);
  }
  return sum;
}

float EuclideanDistance(int n, float* A, float* B){
  float distance = 0;
  for(int i = 0; i<n; i++){
    distance += pow(absolute(B[i] - A[i]),2);
  }
  return sqrt(distance);
}

float ChebyshevDistance(int n, float* A, float* B){
  float C[n];
  float maximum = 0;
  for(int i=0; i<n; i++){
    C[i] = absolute(B[i] - A[i]);
  }
  maximum = C[0];
  for(int i=0; i<n; i++){
    maximum = max(maximum,C[i]);
  }
  return maximum;
}

float KLdivergence(int n, float* A, float* B){
  float sum = 0;
  for(int i = 0; i<n; i++){
    sum += (A[i]*(log(A[i]/B[i])));
  }
  return sum;
}

float JSdivergence(int n, float* A, float* B){
  float s = 0;
  float M[n];
  for(int i = 0; i<n; i++){
    M[i] = ((A[i]+B[i])*0.5);
  }
  s = (0.5*KLdivergence(n,A,M))+(0.5*KLdivergence(n,B,M));
  return s;
}

static inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

int main(){
  int n,x,y,z;
  char c;
  
  int flag1 = 0;
  int flag2 = 0;
  int flag3 = 0;
  int flag4 = 0;
  
  scanf("%d",&n);
  float A[n];
  float B[n];
  char E[n],F[n];
  /*for(int i=0; i<n; i++){
    E[i] = 0;
  }
  for(int i=0; i<n; i++){
    F[i] = 0;
  }*/
  scanf("%d",&x);
  for(int i=0; i<n; i++){
    scanf("%f%c",&A[i],&E[i]);
  }
  scanf("%d",&y);
  for(int i=0; i<n; i++){
    scanf("%f%c",&B[i],&F[i]);
  }

  scanf("%c",&c);
  if(c == '\n'){
    z = 0;
  }
  else if(c == '-'){
    scanf(" %d",&z);
    z = z*-1;
  }
 
  for(int i=0; i<n; i++){
    if(A[i] < 0){
      flag1 = 1;
    }
    if(strcmp(E,",,, ") != 0){
      flag3 = 1;
    }
  }

  for(int i=0; i<n; i++){
    if(B[i] < 0){
      flag2 = 1;
    }
    if(strcmp(F,",,, ") != 0){
      flag4 = 1;
    }
  }

  if(x == -1 && y == -1 && z == -1 && flag1 ==0 && flag2 == 0 && flag3 == 0 && flag4 == 0){
    Normalisation(n,A,B);
    float p = truncfunc(ManhattanDistance(n,A,B));
    float q = truncfunc(EuclideanDistance(n,A,B));
    float r = truncfunc(ChebyshevDistance(n,A,B));
    float s = truncfunc((KLdivergence(n,A,B)+KLdivergence(n,B,A)));
    float t = truncfunc(sqrt(JSdivergence(n,A,B)));
    printf("%.4f,",p);
    printf("%.4f,",q);
    printf("%.4f,",r);
    printf("%.4f,",s);
    printf("%.4f\n",t);
  }
  else{
    printf("%d",-1);
  }
  /*printf("%d",x);
  printf("%d",y);
  printf("%d",z);
  printf("%d",flag1);
  printf("%d",flag2);
  printf("%d",flag3);
  printf("%d",flag4);*/
  /*for(int i = 0; i<n; i++){
  printf("%c",E[i]);
  }
  printf("\n");
  printf("%s\n",F);*/

  return 0;
}
