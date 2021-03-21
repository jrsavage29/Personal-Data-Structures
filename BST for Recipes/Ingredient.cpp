#include "Ingredient.h"

Ingredient::Ingredient(	) : name(""), amount(0), measure("")
{

}	
 
 
void Ingredient::update_name(string new_name)
{
	name = new_name;
}	


void Ingredient::update_amount(double new_amount)
{
	amount = new_amount;
}

	
void Ingredient::update_measure(string new_measure)
{
	measure = new_measure;
}


string Ingredient::get_name( )const
{
	return name;
}


double Ingredient::get_amount( )const
{
	return amount;
}


string Ingredient::get_measure(	)const
{
	return measure;
}


void Ingredient::display(std::ostream & out)const
{
	out<< amount <<"\t"<< measure <<"\t"<< name;
}


std::ostream& operator<<( std::ostream &out, const Ingredient& i )
{
	i.display(out);
	return out;
}


bool Ingredient::operator<(const Ingredient & rhs)const
{
	return this->name < rhs.name;
}


bool Ingredient::operator>(const Ingredient & rhs)const
{
	return this->name > rhs.name;
}

bool Ingredient::operator==(const Ingredient & rhs	)const
{
	return this->name == rhs.name;
}


	