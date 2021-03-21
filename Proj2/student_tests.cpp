#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include "catch.hpp"
#include "Sieve.hpp"

TEST_CASE( "Testing Baisc Factor") 
{
	//INFO( "basic sieve size 10" );
	Sieve s(10);
	//INFO( "s.ith_prime(0) " << s.ith_prime(0) );
	REQUIRE(s.ith_prime(0) == 2 );
	REQUIRE(s.ith_prime(1) == 3 );
	REQUIRE(s.ith_prime(2) == 5 );
	REQUIRE(s.ith_prime(3) == 7 );
	REQUIRE(s.number_of_primes() == 4);
}

TEST_CASE( "Testing Baisc Factor with negative starting number") 
{
	int n = -5;
	Sieve s(n);
	Vector <unsigned int> v;
	v= s.prime_factorization();
	REQUIRE(s.number_of_primes() == 1229);
	REQUIRE(v.return_from(0) == 2);
	REQUIRE(v.return_from(1) == 2);
	REQUIRE(v.return_from(2) == 2);
	REQUIRE(v.return_from(3) == 2);
	REQUIRE(v.return_from(4) == 5);
	REQUIRE(v.return_from(5) == 5);
	REQUIRE(v.return_from(6) == 5);
	REQUIRE(v.return_from(7) == 5);
	REQUIRE(v.get_count() == 8);
	
}

TEST_CASE( "Testing Baisc Factor with only 7 as starting number (which is prime)") 
{
	//INFO( "basic sieve size 10" );
	Sieve s(7);
	Vector <unsigned int> v;
	v= s.prime_factorization();
	//INFO( "s.ith_prime(0) " << s.ith_prime(0) );
	REQUIRE(s.ith_prime(0) == 2 );
	REQUIRE(s.ith_prime(1) == 3 );
	REQUIRE(s.ith_prime(2) == 5 );
	REQUIRE(s.number_of_primes() == 3);
	REQUIRE(v.return_from(0) == 7);
	REQUIRE(v.get_count() == 1);
}

