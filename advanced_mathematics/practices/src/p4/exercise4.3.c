/**
 * @file    exercise4.3.c
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


double fx(double x);
void f1(double ** matrix,int FIL,int COL);
void iniMatriz(double ** matriz,double a,double b,int npartes,int FIL, int COL);
double Px(double ** matriz, double x,int FIL,int COL);

int main(){
    double** matriz;
    double x=0.91;
    double sol;
    double a=-1;
    double b=1;
    int npartes;
    int FIL;
    int COL;
    int i;
    
    
    printf("solucion real)\n\nsol: %lf\n\n",10*fabs(x));
    printf("apartado a)\n");
    //inicializacion de las variables pertinentes del apartado
    npartes=10;
    FIL=npartes+1;
    COL=npartes+2;
    //reserva de memoria
    matriz=(double**)malloc(FIL*sizeof(double*));
    for(i=0;i<COL;i++) matriz[i]=(double*)malloc(COL*sizeof(double));
    //proceso de resolucion del ejercicio
    iniMatriz(matriz,a,b,npartes,FIL,COL);  
    f1(matriz,FIL,COL);
    sol= Px(matriz,x,FIL,COL);
    printf("\nsol: %lf\n\n",sol);
    //liberacion de la memoria
    for(i=0;i<FIL;i++) free(matriz[i]);
    free(matriz);
    
    printf("apartado b)\n");
    //inicializacion de las variables pertinentes del apartado
    npartes=20;
    FIL=npartes+1;
    COL=npartes+2;
    //reserva de memoria
    matriz=(double**)malloc(FIL*sizeof(double*));
    for(i=0;i<COL;i++) matriz[i]=(double*)malloc(COL*sizeof(double));
    //proceso de resolucion del ejercicio
    iniMatriz(matriz,a,b,npartes,FIL,COL);  
    f1(matriz,FIL,COL);
    sol= Px(matriz,x,FIL,COL);
    printf("\nsol: %lf\n\n",sol);
    //liberacion de la memoria
    for(i=0;i<FIL;i++) free(matriz[i]);
    free(matriz);
    
    
    system("PAUSE");
    return 0;
}

double fx(double x){
       return(10*fabs(x));
}

void iniMatriz(double ** matriz,double a,double b,int npartes,int FIL, int COL){
    int i,j;
    double h;
    h=(b-a)/npartes;
    for(i=0;i<FIL;i++){
                     for(j=0;j<COL;j++){
                                      matriz[i][j]=0;
                                      }
                     }    
    for(i=0;i<FIL;i++){
                       matriz[i][0]=a+h*i;
                       matriz[i][1]=fx(matriz[i][0]);
                       }
} 

void f1(double ** matrix,int FIL,int COL){
     int i;
     int j;
     int n=FIL-1;
     int inc=1;
     for(j=2;j<COL;j++){
       for(i=0;i<n;i++){
       matrix[i][j]=(matrix[i+1][j-1]-matrix[i][j-1])/(matrix[i+inc][0]-matrix[i][0]);
       }
     n--;
     inc++;
     }
}

double Px(double ** matriz, double x,int FIl,int COL){
       double result=matriz[0][1];
       double mult=1;
       int i,j,n=1;
       for(i=2;i<COL;i++){
                          mult=matriz[0][i];
                          for(j=0;j<n;j++){
                                           mult=mult*(x-matriz[j][0]);
                                           }
                          result=result+mult;
                          n++;
                          }
       
       return result;
}
