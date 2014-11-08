#include <registerFileManipulator.h>
#include <employee.h>
#include <cassert>
using namespace storage;
using namespace company;
int main(int argc,char **argv)
{
    if (argc!=2){
        cout<<"Uso: file"<<endl;
        return 1;
    }
    //Crea el registro abriendolo
    RegisterFileManipulator File(argv[1]);
    //Comprueba que se ha abierto
    if(!File.isOpen()){

        cout<<"Error en la apertura del fichero"<<endl;
        return 1;
    }
    Employee Eaux;

    //Vamos a comenzar comprobando si el tipo de fichero es adecuado
    if (File.getSignature()!=-1 && File.getSignature()!=Eaux.getSignature()){
        cout<<"El fichero no es del tipo adecuado"<<endl;
        return 1;
    }


    //Creamos un vector de empleados que agregaremos al final
    Employee *E=new Employee[3];
    //Damos nombre y tal
    time_t tnow;
    time(&tnow);
    E[0].setName("antonio");
    E[0].setDateOfBirth(tnow);
    E[0].setSalary(10);
    E[0].setPosition( Employee::mantainace );

    E[1].setName("juan");
    E[1].setDateOfBirth(tnow);
    E[1].setSalary(8);
    E[1].setPosition( Employee::proffessor );

    E[2].setName("chaves");
    E[2].setDateOfBirth(tnow);
    E[2].setSalary(99999);
    E[2].setPosition( Employee::cathedratic );

    //Comprobamos el numero de elementos ahora
    int size=File.size();

    //añadimos los 3 elementos elementos
    for(int i=0;i<3;i++)
        File.add( & E[i] ) ;

    //ahora, los leemos para comprobar que todo ha sido correcto
    for(int i=0;i<3;i++){
        File.read(size+i, & Eaux ) ;
        assert( Eaux==E[i]);
    }
    //Ok, vamos a modificar un registro porque
    //nos hemos equivocado. EL suldo del 3er elemento es incorrecto
    E[2].setSalary(9999999); //ahora esta bien
    File.overWrite(size+2,&E[2]);
    //comprobamos que esta correcto
    File.read(size+2, & Eaux ) ;
    assert( Eaux==E[2]);

    //Vamos a imprimir la information escrita solo por verla
    for(unsigned int i=0;i<File.size();i++){
        File.read(i, & Eaux ) ;
        cout<<Eaux<<endl;
    }

    //Ok, todo bien
    cout<<"Perfect!!!"<<endl;
}
