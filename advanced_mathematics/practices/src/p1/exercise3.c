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
#include<math.h>

double f(double x);
double fp(double x);

int main(){
    double x[101];/*para poder almacenar las 100 iteraciones y x0*/
    int i;
    x[0]=3;
    double a=2;
    double b=3;
    double error;
    double s;
    double minFp;
    printf("****************************************************************\n");
    printf("*  Estimacion de una solucion por el metodo de Newton-Raphson  *\n");
    printf("****************************************************************\n");
    for(i=1;i<=100;i++){
                       x[i]=x[i-1]-(f(x[i-1])/fp(x[i-1]));
                       printf("iteracion %d\n estimacion:%.15lf\n",i,x[i]);
                       s=x[i];
                       }
    minFp=fp(a);/* es a ya que la funcion Fp es creciente en todo el intervalo [a,b], 
               por lo que el menor valor de la funcion estara en a */
    
    error=(f(s))/minFp;
    printf("error= %.18lf\n",error);
     
    
    system("PAUSE");
    
    
    
    
    
}

double f(double x){
       return(pow(x,3)-6*x+2);
       }
double fp(double x){
       return(3*pow(x,2)-6);
       }
