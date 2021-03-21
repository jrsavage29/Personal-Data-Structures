/*
*  Purpose for program:
*  For this project we are creating class methods for a color filling algorithm.
*  The algorithm will be used to change the color in regions of an image using stacks.
*  
*  Programmer: Jamahl Savage
*  Date: October 13, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "region_grower.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*
*  Function: RegionGrower
*  Purpose: The constructor is used to initializes the instances used in the class.
*  It will also set default values if certain criteria for some of the instances are not meet.
*  Specifically, It should set the default values for the Pixel struct's red, green, blue, and alpha to be 255.
*  
*/
RegionGrower::RegionGrower()
{
	colors.red = 255;
	colors.green = 255;
	colors.blue = 255;
	colors.alpha = 255; //The transparency value. This should also stay 255, expecially if you want to see the colors
	
}


/*
*  Function: SetImage
*  Purpose: sets the input PNG image to use. If the PNG image is not a valid PNG
*  or not a PNG at all, it will throw an error and exit the program.
*  
*  imgfile- contains the the name of the PNG file to be used as input. 
*  
*/
bool RegionGrower::SetImage( std::string imgfile)
{
	
	try //try running this to see if you have to throw an exception
	{
		Input = readFromFile(imgfile); //read me in as the input
		return true; // there were no problems so I return true
	}
	
	catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
	{
		std::cout <<"Error: the input image file cannot be opened " <<std::endl; //display error and tell me what the problem was
		return false; //Exit failure because I'm a failure :'(
	}
	
	//return false;
}


/*
*  Function: SetSeed
*  Purpose: sets the seed pixel indicies. If it's not an int then there WILL be a problem and it will EXIT_FAILURE.
*  If any of the coordinates are less than 0 or greater than the width or height of the image, the method will also
*  also EXIT_FAILURE. Before the method returns EXIT_FAILURE, it will display an error message stating the reason for the failure.
*  x - 
*  y -
*  
*/
bool RegionGrower::SetSeed( unsigned int x, unsigned int y)
{
	if( ( x >= 0 && x < Input.width() )&& ( y >= 0 && y < Input.height() ) )//Has to be positive while the x is less than the width and the y is less than the height
	{
		xcoor = x;
		ycoor = y;
		return true;
	}
	
	else
	{
		std::cout <<"Error: the seed is at an invalid position"<<std::endl;
		return false;
	}
}


/*
*  Function: SetReplacement
*  Purpose: sets the pixel color (RGB) used to set the region to. These values for red, green, and blue must be positvie and less than 255.
*  If the if condition fails to be met, the method will display an error message to the user and EXIT_FAILURE.
*  
*  red - contains the amount of red to be used in the pixel
*  green - contains the amount of green to be used in the pixel
*  blue - contains the amount of blue to be used in the pixel
*  
*/
bool RegionGrower::SetReplacement(unsigned int red, unsigned int green,  unsigned int blue)
{
	if( (red >= 0 && red < 255) && (green >= 0 && green < 255) && (blue >= 0 && blue < 255) ) //the colors cannot go above a value of 255 or it could become the color white.
	{
		colors.red = red; //give the value of red to the pixel struct that will hold the colors of the pixel
		colors.green = green;
		colors.blue = blue;
		return true;
	}
	
	else
	{
		std::cout <<"Error: the replacement color is invalid"<<std::endl;
		return false;
	}
}


/*
*  Function: Update
*  Purpose: This is where the color filling algorithm of this project resides. This method
*  is used to replace the color in a region defined by seed with a new color. There are no parameters
*  since it simply uses only locally declared variables and the private data of the class.
*  
*  
*  
*/
void RegionGrower::Update()
throw(std::range_error)
{
	Stack <Pixel> PixelColor; //create a stack for holding the color of the pixel.
	Stack <int> PixelLocationX; //create a stack for holding the x coordinate of the pixel
	Stack <int> PixelLocationY; //create a stack for holding the y coordinate of the pixel
	
	PixelLocationX.push(xcoor); // give the stack the location of the x coordinate of the seed to start at
	PixelLocationY.push(ycoor); // give the stack the location of the y coordinate of the seed to start at
	PixelColor.push( Input( xcoor, ycoor) ); //Set the coloring to start at the location giving by the seed on the input PNG.
	
	//cout<<"Initialized some variables to use"<<endl;
	unsigned int counter = 0; //mainly used for debugging purposes
	while( /*Input.width() * Input.height() > counter &&*/ PixelColor.isEmpty() == false && PixelLocationX.isEmpty() == false && PixelLocationY.isEmpty() == false ) //will only run while the stacks for the pixel is not empty
	{
		//cout << counter << endl;
		counter++;
		Pixel CurrentPix = PixelColor.peek(); //declared a variable to be used to hold the color of the current pixel in the stack at the time.
		unsigned int CurrentX = PixelLocationX.peek(); //declared a variable to be used to hold the x coordinate of the current pixel in the stack at the time.
		unsigned int CurrentY = PixelLocationY.peek(); //declared a variable to be used to hold the y coordinate of the current pixel in the stack at the time.
		
		PixelLocationX.pop(); //get and remove the top item  from each stack to be used for the initial color filling checks
		PixelLocationY.pop();
		PixelColor.pop();
		
		if( CurrentY + 1 > 0 && CurrentY + 1 < Input.height() && Input( CurrentX, CurrentY + 1 ) != colors && CurrentPix == Input( CurrentX, CurrentY + 1 ) )
		{ //first check to see if the location below is a valid location color fill by boundary checking. 
	//if the pixel below not desired color and same color as item then add pixel to stack
			PixelColor.push(Input( CurrentX, CurrentY + 1 ));
			PixelLocationX.push(CurrentX);
			PixelLocationY.push(CurrentY + 1);
			
			//cout<<"Met the first condition and adding to stack"<<endl;
			
		}
		
		if( CurrentY - 1 > 0 && CurrentY - 1 < Input.height() && Input( CurrentX, CurrentY - 1 ) != colors && CurrentPix == Input( CurrentX, CurrentY - 1 ) )
		{//first check to see if the location above is a valid location color fill by boundary checking.
	//if pixel above not desired color and same color as item then add pixel to stack
			PixelColor.push(Input( CurrentX, CurrentY - 1 ));
			PixelLocationX.push(CurrentX);
			PixelLocationY.push(CurrentY - 1);
			
			//cout<<"Met the second condition and adding to stack"<<endl;
		}
		
		if( CurrentX - 1 > 0 && CurrentX - 1 < Input.width() && Input( CurrentX - 1, CurrentY ) !=  colors && CurrentPix == Input( CurrentX - 1 , CurrentY ) )
		{//first check to see if the location to the left is a valid location color fill by boundary checking.
	//if pixel left not desired color and same color as item then add pixel to stack
			PixelColor.push(Input( CurrentX - 1 , CurrentY));
			PixelLocationX.push(CurrentX - 1);
			PixelLocationY.push(CurrentY);
			
			//cout<<"Met the third condition and adding to stack"<<endl;
		}
		
		if( CurrentX + 1 > 0 && CurrentX + 1 < Input.width() && Input( CurrentX + 1, CurrentY ) != colors && CurrentPix == Input( CurrentX + 1 , CurrentY ) )
		{//first check to see if the location to the right is a valid location color fill by boundary checking.
	//if pixel right not desired color and same color as item then add pixel to stack
			PixelColor.push(Input( CurrentX + 1 , CurrentY ));
			PixelLocationX.push(CurrentX + 1);
			PixelLocationY.push(CurrentY);
			
			//cout<<"Met the fourth condition and adding to stack"<<endl;
		}
		// lastly set the item to the desired color by giving the CurrentPix the colors recieved by Pixel struct named colors in the SetReplacement method 
		CurrentPix.red = colors.red;
		CurrentPix.green = colors.green;
		CurrentPix.blue = colors.blue;
		CurrentPix.alpha = colors.alpha;
		//Update the image to the color of the current pixel.
		Input(CurrentX, CurrentY) = CurrentPix;
		
		//cout<<"Repeating the process..."<<endl;
		
	}
	
	//cout<<"I'm out of the while loooooopppp"<<endl;
}


/*
*  Function: GetOutput
*  Purpose: provdies the new PNG image after the color filling. Techmically this should not EXIT_FAILURE unless the previous
*  methods failed before. However, just in case there is a try and catch implemented to catch any exceptions thrown.
*  
*  outfile- Holds and sets for the name of the output PNG if the program runs succesfully. 
*  
*/
bool RegionGrower::GetOutput(std::string outfile)
{
	try
	{
		writeToFile(Input, outfile); //will mainly depend on whether the initial input PNG is exceptable or not. If not, this will throw an exception.
		return true;
	}
	
	catch(std::runtime_error e) //if the exception is thrown then an error statement will displayed and the method will return EXIT_FAILURE.
	{
		std::cout <<"Error: the output image file cannot be opened " <<std::endl;
		return false;
	}
	
}

