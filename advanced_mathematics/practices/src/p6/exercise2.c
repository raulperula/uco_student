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
#include<stdlib.h>
#include<math.h>

double f(double x);
double intCompSimp(double* X,double h,int n);

int main(){
    int i,j;
    int n[5]={10,20,40,80,160};
    double h[5];
    double a=1;
    double b=6;
    double** X;
    double s=8.18347920766278;
    double error[5];
    double ediv[5];
    double integral[5];
   
    X=(double**)malloc(5*sizeof(double*));
    for(i=0;i<5;i++) X[i]=(double*)malloc((n[i]+1)*sizeof(double));
    
    for(i=0;i<5;i++) h[i]=(b-a)/n[i];
    for(i=0;i<5;i++){
        for(j=0;j<n[i]+1;j++) X[i][j]=a+h[i]*j;
        }
    
    for(i=0;i<5;i++) integral[i]=intCompSimp(X[i],h[i],n[i]);
    for(i=0;i<5;i++) error[i]=fabs(s-integral[i]);
    
    ediv[0]=0;
    for(i=1;i<5;i++) ediv[i]=error[i]/error[i-1];
    
    printf("n\terror\t\tediv\n");
    for(i=0;i<5;i++) printf("%d\t%.10lf\t%.10lf\n",n[i],error[i],ediv[i]);
    
    system("PAUSE");
}


double f(double x){
       return (2+sin(2*sqrt(x)));
}

double intCompSimp(double* X,double h,int n){
       double integral=f(X[0]);
       int i;
       for(i=1;i<n;i++){
           if((i%2)==0) integral+=2*f(X[i]);
           else(integral+=4*f(X[i]));
           }
       integral+=f(X[n]);
       return (integral*(h/3));
}
