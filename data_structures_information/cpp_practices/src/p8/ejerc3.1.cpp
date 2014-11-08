#include <iostream>
#include <fstream>
#include <list>
#include <numeric>

using namespace std;

main(){
	ifstream file("file.dat");
	list<float> lista;
	list<float>::iterator it1;
	list<float>::iterator it2;
	float suma=0;
	float num;
	
	while(!file.eof()){
		file>>num;
		if(!file.eof()){
			lista.push_front(num);
		}
		else cout<<"\nfin del fichero\n"<<endl;
	}
	
	lista.sort();

	for(it2=lista.begin();it2!=lista.end();it2++){
		cout<<(*it2)<<endl;
	}
	
	suma=accumulate(it1=lista.begin(),it2=lista.end(),suma);	
	cout<< "suma de todos los elementos de la lista:"<<suma<<endl;

}
