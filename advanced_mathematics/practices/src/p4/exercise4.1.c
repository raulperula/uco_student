/**
 * @file    exercise4.1.c
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

int main(){
    int i,j;
    int n;
    double* l;
    double* X;
    double* Y;
    double x=0.5;
    double denom=1;
    double numer=1;
    double Px=0;
    
    printf("dame el numero de puntos: ");
    scanf("%d",&n);
    
    X=(double*)malloc(n*sizeof(double));
    l=(double*)malloc(n*sizeof(double));
    Y=(double*)malloc(n*sizeof(double));
    

    for(i=0;i<n;i++){
                     printf("DAME EL PUNTO %d POR DONDE QUIERES ESTIMAR:\n",i);
                     printf("x: ");
                     scanf("%lf",&X[i]);
                     printf("y: ");
                     scanf("%lf",&Y[i]);
                     }
                     
    for(i=0;i<n;i++){
                     for(j=0;j<n;j++){
                                      if(i!=j){
                                               numer=numer*(x-X[j]);
                                               denom=denom*(X[i]-X[j]);
                                               }
                                      }
                     l[i]=numer/denom;
                     numer=1;
                     denom=1;
                     }
    for(i=0;i<n;i++){
                     Px=Px+Y[i]*l[i];
                     }
    printf("estimacion--> Px= %lf\n",Px);
    
    system("PAUSE");
    return 0;
}
