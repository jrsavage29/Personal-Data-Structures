#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include "catch.hpp"
#include "Vector.hpp"

TEST_CASE( "Testing insert") 
{
	Vector<int> v;
	REQUIRE(v.insert(10));
	REQUIRE(v.insert(11));
	REQUIRE(v.insert(12));
	REQUIRE(v.get_count() == 3);
}

TEST_CASE( "Testing remove") 
{
	Vector<int> v;
	v.insert(10);
	v.insert(11);
	v.insert(12);
	REQUIRE(v.get_count() == 3);
	
	REQUIRE(v.remove_from(1) == 11);

	REQUIRE(v.get_count() == 2); 
	
}

TEST_CASE( "Testing insert again (for the grow()!!!!)") 
{
	Vector<int> v;
	
	for(int i = 0; i < 100; i++)
	{
		v.insert(i);
	}
	REQUIRE(v.get_count() == 100);
}

TEST_CASE( "Testing insert at 1") 
{
	Vector<int> v;
	v.insert(10);
	v.insert(11);
	v.insert(12);
	REQUIRE(v.get_count() == 3);
	
	v.insert_at(20, 1);
	REQUIRE(v.remove_from(1) == 20);
	
}

TEST_CASE( "Testing insert at 2") 
{
	Vector<int> v;
	v.insert(10);
	v.insert(11);
	v.insert(12);
	REQUIRE(v.get_count() == 3);
	
	v.insert_at(20, -2);
	REQUIRE(v.remove_from(0) == 20);
	
}

TEST_CASE( "Testing insert at 3 (There should be ""nothing"" at location 3 )") 
{
	Vector<int> v;
	v.insert(10);
	v.insert(11);
	v.insert(12);
	REQUIRE(v.get_count() == 3);
	
	v.insert_at(20, 4);
	REQUIRE(v.get_count() == 4);
	
	REQUIRE(v.remove_from(0) == 10);
	REQUIRE(v.remove_from(0) == 11);
	REQUIRE(v.remove_from(0) == 12);
	REQUIRE(v.return_from(0) == 20);
	
	REQUIRE(v.get_count() == 1);
	
	
}

TEST_CASE( "Testing insert at 4 (Adds the the int as the last element of the array)") 
{
	Vector<int> v;
	v.insert(10);
	v.insert(11);
	v.insert(12);
	REQUIRE(v.get_count() == 3);
	
	v.insert_at(20, 3);

	REQUIRE(v.get_count() == 4);
	
	REQUIRE(v.remove_from(0) == 10);
	REQUIRE(v.remove_from(0) == 11);
	REQUIRE(v.remove_from(0) == 12);
	REQUIRE(v.remove_from(0) == 20);
	//REQUIRE(v.remove_from(4) != 20);//Should not exist
	
	REQUIRE(v.get_count() == 0);
	
}

TEST_CASE( "Testing returning") 
{
	Vector<int> v;
	v.insert(10);
	v.insert(11);
	v.insert(12);
	REQUIRE(v.get_count() == 3);
	
	v.insert_at(20, 4);
	REQUIRE(v.get_count() == 4);
	
	REQUIRE(v.return_from(0) == 10);
	REQUIRE(v.return_from(1) == 11);
	REQUIRE(v.return_from(2) == 12);
	REQUIRE(v.return_from(3) == 20);
	REQUIRE(v.return_from(4) != 20); //Should not exist
	
}

TEST_CASE( "Testing copy constructor") 
{
	Vector<int> v;
	for(int i = 0; i < 100; i++)
	{
		v.insert(i);
	}
	
	Vector<int> v2 = v;
	for(int i = 0; i < 100; i++)
	{
		REQUIRE(v2.contains(i)== v.contains(i));
	}
	
}
