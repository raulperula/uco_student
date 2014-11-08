/**
 * @file    exercise3.1.c
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

double Xn(double x,double y);
double Yn(double x,double y);

int main(){
    double x=0.5,y=0.7;
    double aux;
    double error=10;
    double sx=1;
    double sy=1;
    double tol=0.001;
    printf("apartado a)\n\n");
    int i=0;
    while(error>tol){
                     i++;
                     aux=x;
                     x=Xn(x,y);
                     y=Yn(aux,y);
                     printf("x: %lf;y: %lf\n",x,y);
                     error=sqrt(pow(sx-x,2)+pow(sy-y,2));
                     }
    printf("num iter: %d\n",i);
    
    printf("\napartado b)\n\n");
    i=0;
    x=0.25;
    y=1.5;
    error=10;
    while(error>tol){
                     i++;
                     aux=x;
                     x=Xn(x,y);
                     y=Yn(aux,y);
                     error=sqrt(pow(sx-x,2)+pow(sy-y,2));
                     if(i>50){
                              printf("la solucion converge a otra sol: x= %lf; y= %lf",x,y);
                              printf("\npresione ENTER para continuar");
                              break;
                              }
                     }
    system("PAUSE");
    
    
    
    
    
}

double Xn(double x,double y){
       return((x*y-2*x)/(y-1-x));
       }
double Yn(double x,double y){
       return((-x*y+2*y-2)/(y-1-x));
       }
