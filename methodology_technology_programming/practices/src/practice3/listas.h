/**
 * @file    listas.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */
 
#include<stdlib.h>

void nuevoelem(struct lista* poligono, int nlados);
void insertarLista(struct lista* poligono,struct lista ** listaTriangulos);
void borrarElemento(struct lista** listaTriangulos);
