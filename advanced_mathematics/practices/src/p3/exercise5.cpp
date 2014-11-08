#include<stdio.h>
#include<math.h>

#define N 100

int
main(void)
{
  double A[N][N];
  double B[N];
  double x[N];
  double k;
  int i, j, l;
  
  //Inicializacion de A[][]
  for(i=0;i<N;i++){
    A[i][i+1] = 2;
    A[i][i] = 4;
    A[i+1][i] = 1;
    for(j=0;j<N;j++){
      if((A[i][j] != 2) && (A[i][j] != 4) && (A[i][j] != 1)){
        A[i][j] = 0;
      }
    }
  }
  
  //Inicializacion de B[]
  for(l=0;l<N;l++){
    B[l] = pow((l+1), 2)/10.;
  }
  
  //Triangulacion
  for(i=1;i<N;i++){
    k = -A[i][i-1]/A[i-1][i-1];
    A[i][i] = A[i][i]+k*A[i-1][i];
    B[i] = B[i]+k*B[i-1];
  }
  
  //Resolucion
  printf("Los resultados son:\n");
  
  x[N-1]=B[N-1]/A[N-1][N-1];
  
  for(i=N-2;i>=0;i--){
    x[i] = (B[i]-A[i][i+1]*x[i+1])/A[i][i];
  }
  for(i=0;i<N;i++)
    printf("x[%d] = %.0f\t", i, x[i]);
  
  getchar();
  getchar();
  
  return 0;
}
