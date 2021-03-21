#ifndef VECTOR_HPP
 #define VECTOR_HPP
 //Chapter 3 (Array Based bag) and Chapter 9 (Ordered list)
 template <typename T>
 class Vector
 {
 private:
     int size;//this is meant to be capacity, or how much it can hold
     int count;//this is meant to be how much it currently is holding
     T *storage;//this is the array, or rather the pointer to the array
 
     void grow();//used for making the array larger
 
     void make_hole( int location );//used to make a hole at the given position
     void cover_up( int location );
 public:
     Vector();
     ~Vector();
 
     Vector( const Vector& v );
     const Vector& operator=( const Vector& v );
 
     bool contains( T find_me ) const;
     bool insert( T add_me );
     bool insert_at( T add_me, int location );
     T remove_from( int location );
     T return_from( int location ) const;
 
     int get_count() const;
 
 };
 
 //either write your implementation here
 //or #include your cpp file here
 #include "Vector.cpp"
 #endif
