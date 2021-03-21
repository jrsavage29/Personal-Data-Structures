/*
*  Purpose for program:
*  For this project we are overloading operators in order to perform various operations on polynomials
*  The program will utilize another class named Term which holds a term for a polynomial and stores it in a linked list
*  
*  Programmer: Jamahl Savage
*  Date: November 4, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "Polynomial.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

/*
*  Function: Polynomial
*  Purpose: The constructor is used to initializes the instances used in the class.
*  It will also set default values if certain criteria for some of the instances are not meet.
*  However, in this case we do not need defaults for anything for all the terms of the polynomial
*  are handled in the Term class.
*  
*/
Polynomial::Polynomial()
{
	
}


/*
*  Function: insert_term
*  Purpose: Used for inserting terms created by the Term class into the Polynomial as a linked list. If the polynomial has like terms
*  they are added together and treated as one term. Having the terms be of the linked list class makes it easier to organize the terms 
*  in the polynomial based of their degrees.
*  
*  term_to_insert - the term from the Term class to be inserted into the polynomial.
*  
*/
void Polynomial:: insert_term (Term term_to_insert)
{
	//cout<<"getLength was: "<<term.getLength()<<endl;
	if(term.getLength() == 0) //if nothing is in the linked list
		term.insert(1, term_to_insert);
	
	else if(term.getLength() > 0) //if there is 1 or more thing in terms
	{
		for( int k = 1; k <= term.getLength(); k++)
		{
			if(term.getEntry(k).get_power() < term_to_insert.get_power()) //if the power of the term at index k is < the term we want to insert
			{
				term.insert(k, term_to_insert); //inserts term_to_insert at index k
				return;
			}
			else if(term.getEntry(k).get_power() == term_to_insert.get_power()) //if found a term with the same power
			{
				Term t(term_to_insert.get_coefficient() + term.getEntry(k).get_coefficient(), term_to_insert.get_power()); //adds the terms and then replaces
				term.replace(k, t);
				return;
			}
			else if(k == term.getLength())
			{
				term.insert(term.getLength() + 1, term_to_insert);
				return;
			}
		}
	}

	
}
 
 /*
*  Function: operator+
*  Purpose: overloads the addition operator so that it adds the terms of a polynomial. It will compare to see which term in each polynomial has either the larger, smaller, or equal degree to each other.
*  If the terms have equal degrees, their coefficients are added and they share the same degree and are therefore treated as one inserted term. If the term in a polynomial is greater than all
*  terms in both polynomials, it is made to be the highest degree of the result polynomial. If terms have equal degrees but their coefficients cancel each other out, they are treated like the constant 0. If
*  a term has a smaller degree than all the terms of both polynomials then it is simply placed at the end of the result polynomial.
*  
*  rhs - the Polynomial on the right hand side of the addition sign to be added to the Polynomial on the left hand side of the addition sign (*this)
*  
*/
Polynomial Polynomial::operator+ (const Polynomial &rhs)
{
	
	Polynomial result;
	Polynomial p1 = *this;

	int p1c = 1;
	int p2c = 1;
	
	
	while( p1c <= p1.term.getLength() && p2c <= rhs.term.getLength() )
	{
		
		if( rhs.term.getEntry(p2c).get_power() > p1.term.getEntry(p1c).get_power() )
		{
		//	cout<<"Polynomial 2's term is greater than Polynomial 1's term so add Polynomial 2 to the list first"<<endl;
			result.insert_term( rhs.term.getEntry(p2c) );
			p2c++;
			
		}
		
		else if( rhs.term.getEntry(p2c).get_power() < p1.term.getEntry(p1c).get_power() )
		{
		//	cout<<"Polynomial 2's term is less than Polynomial 1's term so add Polynomial 1 to the list first "<<endl;
			result.insert_term(p1.term.getEntry(p1c));
			p1c++;
			
		}
		
		else if(p1.term.getEntry(p1c).get_power() == rhs.term.getEntry(p2c).get_power())
		{
		//	cout<<"The terms were equal so I'm adding them and incrementig the count of both"<<endl;
			Term temp(p1.term.getEntry(p1c).get_coefficient() + rhs.term.getEntry(p2c).get_coefficient(), rhs.term.getEntry(p2c).get_power());
			if( temp.get_coefficient() == 0)
			{
				result.insert_term(Term(0,0));
				p2c++;
				p1c++;	
			}
			
			else if( temp.get_coefficient() == 0 && temp.get_power() == 0)
			{

				result.insert_term(Term(0,0));
				p2c++;
				p1c++;	
			}
			
			else
			{
				result.insert_term(temp);
				p2c++;
				p1c++;	
			}
			
					
		}
		
		if( p2c > rhs.term.getLength() && p1c < p1.term.getLength() )
		{
		//	cout<<"There is no value left in polynomial 2 so just add the term from polynomial 1"<<endl;
			result.term.insert(result.term.getLength() + 1, p1.term.getEntry(p1c));
			p1c++;
		}
		
		if( p1c > p1.term.getLength() && p2c < rhs.term.getLength() )
		{
			//cout<<"There is no value left in polynomial 1 so just add the term from polynomial 2"<<endl;
			result.term.insert(result.term.getLength() + 1, rhs.term.getEntry(p2c));
			p2c++;
		}

	}
	
	
	if(p1c <= p1.term.getLength() )
	{
		while( p1c <= p1.term.getLength() )
		{
			result.term.insert(result.term.getLength() + 1, p1.term.getEntry(p1c));
			p1c++;
		}
	}
	
	if(p2c <= rhs.term.getLength() )
	{
		while( p2c <= rhs.term.getLength() )
		{
			result.term.insert(result.term.getLength() + 1, rhs.term.getEntry(p2c));
			p2c++;
		}
	}
	
	return result;
}


/*
*  Function: operator*
*  Purpose: overloads the multiplication operator so that it multiplies the terms of 2 polynomials.
*  The multiplication will foil each term of the lhs polynomial into each term of the rhs polynomial and insert them in
*  in a result polynomial that will reorder the resultant terms in order (which is the greatest benefit to using a linked list). When finished it will return the ordered result polynomial.
*  
*  rhs - the Polynomial on the right hand side of the multiplication sign to be multiplied to the Polynomial on the left hand side of the multiplication sign (*this)
*  
*/ 
Polynomial Polynomial::operator* (const Polynomial &rhs)
{
	
	Polynomial p1 = *this;
	Polynomial p2 = rhs;
	
	int limit = p2.term.getLength() * p1.term.getLength();
	int p1c = 1;
	int p2c = 1;
	
	Polynomial result;
	
	for(int i = 0; i <= limit + 1; i++)
	{
		Term temp;
		if( p2c <= p2.term.getLength() )
		{
			Term temp( p1.term.getEntry(p1c).get_coefficient() * p2.term.getEntry(p2c).get_coefficient(), p1.term.getEntry(p1c).get_power() + p2.term.getEntry(p2c).get_power() );
			result.insert_term(temp);
			//cout <<"The result polynomial is now: "<< result <<endl;
			p2c++;
		}
		
		else
		{
			p1c++;
			p2c = 1;
		}
		
		
	}
	
	
	return result;
}


/*
*  Function: operator-
*  Purpose: overloads the subtraction operator so that it subtracts the terms of 2 polynomials.
*  This method also relies on the use of the functional overloaded addition and multiplication operators
*  for in order to perform subtraction you need to invert the rhs(multiply -1 across the polynomial) and then add it the lhs(regular addition of polynomials)
*  
*  rhs - the Polynomial on the right hand side of the subtraction sign to be subtracted from the Polynomial on the left hand side of the subtraction sign (*this)
*  
*/
Polynomial Polynomial::operator- (const Polynomial &rhs)
{
	Polynomial neg;
	neg.insert_term(Term(-1,0));
	Polynomial p1 = *this;
	Polynomial p2 = rhs;
	
	return ( p2*neg )+p1;
} 


/*
*  Function: operator/
*  Purpose: overloads the division operator so that it divides the terms of 2 polynomials. The way this method works is that it takes the first term
*  of the remainder polynomial r (which starts out equal to the lhs polynomial) and compares it to divisor terms of polynomial d (the rhs polynomial). This will continue to 
*  happen as long as the degree of r remains bigger than the degree of d. After that condition has failed the result of the remainder and division will already calculated and ordered
*  in their respective polynomials and be ready to be returned. In this case only d is returned because this method is for division. 
*  
*  The psuedocode for this can be found using this link: https://en.wikipedia.org/wiki/Polynomial_long_division#Pseudo-code
*  
*  rhs - the Polynomial on the right hand side of the division sign to be divided by the Polynomial on the left hand side of the division sign (*this)
*  
*/
Polynomial Polynomial::operator/ (const Polynomial &rhs)
{
	Polynomial n = *this;
	Polynomial d = rhs;
	Polynomial q;
	Polynomial r = n;
	Polynomial TERM;
	Term temp;
	q.insert_term(Term(0,0));
	
	for(int i = 1; i <= d.term.getLength(); i++ )
	{
		if(d.term.getEntry(i).get_power() < 0)
		{
			throw "The divisor had a term of a negative degree or a degree of 0!";
		}
	}
	
		//cout <<"The coefficient of r is: "<< r.term.getEntry(1).get_coefficient()<<endl;
	while( r.term.getEntry(1).get_coefficient() != 0 && r.term.getEntry(1).get_power() >= d.term.getEntry(1).get_power() )
	{
		//cout<<"The r has a degree of: " << r.term.getEntry(1).get_power() << endl;
		//cout <<"The d has a degree of: "<<d.term.getEntry(1).get_power() <<endl;
		
		Term temp( r.term.getEntry(1).get_coefficient() / d.term.getEntry(1).get_coefficient() , r.term.getEntry(1).get_power() - d.term.getEntry(1).get_power() );
			
		TERM.insert_term(temp); 
		//cout<<"the temp is this value: "<< TERM <<endl;
			
		q = q + TERM; 
		//cout <<"the result of adding q to TERM is: " << q <<endl;
		r = r - d*TERM;
		//cout<<"The remainder is currently: " << r<<endl;
			
		
		int j = TERM.term.getLength();
		
		while( !TERM.term.isEmpty() )
		{
			TERM.term.remove(j);
			j--;
		}
	}
	//cout <<"The coefficient of r for the final time is: "<< r.term.getEntry(1).get_coefficient()<<endl;
	//cout<<"The final quotient result is: " << q <<endl;
	//cout<<"The final remainder is: " << r <<endl;
	//cout<<"I'm done with division bye!!"<<endl;
	return q;
}

/*
*  Function: operator%
*  Purpose: overloads the modulus operator so that it returns the remainder after the division of the two polynomials.
*  Basically the same as division but insead returns the remainder polynomial
*  
*  rhs - the Polynomial on the right hand side of the modulus sign to get the modulus of the Polynomials, with the other Polynomial being on the left hand side of the modulus sign (*this)
*  
*/
Polynomial Polynomial::operator% (const Polynomial &rhs)
{
	Polynomial n = *this;
	Polynomial d = rhs;
	Polynomial q;
	Polynomial r = n;
	Polynomial TERM;
	Term temp;
	q.insert_term(Term(0,0));
	
	for(int i = 1; i <= d.term.getLength(); i++ )
	{
		if(d.term.getEntry(i).get_power() < 0)
		{
			throw "The divisor had a term of a negative degree or a degree of 0!";
		}
	}
	
		
	while( r.term.getEntry(1).get_coefficient() != 0 && r.term.getEntry(1).get_power() >= d.term.getEntry(1).get_power() )
	{
		
		Term temp( r.term.getEntry(1).get_coefficient() / d.term.getEntry(1).get_coefficient() , r.term.getEntry(1).get_power() - d.term.getEntry(1).get_power()  );
			
		TERM.insert_term(temp);
		
			
		q = q + TERM; 
		
		r = r - d*TERM;
		
			
		
		int j = TERM.term.getLength();
		
		while( !TERM.term.isEmpty() )
		{
			TERM.term.remove(j);
			j--;
		}
	}
	
	r = (r+r) - r;
	return r;
}


/*
*  Function: operator<<
*  Purpose: A friend method of the class that will output the given polynomial on the given ostream.
*  It uses the Term's operator<< to output each term in the appropriate fashion a polynomial.
*  
*  out - the ostream to output the polynomial on
*  p - the Polynomial to output
*/	
std::ostream& operator<< (std::ostream &out, const Polynomial &p)
{
	//cout<<"About to cout and getLength is: "<<p.term.getLength()<<endl;
	for(int i=1; i <= p.term.getLength(); i++)
	{
		if(i == 1)
		{
			out << p.term.getEntry(i);
		}
		
		else if(p.term.getEntry(i).get_coefficient() > 0)
		{
			out << "+"<< p.term.getEntry(i);
		}
		
		else
		{
			out << ""<< p.term.getEntry(i);
		}
	}
	return out;
}