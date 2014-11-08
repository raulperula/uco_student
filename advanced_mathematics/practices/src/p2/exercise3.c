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

double gpf(double x);
double gnr(double x);
double gpnr(double x);

int main(){
   double x[6];
   double e[6];
   double d;
   double sol=1.3652230013;
   int i;
   double epf;
   double enr;
   x[0]=1;
   e[0]=fabs(sol-x[0]);
   
   printf("Iteracion de punto fijo\n\n");
   for(i=1;i<6;i++){
                    x[i]=gpf(x[i-1]);
                    d=x[i];
                    e[i]=fabs(sol-d);
                    printf("iter: %d\n sol: %lf\n error: %lf\n",i,d,e[i]);
                    }
   epf=e[5];      
   printf("Metodo de Newton-Raphson\n\n");
   for(i=1;i<6;i++){
                    x[i]=x[i-1]-(gnr(x[i-1])/gpnr(x[i-1]));
                    d=x[i];
                    e[i]=fabs(sol-d);
                    printf("iter: %d\n sol: %lf\n error: %lf\n",i,d,e[i]);
                    }
   enr=e[5];
   if(enr<epf) printf("N-R mas rapido que PF\n");
   else printf("N-R mas lento que PF");
   
   system("PAUSE");
   return 0;
   
   
}

double gpf(double x){
       return(sqrt(10-pow(x,3))*1/2);
       }
       
double gnr(double x){
       return(pow(x,3)+4*pow(x,2)-10);
       }
double gpnr(double x){
       return(3*pow(x,2)+8*x);
       }
