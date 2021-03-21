#ifndef NODE_H
#define NODE_H
 
 template <typename T>
 class Node
 {
 private:
     T data;
     Node<T>* Right; //right sub-tree pointer
     Node<T>* Left; //left sub-tree pointer
 
 public:
     Node( T item = T(), Node<T>* right = nullptr, Node<T>* left = nullptr );
 
     T get_item() const;
     Node<T>* get_right() const;
     Node<T>* get_left() const;
 
     void set_item( T item );
 
     void set_right( Node<T>* right );
     void set_left( Node<T>* left );
     
 };




template<typename T>
Node<T>:: Node(T item, Node<T>* right, Node<T>* left) : data(item), Right(right), Left(left)
{
	
}


template<typename T>	
void Node<T>::set_item(T item)
{
	data = item;
}

template<typename T>
void Node<T>:: set_right( Node<T>* right)
{
	Right = right;
}

template<typename T>
void Node<T>::set_left(Node <T>* left)
{
	Left = left;
}

template<typename T>
T Node<T>::get_item() const
{
	return data;
}

template<typename T>
Node<T>* Node<T>::get_right() const
{
	return Right;
}

template<typename T>
Node<T>* Node<T>::get_left() const
{
	return Left;
}



#endif
