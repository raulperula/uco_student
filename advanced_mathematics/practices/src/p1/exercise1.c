/**
 * @file    exercise1.c
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

double f(double x);
int main(){
    double tol=pow(10,-11);
    double a=2;
    double b=3;
    double x;
    double error=7;
    int i=0;
    while(error>tol){
        i++;
        x=(a+b)/2;
        error=(b-a)/2;
        printf("iteracion: %d\n sol: %lf\n error: %lf\n",i,x,error);
        if((f(a)*f(x))<0) b=x;
        else a=x;
        }
        
    printf("el numero de iteraciones es %d y la sol: %lf",i,x);
    system("PAUSE");
}

double f(double x){
   return(x*sin(x)-1);
}
