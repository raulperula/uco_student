#include "image.h"
using namespace std;
int main(int argc,char **argv)
{
	try{
		if(argc != 3){
			cout<<"Argumentos in.ppm out.ppm"<<endl;
			exit(0);
		}
		Image Img;
		for(int i=0;i<1000;i++){
			Img.loadFromFile(argv[1]);
			cout<<i<<" ";cout.flush();
		}
		cout<<endl;
		Img.saveToFile(argv[2]); 

	}catch(std::exception &ex)
	{
	cout<<"Exception ocurred:"<<ex.what()<<endl;
	}
}
