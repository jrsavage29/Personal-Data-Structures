 #ifndef SIEVE_HPP
 #define SIEVE_HPP
 
 #include "Vector.hpp"
 class Sieve
 {
 private:
     Vector<unsigned int> sieve;
     unsigned int start;
     void factor( int starting_loc );
 public:
 
     Sieve( int n=10000 );
 
     unsigned int ith_prime( int ith ) const;
 
     unsigned int number_of_primes() const;
 
     Vector<unsigned int> prime_factorization() const;
 };
 
 #endif
