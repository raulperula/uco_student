#include <image.h>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <imagearith.h>

using namespace std;

int
main(int argc, char **argv)
{
	/** Imagen en escala de grises */
	try{
		//Load image
		Image I(100,100); //100x100 grey
		I=30;
		I.saveToFile("i0.ppm");
		Image I2(I);
		
		//add
		ImageArith::add(I2,10);
		assert(I2(0,0)==40);
		ImageArith::add(I2,I);
		assert(I2(0,0)==70);
		
		//Strange things
		try{
			Image I3;
			ImageArith::add(I2,I3);
			assert(false);
		}catch(std::exception &ex)
		{
			cout<<"A valid exception"<<endl;
			assert(true);
		}
		
		//sub
		ImageArith::sub(I2,10);
		assert(I2(0,0)==60);
		ImageArith::sub(I2,I);
		assert(I2(0,0)==30);
		
		//Strange things
		try{
			Image I3;
			ImageArith::sub(I2,I3);
			assert(false);
		}catch(std::exception &ex)
		{
			cout<<"A valid exception"<<endl;
			assert(true);
		}
		
		//mul
		I=1;
		I2=20;
		ImageArith::mul(I2,10);
		assert(I2(0,0)==200);
		ImageArith::mul(I2,I);
		assert(I2(0,0)==200);
		
		//Strange things
		try{
			Image I3;
			ImageArith::sub(I2,I3);
			assert(false);
		}catch(std::exception &ex)
		{
			cout<<"A valid exception"<<endl;
			assert(true);
		}
		
		//div
		I=1;
		I2=20;
		ImageArith::div(I2,10);
		assert(I2(0,0)==2);
		ImageArith::div(I2,I);
		assert(I2(0,0)==2);
		
		//Strange things
		try{
			Image I3;
			ImageArith::sub(I2,I3);
			assert(false);
		}catch(std::exception &ex)
		{
			cout<<"A valid exception"<<endl;
			assert(true);
		}
		cout<<"Perfect"<<endl;
	}catch(std::exception &ex)
	{
		cout<<ex.what()<<endl;
	}
	
	/** Imagen en color */
	try{
		//Load image
		Image I10(1024,1024,1); //100x100 color
		int k = 0;
		for(int i=0;i<1024;i++){
			for(int j=i;j<1024;j++){
				I10(j,i,(k%3))=200;
			}
			if( i%100 == 0 ) k++;
		}
		k = 0;
		for(int i=0;i<1024;i++){
			for(int j=i;j<1024;j++){
				I10(i,j,(k%3))=200;
			}
			if( i%100 == 0 ) k++;
		}

		I10.saveToFile("i1.ppm");
		Image I20(I10);
		
		//add
		ImageArith::add(I20,10);
		assert(I20(0,0,0)==210);
		ImageArith::add(I20,I10);
		assert(I20(0,0,0)==255);
		
		//Strange things
		try{
			Image I30;
			ImageArith::add(I20,I30);
			assert(false);
		}catch(std::exception &ex)
		{
			cout<<"A valid exception"<<endl;
			assert(true);
		}
		
		//sub
		ImageArith::sub(I20,10);
		//assert(I20(0,0)==60);
		ImageArith::sub(I20,I10);
		//assert(I20(0,0)==30);
		
		//Strange things
		try{
			Image I30;
			ImageArith::sub(I20,I30);
			assert(false);
		}catch(std::exception &ex)
		{
			cout<<"A valid exception"<<endl;
			assert(true);
		}
		
		//mul
		I10=1;
		I20=20;
		ImageArith::mul(I20,10);
		//assert(I20(0,0)==200);
		ImageArith::mul(I20,I10);
		//assert(I20(0,0)==200);
		
		//Strange things
		try{
			Image I30;
			ImageArith::sub(I20,I30);
			assert(false);
		}catch(std::exception &ex)
		{
			cout<<"A valid exception"<<endl;
			assert(true);
		}
		
		//div
		I10=1;
		I20=20;
		ImageArith::div(I20,10);
		//assert(I20(0,0)==2);
		ImageArith::div(I20,I10);
		//assert(I20(0,0)==2);
		
		//Strange things
		try{
			Image I30;
			ImageArith::sub(I20,I30);
			assert(false);
		}catch(std::exception &ex)
		{
			cout<<"A valid exception"<<endl;
			assert(true);
		}
		cout<<"Perfect"<<endl;
	}catch(std::exception &ex)
	{
		cout<<ex.what()<<endl;
	}
}

