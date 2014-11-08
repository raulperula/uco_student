/**
 * @file    imagen.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include"imagen.h"
#include<stdio.h>

imagen leerImagen(char* n){
  FILE* f;
  int i;
  int j;
  imagen image;
  if((f=fopen(n,"rb"))==NULL) printf("error al leer fichero");
  fgets(image.numeromag,3,f);
  if(image.numeromag[strlen(image.numeromag)-1]=='\n') 
    image.numeromag[strlen(image.numeromag)-1]='\0';
  fscanf(f,"%d%d",&image.col,&image.fil);
  fscanf(f,"%d",&image.n_max);
  fgetc(f);
  image.matriz=(unsigned char **)malloc(image.fil*sizeof(unsigned char *));
  for(i=0;i<image.fil;i++){
    image.matriz[i]=(unsigned char *)malloc(image.col*sizeof(unsigned char));
  }

  for(i=0;i<image.fil;i++){
    for(j=0;j<image.col;j++){
	fread(&(image.matriz[i][j]),sizeof(unsigned char),1,f);
	}
  }
  fclose(f);
  return (image);

}

void escribirImagen(char* n2,imagen aux){
  int i;
  int j;
  FILE* f;
  if((f=fopen(n2,"wb"))==NULL){
    printf("error al leer archivo");
  }
  fprintf(f,"%s\n%d %d\n %d\n",aux.numeromag,aux.col,aux.fil,aux.n_max);
  for(i=0;i<aux.fil;i++){
    for(j=0;j<aux.col;j++){
      fwrite(&(aux.matriz[i][j]),sizeof(unsigned char),1,f);
    }
  }
  fclose(f);
}

void leerMensaje(char* nomb,imagen im){
  FILE* g;
  unsigned char* lsb;
  int i=0,j=0,pos=0;
  
  g=fopen("texto","wb");
    
  lsb=(unsigned char*)malloc(im.fil*im.col*sizeof(unsigned char));
  
  
  for(i=0;i<im.fil;i++)
  {
  
    for(j=0;j<im.col;j++)
    {
      if((im.matriz[i][j]%2)==0)
            {lsb[pos]=0;}
      else
      {lsb[pos]=1;}
      pos++;
    }
  }
  
  for(i=0;i<im.fil*im.col;i=i+8){
    fprintf(g,"%c",binToDec(lsb,i));
  }
  printf("\nMensaje Descifrado\n");
  
  fclose(g);
}

unsigned char binToDec(unsigned char* lsb,int ini){

  unsigned char caracter;
  
  caracter=(lsb[ini]*pow(2,7)+lsb[ini+1]*pow(2,6)+lsb[ini+2]*pow(2,5)+lsb[ini+3]*pow(2,4)+lsb[ini+4]*pow(2,3)+lsb[ini+5]*pow(2,2)+lsb[ini+6]*pow(2,1)+lsb[ini+7]*pow(2,0));
  return caracter;
}

unsigned char cargarMensaje(char* nomb,int fil, int col){
  FILE F*;
  unsigned char* cadbits;
  char letra;
  unsigned char letrabin[8];
  int i,j,pos=0;
  cadbits=(unsigned char*)malloc(fil*col*sizeof(unsigned char);
  f=fopen(nomb,"rb");
   
  for(i=0;(letra=fgetc(f))!=EOF;i++){
    DectoBin(letrabin,letra);
    cadbits[i]=letrabin[pos];
    pos++;
    if(pos==8) pos=0;
    j++;
  }
  for(i=0,i<4;i++){
    cadbits[j+i]=*;
  }
  return cadbits;
}


void DectoBin(unsigned char* letrabin, unsigned char letra){
  int i,aux;

  aux=letra;
  
  for(i=7;i>=0;i--)
  {
   letrabin[i]=aux%2;
   aux=aux/2;
  }
   
}

void ocultarMensaje(imagen im,unsigned char* cad,){
  int i,j, pos=0;
  
  
  for(i=0;i<im.fil;i++){
    for(j=0,j<im.col;j++){
      if(cad[i]==0){
      	if((im.matriz[i][j]%2)==1) im.matriz[i][j]=im.matriz[i][j]-1;
	}
      else{ if((im.matriz[i][j]%2)==0) im.matriz[i][j]=im.matriz[i][j]+1;}
      pos++;
    }
  } 
}
