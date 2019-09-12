#ifndef STACK_HPP
 #define STACK_HPP
 
 #include <stdexcept>
 #include "Node.hpp"
 
 template<typename T>
 class Stack
 {
 private:
   Node<T>* headPtr; // Pointer to first node
   int currentSize;         // Current depth of the stack
   
 public:
   Stack();
   Stack(const Stack& rhs );
   Stack& operator=(Stack rhs);
   int size() const;
   bool isEmpty() const;
   bool push(const T& newItem);
   bool pop();
   T peek() const throw(std::range_error);
   void clear();
   void swap(Stack<T>& x, Stack<T>& y);
   virtual ~Stack();
 }; // end Stack
 
 #include "Stack.cpp"
 #endif