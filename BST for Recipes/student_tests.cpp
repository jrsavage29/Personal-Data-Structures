#define CATCH_CONFIG_MAIN

#include <cstdlib>
#include <ctime>
#include "catch.hpp"
#include <memory>
#include "Recipe.h"
#include <iostream>
#include <fstream>
#include <ostream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;


TEST_CASE( "Test construction and add ingredient" )
{
	Recipe Cake;
	Ingredient A;
	Ingredient B;
	Ingredient C;
	Ingredient D;
	
	A.update_name("egg");
	A.update_amount(5);
	A.update_measure("whole");
	
	B.update_name("sugar");
	B.update_amount(2);
	B.update_measure("cup");
	
	C.update_name("spice");
	C.update_amount(7);
	C.update_measure("cup");
	
	D.update_name("everything nice");
	D.update_amount(1);
	D.update_measure("gallon");
	
	REQUIRE(Cake.add_ingredient(A));
	REQUIRE(Cake.add_ingredient(B));
	REQUIRE(Cake.add_ingredient(C));
	REQUIRE(Cake.add_ingredient(D));
	
	//cout<<Cake;
	
	
	
}

TEST_CASE( "Test remove ingredient " )
{
	Recipe Cake;
	Ingredient A;
	Ingredient B;
	Ingredient C;
	Ingredient D;
	
	A.update_name("egg");
	A.update_amount(5);
	A.update_measure("whole");
	
	B.update_name("sugar");
	B.update_amount(2);
	B.update_measure("cup");
	
	C.update_name("spice");
	C.update_amount(7);
	C.update_measure("cup");
	
	D.update_name("everything nice");
	D.update_amount(1);
	D.update_measure("gallon");
	
	REQUIRE(Cake.add_ingredient(A));
	REQUIRE(Cake.add_ingredient(B));
	REQUIRE(Cake.add_ingredient(C));
	REQUIRE(Cake.add_ingredient(D));
	
	//cout<<Cake;
	//cout<< endl;
	//cout<<endl;
	
	REQUIRE(Cake.remove_ingredient(D) == D);
	
	//cout<<Cake;
	//cout<< endl;
	//cout<<endl;
	
	REQUIRE(Cake.remove_ingredient(A) == A);
	
	//cout<<Cake;
	
}

TEST_CASE( "Test get ingredient count" )
{
	Recipe Cake;
	Ingredient A;
	Ingredient B;
	Ingredient C;
	Ingredient D;
	
	A.update_name("egg");
	A.update_amount(5);
	A.update_measure("whole");
	
	B.update_name("sugar");
	B.update_amount(2);
	B.update_measure("cup");
	
	C.update_name("spice");
	C.update_amount(7);
	C.update_measure("cup");
	
	D.update_name("everything nice");
	D.update_amount(1);
	D.update_measure("gallon");
	
	REQUIRE(Cake.add_ingredient(A));
	REQUIRE(Cake.add_ingredient(B));
	REQUIRE(Cake.add_ingredient(C));
	REQUIRE(Cake.add_ingredient(D));
	REQUIRE(Cake.get_ingredient_count() == 4);
	//cout<<Cake;
	//cout<< endl;
	//cout<<endl;
	
	REQUIRE(Cake.remove_ingredient(D) == D);
	REQUIRE(Cake.get_ingredient_count() == 3);
	//cout<<Cake;
	//cout<< endl;
	//cout<<endl;
	
	REQUIRE(Cake.remove_ingredient(A) == A);
	REQUIRE(Cake.get_ingredient_count() == 2);
	//cout<<Cake;
}

TEST_CASE( "Test update steps, update name, get steps, and get name " )
{
	Recipe Bake;
	Bake.update_name("Cake");
	Bake.update_steps("Add 5 whole eggs, 2 cups of sugar, 7 cups of spice, and 1 gallon of everything nice!");
	Ingredient A;
	Ingredient B;
	Ingredient C;
	Ingredient D;
	
	A.update_name("egg");
	A.update_amount(5);
	A.update_measure("whole");
	
	B.update_name("sugar");
	B.update_amount(2);
	B.update_measure("cup");
	
	C.update_name("spice");
	C.update_amount(7);
	C.update_measure("cup");
	
	D.update_name("everything nice");
	D.update_amount(1);
	D.update_measure("gallon");
	
	REQUIRE(Bake.add_ingredient(A));
	REQUIRE(Bake.add_ingredient(B));
	REQUIRE(Bake.add_ingredient(C));
	REQUIRE(Bake.add_ingredient(D));
	
	REQUIRE(Bake.get_name() == "Cake");
	REQUIRE(Bake.get_steps() == "Add 5 whole eggs, 2 cups of sugar, 7 cups of spice, and 1 gallon of everything nice!");
	
}

TEST_CASE( "Test getting ingredient and more!" )
{
	Recipe Bake;
	Bake.update_name("Cake");
	Bake.update_steps("Add 5 whole eggs, 2 cups of sugar, 7 cups of spice, and 1 gallon of everything nice!");
	Ingredient A;
	Ingredient B;
	Ingredient C;
	Ingredient D;
	Ingredient E;
	Ingredient F;
	
	A.update_name("egg");
	A.update_amount(5);
	A.update_measure("whole");
	
	B.update_name("sugar");
	B.update_amount(2);
	B.update_measure("cup");
	
	C.update_name("spice");
	C.update_amount(7);
	C.update_measure("cup");
	
	D.update_name("everything nice");
	D.update_amount(1);
	D.update_measure("gallon");
	
	E.update_name("Underwear");
	E.update_amount(12);
	E.update_measure("packs");
	
	F.update_name("Marshmellows");
	F.update_amount(6);
	F.update_measure("bags");
	
	REQUIRE(Bake.add_ingredient(A));
	REQUIRE(Bake.add_ingredient(B));
	REQUIRE(Bake.add_ingredient(C));
	REQUIRE(Bake.add_ingredient(D));
	
	REQUIRE(Bake.get_name() == "Cake");
	REQUIRE(Bake.get_steps() == "Add 5 whole eggs, 2 cups of sugar, 7 cups of spice, and 1 gallon of everything nice!");
	
	REQUIRE(Bake.get_ingredient(E) == Ingredient());
	REQUIRE_FALSE(Bake.get_ingredient(B) == Ingredient());
	
	Bake.update_name("Nasty Cake");
	Bake.update_steps("Add 5 whole eggs, 2 cups of sugar, 7 cups of spice, 1 gallon of everything nice, and UNDERWEAR?!");
	REQUIRE(Bake.add_ingredient(E));
	REQUIRE(Bake.get_ingredient_count() == 5);
	
	cout << Bake;
	cout<<endl;
	cout<<endl;
	
	REQUIRE(Bake.add_ingredient(F));
	cout<<Bake;
}

