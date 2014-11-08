/**
 * @file    exercise5.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include<stdio.h>
#include<math.h>

#define N 100

int main()
{
  double A[N][N];
  double B[N];
  double x[N];
  double k;
  int i, j;
  
  //Inicializamos A
  for(i=0;i<N;i++){
      for(j=0;j<N;j++) A[i][j]=0;
      }
      
  for(i=0;i<N-1;i++){
      A[i][i]=4;
      A[i][i+1]=2;
      A[i+1][i]=1;
      }
  A[99][99]=4;
  A[99][98]=1;
  
  //Inicializamos B
  for(i=1;i<=N;i++){
      B[i-1]=pow(i, 2)/10.;
  }
  B[99]=pow(100, 2)/10.;
  
  for(i=1;i<N;i++){
      k=-A[i][i-1]/A[i-1][i-1];
      A[i][i]=A[i][i]+k*A[i-1][i];
      B[i]=B[i]+k*B[i-1];
      }
   
  printf("Soluciones:\n\n");
  
  x[N-1]=B[N-1]/A[N-1][N-1];
  
  for(i=N-2;i>=0;i--){
      x[i]=(B[i]-A[i][i+1]*x[i+1])/A[i][i];
  }
  
  for(i=0;i<N;i++) printf("X%d= %lf\n", i+1, x[i]);
  
  system("PAUSE");
}
