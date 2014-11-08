#include <image.h>
#include <fimage.h>
#include <imageutils.h>
#include <histogram.h>
#include <morphologicalutils.h>
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
{ OpCanny = 1, OpSobel, OpHistogram };

int __G_operation = 0;        //code with the operation to be done
float __G_t1 = 0;
float __G_t2 = 0;
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
    if(__G_operation == 0){
      throw ImageException("A valid operation must be specified");
    }
    if(__G_inFileName == "" || __G_outFileName == ""){
      throw ImageException("Inputs and outputs must be specifed");
    }

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
      case OpCanny:
		  {
		    cout << "Doing ... Canny with t1 = " << __G_t1 << " and t2 = " << __G_t2 << endl;
		    FImage fAngle, fMod; 
		    ImageUtils::canny(fInImage, fMod, fAngle, ucOutImage, __G_t1, __G_t2);
		    ucOutImage.saveToFile(__G_outFileName);
		  }
		  break;
      
      case OpSobel:
		  {
		    cout << "Doing ... Sobel" << endl;
		    FImage fSobelAngle;
		    ImageUtils::Sobel (fInImage, fOutImage, fSobelAngle);
		    ImageUtils::scale (fOutImage, ucOutImage);
		    ucOutImage.saveToFile (__G_outFileName);
		  }
		  break;
		  
      case OpHistogram:
		  {
		    cout << "Doing ... Histogram. Acc=" << __G_Histo_Acc << " Norm=" <<
		      __G_Histo_Norm << " NBins=" << __G_Histo_NBins << endl;
		    Histogram Hist;
//		    ImageUtils::ecualize(ucInImage, ucOutImage);
//		    ucOutImage.saveToFile ("new.pgm");
//		    Hist.calculate (ucOutImage, __G_Histo_NBins, __G_Histo_Norm, __G_Histo_Acc);
				/** Histograma para image */
		    Hist.calculate (ucInImage, __G_Histo_NBins, __G_Histo_Norm, __G_Histo_Acc);
				/** Histograma para fimage */
//		    Hist.calculate (fInImage, 100, __G_Histo_Norm, __G_Histo_Acc);

		    //now, save the histogram to file
		    ofstream file (__G_outFileName.c_str ());
		    assert (file.is_open ());

		    for (int i=0;i<(int)Hist.size();i++)
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
usage()
{
  string msg =
    "Final practice. Arguments:\n-h | --help : this help";
  msg +=
    "\n-i | --in : input image\n-o | --out : output";
  msg +=
    "\n Operations:\n   -c threshold1% threshold2% | --canny threshold1% threshold2% :";
  msg +=
    "\n\t Aply the Canny algorithm in a image\n";
  msg +=
    "   -s | --sobel :  sobel filter\n";
  msg +=
    "   -H | --hist : creates the histogram.\n\t\tThen, you must specify the rest of the parameters";
  msg +=
    "\n\t-a | --acc : if you want it to be accumulated \n\t-n | --norm : if you want it to be normalized\n\t";
  msg +=
    "-N | --nbins n : number of bins of the histogram, by default 256.\n";
  cout << msg << endl;
}

/////////////////////////////////////////////
//
static const char short_options[] = "hi:o:c:sHan";

static const struct option long_options[] = {
  {"help", no_argument, NULL, 'h'},
  {"in", required_argument, NULL, 'i'},
  {"out", required_argument, NULL, 'o'},
  {"canny", required_argument, NULL, 'c'},
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
    c = getopt_long(argc, argv, short_options, long_options, &index);

	  if(-1 == c){
	 		break;
	 	}

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
			case 'c':
				__G_operation = OpCanny;
				assert(argc == 8);
				__G_t1 = atof(argv[6])/100.0;
				__G_t2 = atof(argv[7])/100.0;
				assert(__G_t1 < __G_t2);
				assert((__G_t1 > 0) && (__G_t2 > 0) && (__G_t1 < 100) && (__G_t2 < 100));
				break;
			case 's':
				__G_operation = OpSobel;
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

