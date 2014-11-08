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
#include<stdlib.h>
#include<math.h>
#define N 20

double f(double x,double y);
double freal(double x);

int main(){
    double a=0;
    double b=2;
    double h=0.1;
    double X[N+1];
    double Y[N+1];
    double sol[N+1];
    double error[N+1];
    int i;
    
    X[0]=a;
    Y[0]=3;
    sol[0]=freal(X[0]);
    for(i=1;i<N+1;i++){
        X[i]=X[i-1]+h;
        Y[i]=Y[i-1]+f(X[i-1],Y[i-1])*h;
        sol[i]=freal(X[i]);
        error[i]=fabs(sol[i]-Y[i]);
        }
    printf("Para x=2:\n estimacion:%.8lf\n solucion real:%lf\n error:%lf\n", Y[N],sol[N],error[N]);
    
    system("PAUSE");
}

double f(double x,double y){
       return (2*x+y);
}

double freal(double x){
       return (-2+5*exp(2)-2*x);
}
