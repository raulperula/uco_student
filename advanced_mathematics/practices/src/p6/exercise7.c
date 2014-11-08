/**
 * @file    exercise7.c
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

double yp(double x,double y);
double ypp(double x,double y);


int main(){
    double a=0;
    double b=1;
    double* X;
    double* Y;
    double* Yp;
    double error;
    double sol=(-1+5*exp(1/2.));
    double h;
    int n;
    int i;
    
    //apartado a)
    h=0.1;   
    n=(b-a)/h+1;
    X=(double*)malloc((n+1)*sizeof(double));
    Y=(double*)malloc((n+1)*sizeof(double));
    
    X[0]=a;
    Y[0]=4;
    for(i=1;i<n+1;i++){
        X[i]=X[i-1]+h;
        Y[i]=Y[i-1]+yp(X[i-1],Y[i-1])*h+ypp(X[i-1],Y[i-1])*pow(h,2)/2;
        }
    error=fabs(sol-Y[n]);
    printf("Para x=1 y con h=%lf:\n error:%lf\n",h,error);
    free(X);
    free(Y);
    
    //apartado b)
    h=0.01;   
    n=(b-a)/h+1;
    X=(double*)malloc((n+1)*sizeof(double));
    Y=(double*)malloc((n+1)*sizeof(double));
    
    X[0]=a;
    Y[0]=4;
    for(i=1;i<n+1;i++){
        X[i]=X[i-1]+h;
        Y[i]=Y[i-1]+yp(X[i-1],Y[i-1])*h+ypp(X[i-1],Y[i-1])*pow(h,2)/2;
        }
    error=fabs(sol-Y[n]);
    printf("Para x=1 y con h=%lf:\n error:%lf\n",h,error);
    free(X);
    free(Y);
    
    //apartado c)
    h=0.001;   
    n=(b-a)/h+1;
    X=(double*)malloc((n+1)*sizeof(double));
    Y=(double*)malloc((n+1)*sizeof(double));
    
    X[0]=a;
    Y[0]=4;
    for(i=1;i<n+1;i++){
        X[i]=X[i-1]+h;
        Y[i]=Y[i-1]+yp(X[i-1],Y[i-1])*h+ypp(X[i-1],Y[i-1])*pow(h,2)/2;
        }
    error=fabs(sol-Y[n]);
    printf("Para x=1 y con h=%lf:\n error:%lf\n",h,error);
    free(X);
    free(Y);
    
    system("PAUSE");    
}

double yp(double x,double y){
       return (x*y+x);
}

double ypp(double x,double y){
       return (y+yp(x,y)*x+1);
}
