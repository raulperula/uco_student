/**
 * @file    fractal.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include<stdio.h>
#include<math.h>

//Prototipos de funciones
double funcion(double, double);

int
main(void)
{
    int i, j = 0;
    double b1 = 1., b2 = 4.0001; //Fin de intervalos
    double r = 2.5; //Valor inicial de r
    double x = 0.1; //Valor inicial de x
    double aux; //Variable auxiliar
    double h = 0.001; //Valor de h, representa el tamaño del intervalo
    //Se itera desde 2.5 hasta el fin de intervalo
    while(r <= b2){
        //Efectuamos 1050 iteraciones de las cuales nos quedamos las 50 ultimas
        for(i=0;i<1050;i++){
            //Almacenamos en la variable auxiliar el valor de la función
            aux = funcion(x,r);
            //Almacenamos el valor auxiliar en la variable x para que posteriormente se
            produzca la iteracion de punto fijo
            x = aux;
            if(i > 999){
                printf("%lf %lf\n", r, x); //Imprimimos los valores de los puntos
            }
        }
        r += h;
        x = 0.1;
    }

    return 0;
}

//Función
double funcion(double x, double r)
{
    return(r*x*(1-x));
}
