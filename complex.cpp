 #include "complex.hpp"

Complex::Complex()
{
	real = 1;
	imaginary = 1;
}

Complex::Complex(double real, double imaginary)
{
	this-> real = real;
	this-> imaginary = imaginary;
}

Complex Complex::add(const Complex &rhs)const
{
	Complex Add;
	Add.real = real + rhs.real;
	Add.imaginary = imaginary + rhs.imaginary;
	
	return Add;
	
}

bool Complex::equal(const Complex &rhs)const
{
	if (real == rhs.real && imaginary == rhs.imaginary)
	{
		return true;
	}
	
	else
		return false;
}

double Complex::getImaginary()const
{
	return imaginary;
}

double Complex::getReal()const
{
	return real;
}

Complex Complex::multiply(const Complex &rhs)const
{
	Complex Multi;
	Multi.real = (real * rhs.real) -(imaginary * rhs.imaginary);
	Multi.imaginary = (real * rhs.imaginary) + (rhs.real * imaginary);
	
	return Multi;
}

void Complex::output(std::ostream &out)const
{
	out << real <<" + " << imaginary << "i" << endl;
}

void Complex::setImaginary(double imaginary)
{
	this-> imaginary = imaginary;
}

void Complex::setReal(double real)
{
	this-> real = real;
}