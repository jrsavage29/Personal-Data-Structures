/*
*  Purpose for program:
*  For this project we are creating class methods for a provided header file.
*  The program will accept ingredients for a Recipe and store them into a BST of class Ingredient called list.
*  It will also have a string that can store the steps for the recipe. A class called Ingredient
*  is used to store the information about the ingredient used in this class.
*  
*
*  Programmer: Jamahl Savage
*  Date: Dec 5, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "Recipe.h"

/*
*  Function: Recipe
*  Purpose: This is the constructor for the Recipe class. It will initialize the
*  2 private data fields steps and name.
*  
*  steps - this is a string that indicates how to make the recipe.
*  name -  this is the name of the recipe
*
*/
Recipe::Recipe(	) : steps(""), name("") 
{
	
}
	

/*
*  Function: add_ingredient
*  Purpose: This is used for adding ingredients to the list of ingredients
*  
*  
*  i - the Ingredient object to be added to the list
*  
*/	
bool Recipe::add_ingredient(Ingredient i)	
{
	return list.insert(i);
}


/*
*  Function: remove_ingredient
*  Purpose: This function will attempt to remove the ingredient from the Recipe's list
*  of ingredients. If the ingredient is found, then it is removed and returned, else the default ingredient is returned.
*  
*  i - the Ingredient to be removed from the Recipe
*   
*/
Ingredient Recipe::remove_ingredient(Ingredient i)	
{
	return list.remove(i);
}


/*
*  Function: show_recipe
*  Purpose: This function is used to display the list of ingredients and then the steps 
*  to make the recipe 
*  
*  out - the ostream to use to output the recipe
*  
*/
void Recipe::show_recipe(std::ostream & out)const
{
	out << list;
}


/*
*  Function: operator<<
*  Purpose: This used to display the list of ingredients and then the steps to make the recipe. 
*  
*  
*  out - the ostream to use to output the recipe
*  r - the recipe to display
*/
std::ostream& operator<<(std::ostream & out, const Recipe & r)		
{
	r.show_recipe(out);
	return out;
}


/*
*  Function: update_steps
*  Purpose: This will update the steps for the recipe to the new given steps 
*  
*  
*  new_steps - the new steps to follow to create the recipe
*  
*/
void Recipe::update_steps(string new_steps)	
{
	steps = new_steps;
}


/*
*  Function: get_steps
*  Purpose: This will return the current steps for the recipe 
*  
*  
*  
*  
*/
string Recipe::get_steps( )const
{
	return steps;
}


/*
*  Function: get_ingredient
*  Purpose: This will find and return the given ingredient from the list of ingredients 
*  
*  
*  i - the ingredient to be found in the list of ingredients
*  
*/
Ingredient Recipe::get_ingredient(Ingredient i)	const
{
	return list.find(i);
}


/*
*  Function: get_ingredient_count
*  Purpose:  This will return how many ingredients are currently in the list of ingredients
*  
*  
*  
*/
int Recipe::get_ingredient_count( )const
{
	return list.numberofNodes();
}


/*
*  Function: get_name
*  Purpose: This will get the current name of the recipe 
*  
*  
*  
*  
*/
string Recipe::get_name( )const 
{
	return name;
}


/*
*  Function: update_name
*  Purpose: This will update the name of the recipe to the given new_name
*  
*  
*  new_name - the new name for the recipe
*  
*/
void Recipe::update_name(string new_name)
{
	name = new_name;
}