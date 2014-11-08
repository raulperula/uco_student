#include<cat.h>
#include<dog.h>
#include<iostream>
#include<ctime>


using namespace std;
using namespace animals;
using namespace registers;


void doEat(Animal* A){
	A->eat();
}


int main(){
	time_t timenow1,timenow2,timenow3;
	time(&timenow1);
	time(&timenow2);
	time(&timenow3);
	int i;

	Animalreg reg("fichero");
	if(reg.isOpen()) cout<<"abierto"<<endl;

	Cat gato[3];
	Cat gAux;
	gato[0].setName("antoine");
	gato[0].setDateOfBirth(timenow1);
	gato[0].setHair("marron");

	gato[1].setName("hugo");
	gato[1].setDateOfBirth(timenow2);
	gato[1].setHair("gris");

	gato[2].setName("pepe");
	gato[2].setDateOfBirth(timenow3);
	gato[2].setHair("blanco");

	
	for(i=0;i<3;i++){
		reg.add(&gato[i]);
	}
	cout<<reg.getSize()<<endl;
	cout<<"ha insertado"<<endl;
	for(i=0;i<reg.getSize();i++){
		reg.read(i,&gAux);
		cout<<gAux;
	}

/*	Dog perro;
	perro.setName("snoopy");
	perro.setDateOfBirth(timenow);
	perro.setHair("marron");*/

	cout<<reg.getSize()<<endl;
	
	return 0;
}
