#include <image.h>
#include <fimage.h>
#include <imageutils.h>
#include <histogram.h>
#include <iostream>
#include <getopt.h>
#include <cstdlib>
#include <string>
#include <cassert>
#include <fstream>

using namespace std;

void readArguments (int argc, char **argv);
void usage ();

//Argument parameters
//Posible operations
enum Operations
{ OpMean = 1, OpGauss, OpSobel, OpHistogram };

int __G_operation = 0;        //code with the operation to be done
int __G_maskSize = 0;
int __G_gausssigma = 0;
string __G_inFileName;
string __G_outFileName;
bool __G_Histo_Norm = false;
bool __G_Histo_Acc = false;
int __G_Histo_NBins = 256;

///////////////////////////////
//
//
///////////////////////////////
int
main (int argc, char **argv)
{
  try
  {
    //read the arguments
    if(argc == 1){                //no arguments
	    usage ();
  	  exit(EXIT_FAILURE);
    }
    readArguments(argc, argv);    //parse the arguments

    //check if the user has specified an operation
    if(__G_operation == 0)
      throw ImageException("A valid operation must be specified");
    if(__G_inFileName == "" || __G_outFileName == "")
      throw ImageException("Inputs and outputs must be specifed");

    //Read input image and convert
    Image ucInImage;
    ucInImage.loadFromFile(__G_inFileName);
    FImage fInImage;
    ImageUtils::convert(ucInImage, fInImage);
    //output image
    FImage fOutImage;
    Image ucOutImage;

    //Act according to the operation to be done
    switch(__G_operation){
      case OpMean:
		  {
		    cout << "Doing ... Mean with masksize=" << __G_maskSize << endl;
		    assert (__G_maskSize != 0);
		    ImageUtils::MeanMask (fInImage, __G_maskSize, fOutImage); //apply
		    ImageUtils::convert (fOutImage, ucOutImage);    					//convert
		    ucOutImage.saveToFile (__G_outFileName);    							//save to file
		  }
		  break;

      case OpGauss:
		  {
		    cout << "Doing ... Gauss with sigma=" << __G_gausssigma << endl;
		    assert (__G_gausssigma != 0);
		    ImageUtils::GaussianMask (fInImage, __G_gausssigma, fOutImage);	//apply
		    ImageUtils::convert (fOutImage, ucOutImage);    								//convert
		    ucOutImage.saveToFile (__G_outFileName);    								//save to file
		  }
		  break;

      case OpSobel:
		  {
		    cout << "Doing ... Sobel" << endl;
		    FImage fSobelAngle;    																//store angle
		    ImageUtils::Sobel (fInImage, fOutImage, fSobelAngle); //apply
		    ImageUtils::scale (fOutImage, ucOutImage);    				//scale
		    ucOutImage.saveToFile (__G_outFileName);    					//save to file
		  }
		  break;

      case OpHistogram:
		  {
		    cout << "Doing ... Histogram. Acc=" << __G_Histo_Acc << " Norm=" <<
		      __G_Histo_Norm << " NBins=" << __G_Histo_NBins << endl;
		    Histogram Hist;
		    ImageUtils::ecualize(ucInImage, ucOutImage);
		    ucOutImage.saveToFile ("new.pgm");
		    Hist.calculate (ucOutImage, __G_Histo_NBins, __G_Histo_Norm, __G_Histo_Acc);
//		    Hist.calculate (ucInImage, __G_Histo_NBins, __G_Histo_Norm, __G_Histo_Acc);

		    //now, save the histo to file
		    ofstream file (__G_outFileName.c_str ());
		    assert (file.is_open ());

		    for (int i = 0; i < Hist.size (); i++)
		      file << i << " " << Hist[i] << endl;

		    file.close ();
		  }
		  break;
    };
  }
  catch (std::exception & ex)
  {
    cout << "An exception occurred: " << ex.what () << endl;
    usage ();
    exit (EXIT_FAILURE);
  }
}



/////////////////////////////////////////////
//
//
/////////////////////////////////////////////
void
usage ()
{
  string msg =
    "Exercise 4. Arguments:\n-h | --help : this help\n-i | --in : input image\n";
  msg +=
    "-o | --out : output \n Operations:\n   -s | --sobel :  sobel filter\n   -m | --mean masksize :  median filter of the specified mask size";
  msg +=
    "\n   -g | --gauss sigma : gauss filter of the specified size\n   -H | --hist : creates the histogram.\n\t\tThen, you must specify the rest of the parameters";
  msg +=
    "\n\t-a | --acc : if you want it to be accumulated \n\t-n | --norm : if you want it to be normalized\n\t";
  msg +=
    "-N | --nbins n : number of bins of the histogram, by default 256.\n";
  cout << msg << endl;
}

/////////////////////////////////////////////
//
static const char short_options[] = "hi:o:m:g:sHan";

static const struct option long_options[] = {
  {"help", no_argument, NULL, 'h'},
  {"in", required_argument, NULL, 'i'},
  {"out", required_argument, NULL, 'o'},
  {"mean", required_argument, NULL, 'm'},
  {"gauss", required_argument, NULL, 'g'},
  {"sobel", no_argument, NULL, 's'},
  {"hist", no_argument, NULL, 'H'},
  {"acc", no_argument, NULL, 'a'},
  {"norm", no_argument, NULL, 'n'},
  {"nbins", required_argument, NULL, 'N'},
  {0, 0, 0, 0}
};


///////////////////////////////
//
//
///////////////////////////////
void
readArguments (int argc, char **argv)
{
  for(;;){
    int index;
    int c;
    c = getopt_long (argc, argv, short_options, long_options, &index);

	  if (-1 == c)
	 		break;

	  switch(c){
			case 0:
			  break;
			case 'i':
			  __G_inFileName = optarg;
			  break;
			case 'h':
			  usage ();
			  exit (EXIT_SUCCESS);
			  break;
			case 'o':
			  __G_outFileName = optarg;
			  break;
			case 's':
				__G_operation = OpSobel;
				break;
			case 'm':
			  __G_operation = OpMean;
			  __G_maskSize = atoi (optarg);
			  assert (__G_maskSize % 2 != 0 && __G_maskSize >= 3);    //mask value must be odd (impar)
			  break;
			case 'g':
			  __G_operation = OpGauss;
			  __G_gausssigma = atof (optarg);
			  assert (__G_gausssigma >= 1);
			  break;
			case 'H':
			  __G_operation = OpHistogram;
			  break;
			case 'a':
			  __G_Histo_Acc = true;
			  break;
			case 'n':
			  __G_Histo_Norm = true;
			  break;
			case 'N':
			  __G_Histo_NBins = atoi (optarg);
			  assert (__G_Histo_NBins >= 1);
			  break;
			default:
			  usage ();
			  exit (EXIT_FAILURE);
	  };
  }
}

