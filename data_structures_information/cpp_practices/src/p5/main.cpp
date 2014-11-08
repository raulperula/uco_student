#include <contactlist.h>
using namespace contacts;
int main(int argc,char **argv)
{
    ContactList CL;
    CL.add(Contact("pepe",12398));
    Contact C1("maria",9312);
    Contact C2("pablo",99999);
    CL.add(C1);
    CL.add(Contact("juan",212398));
    CL.add(Contact("carmen",2398));
    CL.add(Contact("pedro",2398));
    cout<<"N contacts="<<CL.size()<<endl;
    CL.print();
    CL.add(Contact("jose",12398));
    cout<<endl;
    cout<<"N contacts="<<CL.size()<<endl;
    CL.print();
    CL.delete_contact(C1);
    cout<<"N contacts="<<CL.size()<<endl;
    CL.print();
}
