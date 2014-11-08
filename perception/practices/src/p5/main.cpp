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
{ OpT = 1, OpDilate, OpErode, OpClose, OpOpening, OpContour };

int __G_operation = 0;        //code with the operation to be done
int __G_size = 0;
string __G_inFileName;
string __G_outFileName;
bool __G_Invert = false;

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
      case OpT:
		  {
		    cout << "Doing ... Threshold with value=" << __G_size << endl;
		    assert(__G_size != 0);
		    ImageUtils::fixedThreshold(ucInImage, ucOutImage, __G_size);
		    ucOutImage.saveToFile(__G_outFileName);
		  }
		  break;

      case OpDilate:
		  {
		    cout << "Doing ... Dilate with mSize=" << __G_size << endl;
		    MorphologicalUtils::dilate(ucInImage, ucOutImage, __G_size);
		    ucOutImage.saveToFile(__G_outFileName);
		  }
		  break;

      case OpErode:
		  {
		    cout << "Doing ... Erode with mSize=" << __G_size << endl;
		    MorphologicalUtils::erode(ucInImage, ucOutImage, __G_size);
		    ucOutImage.saveToFile(__G_outFileName);
		  }
		  break;

      case OpClose:
		  {
		    cout << "Doing ... Close with mSize=" << __G_size << endl;
		    MorphologicalUtils::open(ucInImage, ucOutImage, __G_size);
		    ucOutImage.saveToFile(__G_outFileName);
		  }
		  break;
		  
      case OpOpening:
		  {
		    cout << "Doing ... Opening with mSize=" << __G_size << endl;
		    MorphologicalUtils::close(ucInImage, ucOutImage, __G_size);
		    ucOutImage.saveToFile(__G_outFileName);
		  }
		  break;
		  
		  case OpContour:
		  {
		    cout << "Doing ... Contour" << endl;
		    MorphologicalUtils::outerContour(ucInImage, ucOutImage);
		    ucOutImage.saveToFile(__G_outFileName);
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
    "Exercise 5. Arguments:\n-h | --help : this help";
  msg +=
    "\n-i | --in : input image\n-o | --out : output";
  msg +=
    "\n Operations:\n   -t value : threshold the input image with the threshold indicated";
//  msg +=
//  	"\n\t-I | --invert : if you want it to be inverted";
  msg +=
    "\n   -D | --dilate mSize : dilates the image using a mSizexmSize mask";
  msg +=
    "\n   -E | --erode mSize : erodes the image using a mSizexmSize mask";
  msg +=
    "\n   -C | --close mSize : closes the image using a mSizexmSize mask";
  msg +=
    "\n   -O | --opening mSize : opens the image using a mSizexmSize mask";
  msg +=
    "\n   -c | --contour : extracs the outer contour of an image";
  cout << msg << endl;
}

/////////////////////////////////////////////
//
static const char short_options[] = "hi:o:t:D:E:C:O:c";

static const struct option long_options[] = {
  {"help", no_argument, NULL, 'h'},
  {"in", required_argument, NULL, 'i'},
  {"out", required_argument, NULL, 'o'},
  {"t", required_argument, NULL, 't'},
  {"dilate", required_argument, NULL, 'D'},
  {"erode", required_argument, NULL, 'E'},
  {"close", required_argument, NULL, 'C'},
  {"opening", required_argument, NULL, 'O'},
  {"contour", no_argument, NULL, 'c'},
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
			case 't':
				__G_operation = OpT;
				__G_size = atoi(optarg);
				assert(__G_size >= 0 && __G_size <= 255);
				break;
//			case 'I':
//				__G_Invert = true;
//				break;
			case 'D':
			  __G_operation = OpDilate;
			  __G_size = atoi(optarg);
			  assert (__G_size%2 != 0 && __G_size >= 3);
			  break;
			case 'E':
			  __G_operation = OpErode;
			  __G_size = atoi(optarg);
			  assert (__G_size%2 != 0 && __G_size >= 3);
			  break;
			case 'C':
			  __G_operation = OpClose;
			  __G_size = atoi(optarg);
			  assert (__G_size%2 != 0 && __G_size >= 3);
			  break;
			case 'O':
			  __G_operation = OpOpening;
			  __G_size = atoi(optarg);
			  assert (__G_size%2 != 0 && __G_size >= 3);
			  break;
			case 'c':
			  __G_operation = OpContour;
			  break;
			default:
			  usage ();
			  exit (EXIT_FAILURE);
	  };
  }
}

