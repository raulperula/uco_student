#include<integer.h>
#include<iostream>
using namespace std;
using namespace values;


int main(int argc, char **argv){
  
  values::Integer I(8);

  cout << I.getValue()<<endl;

  values::Integer I2(I);
  cout << I2.getValue()<<endl;
  
  I.setValue(10);

  cout<<I.getValue()<<endl;

  values::Integer I3;
  I3=I2;
  cout<<I3.getValue()<<endl;

  I3=74;
  cout<<I3.getValue()<<endl;
  I3=I2=58;
  cout<<I2.getValue()<<endl;
  cout<<I3.getValue()<<endl;









}
