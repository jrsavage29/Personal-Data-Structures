#define CATCH_CONFIG_MAIN

#include <cstdlib>
#include <ctime>
#include "catch.hpp"
#include <memory>
#include "LinkedList.hpp"
#include "Polynomial.hpp"
#include "Term.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
using std::istringstream;
using std::ostringstream;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

TEST_CASE( "Test construction" )
{
	cout<<endl;
	cout <<"This is Polynomial 1:" <<endl;
	Polynomial p1;
	ostringstream out;
	
	p1.insert_term(Term(4,2));
	//cout << p1<<endl;
	p1.insert_term(Term(-3,2));
	//cout << p1<<endl;
	p1.insert_term(Term(2,5));
	//cout << p1<<endl;
	p1.insert_term(Term(66,2));
	//cout << p1<<endl;
	p1.insert_term(Term(72,3));
	cout<<p1<<endl;
	
	out << p1;
	
	REQUIRE("2x^5+72x^3+67x^2" == out.str() );
	
}

TEST_CASE( "Test addition" )
{
	Polynomial p1;
	Polynomial p2;
	ostringstream out;
	
	cout<<endl;
	cout<<endl;
	cout <<"This is Polynomial 1:" <<endl;
	p1.insert_term(Term(4,2));
	//cout << p1<<endl;
	p1.insert_term(Term(-3,2));
	//cout << p1<<endl;
	p1.insert_term(Term(2,5));
	//cout << p1<<endl;
	p1.insert_term(Term(66,2));
	//cout << p1<<endl;
	p1.insert_term(Term(72,3));
	cout<<p1<<endl;
	
	cout<<endl;
	
	cout<<"Now for polynomial 2:"<<endl;
	
	p2.insert_term(Term(7,1));
	//cout << p2<<endl;
	p2.insert_term(Term(-1,1));
	//cout << p2<<endl;
	p2.insert_term(Term(8,5));
	//cout << p2<<endl;
	p2.insert_term(Term(50,1));
	//cout << p2<<endl;
	p2.insert_term(Term(60,3));
	//cout<<p2<<endl;
	p2.insert_term(Term(80,0));
	cout<<p2<<endl;
	
	cout<<"The result of addition is: "<<p1+p2<<endl;
	out <<p1+p2;
	REQUIRE("10x^5+132x^3+67x^2+56x+80" == out.str() );
}

TEST_CASE( "Test addition 2" )
{
	Polynomial p1;
	Polynomial p2;
	ostringstream out;
	
	cout<<endl;
	cout<<endl;
	cout <<"This is Polynomial 1:" <<endl;
	p1.insert_term(Term(4,2));
	cout << p1<<endl;
	
	cout<<endl;
	
	cout<<"Now for polynomial 2:"<<endl;
	
	p2.insert_term(Term(-4,2));
	cout << p2<<endl;
	
	cout<<"The result of addition is: "<<p1+p2<<endl;
	out <<p1+p2;
	REQUIRE( "" == out.str() );
}

TEST_CASE( "Test multiplication" )
{
	Polynomial p1;
	Polynomial p2;
	ostringstream out;
	
	cout<<endl;
	cout<<endl;
	cout <<"This is Polynomial 1:" <<endl;
	p1.insert_term(Term(-2,2));
	//cout << p1<<endl;
	p1.insert_term(Term(3,1));
	//cout << p1<<endl;
	p1.insert_term(Term(4,0));
	cout << p1<<endl;
	
	cout<<endl;
	cout<<endl;
	
	cout<<"Now for polynomial 2:"<<endl;
	
	p2.insert_term(Term(3,3));
	//cout << p2<<endl;
	p2.insert_term(Term(3,2));
	//cout << p2<<endl;
	p2.insert_term(Term(5,1));
	cout << p2<<endl;
	
	cout<<endl;
	
	cout<<"The result of multiplication is: "<<p1*p2<<endl;
	out <<p1*p2;
	REQUIRE("-6x^5+3x^4+11x^3+27x^2+20x" == out.str() );
}


TEST_CASE( "Test inversion" )
{
	Polynomial p1;
	Polynomial p2;
	ostringstream out;
	
	cout<<endl;
	cout<<endl;
	cout <<"This is Polynomial 1:" <<endl;
	p1.insert_term(Term(-1,0));
	cout << p1<<endl;
	
	cout<<endl;
	cout<<endl;
	
	cout<<"Now for polynomial 2:"<<endl;
	
	p2.insert_term(Term(3,2));
	//cout << p2<<endl;
	p2.insert_term(Term(4,1));
	//cout << p2<<endl;
	p2.insert_term(Term(1,0));
	cout << p2<<endl;
	
	cout<<endl;
	
	cout<<"The result of inversion is: "<<p2*p1<<endl;
	out <<p2*p1;
	REQUIRE("-3x^2-4x-1" == out.str() );
}


TEST_CASE( "Test subtraction" )
{
	Polynomial p1;
	Polynomial p2;
	ostringstream out;
	
	cout<<endl;
	cout<<endl;
	cout <<"This is Polynomial 1:" <<endl;
	p1.insert_term(Term(-2,2));
	//cout << p1<<endl;
	p1.insert_term(Term(3,1));
	//cout << p1<<endl;
	p1.insert_term(Term(4,0));
	cout << p1<<endl;
	
	cout<<endl;
	cout<<endl;
	
	cout<<"Now for polynomial 2:"<<endl;
	
	p2.insert_term(Term(3,2));
	//cout << p2<<endl;
	p2.insert_term(Term(4,1));
	//cout << p2<<endl;
	p2.insert_term(Term(1,0));
	cout << p2<<endl;
	
	cout<<endl;
	
	cout<<"The result of subtraction is: "<<p1-p2<<endl;
	out <<p1-p2;
	REQUIRE("-5x^2-x+3" == out.str() );
}


TEST_CASE( "Test division" )
{
	Polynomial p1;
	Polynomial p2;
	ostringstream out;
	
	cout<<endl;
	cout<<endl;
	cout <<"This is Polynomial 1:" <<endl;
	p1.insert_term(Term(-2,2));
	//cout << p1<<endl;
	p1.insert_term(Term(3,1));
	//cout << p1<<endl;
	p1.insert_term(Term(-2,0));
	cout << p1<<endl;
	
	cout<<endl;
	cout<<endl;
	
	cout<<"Now for polynomial 2:"<<endl;
	
	p2.insert_term(Term(1,1));
	//cout << p2<<endl;
	p2.insert_term(Term(-1,0));
	cout << p2<<endl;
	
	cout<<endl;
	
	cout<<"The result of divison is: "<<p1/p2<<endl;
	out <<p1/p2;
	REQUIRE("-2x+1" == out.str() );
}


TEST_CASE( "Test modulus" )
{
	Polynomial p1;
	Polynomial p2;
	ostringstream out;
	
	cout<<endl;
	cout<<endl;
	cout <<"This is Polynomial 1:" <<endl;
	p1.insert_term(Term(-2,2));
	//cout << p1<<endl;
	p1.insert_term(Term(3,1));
	//cout << p1<<endl;
	p1.insert_term(Term(-2,0));
	cout << p1<<endl;
	
	cout<<endl;
	cout<<endl;
	
	cout<<"Now for polynomial 2:"<<endl;
	
	p2.insert_term(Term(1,1));
	//cout << p2<<endl;
	p2.insert_term(Term(-1,0));
	cout << p2<<endl;
	
	cout<<endl;
	
	cout<<"The result of modulus is: "<<p1%p2<<endl;
	out <<p1%p2;
	REQUIRE("-1" == out.str() );
	
	
}




