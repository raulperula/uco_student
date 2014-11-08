/**
 * @file    exercise4.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include<stdio.h>

#define N 5

int main()
{
  double A[N][N] = {{4, 1, 0, 0, 0}, 
                    {2, 3, 1, 0, 0}, 
                    {0, 1, 1, 1, 0}, 
                    {0, 0, 2, 1, 2}, 
                    {0, 0, 0, 3, 1}};
  double B[N] = {9, 7, 0, 1, -2};
  double x[N];
  double k;
  int i; 
  
  for(i=1;i<N;i++){
          k = -A[i][i-1]/A[i-1][i-1];
          A[i][i] = A[i][i]+k*A[i-1][i];
          B[i] = B[i]+k*B[i-1];
  }
  
  printf("Soluciones:\n\n");
  
  x[N-1]=B[N-1]/A[N-1][N-1];
  
  for(i=N-2;i>=0;i--){
    x[i] = (B[i]-A[i][i+1]*x[i+1])/A[i][i];
  }
  
  for(i=0;i<N;i++)
    printf("X%d= %.0lf\n", i+1, x[i]);

  system("PAUSE");
}
