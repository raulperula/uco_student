/**
 * @file    vertores.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include"vectores.h"

void regVector(int nconejos,struct conejos* listacon){
  int i;
  FILE* f;
  f=fopen("conejos2006.bin","rb");
  listacon=(struct conejos*)malloc(nconejos*sizeof(struct conejos));
  for(i=0;i<nconejos;i++){
    fread(listacon[i].codigo,sizeof(listacon[i].codigo),1,f);
    fread(listacon[i].edad,sizeof(int),1,f);
    fread(listacon[i].peso,sizeof(double),1,f);
  }
}

int pesoMedio(int nconejos,struct conejos* listacon){
  int pesomed;
  int pesos=0;
  int i;
  for(i=0;i<nconejos;i++){
    pesos=pesos+listacon[i].peso;
  }
  pesomed=pesos/nconejos;
  return pesomed;
}

int pesoBueno(struct conejos conejo,int m){
  int verdadero=0;
  if(m-300<(conejo.peso)<m+300) verdadero=1;
  return verdadero;
}

int conejosBuenos(struct conejos* listacon,int nconejos, int m){
  int i;
  int cbuenos=0;
  for(i=0;i<nconejos;i++{
    if(pesoBueno(listacon[i],m)==1) cbuenos++;
  }
  return cbuenos;
}

void pasarLista(struct conejos* listacon,int nconejos, struct lista* conejos){
  int pmed;
  int i;
  struct lista* nodo;
  pmed=pesoMedio(nconejos,listacon);
  for(i=0;i<nconejos;i++){
    if((pesoBueno(listacon.[i],pmed))==1){
      nodo=nuevoElem;
      strcpy(nodo->codigo,listacon[i].codigo);
      nodo->edad=listacon[i].edad;
      nodo->peso=listacon[i].peso;
      





