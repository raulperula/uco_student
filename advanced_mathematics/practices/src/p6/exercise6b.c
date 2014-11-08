/**
 * @file    exercise6b.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x,double y);
double freal(double x);

int main(){
    double a=0;
    double b=1;
    double h1=0.1;
    double h2=0.01;
    double h3=0.001;
    double* X;
    double* Y;
    double* sol;
    double j;
    int i;
    int n;
    
    //Obtencion de puntos del apartado a)
    n=(b-a)/h1+1;
    X=(double*)malloc((n+1)*sizeof(double));
    Y=(double*)malloc((n+1)*sizeof(double));
    
    X[0]=a;
    Y[0]=4;
    printf("%lf %lf\n",X[0],Y[0]);
    for(i=1;i<n+1;i++){
        X[i]=X[i-1]+h1;
        Y[i]=Y[i-1]+f(X[i-1],Y[i-1])*h1;
        printf("%lf %lf\n",X[i],Y[i]);
        }
    printf("\n\n");    
    free(X);
    free(Y);
    
    //Obtencion de puntos del apartado b)
    n=(b-a)/h2+1;
    X=(double*)malloc((n+1)*sizeof(double));
    Y=(double*)malloc((n+1)*sizeof(double));
    
    X[0]=a;
    Y[0]=4;
    printf("%lf %lf\n",X[0],Y[0]);
    for(i=1;i<n+1;i++){
        X[i]=X[i-1]+h2;
        Y[i]=Y[i-1]+f(X[i-1],Y[i-1])*h2;
        printf("%lf %lf\n",X[i],Y[i]);
        }
  
    printf("\n\n");
    free(X);
    free(Y);
    
    //Obtencion de puntos reales
    n=(b-a)/0.01+1;
    sol=(double*)malloc((n+1)*sizeof(double));
    X=(double*)malloc((n+1)*sizeof(double));
    for(i=a;i<n+1;i++){
        X[i]=a+i*0.01;
        printf("%lf %lf\n",X[i],freal(X[i]));
        }
    
}

double f(double x,double y){
       return (x*y+x);
}

double freal(double x){
       return (-1+5*exp(x*x/2));
}
