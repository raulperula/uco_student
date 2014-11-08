/**
 * @file    exercise3.6.c
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

double fX1(double x1,double x2,double x3);
double fX2(double x1,double x2,double x3);
double fX3(double x1,double x2,double x3);


int main(){
    double A[3][3]={{4,1,1},{1,3,1},{1,1,5}};
    double X0[3]={0,0,0};
    double X[3];
    double B[3]={9,10,18};
    double error=10;
    double sol[3]={1,2,3};
    double tol=pow(10,-6);
    int i=0;
    printf("Metodo de jacobi\n");
    while(error>tol){
                     i++;
                     X[0]=fX1(X0[0],X0[1],X0[2]);
                     X[1]=fX2(X0[0],X0[1],X0[2]);
                     X[2]=fX3(X0[0],X0[1],X0[2]);
                     X0[0]=X[0];
                     X0[1]=X[1];
                     X0[2]=X[2];
                     error=sqrt(pow(sol[0]-X[0],2)+pow(sol[1]-X[1],2)+pow(sol[2]-X[2],2));
                     }
    printf("iteraciones: %d\n",i);
    printf("Metodo de Gauss-Seidel\n");
    X[0]=0;
    X[1]=0;
    X[2]=0;
    error=10;
    i=0;
    while(error>tol){
                     i++;
                     X[0]=fX1(X[0],X[1],X[2]);
                     X[1]=fX2(X[0],X[1],X[2]);
                     X[2]=fX3(X[0],X[1],X[2]);
                     error=sqrt(pow(sol[0]-X[0],2)+pow(sol[1]-X[1],2)+pow(sol[2]-X[2],2));
                     }
    printf("iteraciones: %d\n",i);
    
    printf("\napartado c)\n\n");
    i=0;
    X0[0]=-527;
    X0[1]=1000;
    X0[2]=-80000;
    error=10;
    while(error>tol){
                     i++;
                     X[0]=fX1(X0[0],X0[1],X0[2]);
                     X[1]=fX2(X0[0],X0[1],X0[2]);
                     X[2]=fX3(X0[0],X0[1],X0[2]);
                     X0[0]=X[0];
                     X0[1]=X[1];
                     X0[2]=X[2];
                     error=sqrt(pow(sol[0]-X[0],2)+pow(sol[1]-X[1],2)+pow(sol[2]-X[2],2));
                     }
    printf("iteraciones: %d\n",i);
    
    printf("\napartado d)\n\n");
    i=0;
    X[0]=-527;
    X[1]=1000;
    X[2]=-80000;
    error=10;
    while(error>tol){
                     i++;
                     X[0]=fX1(X[0],X[1],X[2]);
                     X[1]=fX2(X[0],X[1],X[2]);
                     X[2]=fX3(X[0],X[1],X[2]);
                     error=sqrt(pow(sol[0]-X[0],2)+pow(sol[1]-X[1],2)+pow(sol[2]-X[2],2));
                     }
    printf("iteraciones: %d\n",i);
    
    system("PAUSE");   
}

double fX1(double x1,double x2,double x3){
       return((9-x2-x3)/4.);
       }
       
double fX2(double x1,double x2,double x3){
       return((10-x1-x3)/3.);
       }
       
double fX3(double x1,double x2,double x3){
       return((18-x2-x1)/5.);
       }
