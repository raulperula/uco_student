/**
 * @file    accione.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
int comptablero(int * tablero){
  int econtrada=0;
  int igual=1;
  int i;
  int aux[9];
  FILE* f;
  f=fopen("memoria","rb");
  fseek(f,0,SEEK_SET);
  while((f!=NULL)&& (encontrada==0)){
    fread(aux,sizeof(int),9,f); //lectura de la posicion actual del tablero
    while((i<9)&&(igual=1){
      if(aux[i]=tablero[i]) {
          igual=1;
          i++;
      }
      else(igual=0);
    }
    if(igual=1) encontrada=1;
  }
  fclose(f);
  return encontrada;
}

int hacerjugada(int* jugada){
  int proxmov;
  int igual=1;
  int encontrado=0
  int i=0;
  int indice;
  struct jugada aux;
  FILE* f;
  f=fopen("memoria","a+b");
  fseek(f,0,SEEK_SET);
  while((f!=NULL)&&(encontrado=0)){
    fread(aux.tablero,sizeof(int),9,f); //lectura de la posicion actual del tablero
    fread(aux.sigjug,sizeof(int),100,f); //lectura de las probabilidades de la siguiente jugada
    while((i<9)&&(igual=1){
      if(aux.tablero[i]=jugada[i]) {
          igual=1;
          i++;
      }
      else(igual=0);
    }
    if (igual=1){
      indice=rand()%100;
      proxmov=aux.sigjug[indice];
      encontrado=1;
    }
  }
  fclose(f);
  if(econtrado=0){
    storegame(jugada);
    proxmov=jugadaAzar(jugada);
  }
  
  return proxmov;
}

void storegame(int* jugada){
  FILE* f;
  struct jugada aux;
  int i;
  int j;
  int resto;
  int prob;
  int pos=0;
  int opciones[9];
  for(i=0;i<9;i++){
    aux.tablero[i]=jugada[i];
  }
  for(i=0;i<9;i++){
    opciones[i]=0;
  }
  for(i=0;i<9;i++){
    if(aux.tablero[i]!=0){
      opciones[pos]=i;
      pos++;
    }
  }
  prob=100/pos;
  for(i=0;i<pos;i++){
    for(j=0;j<prob;j++){
      aux.sigjud[j]=opciones[i];
    }
  }
  if((100%pos)!=0){
    resto=100-(pos*prob);
    for(i=99;i>=100-resto;i--){
      aux.sigjug[i]=opciones[1];
    }
  }
  f=fopen("memoria","ab");
  fwrite(aux.tablero,sizeof(int)9,f);
  fwrite(aux.sigjug,sizeof(int),100,f);
  fclose(f);
}
