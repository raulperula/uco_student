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
Int1=Int2/Int3;
}
