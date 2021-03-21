// implement your program here

#include <iostream>
#include <fstream>
#include <string>
using std::cout; 
using std::endl;
using std::string;

#include "region_grower.hpp"
#include "image.h"

int main( int argc, char* argv[] )
{
	if(argc != 8)
	{
		//cout <<"Usage: fillregion"
		//<< "<executible> <input_filename> <seed location x> <seed location y> <new red color> <new green color> <new blue color> <output_filename>"
		//<< endl;
		cout<<"Error: Not acceptable argumnets" << endl;
		return EXIT_FAILURE;
	}
	
	else
	{	
		string imgfile = argv[1];
		string outfile = argv[7];
		
		RegionGrower r;
		
		if(r.SetImage(imgfile) == false )
		{
			//cout <<"Error: the input image file cannot be opened " <<endl;
			return EXIT_FAILURE;
		}
		
		unsigned int xtest = std::atoi(argv[2]);
		unsigned int ytest = std::atoi(argv[3]);
		unsigned int redtest = std::atoi(argv[4]);
		unsigned int greentest = std::atoi(argv[5]);
		unsigned int bluetest = std::atoi(argv[6]);
		
		
		if(!(xtest = std::atoi(argv[2])) && xtest < 0)
		{
			cout<<"Error: invalid seed argument"<<endl;
			return EXIT_FAILURE;
		}
		
		if(!(ytest = std::atoi(argv[3])) && ytest < 0)
		{
			cout<<"Error: invalid seed argument"<<endl;
			return EXIT_FAILURE;
		}
		
		if(!(redtest = std::atoi(argv[4])))
		{
			cout<<"Error: invalid color argument"<<endl;
			return EXIT_FAILURE;
		}
		
		if(!(greentest = std::atoi(argv[5])))
		{
			cout<<"Error: invalid color argument"<<endl;
			return EXIT_FAILURE;
		}
		
		if(!(bluetest = std::atoi(argv[6])))
		{
			cout<<"Error: invalid color argument"<<endl;
			return EXIT_FAILURE;
		}
		
		unsigned int red = std::stoi(argv[4]);
		unsigned int green = std::stoi(argv[5]);
		unsigned int blue = std::stoi(argv[6]);
		unsigned int x = std::stoi(argv[2]);
		unsigned int y = std::stoi(argv[3]);
		
		if(r.SetSeed(x,y) == false)
		{
			//cout <<"Error: the seed is at an invalid position"<<endl;
			return EXIT_FAILURE;
		}
		
		if(r.SetReplacement(red, green, blue) == false)
		{
			//cout <<"Error: the replacement color is invalid"<<endl;
			return EXIT_FAILURE;
		}
		
		r.Update();
		
		if(r.GetOutput(outfile) == false)
			return EXIT_FAILURE;
		
		else
			return EXIT_SUCCESS;
		
	  return 0;
	}
}
