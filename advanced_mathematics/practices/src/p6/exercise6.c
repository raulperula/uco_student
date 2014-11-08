/**
 * @file    exercise6.c
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
    double* error;
    int i;
    int n;
    
    //apartado a)
    n=(b-a)/h1+1;
    printf("n:%d\n",n);
    X=(double*)malloc((n+1)*sizeof(double));
    Y=(double*)malloc((n+1)*sizeof(double));
    sol=(double*)malloc((n+1)*sizeof(double));
    error=(double*)malloc((n+1)*sizeof(double));
    
    X[0]=a;
    Y[0]=4;
    sol[0]=freal(X[0]);
    for(i=1;i<n+1;i++){
        X[i]=X[i-1]+h1;
        Y[i]=Y[i-1]+f(X[i-1],Y[i-1])*h1;
        sol[i]=freal(X[i]);
        error[i]=fabs(sol[i]-Y[i]);
        }
    printf("Para x=1 y con h=%lf:\n error:%lf\n",h1,error[n]);
    free(X);
    free(Y);
    free(sol);
    free(error);
    
    //apartado b)
    n=(b-a)/h2+1;
    printf("n:%d\n",n);
    X=(double*)malloc((n+1)*sizeof(double));
    Y=(double*)malloc((n+1)*sizeof(double));
    sol=(double*)malloc((n+1)*sizeof(double));
    error=(double*)malloc((n+1)*sizeof(double));
    
    X[0]=a;
    Y[0]=4;
    sol[0]=freal(X[0]);
    for(i=1;i<n+1;i++){
        X[i]=X[i-1]+h2;
        Y[i]=Y[i-1]+f(X[i-1],Y[i-1])*h2;
        sol[i]=freal(X[i]);
        error[i]=fabs(sol[i]-Y[i]);
        }
    printf("Para x=1 y con h=%lf:\n error:%lf\n",h2,error[n]);
    free(X);
    free(Y);
    free(sol);
    free(error);
    
    //apartado c)
    n=(b-a)/h3+1;
    printf("n:%d\n",n);
    X=(double*)malloc((n+1)*sizeof(double));
    Y=(double*)malloc((n+1)*sizeof(double));
    sol=(double*)malloc((n+1)*sizeof(double));
    error=(double*)malloc((n+1)*sizeof(double));
    
    X[0]=a;
    Y[0]=4;
    sol[0]=freal(X[0]);
    for(i=1;i<n+1;i++){
        X[i]=X[i-1]+h3;
        Y[i]=Y[i-1]+f(X[i-1],Y[i-1])*h3;
        sol[i]=freal(X[i]);
        error[i]=fabs(sol[i]-Y[i]);
        }
    printf("Para x=1 y con h=%lf:\n error:%lf\n",h3,error[n]);
    free(X);
    free(Y);
    free(sol);
    free(error);
    
    
    //getchar();
    system("PAUSE");
}

double f(double x,double y){
       return (x*y+x);
}

double freal(double x){
       return (-1+5*exp(x*x/2));
}
