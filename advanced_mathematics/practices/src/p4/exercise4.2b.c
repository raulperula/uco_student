/**
 * @file    exercise4.2b.c
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

#define FIL 4
#define COL 5

void f1(double ** matrix);
void iniMatriz(double ** matriz);
void verMatriz(double ** matriz);
double Px(double ** matriz, double x);

int main(){
    double** matriz;
    double x=5.3;
    double sol;
    int i;
    
    matriz=(double**)malloc(FIL*sizeof(double*));
    for(i=0;i<COL;i++) matriz[i]=(double*)malloc(COL*sizeof(double));

    iniMatriz(matriz);    
    f1(matriz);

    
    printf("MATRIZ\n\n");
    verMatriz(matriz);
    
    sol= Px(matriz,x);
    printf("\nsol: %lf\n\n",sol);
    
    system("PAUSE");
    return 0;
}

void verMatriz(double ** matriz){
     int i;
     int j;
     for(i=0;i<FIL;i++){
         for(j=0;j<COL;j++){
                          printf("%lf ",matriz[i][j]);
                          }
         printf("\n");
     }
}

void iniMatriz(double ** matriz){
    int i,j;
    for(i=0;i<FIL;i++){
                     for(j=0;j<COL;j++){
                                      matriz[i][j]=0;
                                      }
                     }    
    matriz[0][0]=1;
    matriz[1][0]=3;
    matriz[2][0]=5;
    
