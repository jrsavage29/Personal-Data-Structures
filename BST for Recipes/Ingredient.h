 #ifndef INGREDIENT_H
 #define INGREDIENT_H
 
 #include <string>
 #include <iostream>
 
 using std::string;
 
 class Ingredient
 {
 private:
     string name;
     double amount;
     string measure;
 public:
 
     Ingredient();
 
     void update_name( string new_name );
     void update_amount( double new_amount );
     void update_measure( string new_measure );
 
     string get_name() const;
 
     double get_amount() const;
 
     string get_measure() const;
 
     void display( std::ostream &out ) const;
 
     friend std::ostream& operator<<( std::ostream &out, const Ingredient& i );
 
     bool operator<( const Ingredient& rhs ) const;
     bool operator>( const Ingredient& rhs ) const;
     bool operator==( const Ingredient& rhs ) const;
 };
 
	
 #endif