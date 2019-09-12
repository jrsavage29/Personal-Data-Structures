#define CATCH_CONFIG_MAIN

#include "Stack.hpp"
#include <iostream>
#include "catch.hpp"

TEST_CASE("test construction")
{
	Stack<int> s;
	REQUIRE(s.size() == 0);
	REQUIRE( s.isEmpty() );
}

TEST_CASE("Testing Push")
{
	Stack<int> s;
	s.push(1);
	REQUIRE( s.size() == 1 );
	REQUIRE( s.isEmpty() == false );
}

TEST_CASE("Testing Push 2")
{
	Stack<int> s;
	for(int i = 0; i < 100; i++)
	{
		s.push(i);
	}
	
	REQUIRE( s.size() == 100 );
	REQUIRE( s.isEmpty() == false );
}

TEST_CASE("Testing Pop")
{
	Stack<int> s;
	s.push(1);
	REQUIRE( s.size() == 1 );
	
	int poppedval = s.pop();
	REQUIRE( poppedval == 1 );
	REQUIRE( s.size() == 0 );
	REQUIRE( s.isEmpty() );
}

TEST_CASE("Testing Pop 2 (Invalid case)")
{
	Stack<int> s;
	REQUIRE(s.size() == 0);
	REQUIRE( s.isEmpty() );
	
	REQUIRE(s.pop() == false);
}

TEST_CASE("Testing Peek")
{
	Stack<int> s;
	REQUIRE(s.size() == 0);
	REQUIRE( s.isEmpty() );
	
	s.push(1);
	REQUIRE(s.peek() == 1);
	REQUIRE(s.size() == 1);
	
}

TEST_CASE("Testing Peek 2")
{
	Stack<int> s;
	REQUIRE(s.size() == 0);
	REQUIRE( s.isEmpty() );
	
	REQUIRE_THROWS(s.peek());
}

TEST_CASE("Testing clear")
{
	Stack<int> s;
	REQUIRE(s.size() == 0);
	REQUIRE( s.isEmpty() );
	
	for(int i = 0; i < 100; i++)
	{
		s.push(i);
	}
	
	REQUIRE(s.size() == 100);
	
	s.clear();
	REQUIRE(s.size() == 0);
	REQUIRE( s.isEmpty() );
	
	
}

TEST_CASE("Testing the copy and swap")
{
	Stack<int> s;
	
	for(int i = 0; i < 100; i++)
	{
		s.push(i);
	}
	
	Stack<int> t;
	
	t = s;
	
	REQUIRE(s.size() == 100);
	REQUIRE(t.size() == 100);
	
	REQUIRE(s.peek() == 99);
	REQUIRE(t.peek() == 99);
	
}

TEST_CASE("Testing the copy and swap 2")
{
	Stack<int> s;
	
	for(int i = 0; i < 5; i++)
	{
		s.push(i);
	}
	
	Stack<int> t;
	
	for(int i = 0; i < 100; i++)
	{
		t.push(i);
	}
	
	t = s;
	
	REQUIRE(s.size() == 5);
	REQUIRE(t.size() == 5);
	
	REQUIRE(s.peek() == 4);
	REQUIRE(t.peek() == 4);
	
}