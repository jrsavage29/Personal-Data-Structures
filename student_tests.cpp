#define CATCH_CONFIG_MAIN

#include <cstdlib>
#include <ctime>
#include "catch.hpp"
#include <memory>
#include "LinkedList.hpp"


TEST_CASE( "Test construction" )
{
	INFO( "Hint: Checking basic construction" );
	ListInterface<int> * ll = new LinkedList<int>();
	REQUIRE( ll->isEmpty() );
	REQUIRE( ll->getLength() == 0 );
	delete ll;
	
}

TEST_CASE( "Test insertion" )
{
	ListInterface<int> * ll = new LinkedList<int>();
	ll->insert(1,24);
	REQUIRE( ll->isEmpty() == false );
	REQUIRE( ll->getLength() == 1 );
	delete ll;
}

TEST_CASE( "Test big insertion" )
{
	ListInterface<int> * ll = new LinkedList<int>();
	for(int i=1; i < 100; i++)
	{
		ll->insert(i,i+1);
	}
	
	REQUIRE( ll->isEmpty() == false );
	REQUIRE( ll->getLength() == 99 );
	delete ll;
	
}

TEST_CASE( "testing clear" )
{
	ListInterface<int> * ll = new LinkedList<int>();
	for(int i=1; i < 100; i++)
	{
		ll->insert(i,i+1);
	}
	
	REQUIRE( ll->isEmpty() == false );
	REQUIRE( ll->getLength() == 99 );
	
	ll->clear();
	REQUIRE( ll->isEmpty() );
	
	delete ll;
}

TEST_CASE( "testing remove" )
{
	ListInterface<int> * ll = new LinkedList<int>();
	for(int i=1; i < 100; i++)
	{
		ll->insert(i,i+1);
	}
	
	REQUIRE( ll->isEmpty() == false );
	REQUIRE( ll->getLength() == 99 );
	
	REQUIRE( ll->getEntry(1) == 2 );
	
	ll->remove(1);
	REQUIRE( ll->getLength() == 98 );
	
	delete ll;
	
}

TEST_CASE( "testing insert and remove" )
{
	
}

TEST_CASE( "testing replacing" )
{
	ListInterface<int> * ll = new LinkedList<int>();
	for(int i=1; i < 100; i++)
	{
		ll->insert(i,i+1);
	}
	
	REQUIRE( ll->isEmpty() == false );
	REQUIRE( ll->getLength() == 99 );
	
	REQUIRE( ll->getEntry(1) == 2 );
	
	ll->replace(1,45);
	REQUIRE( ll->getEntry(1) == 45 );
	REQUIRE( ll->getLength() == 99 );
	
	delete ll;
}

TEST_CASE( "testing copy & swap" )
{
	ListInterface<int> * ll = new LinkedList<int>();
	ListInterface<int> * nn = new LinkedList<int>();
	for(int i=1; i < 100; i++)
	{
		ll->insert(i,i+1);
	}
	
	REQUIRE( ll->isEmpty() == false );
	REQUIRE( ll->getLength() == 99 );
	
	nn = ll;
	
	REQUIRE( nn->isEmpty() == false );
	REQUIRE( nn->getLength() == 99 );
	
	REQUIRE( ll->getEntry(2) == nn->getEntry(2) );
	
	delete ll;
}
