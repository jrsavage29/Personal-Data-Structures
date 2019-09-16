#ifndef BST_H
 #define BST_H
 
 #include <iostream>
 #include <iomanip>
 #include <algorithm>
 #include "Node.hpp"
 using std::max;
 using std::setw;
 
 //This is here to allow the friend of the template
 template <typename T>
 class BST;
 
 //This is here so we can add it to the class declaration
 template <typename T>
 std::ostream& operator<<( std::ostream& out, const BST<T>& tree ) ;
 
 template <typename T>
 class BST
 {
 private:
     enum Direction { RIGHT, LEFT, NONE };
     Node<T>* root;
 
     Node<T>* copy_helper( Node<T>* sub_root );
 
     void clear_helper( Node<T>* sub_root );
     Node<T>* insert_helper( Node<T>* sub_root, T data );
     T find_helper( Node<T>* sub_root, T data ) const;
     bool contains_helper( Node<T>* sub_root, T data ) const;
     Node<T>* remove_helper( Node<T>* sub_root, T &data );
     Node<T>* remove_node( Node<T>* sub_root );
     Node<T>* find_target( Node<T>* sub_root );
     void display_helper( Node<T>* sub_root, int level, std::ostream &out, Direction d ) const;
 
     int height_helper( Node<T>* sub_root ) const;
	 
	 int numberofNodes_helper( Node<T>* sub_root );
	 
	 
	 
 public:
     BST();
     BST( const BST& b );
     BST& operator=( BST b );
     void swap( BST& lhs, BST& right );
 
     ~BST();
 
     void clear();
 
     bool insert( T data );
 
     T find( T data ) const;
     bool contains( T data ) const;
     T remove( T data );
 
     friend std::ostream& operator<< <>( std::ostream& out, const BST& tree );//WHY DO I NEED TO PUT <>???
 
     int height() const;
	 
	 int numberofNodes();
 
 };
 
 
 
template<typename T> 
Node<T>* BST<T>:: copy_helper( Node<T>* sub_root )
{
	Node<T>* newTreePtr = nullptr;
	
	//Copy tree nodes during a preorder traversal
	if(sub_root != nullptr)
	{
		newTreePtr = new Node<T> (sub_root -> get_item()); //copy node
		newTreePtr -> set_left(copy_helper(sub_root -> get_left()));
		newTreePtr -> set_right(copy_helper(sub_root -> get_right()));
	}
	 //Else tree is empty (newTreePtr is nullptr)
	return newTreePtr;
}


template<typename T>
void BST<T>:: clear_helper( Node<T>* sub_root )
{
	if(sub_root != nullptr)
	{
		clear_helper(sub_root -> get_left());
		clear_helper(sub_root -> get_right()); 
		delete sub_root;
		
	}
}


template<typename T>
Node<T>* BST<T>:: insert_helper( Node<T>* sub_root, T data )
{
	Node<T>* temp = nullptr;
	if ( sub_root == nullptr )
	{
		temp = new Node<T>(data);
		return temp;
	}
	
	else if ( data < sub_root-> get_item() )
	{
		sub_root-> set_left( insert_helper( sub_root-> get_left(), data ) );
	}
	
	else 
	{
		sub_root -> set_right( insert_helper( sub_root-> get_right(), data ) );
	}
	
	return sub_root;
}


template<typename T>
T BST<T>:: find_helper( Node<T>* sub_root, T data ) const
{
	
if(sub_root != nullptr)
	{
            
        if( data < sub_root -> get_item() )
		{
           return find_helper(sub_root-> get_left(), data );
		}
		
        else if( data > sub_root -> get_item() )
		{
           return find_helper( sub_root-> get_right(), data );
		}
		
		else if(data == sub_root -> get_item() )
		{
			return data;
		}
	}
	
	 // no matching node was found
	else if(sub_root == nullptr)
	{
		return T();
	}
	
	return data;
}


template<typename T>
bool BST<T>:: contains_helper( Node<T>* sub_root, T data ) const
{
	if(sub_root != nullptr)
	{
        
		if(data == sub_root -> get_item() )
		{
			return true;
		}
		
        else if( data < sub_root -> get_item() )
		{
           return contains_helper(sub_root-> get_left(), data );
		}
		
        else if( data > sub_root -> get_item() )
		{
            return contains_helper( sub_root-> get_right(), data );
		}

	}
	
	 // no matching node was found
	else if(sub_root == nullptr)
	{
		return false;
	}
	
	return true;
}


template<typename T>
Node<T>* BST<T>:: remove_helper( Node<T>* sub_root, T &data )
{
	if (sub_root != nullptr)
	{		
	
		if( data < sub_root -> get_item() )
		{
			sub_root-> set_left( remove_helper( sub_root-> get_left(), data ) );
		}
			
		else if( data > sub_root -> get_item() )
		{
			sub_root -> set_right( remove_helper( sub_root-> get_right(), data ) );
		}
		
		else if(data == sub_root -> get_item() )
		{
			return remove_node(sub_root);
		}
		
		else
		{
			return T();
		}
	}
	
	return sub_root;
}


template<typename T>
Node<T>* BST<T>:: remove_node( Node<T>* sub_root ) //Can use look ahead syntax since you're done moving and just looking to see if it has children
{
	//if(sub_root -> get_left() == nullptr || sub_root -> get_right() == nullptr )
	//{	
		//Node with only one child or no child
		
		if(sub_root -> get_left() == nullptr)
		{
			Node<T>* deleteNode = sub_root -> get_right();
			//free(sub_root);
			//return deleteNode;
			
			delete sub_root;
			sub_root = nullptr;
			return deleteNode;
		}

		else if(sub_root -> get_right() == nullptr )
		{
			Node<T>* deleteNode = sub_root -> get_left();
			//free(sub_root);
			//return deleteNode;
			
			delete sub_root;
			sub_root = nullptr;
			return deleteNode;
		}
		
		 // node with two children: Get the inorder successor (smallest 
        // in the right subtree)
		Node<T>* deleteNode = find_target( sub_root -> get_right() );
		
		//Copy the inorder successor's content to this node 
		sub_root -> set_item( deleteNode -> get_item() );
		
		// Delete the inorder successor
		T messdata = deleteNode -> get_item();
		sub_root -> set_right( remove_helper(sub_root -> get_right(), messdata ) );
	//}
	
	return sub_root;
}


/* Given a non-empty binary search tree, return the node with minimum 
   value found in the tree. The entire tree does not 
   need to be searched. */
template<typename T>
Node<T>* BST<T>:: find_target( Node<T>* sub_root )//Go right once and then all the way left. If no left node then update with the right side node.
{
	Node<T>* current = sub_root; 
  
    //loop down to find the leftmost leaf in the right subtree
	
    while(current->get_left() != nullptr) 
	{
        current = current->get_left(); 
	}
	
    return current; 
}


template<typename T>
void BST<T>:: display_helper( Node<T>* sub_root, int level, std::ostream &out, Direction d ) const
{
	 if ( sub_root != nullptr )
        {
                display_helper( sub_root->get_right(), level+1,  out, RIGHT);

                out << std::setw(5*level);

                if ( d == RIGHT )
                        out <<  "/";// << endl;
                else if ( d == LEFT )
                        out <<  "\\";// << endl;
                else
                        out <<  "-";

                out << sub_root->get_item();
                out << std::endl;

                display_helper( sub_root->get_left(), level+1,  out, LEFT);
        }
}


template<typename T>
int BST<T>:: height_helper( Node<T>* sub_root ) const
{
	if(sub_root == nullptr)
	{
		return 0;
	}
	
	else
	{
		return 1 + max(height_helper(sub_root -> get_left()), height_helper(sub_root -> get_right()));
	}
}


template<typename T>
int BST<T>:: numberofNodes_helper( Node<T>* sub_root )
{
	if (sub_root == nullptr) 
	{
       return 0; 
	}
	
   return numberofNodes_helper( sub_root -> get_left() ) + numberofNodes_helper( sub_root -> get_right() ) + 1; 
}


template<typename T>
BST<T>:: BST() : root(nullptr)
{
	
}


template<typename T>
BST<T>:: BST( const BST& b )
{
	root = copy_helper(b.root);
}


template<typename T>
BST<T>& BST<T>:: operator=( BST<T> b )
{
	swap(*this, b);
	
	return *this;
}


template<typename T>
void BST<T>:: swap( BST& lhs, BST& right )
{
	std::swap(lhs.root, right.root);
}


template<typename T>
BST<T>:: ~BST()
{
	clear();
}
 
 
template<typename T>
void BST<T>:: clear()
{
	clear_helper(root);
	root = nullptr;
}


template<typename T>
bool BST<T>:: insert( T data )
{
	root = insert_helper(root, data);
	return true;
}


template<typename T>
T BST<T>:: find( T data ) const
{
	return find_helper(root, data);
}


template<typename T>
bool BST<T>:: contains( T data ) const
{
	return contains_helper(root, data );
}


template<typename T>
T BST<T>:: remove( T data ) 
{
	root = remove_helper(root, data);
	return data;
}


template<typename T>
std::ostream& operator<<( std::ostream& out, const BST<T>& tree ) 
{
		int level = 0;
        tree.display_helper( tree.root, level, out, tree.NONE );
		return out;
}


template<typename T>
int BST<T>:: height() const
{
	return height_helper(root);
}


template<typename T>
int BST<T>:: numberofNodes() 
{	
	return numberofNodes_helper(root);
}


#endif
