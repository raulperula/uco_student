/**
 * @file    exercise4.c
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
double fpp(double x);

int main(){
    double x[9];
    int i;
    x[0]=0;
    if((f(1)==0)&&(fp(1)==0)&&(fpp(1)!=0)) printf("\ntiene raiz doble en x=1\n");
    
    printf("\nMetodo de N-R sin modificar\n");
    for(i=1;i<9;i++){
                     x[i]=x[i-1]-(f(x[i-1])/fp(x[i-1]));
                     printf("iteracion: %d\n estimacion: %lf\n",i,x[i]);
                     }
    
    printf("\nMetodo de N-R modificado\n");
    for(i=1;i<9;i++){
                     x[i]=x[i-1]-2*(f(x[i-1])/fp(x[i-1]));
                     printf("iteracion: %d\n estimacion: %lf\n",i,x[i]);
                     }
    
    system("PAUSE");
    return 0;
}

double f(double x){
       return(pow(x,3)-5*pow(x,2)+7*x-3);
       }

double fp(double x){
       return(3*pow(x,2)-10*x+7);
       }
double fpp(double x){
       return(6*x-10*x+7);
       }
