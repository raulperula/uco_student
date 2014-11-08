#include <iostream>
#include <casa.h>

using namespace std;
using namespace values;

main()
{
   int *v;
   int nEle,i,suma;
   cout<<"Dame el numero de elementos del vector"<<endl;
   cin>>nEle;
   
   v=(int*)malloc(nEle*sizeof(int));
   
   for(i=0;i<nEle;i++)
   {
      cout<<"Introduzca el elemento "<<i<<" del vector"<<endl;
      cin>>v[i];
   }
   
   suma=sum(v,nEle);
   ordenacion(v,nEle);
   cout<<"La suma de los elementos del vector es= "<<suma<<endl;
   for(i=0;i<nEle;i++)
   {
      cout<<"Elemento del vector "<<i<<" es "<<v[i]<<endl;
   }
}
