/*
*  Purpose for program:
*  For this project we are creating class methods for a provided header file named Sieve.hpp.
*  The program can take a vector of values and create a list of primes. The program will then use 
*  the list of primes to create the prime factorization of the default or of the users' entered initial number.
*  
*  Programmer: Jamahl Savage
*  Date: September 20, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "Sieve.hpp"
#include <iostream>
#include <math.h>

//using std::cout;
//using std::endl;

/*
*  Function: Sieve
*  Purpose: The constructor is used to initializes the instances used in the class.
*  It will also set default values if certain criteria for some of the instances are not meet.
*  Specifically, It should set the default to 10000. If the user enters a valid starting number (greater than 0)
*  then the starting number is set to that.
*  
*  n- the starting number for the sieve
*  
*/
Sieve::Sieve(int n)//the default is defined in the header and therefore there is no need to define it again in the .cpp. Default will be used when no values are given by the user.
{
	if(n > 0)//Change the starting number if the given number is greater than 0
	{
		start = n;
	}
	
	else //If the starting number is less than 0 then revert back to the default
	{
		start = 10000;
	}
	for(int i = 2;  i < start; i++ )//create values to fill up the array to the staring number 
		sieve.insert(i);
		
	factor(0); //Start the factorization at the first spot in the vector.
}


/*
*  Function: factor
*  Purpose: This is the recursive method that uses tail recursion to generate a list of primes.
*  The constructor will call this to create the list of primes starting form index 0. This will
*  go through every value inside the sieve until only the primes are left.
*    
*  starting_loc - the index for the starting position in the vector to start factoring at
*
*
*/
void Sieve::factor(int starting_loc)	
{
	if(starting_loc  > sieve.get_count() - 1) //This is the base case which allows to escape the recursive method when we reach the end of the values in the vector.
	{
		return;
	}
	
	int val = sieve.return_from(starting_loc); //holds the value of what is in the sieve at the starting location
	//cout<< val<<" ";
	for(int i = starting_loc + 1; i < sieve.get_count(); i++ )//as long as the i is below the maximum number of values in the vector
	{
		//cout<< sieve.return_from(i)<<" ";
		if(sieve.return_from(i) % val  == 0) //If the value at i in the sieve is divisible by the value at the starting location then remove it from the vector for it is not prime
		{
			sieve.remove_from(i);
			i--;	
		}
		
	}
	//cout<<endl;
	factor(starting_loc + 1); //move onto the next value next to the previous starting location and repeat the process until the base case is triggered. 
	
}


/*
*  Function: ith_prime
*  Purpose: This function will return the a prime from the list of primes based
*  on which index it is given. If the given index is less than 0 or  greater the last index
*  it will return 0.
*
*  ith - the integer index for the prime you want
*
*
*/
unsigned int Sieve::ith_prime(int ith)const
{
	//if(ith >= 0 && ith < sieve.get_count() - 1 ) //This check is basically taking place inside of the Vector.cpp which will always check the bounds of validity
	//{
		return sieve.return_from(ith); //Therefore all that's needed is this return statement
	//}
	
	//else
	//{
		//return 0;
	//}
}


/*
*  Function: number_of _primes
*  Purpose: This function will return how many primes are in the list of primes
*  
*/
unsigned int Sieve::number_of_primes()const
{
	return sieve.get_count();
}


/*
*  Function: prime_factorization
*  Purpose: This function will return a vector of primes that make up the prime factorization for 
*  the given starting number.
*/
Vector< unsigned int > Sieve::prime_factorization()const
{
	int start1 = start; //since start is a constant we have to use another variable with the same value in order to "alter" its value.
	Vector<unsigned int> temp; //a temp vector created to hold the prime factorization of the starting number. 
	for(int i = 0; i < sieve.get_count(); i++)
	{
		while(start1 % sieve.return_from(i) == 0)//If the starting number is divisible by the the prime at location(i)
		{
			start1 = start1/sieve.return_from(i); //changes the previous value of the start and the prime number used is stored in the temp.
			
			temp.insert(sieve.return_from(i));	
		}
			
	}
	
	if(temp.get_count() == 0) //If there is nothing stored inside temp, then the starting number must have been a prime number to begin with.
	{
		temp.insert(start1);
	}
	
	
		return temp;
}

