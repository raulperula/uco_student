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

double g1(double x);
double g2(double x);
double g3(double x);
double g4(double x);

int main(){
   double x[101];
   double d;
   int i;
   x[0]=2;
   printf("apartado a)\n");
   for(i=1;i<100;i++){
                      x[i]=g1(x[i-1]);
                      d=x[i];
                      }
   printf("sol: %lf\n",d);
   printf("presione ENTER para continuar");
   getchar();
   system("cls");
   
   printf("apartado b)\n");
   for(i=1;i<100;i++){
                      x[i]=g2(x[i-1]);
                      d=x[i];
                      }
   printf("sol: %lf\n",d);
   printf("presione ENTER para continuar");
   getchar();
   system("cls");
   
   printf("apartado c)\n");
   for(i=1;i<100;i++){
                      x[i]=g3(x[i-1]);
                      d=x[i];
                      }
   printf("sol: %lf\n",d);
   printf("presione ENTER para continuar");
   getchar();
   system("cls");
   
   printf("apartado d)\n");
   for(i=1;i<100;i++){
                      x[i]=g4(x[i-1]);
                      d=x[i];
                      }
   printf("sol: %lf\n",d);

   system("PAUSE");
}

double g1(double x){
       return((2*pow(x,3)+1)/(3*pow(x,2)-1));
} 

double g2(double x){
       return((pow(x,3)-1));
} 

double g3(double x){
       return(sqrt((x+1)/x));
} 

double g4(double x){
       return(sqrt((pow(x,2)+1)/x));
} 
