#include <image.h>
#include <linearcontrast.h>
#include <linearfunction.h>
#include <iostream>
#include <vector>

using namespace std;

int
main(int argc, char **argv)
{
	try{
		if(argc != 4){
			throw ImageException("Usage: linearfunction in.ppm out.ppm");
		}
		
		LinearFunction LF;
		LF.loadFromFile(argv[1]);
	
		Image in, out;
		in.loadFromFile(argv[2]);
	
		LinearContrast LC;
		LC.applyFunction(in, out, LF);
	
		out.saveToFile(argv[3]);
	
	}catch(std::exception &ex)
	{
		cout<<ex.what()<<endl;
	}
}
