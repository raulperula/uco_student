/**
 * @file    functions.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
void f1(double ** matrix){
     int i;
     int j;
     int n=3;
     int inc=1;
     for(j=2;j<5;j++){
                      for(i=0;i<n;i++){
                                       matrix[i][j]=(matrix[i+1][j-1]-matrix[i][j-1])/(matrix[i+inc][0]-matrix[i][0]);
                                       }
                      n--;
                      inc++;
                      }
}

double Px(double ** matriz, double x){
     return(matriz[0][1]+matriz[0][2]*(x-matriz[0][0])+matriz[0][3]*(x-matriz[1][0])*(x-matriz[0][0])+matriz[0][4]*(x-matriz[0][0])*(x-matriz[1][0])*(x-matriz[2][0]));
}


double Px(double ** matriz, double x){
       double result=matriz[0][1];
       double mult=1;
       int i,j,n=1;
       for(i=2;i<COL;i++){
                          mult=matriz[0][i]
                          for(j=0;j<n;j++){
                                           mult=mult*(x-matriz[j][0]);
                                           }
                          result=result+mult;
                          n++;
                          }
       
       return result;
}
