/**
 * @file    exercise5b.c
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
  double a=0;
  double b=4;
  double p;
  double c;
  double d;
  double x[4];
  int i;
  double h;
  printf("METODO 1\n\n");
  
  for(i=0;i<20;i++){
                    h=(b-a)/3;
                    c=a+h;
                    d=2*h+a;      
                    if(f(c)<f(d)) a=c;
                    else b=d;
                    }
  p=(a+b)/2;
  printf("x: %lf y: %lf\n",p,f(p));
  
  printf("METODO 2\n\n");
  
  x[0]=2;
  for(i=1;i<4;i++){
                   x[i]=x[i-1]-(fp(x[i-1])/fpp(x[i-1]));
                   p=x[i];
                   }

  printf("estimacion: x= %lf y= %lf\n",p,f(p)); 
  system("PAUSE");
  return 0;


}

double f(double x){
       return(2*sin(x)-(pow(x,2)/10));
       }

double fp(double x){
       return(2*cos(x)-x*1/5.);
       }
double fpp(double x){
       return(2*(-sin(x))-1/5.);
       }
