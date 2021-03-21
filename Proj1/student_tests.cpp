#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "mandelbrot.hpp"
#include "image.h"

// TODO

/*TEST_CASE( "Image compare", "[mandelbrot]" )
{
  //this is probably a bad idea...use compare.cpp instead.
  Mandelbrot m(1020,680);

  m.draw();

  Image<Pixel> test1 = readFromFile("fractal.png");
  Image<Pixel> ref1 = readFromFile("fractal01.png");

  REQUIRE(test1.width() == ref1.width());
  REQUIRE(test1.height() == ref1.height());
  
  for (intmax_t i = 0; i < test1.width(); ++i)
    for (intmax_t j = 0; j < test1.height(); ++j)
      REQUIRE( test1(i,j) == ref1(i,j));

}*/

TEST_CASE( "Check default values to make sure they ARE the default values", "[mandelbrot]" )
{
  Mandelbrot m;
  REQUIRE( m.getRealAxis().first == -2 );
  REQUIRE( m.getRealAxis().second == 1 );
  
  REQUIRE( m.getImageSize().first == 1020 );
  REQUIRE( m.getImageSize().second == 680 );
  
  REQUIRE( m.getImaginaryAxis().first == -1 );
  REQUIRE( m.getImaginaryAxis().second == 1 );
}

TEST_CASE( "User sets values so they should change from default", "[mandelbrot]" )
{
  Mandelbrot m(1000,650);
  
  m.setRealAxis(-0.5,0.5);
  m.setImaginaryAxis(0,0.7);
  
  REQUIRE( m.getImageSize().first == 1000 );
  REQUIRE( m.getImageSize().second == 650 );
  
  REQUIRE( m.getRealAxis().first == -0.5 );
  REQUIRE( m.getRealAxis().second == 0.5 );
  
  REQUIRE( m.getImaginaryAxis().first == 0 );
  REQUIRE( m.getImaginaryAxis().second == 0.7 );
  
  //m.draw();
}

TEST_CASE( "Reset to default image size if breaks requirements", "[mandelbrot]" )
{
  Mandelbrot m(1,1);
  REQUIRE( m.getImageSize().first == 2 );
  REQUIRE( m.getImageSize().second == 2 );
}

TEST_CASE( "Take the image size as 2 by 2 and create it", "[mandelbrot]" )
{
  Mandelbrot m(2,2);
  //m.draw();
  
}

TEST_CASE( "Testing individual min and max axis change", "[mandelbrot]" )
{
  Mandelbrot m(0,690);
  
  m.setRealAxis(-3,0);
  m.setImaginaryAxis(-3,0.7);
  
  REQUIRE( m.getImageSize().first == 2 );
  REQUIRE( m.getImageSize().second == 690 );
  
  REQUIRE( m.getRealAxis().first == -2 );
  REQUIRE( m.getRealAxis().second == 1 );
  
  REQUIRE( m.getImaginaryAxis().first == -1 );
  REQUIRE( m.getImaginaryAxis().second == 1 );
  
  
}

TEST_CASE( "Minimums can not be greater than Maximums", "[mandelbrot]" )
{
  Mandelbrot m(0,690);
  
  m.setRealAxis(0.5,-1);
  m.setImaginaryAxis(0.5,0);
  
  REQUIRE( m.getImageSize().first == 2 );
  REQUIRE( m.getImageSize().second == 690 );
  
  REQUIRE( m.getRealAxis().first == -2 );
  REQUIRE( m.getRealAxis().second == 1 );
  
  REQUIRE( m.getImaginaryAxis().first == -1 );
  REQUIRE( m.getImaginaryAxis().second == 1 );
}

