/**
 * @file    exercise4.4.c
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
    double a=-1;
    double b=1;
    double sol;
    int npartes;
    int FIL;
    int COL;
    int j;
    double i;
    
    
    //inicializacion de las variables pertinentes
    npartes=10;
    FIL=npartes+1;
    COL=npartes+2;
    //reserva de memoria
    matriz=(double**)malloc(FIL*sizeof(double*));
    for(j=0;j<COL;j++) matriz[j]=(double*)malloc(COL*sizeof(double));
    
    //imprime punto e imagen de los puntos interpoladores
    iniMatriz(matriz,a,b,npartes,FIL,COL);
    printf("\n\n");
    
    //imprime x y f(x) de la funcion f(x)=10*fabs(x) en el intervalo [a,b]
    for(i=a;i<b+0.01;i+=0.01) printf("%lf %lf \n",i,(10*fabs(i)));
    printf("\n\n");
    
    //imprime x y P(x)
    f1(matriz,FIL,COL);
    for(i=a;i<b+0.01;i+=0.01){
                          sol= Px(matriz,i,FIL,COL);
                          printf("%lf %lf \n",i,sol);
                          }
    //liberacion de la memoria
    for(j=0;j<FIL;j++) free(matriz[j]);
    free(matriz);
    
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
                       printf("%lf %lf \n",matriz[i][0],matriz[i][1]);
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
