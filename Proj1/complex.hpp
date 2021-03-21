#ifndef COMPLEX_HPP
 #define COMPLEX_HPP
	
	#include <iostream>
	#include <fstream>
	#include <cmath>
	
	using std::ostream;
	using std::endl;
	
class Complex
{
	private:
		double real;
		double imaginary;
		
	public:
		Complex();
		Complex(double real, double imaginary);
		
		double getReal() const;
		double getImaginary() const;
		void setReal(double newReal);
		void setImaginary(double newImaginary);
		bool equal(const Complex &rhs) const;
		Complex add(const Complex &rhs) const;
		Complex multiply(const Complex &rhs) const;
		void output(std::ostream &out) const;
};

#endif
