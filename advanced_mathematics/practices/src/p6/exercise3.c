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
#include<stdlib.h>
#include<math.h>
#define N 10

double f(double t,double a,double b);
double intGauss(double x0,double x1,double a,double b);

int main(){
    double a=2;
    double b=5;
    double x0=-sqrt(1/3.);
    double x1=sqrt(1/3.);;
    double integral=0;
    double h=(b-a)/N;
    double X[N+1];
    int i;
    
    for(i=0;i<N+1;i++) X[i]=a+h*i;
    
    for(i=0;i<N;i++) integral+=intGauss(x0,x1,X[i],X[i+1]);
    
    printf("estimacion de la integral: %lf\n",integral);
    
    system("PAUSE");
}

double f(double t,double a,double b){
       double dx=(b-a)/2;
       double x=((b-a)/2)*t+(b+a)/2;
       return (sqrt(x)*log(x*x+1)*dx);       
}

double intGauss(double x0,double x1,double a,double b){
       return (f(x0,a,b)+f(x1,a,b));
}
