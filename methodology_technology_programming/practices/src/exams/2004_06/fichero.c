/**
 * @file    fichero.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include"fichero.h"

#include<stdio.h>

int calcularReg(){
  int tam;
  int numreg;
  FILE* f;
  f=fopen("PUBLICO","rb");
  fseek(f,0,SEEK_END);
  tam=ftell(f);
  numreg=tam/sizeof(struct lista);
  return numreg;
}

void almacenaRegistros(struct lista* reg,int numreg){
  int i;
  FILE* f;
  f=fopen("PUBLICO","rb");
  reg=(struct lista*)malloc(numreg*sizeof(struct lista));
  for(i=0;i<numreg;i++){
    fread(reg[i].nombre,sizeof(reg->nombre),1,f);
    fread(reg[i].pais,sizeof(reg->pais),1,f);
    fread(&(reg[i].anyo),sizeof(int),1,f);
  }
}

void visualizarReg(struct lista* reg,int numreg){
  int i;
  for(i=0;i<numreg;i++){
    printf("Registro %d:\nnombre: %s \npais: %s \nanyo: %d",i+1,reg[i].nombre,reg[i].pais,reg[i].anyo);
  }
}
