/**
 * @file    exercise7.c
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

#define N 100
#define PI 3.14192654

double f(double x);
double g(double x);
double intCompSimp(double* X,double h,int c);


int main(){
    int i;
    double a=0;
    double b=1;
    double* X;
    double h;
    double longitud;
    double area;
    
    X=(double*)malloc((N+1)*sizeof(double));
    h=(b-a)/N;
    
    for(i=0;i<N+1;i++) X[i]=a+h*i;
    
    longitud=intCompSimp(X,h,1);
    printf("longitud--> %lf\n",longitud);
    
    area=2*PI*intCompSimp(X,h,2);
    printf("area--> %lf\n",area);
    
    system("PAUSE");
    return 0;
}

double intCompSimp(double* X,double h,int c){
       double integral=f(X[0]);
       int i;
       while(c==1){
       for(i=1;i<N;i++){
           if((i%2)==0) integral+=2*f(X[i]);
           else(integral+=4*f(X[i]));
           }
       integral+=f(X[N]);
       return (integral*(h/3));
       }
       while(c==2){
       for(i=1;i<N;i++){
           if((i%2)==0) integral+=2*g(X[i]);
           else(integral+=4*g(X[i]));
           }
       integral+=f(X[N]);
       return (integral*(h/3));
       }
}

double f(double x){
       return (sqrt(1+exp(-x)*exp(-x)));
}

double g(double x){
       return (exp(-x)*(sqrt(1+exp(-x)*exp(-x))));
}
