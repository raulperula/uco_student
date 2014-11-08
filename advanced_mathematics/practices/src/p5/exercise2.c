/**
 * @file    exercise2.c
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
#include<stdlib.h>

#define N 7
#define M 5

void inicializaciones(double* h,double* X,double* Y,double* A);
void iniB(double* B,double* A);
void iniMatriz(double** matriz,double* h);
void solSistema(double** A,double* B,double* v);

int main(){
    double X[N]={40,45,50,55,60,65,70};
    double Y[N]={390,340,290,250,210,180,160};
    double h[N-1];
    double A[N-1];
    double a[N-1];
    double b[N-1];
    double c[N-1];
    double d[N-1];
    double** matriz;
    double v[N];
    double B[N-2];
    int i;
    
    matriz=(double**)malloc((N-2)*sizeof(int*));
    for(i=0;i<N-2;i++) matriz[i]=(double*)malloc((N-2)*sizeof(int));
    
    inicializaciones(h,X,Y,A);
    iniB(B,A);
    iniMatriz(matriz,h);
    solSistema(matriz,B,v);
    
    for(i=0;i<N-1;i++){
         a[i]=(v[i+1]-v[i])/(6*h[i]);
         b[i]=v[i]/2;
         c[i]=A[i]-((2*v[i]+v[i+1])/6)*h[i];
         d[i]=Y[i];
         }
    for(i=0;i<6;i++) printf(" a%d:%lf",i,a[i]);
    printf("\n");
    for(i=0;i<6;i++) printf(" b%d:%lf",i,b[i]);
    printf("\n");
    for(i=0;i<6;i++) printf(" c%d:%lf",i,c[i]);
    printf("\n");
    for(i=0;i<6;i++) printf(" d%d:%lf",i,d[i]);
    printf("\n");
    getchar();
    
    system("PAUSE");
    return 0;
}

void inicializaciones(double* h,double* X,double* Y,double* A){
     int i;
     for(i=0;i<N-1;i++){
         h[i]=X[i+1]-X[i];
         A[i]=(Y[i+1]-Y[i])/h[i];
         }
}

void iniB(double* B,double* A){
     int i;
     for(i=0;i<N-2;i++) B[i]=6*(A[i+1]-A[i]);
}

void iniMatriz(double** matriz,double* h){
     int i,j;
     for(i=0;i<N-2;i++){
         for(j=0;j<N-2;j++){
             matriz[i][j]=0;
             }
         }
     
     for(i=0;i<N-3;i++){
         matriz[i][i]=2*(h[i]+h[i+1]);
         matriz[i][i+1]=h[i+1];
         matriz[i+1][i]=h[i+1];
     }
     matriz[N-3][N-3]=2*(h[i]+h[i+1]);
}

void solSistema(double** A,double* B,double* v){
     int i;
     double k;
     
     for(i=1;i<M;i++){
          k = -A[i][i-1]/A[i-1][i-1];
          A[i][i] = A[i][i]+k*A[i-1][i];
          B[i] = B[i]+k*B[i-1];
          }
  
     v[M-1]=B[M-1]/A[M-1][M-1];
  
     for(i=M-2;i>=0;i--){
         v[i] = (B[i]-A[i][i+1]*v[i+1])/A[i][i];
         }
     for(i=N-2;i>0;i--) v[i]=v[i-1];
     v[0]=0;
     v[6]=0;
}
