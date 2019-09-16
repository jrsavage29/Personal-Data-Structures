#define CATCH_CONFIG_MAIN

#include <cstdlib>
#include <ctime>
#include "catch.hpp"
#include <memory>
#include "deque.hpp"
#include <iostream>
using std::cout;
using std::endl;


TEST_CASE( "Test construction" )
{
	INFO( "Hint: Checking basic construction" );
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	delete dd;
	
}


TEST_CASE( "Testing pushFront" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	dd->pushFront(2);
	REQUIRE( dd->isEmpty() == false);
	
	
	delete dd;
	
}


TEST_CASE( "Testing popFront" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	dd->pushFront(2);
	dd->pushFront(67);
	REQUIRE( dd->isEmpty() == false);
	REQUIRE( dd-> front() == 67);
	dd->popFront();
	REQUIRE( dd-> front() == 2);
	delete dd;
	
}


TEST_CASE( "Testing peek front" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	dd->pushFront(2);
	dd->pushFront(67);
	REQUIRE( dd->isEmpty() == false);
	REQUIRE( dd-> front() == 67);
	delete dd;
	
}


TEST_CASE( "Testing pushBack" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	dd->pushBack(2);
	dd->pushBack(67);
	dd->pushBack(80);
	REQUIRE( dd->isEmpty() == false);
	REQUIRE( dd-> front() == 2);
	delete dd;
	
}


TEST_CASE( "Testing popBack" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	dd->pushBack(2);
	dd->pushBack(67);
	dd->pushBack(80);
	REQUIRE( dd->isEmpty() == false);
	REQUIRE( dd-> front() == 2);
	dd->popBack();
	dd->popBack();
	REQUIRE( dd-> back() == 2);
	delete dd;
	
}


TEST_CASE( "Testing peek back" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	dd->pushBack(2);
	dd->pushBack(67);
	dd->pushBack(80);
	REQUIRE( dd->isEmpty() == false);
	REQUIRE( dd-> front() == 2);
	REQUIRE(dd->back() == 80);
	dd->popBack();
	REQUIRE( dd-> front() == 2);
	REQUIRE(dd->back() == 67);
	delete dd;
	
}

TEST_CASE( "Testing random" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	dd->pushBack(2);
	dd->pushBack(67);
	dd->pushBack(80);
	REQUIRE( dd->isEmpty() == false);
	REQUIRE( dd-> front() == 2);
	REQUIRE(dd->back() == 80);
	dd->popFront();
	REQUIRE( dd-> front() == 67);
	REQUIRE(dd->back() == 80);
	dd ->popBack();
	REQUIRE( dd-> front() == 67);
	REQUIRE(dd->back() == 67);
	delete dd;
	
} 

TEST_CASE( "Testing copying & swapping" )
{
	Deque<int> * dd = new Deque<int>();
	Deque<int> * ee = new Deque<int>();
	
	dd->pushFront(3);
	dd->pushFront(40);
	dd->pushBack(2);
	dd->pushBack(67);
	
	REQUIRE( dd-> front() == 40);
	REQUIRE(dd->back() == 67);
	REQUIRE( dd->isEmpty() == false);
	
	*ee = *dd;
	
	REQUIRE(dd->isEmpty() == false);
	REQUIRE(ee->isEmpty() == false);
	
	//cout<<"I'm about to peek the front of ee!"<<endl;
	REQUIRE(ee-> front() == 40);
	//cout<<"I'm about to peek the back of ee!"<<endl;
	REQUIRE(ee->back() == 67);
	
	ee->popBack();
	ee->popFront();
	
	//cout<<"I'm about to peek the front of ee again!"<<endl;
	REQUIRE( ee-> front() == 3);
	//cout<<"I'm about to peek the back of ee again!"<<endl;
	REQUIRE(ee->back() == 2);
	
	ee->popBack();
	ee->popFront();
	
	REQUIRE( ee->isEmpty() );
	REQUIRE( dd->isEmpty() == false); //I DON'T THINK IT'S COPYING WHILE MAINTAING IT'S DATA IN ITSELF
	delete dd;
}


TEST_CASE( "Testing throw frontpop" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	REQUIRE_THROWS(dd->popFront());
	delete dd;
}


TEST_CASE( "Testing throw backpop" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	REQUIRE_THROWS(dd->popBack());
	delete dd;
}


TEST_CASE( "Testing throw front peek" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	REQUIRE_THROWS(dd->front());
	delete dd;
	
}


TEST_CASE( "Testing throw back peek" )
{
	AbstractDeque<int> * dd = new Deque<int>();
	REQUIRE( dd->isEmpty() );
	REQUIRE_THROWS(dd->back());
	delete dd;
	
}