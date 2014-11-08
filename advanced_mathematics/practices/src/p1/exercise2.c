/**
 * @file    exercise2.c
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
double calculaC(double a,double b);
int system();

int main(){
    double tol=pow(10,-7);
    double a=2;
    double b=3;
    double x;
    double s=2.41679918;
    double error=7;
    int i=0;
    printf("METODO REGULA FALSI\n");
    system("PAUSE");
    while(error>tol){
        i++;
        x=calculaC(a,b);
        error=fabs(x-s);
        printf("iteracion: %d\n sol: %lf\n error: %lf\n",i,x,error);
        if((f(a)*f(x))<0) b=x;
        else a=x;
        }
        
    printf("el numero de iteraciones es %d y la sol: %lf\n",i,x);
    system("PAUSE");
    system("cls");
    printf("METODO DE LA BISECCION\n");
    system("PAUSE");
    error=8;
    a=2;
    b=3;
    i=0;
    while(error>tol){
        i++;
        x=(a+b)/2;
        error=fabs(x-s);
        printf("iteracion: %d\n sol: %.10lf\n error: %.10lf\n",i,x,error);
        if((f(a)*f(x))<0) b=x;
        else a=x;
        }
        
    printf("el numero de iteraciones es %d y la sol: %lf",i,x);
    system("PAUSE");
}

double f(double x){
       return(pow(x,4)-pow(x,3)-20);
       }
       
double calculaC(double a,double b){
       return(a-((f(a)*(b-a))/(f(b)-f(a))));
       }
