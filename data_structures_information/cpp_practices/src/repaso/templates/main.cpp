#include<number.h>
#include<iostream>
#include<cassert>

using namespace std;
using namespace values;

template<class Type>
void ordenar(Number<Type>* N,int n);


int main(){
	Number<int> Int(10);
	cout<<Int.getValue()<<endl;
	Int=8;
	Number<int>* vec;
	Number<float> Fl(12);
	vec=(Number<int>*)malloc(5*sizeof(Number<int>));
	cout<<Int.getValue()<<endl;
	cout<<Fl.getValue()<<endl;
	Number<int> F3;
	F3=Int+1;
	assert(Int<F3);
	vec[0]=0;
	vec[1]=3;
	vec[2]=1;
	vec[3]=4;
	vec[4]=2;
	ordenar(vec,5);
	for(int i=0;i<5;i++) cout<<vec[i].getValue()<<endl;
	cout<<"perfect"<<endl;
	return 0;
}
template<class Type>
void ordenar(Number<Type>* N,int n){
	int i;
	int j;
	Type aux;
	for(i=2;i<n;i++){
		for(j=n-1;j!=0;j--){
			if(N[j]<N[j-1]){
			aux=N[j].getValue();
			N[j]=N[j-1];
			N[j-1].setValue(aux);
			}
		}
	}
}	
