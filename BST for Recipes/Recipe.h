#ifndef RECIPE_H
 #define RECIPE_H
 
 #include "Ingredient.h"
 #include "BST.hpp"
 
 class Recipe
 {
 private:
     BST<Ingredient> list;//this is the list of ingredients, stored in a bst and indexed from the name
     string steps; //this is a string that indicates how to make the recipe.
     string name; //this is the name of the recipe
 
 public:
 
     Recipe();
 
     bool add_ingredient( Ingredient i );
 
     Ingredient remove_ingredient( Ingredient i );
 
     void show_recipe( std::ostream &out ) const;
 
     friend std::ostream& operator<<( std::ostream &out, const Recipe& r );
     void update_steps( string new_steps );
 
     string get_steps() const;
 
     Ingredient get_ingredient( Ingredient i ) const;
 
     int get_ingredient_count() const;
 
     string get_name() const;
 
     void update_name( string new_name );
     
 };

 #endif
