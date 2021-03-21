#include "Term.hpp"

 
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
 
class Polynomial
{
	private:
    LinkedList<Term> term;
     
	public:
	Polynomial();
    void insert_term (Term term_to_insert);
 
	Polynomial operator+ (const Polynomial &rhs);
 
	Polynomial operator* (const Polynomial &rhs);
 
	Polynomial operator- (const Polynomial &rhs);
 
	Polynomial operator/ (const Polynomial &rhs);

	Polynomial operator% (const Polynomial &rhs);
	
	friend std::ostream& operator<< (std::ostream &out, const Polynomial &p);
	 
};
 
 #endif
 //if empty just insert the term
 //if something is in there check for the degree using a loop
 //combine the coefficients if they are of like terms when inserting
 //3x^3+2x try inserting 2x^2. Then use replace to switch the order.
 //If a polynomial has no terms it should output 0;