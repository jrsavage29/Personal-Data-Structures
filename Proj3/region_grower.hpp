// define your class here
#ifndef _REGION_GROWER_HPP_
#define _REGION_GROWER_HPP_

#include "Stack.hpp"
#include "image.h"
#include <iostream>

class RegionGrower
{
private:

Pixel colors;
	
unsigned int xcoor; //store the x coordinates of the pixel
unsigned int ycoor; //store the y coordinates of the pixel
Image <Pixel> Input;

	
public:

RegionGrower();
bool SetImage( std::string imgfile);
bool SetSeed( unsigned int x, unsigned int y); //check if the seed is valid here (peek and then pop)
bool SetReplacement(unsigned int red, unsigned int green, unsigned int blue); //sets
void Update() throw(std::range_error); //or check if the seed is valid here IMPLEMENT THE ALGORITHM HERE
bool GetOutput(std::string outfile); //call update from here
};

#endif
