#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>
#include <ostream>
#ifndef TERM_H
#define TERM_H
 
class Term
{
	private: 
		double coefficient;
		int power;
		
	public:
		Term(double coefficient = 0, int power = 0);
		double get_coefficient() const;
		int get_power() const;
		friend std::ostream & operator<< (std::ostream &out, const Term &t);
		
};
 
 #endif
 // 3x^2 is a term
 // Term t(1,0);
 //cout << t -> //=1
 
 //Term t(2,0)
 //cout << t; //=2
 
 //ostream& operator<< (ostream& out, const Term &t)
 //{
	 //stuff
	 //return out;
 //} //THIS ALLOWS ME TO DO cout << t1 << t2;