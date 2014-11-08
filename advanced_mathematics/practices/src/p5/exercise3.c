/**
 * @file    exercise3.c
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

#define N 5
#define M 5

void inicializaciones(double* h,double* X,double* Y,double* A);
void iniB(double* B,double* A);
void iniMatriz(double** matriz,double* h);
void solSistema(double** A,double* B,double* v);
double spline(double x,double* X,double* a,double* b,double* c,double* d);

int main(){
    double X[N]={0,2,3,5,6.1};
    double Y[N]={2.51,4.04,4.7,5.54,5.8};
    double h[N-1];
    double A[N-1];
    double a[N-1];
    double b[N-1];
    double c[N-1];
    double d[N-1];
    double** matriz;
    double v[N];
    double B[N];
    double x;
    double estimacion;
    int i;
    
    matriz=(double**)malloc(N*sizeof(int*));
    for(i=0;i<N;i++) matriz[i]=(double*)malloc(N*sizeof(int));
    
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
    printf("dame el punto a estimar-->\n x:");
    scanf("%lf",&x);
    getchar();
    estimacion=spline(x,X,a,b,c,d);
    printf("estimacion--> %lf\n",estimacion);
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
     for(i=1;i<N-1;i++) B[i]=6*(A[i]-A[i-1]);
     B[0]=6*(A[0]-0.8);
     B[N-1]=6*(0.2-A[N-2]);
}

void iniMatriz(double** matriz,double* h){
     int i,j;
     for(i=0;i<N;i++){
         for(j=0;j<N;j++){
             matriz[i][j]=0;
             }
         }
     
     for(i=1;i<N-1;i++){
         matriz[i][i]=2*(h[i-1]+h[i]);
         matriz[i][i+1]=h[i];
         matriz[i+1][i]=h[i];
     }
     matriz[N-1][N-1]=2*h[3];
     matriz[N-1][N-2]=h[3];
     matriz[N-2][N-1]=h[3];
     matriz[0][0]=2*h[0];
     matriz[0][1]=h[0];
     matriz[1][0]=h[0];
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
}

double spline(double x,double* X,double* a,double* b,double* c,double* d){
       int opcion=-1;
       if((0<x)&&(x<2)) opcion=1;
       else if ((2<x)&&(x<3)) opcion=2;
       else if ((3<x)&&(x<5)) opcion=3;
       else if ((5<x)&&(x<6.1)) opcion=4;
       switch(opcion){
           case (1): return (a[0]*pow(x-X[0],3)+b[0]*pow(x-X[0],2)+c[0]*(x-X[0])+d[0]);
                     break;
           case (2): return (a[1]*pow(x-X[1],3)+b[1]*pow(x-X[1],2)+c[1]*(x-X[1])+d[1]);
                     break;
           case (3): return (a[2]*pow(x-X[2],3)+b[2]*pow(x-X[2],2)+c[2]*(x-X[2])+d[2]);
                     break;
           case (4): return (a[3]*pow(x-X[3],3)+b[3]*pow(x-X[3],2)+c[3]*(x-X[3])+d[3]);
                     break;
           default: break;
           }
}
