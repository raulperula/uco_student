#include<float.h>
#include<iostream>
using namespace std;
using namespace values;


int main(int argc, char **argv){
  
  values::Float F(8);

  cout << F.getValue()<<endl;

  values::Float F2(F);
  cout << F2.getValue()<<endl;
  
  F.setValue(10);

  cout<<F.getValue()<<endl;

  values::Float F3;
  F3=F2;
  cout<<F3.getValue()<<endl;

  F3=74;
  cout<<F3.getValue()<<endl;
  F3=F2=58;
  cout<<F2.getValue()<<endl;
  cout<<F3.getValue()<<endl;
  F2=F2+F3;
  cout<<F2.getValue()<<endl;
  F2=F3*F3;
  cout<<F2.getValue()<<endl;







}
