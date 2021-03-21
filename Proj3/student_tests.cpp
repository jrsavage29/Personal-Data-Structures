#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include "catch.hpp"
#include "region_grower.hpp"
#include <string>
using std::string;
/*TEST_CASE( "Testing Image creation and comparing it with sample") 
{
	RegionGrower r;

  //set the background: green
  r.SetImage(std::string("hokie.png"));
  r.SetSeed(0,0);
  r.SetReplacement(88, 96, 26);
  r.Update();
  r.GetOutput(std::string("hokie_bg.png"));

  //set the chest: blue
  r.SetImage(std::string("hokie_bg.png"));
  r.SetSeed(350,350);
  r.SetReplacement(10, 35, 63);
  r.Update();
  r.GetOutput(std::string("hokie_chest.png"));

  //set the legs: metallic gold
  r.SetImage(std::string("hokie_chest.png"));
  r.SetSeed(350,450);
  r.SetReplacement(176, 144, 67);
  r.Update();
  r.GetOutput(std::string("hokie_legs.png"));

  //set the head:  gold
  r.SetImage(std::string("hokie_legs.png"));
  r.SetSeed(125,315);
  r.SetReplacement(201, 151, 44);
  r.Update();
  r.GetOutput(std::string("hokie_cool_test.png"));
  
  Image<Pixel> testAgainst = readFromFile("hokie_cool.png");
  Image<Pixel> mine = readFromFile("hokie_cool_test.png");

    for (unsigned int i = 0; i < testAgainst.height(); i++)
	{
        for(unsigned int j = 0; j < testAgainst.width(); j++)
		{
            REQUIRE( testAgainst(j,i) == mine(j,i) );
		}
	}
}*/

TEST_CASE( "Testing Image input throwing") 
{
	RegionGrower r;
	REQUIRE( r.SetImage(std::string("beamer_celebration.png")) == false );
	REQUIRE( r.SetSeed(0,0) == false);
	REQUIRE( r.SetReplacement(200, 151, 44) == true );
}

TEST_CASE( "Testing set seed throwing") 
{
	RegionGrower r;
	r.SetImage(std::string("hokie.png"));
	REQUIRE( r.SetSeed(-1,0) == false);
}

TEST_CASE( "Testing set seed throwing 2") 
{
	RegionGrower r;
	r.SetImage(std::string("hokie.png"));
	REQUIRE( r.SetSeed(-1,-1) == false);
}


TEST_CASE( "Testing set seed throwing 3") 
{
	RegionGrower r;
	r.SetImage(std::string("hokie.png"));
	REQUIRE( r.SetSeed(800,800) == false);
}

TEST_CASE( "Testing set Replacement throwing") 
{
	
	RegionGrower r;
	r.SetImage(std::string("hokie.png"));
	r.SetSeed(0,0);
	REQUIRE( r.SetReplacement(255, 151, 44) == false );
}

TEST_CASE( "Testing set Replacement throwing 2") 
{
	RegionGrower r;
	r.SetImage(std::string("hokie.png"));
	r.SetSeed(0,0);
	REQUIRE( r.SetReplacement(143, -1, 44) == false);
}

/*TEST_CASE( "Testing GetOutput throwing ") 
{
	RegionGrower r;
	REQUIRE( r.SetImage(std::string("hokie.png")) == false );
	r.SetSeed(350,350);
	r.SetReplacement(10, 35, 63);
	r.Update();
	//REQUIRE( r.GetOutput(std::string("Hokie failure.docx")) == false );
	REQUIRE( r.GetOutput(std::string("Hokie failure.docx"))== false );
}*/
