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
#include<math.h>

double f(double x);
int main(){
    double tol=pow(10,-11);
    double a=6;
    double b=7;
    double x, y;
    double error=7;
    int i=0;
    while(error>tol){
        i++;
        x=(a+b)/2;
        error=(b-a)/2;
        y=20-x;
        printf("iteracion: %d\n x: %lf\ny: %lf\n",i,x,y);
        if((f(a)*f(x))<0) b=x;
        else a=x;
        }
    printf("\n\nsoluciones:");
    printf("\n\nx: %lf; y: %lf\n",x,y);
    system("PAUSE");
}

double f(double x){ //la ecuacion la sacamos del sistema formado por ---> x+y=20 ; (x+sqrt(x))*(y+sqrt(y))=155.55
       return((x+sqrt(x))*((20-x)+(sqrt(20-x)))-155.55);
       }
