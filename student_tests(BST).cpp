#define CATCH_CONFIG_MAIN

#include <cstdlib>
#include <ctime>
#include "catch.hpp"
#include <memory>
#include "BST.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;


TEST_CASE( "Test construction and basic insertion" )
{
	BST<int> B;
	REQUIRE( B.insert(2) == true );
	REQUIRE( B.insert(1) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(0) == true );
	REQUIRE( B.insert(4) == true );
	REQUIRE( B.insert(3) == true );
	REQUIRE( B.insert(2) == true );
	//cout<<B;
}

TEST_CASE( "Test contains" )
{
	BST<int> B;
	REQUIRE( B.insert(2) == true );
	REQUIRE( B.insert(1) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(0) == true );
	
	REQUIRE( B.contains(0) == true );
	REQUIRE( B.contains(7) == false );
	//cout<<B;
}

TEST_CASE( "Test find " )
{
	BST<int> B;
	REQUIRE( B.insert(2) == true );
	REQUIRE( B.insert(1) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(0) == true );
	
	REQUIRE( B.contains(5) == true );
	REQUIRE( B.contains(7) == false );
	
	REQUIRE( B.find(5) == 5 );
	REQUIRE( B.find(7) == 0 );
	//cout<<B;
}

TEST_CASE( "Test copying and swapping " )
{
	BST<int> B;
	BST<int> C;
	
	REQUIRE( B.insert(2) == true );
	REQUIRE( B.insert(1) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(0) == true );
	REQUIRE( B.insert(4) == true );
	REQUIRE( B.insert(3) == true );
	REQUIRE( B.insert(2) == true );
	
	C = B;
	REQUIRE( C.contains(2) == true );
	REQUIRE( C.contains(1) == true );
	REQUIRE( C.contains(5) == true );
	REQUIRE( C.contains(5) == true );
	REQUIRE( C.contains(0) == true );
	REQUIRE( C.contains(4) == true );
	REQUIRE( C.contains(3) == true );
	REQUIRE( C.contains(2) == true );
	
	REQUIRE( B.contains(2) == true );
	REQUIRE( B.contains(1) == true );
	REQUIRE( B.contains(5) == true );
	REQUIRE( B.contains(5) == true );
	REQUIRE( B.contains(0) == true );
	REQUIRE( B.contains(4) == true );
	REQUIRE( B.contains(3) == true );
	REQUIRE( B.contains(2) == true );
	//cout<<C;
}

TEST_CASE( "Test height " )
{
	BST<int> B;
	REQUIRE( B.height() == 0 );
	
	REQUIRE( B.insert(2) == true );
	REQUIRE( B.insert(1) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(0) == true );
	REQUIRE( B.insert(4) == true );
	REQUIRE( B.insert(3) == true );
	REQUIRE( B.insert(2) == true );
	
	REQUIRE( B.height() == 5 );
	//cout<<B;
}

TEST_CASE( "Test Remove " )
{
	BST<int> B;
	REQUIRE( B.height() == 0 );
	
	REQUIRE( B.insert(2) == true );
	REQUIRE( B.insert(1) == true );
	REQUIRE( B.insert(5) == true );
	
	REQUIRE( B.height() == 2 );
	
	REQUIRE( B.remove(5) == 5 );
	
	//cout<<B;
	
}

TEST_CASE( "Test node count " ) 
{
	BST<int> B;
	REQUIRE( B.height() == 0 );
	
	REQUIRE( B.insert(50) == true );
	REQUIRE( B.insert(40) == true );
	REQUIRE( B.insert(70) == true );
	REQUIRE( B.insert(60) == true );
	REQUIRE( B.insert(80) == true );
	REQUIRE( B.insert(60) == true );
	REQUIRE( B.insert(80) == true );
	
	REQUIRE( B.numberofNodes() == 7 );
	
	//cout<<B;
}


TEST_CASE( "Test Remove 2 " )
{
	BST<int> B;
	REQUIRE( B.height() == 0 );
	
	REQUIRE( B.insert(2) == true );
	REQUIRE( B.insert(1) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(5) == true );
	
	REQUIRE( B.height() == 5 );
	
	REQUIRE( B.remove(5) == 5 );
	
	//cout<<B;
}

TEST_CASE( "Test Remove 3 " ) //Doesn't seem to work
{
	BST<int> B;
	REQUIRE( B.height() == 0 );
	
	REQUIRE( B.insert(2) == true );
	REQUIRE( B.insert(1) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(5) == true );
	REQUIRE( B.insert(4) == true );
	REQUIRE( B.insert(3) == true );
	
	REQUIRE( B.remove(5) == 5 );
	REQUIRE( B.remove(5) == 5 );
	REQUIRE( B.remove(5) == 5 );
	//cout<<B;
}

TEST_CASE( "Test Remove 4 " ) //removing the root and it doesn't work
{
	BST<int> B;
	REQUIRE( B.height() == 0 );
	
	REQUIRE( B.insert(50) == true );
	REQUIRE( B.insert(40) == true );
	REQUIRE( B.insert(70) == true );
	REQUIRE( B.insert(60) == true );
	REQUIRE( B.insert(80) == true );
	//cout<<B;
	//cout<<endl;
	//cout<<endl;
	
	REQUIRE( B.remove(50) == 50 );
	//cout<<B;
}

TEST_CASE( "Test Remove 5 " ) //removing the root and it doesn't work
{
	BST<int> B;
	REQUIRE( B.height() == 0 );
	
	REQUIRE( B.insert(50) == true );
	REQUIRE( B.insert(40) == true );
	REQUIRE( B.insert(70) == true );
	REQUIRE( B.insert(60) == true );
	REQUIRE( B.insert(80) == true );
	//cout<<B;
	//cout<<endl;
	//cout<<endl;
	
	REQUIRE( B.remove(50) == 50 );
	//cout<<B;
	//cout<<endl;
	//cout<<endl;
	
	REQUIRE( B.remove(70) == 70 );
	//cout<<B;
	//cout<<endl;
	//cout<<endl;
	
	REQUIRE( B.remove(60) == 60 );
	//cout<<B;
	//cout<<endl;
	//cout<<endl;
	
	REQUIRE( B.remove(80) == 80 );
	//cout<<B;
	//cout<<endl;
	//cout<<endl;
	
	REQUIRE( B.remove(40) == 40 );
	//cout<<B;
	
	REQUIRE( B.height() == 0 );
	REQUIRE( B.numberofNodes() == 0);
	
	if(B.numberofNodes() == 0)
	{
		//cout<<"WE HAVE REMOVED ALL THE NODES!!!!!!"<<endl;
		//cout<<endl;
	}
	
	REQUIRE( B.insert(5000) == true );
	//cout<<B;
	//cout<<endl;
	
	if(B.numberofNodes() != 0)
	{
		//cout<<"THE TREE IS NO LONGER EMPTY. I'M NOT DUMB BUT I'M 99.99% SURE YOU INSERTED SOMETHING!!!!!!"<<endl;
	}
	
	B.clear();
	REQUIRE( B.numberofNodes() == 0);
	
}

TEST_CASE( "Test construction and basic insertion 2" )
{
	const int SIZE = 30;
    int numbers[SIZE];
    for ( int i=0; i<SIZE; i++ )
        numbers[i] = rand() % 1000;
    
    BST<int> bst;

    INFO("Hint: inserting 30 numbers into the tree");
    for ( int i=0; i<SIZE; i++ )
	{
        REQUIRE(bst.insert(numbers[i]));
	}
	
	//cout<<bst;
	
}