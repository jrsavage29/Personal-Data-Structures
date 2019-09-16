
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include <cstdlib>
#include <ctime>

#include "complex.hpp"

// This is just a simple example for demonstration
// we will see how to do proper testing in meeting 3
TEST_CASE( "Default constructor is the what it's supposed to be", "[complex]" ) {
	Complex c;
	REQUIRE( c.getReal() == 1 );
	REQUIRE( c.getImaginary() == 1 );
}

TEST_CASE( "Test to make sure the users' values entered are the same as the value gotten", "[complex]" ) {
	Complex c(2, 3);
	REQUIRE( c.getReal() == 2 );
	REQUIRE( c.getImaginary() == 3 );
}

TEST_CASE( "Test to make sure the users' values entered are the same as the value gotten pt.2", "[complex]" ) {
	Complex c(2, 3);
	REQUIRE( c.getReal() != 3 );
	REQUIRE( c.getImaginary() != 4);
	//c.output("TEST");
}

TEST_CASE( "Test  Addition", "[complex]" ) {
	Complex c(2, 3);
	Complex d(4, 5);
	REQUIRE( c.getReal() == 2 );
	REQUIRE( c.getImaginary() == 3 );
	REQUIRE( d.getReal() == 4 );
	REQUIRE( d.getImaginary() == 5 );
	
	Complex Add =( c.add(d) );
	
	REQUIRE(Add.getReal() == 6 );
	REQUIRE(Add.getImaginary() == 8 );
	
	//REQUIRE(c.getReal() + d.getReal() == 6);
	//REQUIRE(c.getImaginary() + d.getImaginary() == 8);
	//REQUIRE();
}

TEST_CASE( "Test Multiplication", "[complex]" ) {
	Complex c(2, 3);
	Complex d(4, 5);
	REQUIRE( c.getReal() == 2 );
	REQUIRE( c.getImaginary() == 3 );
	REQUIRE( d.getReal() == 4 );
	REQUIRE( d.getImaginary() == 5 );
	
	Complex Mult =( c.multiply(d) );
	
	REQUIRE(Mult.getReal() == -7 );
	REQUIRE(Mult.getImaginary() == 22 );
}

TEST_CASE( "Test Equal", "[complex]" ) {
	Complex c(2, 3);
	Complex d(2, 3);
	REQUIRE( c.getReal() == 2 );
	REQUIRE( c.getImaginary() == 3 );
	REQUIRE( d.getReal() == 2 );
	REQUIRE( d.getImaginary() == 3 );
	
	REQUIRE( c.equal(d) == true);
	
	
}



