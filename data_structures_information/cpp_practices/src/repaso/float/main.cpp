#include <iostream>
#include <float.h>

using namespace std;
using namespace values;


int main(int argc,char** argv){
	Float F1,F3,F4;
	cout<<F1.getValue()<<endl;
	F1.setValue(10);
	Float F2(8);
	cout<<F2.getValue()<<endl;
	F4=F1*F2;
	F3=F1+F2+F1;
	cout<<F3.getValue()<<endl;
	cout<<F4.getValue()<<endl;
	if(F1<F2) cout<<"true"<<endl;
	else cout<<"false"<<endl;
}
