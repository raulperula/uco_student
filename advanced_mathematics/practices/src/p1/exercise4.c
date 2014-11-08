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
double fp(double* x, int i);
//double minfp(double a, double b);

int main(){
    double x[6];/*para poder almacenar las 5 iteraciones y x0*/
    int i;
    x[0]=0.5;
    x[1]=0.9;
    double a=0;
    double b=1;
    double error;
    double s;
    double minFp=1;// f'(x) en valor absoluto tiene un minimo en x=0 cuyo valor es 1
    printf("Estimacion de una solucion por el Metodo de la Secante\n\n\n");
    printf("iteracion 0\n estimacion:%lf\n",x[0]);
    printf("iteracion 1\n estimacion:%lf\n",x[1]);
    for(i=2;i<6;i++){
                       x[i]=x[i-1]-(f(x[i-1])/fp(x,i));
                       printf("iteracion %d\n estimacion:%.15lf\n",i,x[i]);
                       s=x[i];
                       error=fabs((f(s)))/(minFp);
                       printf("error<= %.18lf\n",error);
                       }
    
     
    
    system("PAUSE");
    
    
    
    
    
}

double f(double x){
       return(cos(x)-x);
       }
double fp(double* x, int i){
       return ((f(x[i-1])-f(x[i-2]))/(x[i-1]-x[i-2]));
       }
/*double minfp(double a, double b){
       double i;
       double min=10;
       for(i=a;i<=b;i=i+0.01){
                              if((fabs((-sin(i))-i))<min) {min=(fabs(-sin(i)-i));}
                              }
       return min;  
       }
*/
