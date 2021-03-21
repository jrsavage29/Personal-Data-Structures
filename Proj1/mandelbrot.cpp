/*
*  Purpose for program:
*  For this project we are creating class methods for a provided header file named Mandelbrot.hpp.
*  The program can accept a width and height parameters that will be used as pixels for generating  
*  a fractal image in the complex plain. 
*  
*  Programmer: Jamahl Savage
*  Date: September 4, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/


#include <iostream>
#include <math.h>

#include "lodepng.h"
#include "mandelbrot.hpp"

#define PI 3.14159265
 //using std::cout;
 //using std::endl;

 /*
*  Function: Mandelbrot
*  Purpose: The constructor is used to initializes the instances used in the class.
*  It will also set default values if certain criteria for some of the instances are not meet.
*  Specifically, It should set the width and height to 1020 by 680, the max iterations to 100, 
*  and all the real and imaginary maxs/mins to the required default values.
*/
Mandelbrot::Mandelbrot() : width(1020), height(680)
{
	 size = width*height;
	 img = new uint32_t[size];
	 c = new Complex[size];
	 zn = new Complex[size];
	 
	 realMin = -2;
	 realMax = 1;
	 imaginaryMin = -1;
	 imaginaryMax = 1;
	 n = 100;
	 
	 
}

/*
*  Function: escape
*  Purpose: A special method created for the purpose of running the escape-time algorithm that
*  will run over for the specified complex plane and for the specified number of iterations 
*  and grab the iteration in which the pixel ever "escapes".  
*
*  c - an array of size width-times-height to hold iteration number at which pixel (point) escaped
*  zn - an array of complex numbers that represents the value of the escape algorithm (z_{n+1} = z_n + c) after the n-th iteration
*  n - holds the number of max iterations
*  img - an array of size width-times-height to hold iteration number at which the pixel escapes
*  j - a counter from the draw method that is used to keep track of the pixel going into the escape method.
*/
void Mandelbrot::escape(Complex* c, Complex* zn, uint32_t n , uint32_t* img, int j) 
{
	zn[0] = Complex(0,0); //starts at zero
	unsigned int i;
	bool check = false;
	
	for( i = 0; i < n; i++)
	{
		zn[i+1] = c[j].add( (zn[i].multiply(zn[i])) );
		
		if( ( pow(zn[i+1].getReal(), 2) + pow(zn[i+1].getImaginary(), 2) ) > 4 )
		{
			
			img[j] = i;
			check = true; 
			break;
		}
		
	}
	
	if(check == false) 
	{
		img[j] = n;
		
	}
	
}

/*
*  Function: writeImg
*  Purpose: After using the draw method, this method is used to create a png named fractal.png
*/
bool Mandelbrot::writeImg()
{  
  int i; //for iterating over pixels
  std::size_t idx = 0; //for iterating over rgba value per pixel
  uint32_t N = 1; //maximum number of iterations achieved (no division by zero).
  std::vector<double> t(width*height); //normalized color table
  std::vector<unsigned char> raw(4*width*height);; //rgba data for each pixel (each pixel has a byte for each; order is rgba)

  //normalize pixel values
  for(i = 0; i < width*height; i++)
    if(img[i] > N)
      N = img[i];

  for(i = 0; i < width*height; i++)
    t[i] = (double)img[i]/N;

  //assign pixel values according palette
  for(i = 0; i < width*height; i++)
    {
      raw[idx++] = 255*(0.5 + 0.5 * cos(2*PI*(1*t[i] + 0.00))); //r
      raw[idx++] = 255*(0.5 + 0.5 * cos(2*PI*(1*t[i] + 0.33))); //g
      raw[idx++] = 255*(0.5 + 0.5 * cos(2*PI*(1*t[i] + 0.67))); //b
      raw[idx++] = 255; //a
    }
  
  //write png      
  unsigned error = lodepng::encode("fractal.png", raw, width, height);
  return true;
}

/*
*  Function: ~Mandelbrot
*  Purpose: This deconstructor and it is used to deallocate the memory created
*  for the array after the program is finished using it. 
*  Will help prevent memory leaks.
*  
*/
Mandelbrot::~Mandelbrot()
 {
	 delete [] c;
	 delete [] img;
	 delete [] zn;
	 
	 c = nullptr;
	 img = nullptr;
	 zn = nullptr;
 }
 
/*
*  Function: Mandelbrot
*  Purpose: This the other constructor which is used to initialize the instances used in the class
*  when the user decides to specify their own width and height for the image. However if the  width and
*  height are bellow 2 by 2, then the values will use the default values instead.
*  All the other variables initialized in this constructor is the same as the first one.
*
*  w - number of horizontal pixels for image of Mandelbrot set (can be changed if appropriately specified by the user)
*  h - number of vertical pixels for image of Mandelbrot set (can be changed if appropriately specified by the user)
*/
Mandelbrot:: Mandelbrot( uint16_t w, uint16_t h) : width(w >= 2 ? w : 2), height(h >= 2 ? h : 2)//Might have to change back to 1020 and 680.
{
	 size = width*height;
	 img = new uint32_t[size];
	 c = new Complex[size];
	 zn = new Complex[size];
	 
	 realMin = -2;
	 realMax = 1;
	 imaginaryMin = -1;
	 imaginaryMax = 1;
	 n = 100;
}

/*
*  Function: setIterations
*  Purpose: Allows the user to specify the number of iterations that are less than 100.
*  
*  
*  n - holds the number of iterations
*/
void Mandelbrot::setIterations(uint32_t n)
{	
	if( n < 100 || n > 0)
	{
		this-> n = n;
	}
	
	else 
		this-> n = n;
}

/*
*  Function: setRealAxis
*  Purpose: used to set the minimum and maximum value of the real axis. If the
*  user specifies bounds that are not between[-2,1] then the default values will be used.
*  
*  min - the minimum value of the real axis that can take the users' inputs if valid.
*  max - the maximum value of the real axis that can take the users' inputs if valid.
*/ 
bool Mandelbrot::setRealAxis(double realMin, double realMax)
{
	
	if( (realMin >= -2 && realMin <= 1) && realMin != realMax && realMin < realMax)
	{
		
		if( (realMax >= -2 && realMax <= 1 ) && realMax != realMin && realMin < realMax)
		{
			this-> realMin = realMin;
			this-> realMax = realMax;
			return true;
		}
		
		else 
		{
			return false;
		}
		
	}
	
	else
	{
		return false;
	}
	
}

/*
*  Function: setImaginaryAxis
*  Purpose: used to set the minimum and maximum value of the imaginary axis. If the
*  user specifies bounds that are not between[-1,1] then the default values will be used.
*  
*  min - the minimum value of the imaginary axis that can take the users' inputs if valid.
*  max - the maximum value of the imaginary axis that can take the users' inputs if valid.
*/
bool Mandelbrot::setImaginaryAxis(double imaginaryMin, double imaginaryMax)
{
	if( ( imaginaryMin >= -1 && imaginaryMin <= 1 ) && imaginaryMin != imaginaryMax && imaginaryMin < imaginaryMax)
	{
		
		
		if( ( imaginaryMax >= -1 && imaginaryMax <= 1 ) && imaginaryMax != imaginaryMin && imaginaryMin < imaginaryMax)
		{
			this-> imaginaryMin = imaginaryMin;
			this-> imaginaryMax = imaginaryMax;
			return true;
		}
		
		else
		{
			return false;
		}
	}
	
	else
	{
		return false;
	}
	
}

/*
*  Function: draw
*  Purpose: used to convert the pixels into coordinates in the complex plane and
*  run escape time algorithm on the axes specified by the user 
*  then write result to the file.
* 
*/  
bool Mandelbrot::draw()
{
	
	for(int j = 0; j <= ((width * height) -1); j++ )
	{
		double x = (realMax - realMin)/(width -1);
		double y = (imaginaryMax - imaginaryMin)/(height - 1);
	
		double Cr = (realMin +  x * (j%width));
		double Ci = (imaginaryMax - y * (j/width));
		
		c[j].setReal(Cr);
		c[j].setImaginary(Ci); 
		
		escape(c, zn, n , img, j);
		
	
	}
		return writeImg();
}

/*
*  Function: getRealAxis
*  Purpose: Used to return the real axis values in a pair.
*  Parts of the pair can be called separately as well.
*  
*/  
std::pair<double,double> Mandelbrot::getRealAxis()
{
	std::pair<double,double> real;
	real.first = realMin;
	real.second = realMax;
	return real;
}

/*
*  Function: getImaginaryAxis
*  Purpose: Used to return the imaginary axis values in a pair.
*  Parts of the pair can be called separately as well.
*  
*/  
std::pair<double,double> Mandelbrot::getImaginaryAxis()
{
	std::pair<double,double> imaginary;
	imaginary.first = imaginaryMin;
	imaginary.second = imaginaryMax;
	return imaginary;
}

/*
*  Function: getImageSize
*  Purpose: Used to return the image size in a pair.
*  Parts of the pair can be called separately as well.
*
*/  
std::pair<uint16_t,uint16_t> Mandelbrot::getImageSize()
{
	std::pair<double,double> image; 
	image.first = width;
	image.second = height;
	return image;
}