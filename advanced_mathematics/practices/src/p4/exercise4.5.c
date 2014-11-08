/**
 * @file    exercise4.5.c
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

double fn(int grado,double x);
double factorial(double x);
double P(int grado, double x);


int main(){
    double x=1;
    double f;
    double sol;
    double error;
    int grado=10;
    
    f=P(grado,x);
    printf("estimacion---> P: %lf\n",f);

    sol=exp(x/2.);
    error=fabs(sol-f);
    printf("error---> error: %.15lf\n",error);
    
    system("PAUSE");
    return 0;
}


double fn(int grado,double x){
       return(pow(1/2.,grado)*exp(x/2.));
}

double P(int grado, double x){
       double P=0;
       int i;
       for(i=0;i<=grado;i++){
                             P+=((fn(i,0))*pow(x,i))/factorial(i);
                             }
       return P;
}

double factorial(double x){
       int i;
       double fact=1;
       for(i=2;i<=x;i++){
                         fact*=i;
                         }
       return fact;
}
