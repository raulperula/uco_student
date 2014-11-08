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
#include<stdlib.h>

double f(double x);
double intCompTrap(double* X,double h,int n);


int main(){
    int n;
    int i;
    double a=2;
    double b=7;
    double* X;
    double h;
    double integral;
    printf("dame el numero de aprtes a dividir el intervalo:");
    scanf("%d",&n);
    
    X=(double*)malloc((n+1)*sizeof(double));
    h=(b-a)/n;
    
    for(i=0;i<n+1;i++) X[i]=a+h*i;
    
    integral=intCompTrap(X,h,n);
    printf("estimacion de la integral--> %lf\n",integral);
    
    system("PAUSE");
    return 0;
}

double intCompTrap(double* X,double h,int n){
       double integral=f(X[0]);
       int i;
       for(i=1;i<n;i++) integral+=2*f(X[i]);
       printf("%d\n",i);
       integral+=f(X[n]);
       return (integral*(h/2));
}

double f(double x){
       return (sqrt(1+x)/(2+sin(x)));
}
