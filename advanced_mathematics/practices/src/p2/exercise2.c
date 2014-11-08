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

double g(double x);

int main(){
   double x[101];
   double e[100];
   double d;
   double sol=2;
   int i;
   x[0]=1.5;
   e[0]=fabs(sol-x[0]);
   for(i=1;i<61;i++){
                     x[i]=g(x[i-1]);
                     d=x[i];
                     e[i]=fabs(sol-d);
                     printf("iter: %d\nestimacion: %lf\n En/En-1= %lf\n",i,d,e[i]/e[i-1]);
                     }
   
   
   system("PAUSE");
   return 0;

}

double g(double x){
       return((pow(x,2)+6)/5);
       }
