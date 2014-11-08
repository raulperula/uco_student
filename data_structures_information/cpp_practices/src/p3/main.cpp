#include <number.h>
#include <iostream>
#include <cassert>
using namespace std;
using namespace values;
 
int main()
{
Number<int> Int1(10);
 
Number<float> Float1=20;
Number<int> Int2=Int1;
Number<int> Int3(Int2);
 
assert( Int1==Int2 &&  Int2==Int3);
Int2=20;
Int3=Int1*Int2;
assert(Int3>=Int2);
assert(Int2<Int3);
assert(Int2<=Int3);
assert(Int2!=Int3);
assert(Int3>Int2);
Int3=Int2/Int1;
assert(Int3==2);
 
Int3=Int1*20;
assert(Int3>=Int2);
assert(Int2<Int3);
assert(Int2<=Int3);
assert(Int2!=Int3);
assert(Int3>Int2);
Int3=Int2/Int1;
assert(Int3==2);
 
Int1++;
Int1--;
assert(Int1==10);
cout<<"Perfect"<<endl;
}
