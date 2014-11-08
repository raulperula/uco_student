#include <vector.h>
#include <iostream>
#include <cassert>
using namespace std;
 
int main()
{
 
storage::Vector<int> v;
v.resize(10);
for(unsigned int i=0;i<v.size();i++)
v[i]=i;
 
storage::Vector<int> v2=v;
for(unsigned int i=0;i<v.size();i++)
assert(v[i]==v2[i]);
 
cout<<"Perfect"<<endl;
 
v.resize(9);
cout<<"Now, it should abort the program"<<endl;
v[9]=10;
cout<<"If you are here, then there is any problem in the code"<<endl;
}
