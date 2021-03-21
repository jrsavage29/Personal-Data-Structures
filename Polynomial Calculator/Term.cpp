#include "Term.hpp"

Term::Term(double coefficient, int power)//This is the constructor. It sets the coefficient and power to the given values. It will default to using 0,0 if no input for the coefficient or power are given.
{
	this->coefficient = coefficient;
	this->power = power;
}

double Term:: get_coefficient() const //returns the value stored in coefficient of a term
{
		return coefficient;
}

int Term:: get_power() const //returns the value stored in power of a term
{
		return power;
}

std::ostream & operator<< (std::ostream &out, const Term &t) //This a friend function. Used in addition to the Polynomial class's overloaded operator<< to properly display polynomials.
{
	if( t.power != 0 && t.power != 1)
	{
		if( t.coefficient == 0 )
		{
			out << "";
		}
		
		else if( t.coefficient == 1 )
		{
			out <<"x^" << t.power;
		}
		
		else if( t.coefficient == -1 )
		{
			out <<"-x^" << t.power;
		}
		
		else
		{
			out << t.coefficient <<"x^"<< t.power;
		}
	}
	
	else if( t.power == 1)
	{
		if( t.coefficient == 0 )
		{
			out << "";
		}
		
		else if( t.coefficient == 1 )
		{
			out <<"x";
		}
		
		else if( t.coefficient == -1 )
		{
			out <<"-x";
		}
		
		else
		{
			out << t.coefficient <<"x";
		}
	}
	
	else if( t.power == 0)
	{
		
		
		if( t.coefficient == 0 )
		{
			out << "";
		}
		
		
		else
		{
			out << t.coefficient <<"";
		}
	}
	
	return out;
	//if coefficient is 0, don't output anything or just don't insert it.
}