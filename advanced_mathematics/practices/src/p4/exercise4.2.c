/**
 * @file    exercise4.2.c
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

void f1(double ** matrix);
void f2(double ** matrix);
void f3(double ** matrix);
void iniMatriz(double ** matriz);
void verMatriz(double ** matriz);
double Px(double ** matriz, double x);

int main(){
    double** matriz;
    double x=5.3;
    double sol;
    int i;
    
    matriz=(double**)malloc(4*sizeof(double*));
    for(i=0;i<5;i++) matriz[i]=(double*)malloc(5*sizeof(double));

    iniMatriz(matriz);    
    f1(matriz);
    f2(matriz);
    f3(matriz);
    
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
     for(i=0;i<4;i++){
         for(j=0;j<5;j++){
                          printf("%lf ",matriz[i][j]);
                          }
         printf("\n");
     }
}

void iniMatriz(double ** matriz){
    int i,j;
    for(i=0;i<4;i++){
                     for(j=0;j<5;j++){
                                      matriz[i][j]=0;
                                      }
                     }    
    matriz[0][0]=1;
    matriz[1][0]=3;
    matriz[2][0]=5;
    matriz[3][0]=10;
    
    matriz[0][1]=1;
    matriz[1][1]=4.09861;
    matriz[2][1]=6.60944;
    matriz[3][1]=12.3026;
} 
void f1(double ** matrix){
     int i;
     for(i=0;i<3;i++){
                      matrix[i][2]=(matrix[i+1][1]-matrix[i][1])/(matrix[i+1][0]-matrix[i][0]);
                      }
}

void f2(double ** matrix){
     int i;
     for(i=0;i<2;i++){
                      matrix[i][3]=(matrix[i+1][2]-matrix[i][2])/(matrix[i+2][0]-matrix[i][0]);
                      }
}

void f3(double ** matrix){
     matrix[0][4]=(matrix[1][3]-matrix[0][3])/(matrix[3][0]-matrix[0][0]);
}

double Px(double ** matriz, double x){
     return(matriz[0][1]+matriz[0][2]*(x-matriz[0][0])+matriz[0][3]*(x-matriz[1][0])*(x-matriz[0][0])+matriz[0][4]*(x-matriz[0][0])*(x-matriz[1][0])*(x-matriz[2][0]));
}
