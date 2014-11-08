#include <matrix.h>
#include <iostream>
using namespace std;
using namespace storage;

//Function that prints a matrix

template<class Type>
void print(matrix<Type> &M)
{
for(unsigned int i=0;i<M.getFils();i++){
for(unsigned int j=0;j<M.getCols();j++)
cout<<M.get(i,j)<< " ";
cout<<endl;
}
}

int main(int argc,char argv)
{
matrix<float> M;
M.resize(10,10);
M.setIdentity();
print(M);
matrix<float> M2(M);
print(M2);
matrix<float> M3(10,10);
M3=M+M2;
print(M3);
//check the result
for(unsigned int i=0;i<M3.getFils();i++){
for(unsigned int j=0;j<M.getCols();j++)
if (i!=j)
assert(M3.get(i,j)==0);
else assert(M3.get(i,j)==2);
}
cout<<"Perfect"<<endl;
}
