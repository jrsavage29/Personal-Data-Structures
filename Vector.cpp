
template <typename T>
Vector<T>::Vector()
{
	size = 10;
	count = 0;
	storage = new T[size];
}

template <typename T>
Vector<T>::~Vector()
{
	delete [] storage;
	storage = nullptr;
}

template <typename T>
void Vector<T>::grow()
{
	T * temp = storage; //create temp pointer to old full array
	size = size * 2; //double the size
	storage = new T[size]; //allocate new array
	
	for(int i = 0; i < count; i++)//copy elements from old cramped array into new array
	{
		storage[i] = temp[i];
	}
	
	delete [] temp;// delete old full array
	
	temp = nullptr;// null out temo
}

template <typename T>
void Vector<T>::make_hole(int location)//places a place holder 0 to make a "hole" for the value to inserted
{
	
	for(int i = count -1; i >= location; i--)
	{
		storage[i+1]= storage[i];
	}
	
}

template <typename T>
void Vector<T>::cover_up(int location)
{
	
	for(int i = location; i <= count -1; i++)
		{
			storage[i] = storage[i+1];
		}
}



template <typename T>
Vector<T>::Vector(const Vector& v)
{
	size = v.size;
	count = v.count;
	storage = new T[size];
	
	for(int i =0; i < count; i++)
	{
		storage[i] = v.storage[i];
	}
}

template <typename T>
const Vector<T> &Vector <T>::operator = (const Vector& v)
{
	//check for self assignment
	if( this != &v)
	{
		delete [] storage;
	//copy the regular data
	size = v.size;
	count = v.count;
	//copy the dynamic data
	storage = new T[size];
	for (int i = 0; i < count; i++)
		storage[i] = v.storage[i];
	}
	return *this; //dereference to return object not the pointer to the object.
}



template <typename T>
bool Vector<T>::contains(T find_me)const
{
	bool itHere = false;
	for(int i = 0; i < count; i++)
	{
		if(storage[i] == find_me)
		{
			itHere = true;
		}
	}
	
	return itHere;
}

template <typename T>
bool Vector<T>::insert(T add_me)
{
	
	if(count == size )
	{
		grow();
	}
	
	storage[count] = add_me;
	count++;
	
	return true;
}

template <typename T>
bool Vector<T>::insert_at(T add_me, int location)
{
	
	bool imAdded = false;
	int lastIndex = count -1;
	if(count == size)
	{
		grow();
	}
	
	if(location <= 0)
	{
		make_hole(0);
		storage[0] = add_me;
		count++;
		imAdded = true;
		
	}
	
	if( location >= lastIndex + 1)
	{
		storage[lastIndex + 1] = add_me;
		count++;
		imAdded = true;

	}
	
	else if(location > 0 && location < lastIndex + 1 && imAdded == false)
	{
		make_hole(location);
		count++;
		storage[location] = add_me;
		imAdded = true;
	
	}
	
	return imAdded;
}

template <typename T>
T Vector<T>::remove_from(int location)
{
	
	int lastIndex = count - 1;
	
	if(location >= 0 && location == lastIndex)
	{
		T temp = storage[location];
		count--;
		
		return temp;
	}
	
	if(location >= 0 && location < lastIndex)
	{
		T temp = storage[location];
		cover_up(location);
		count--;
		
		return temp;
	}
	
	else if (count == 0)
	{
		
		return T();
	}
	
	else
	{
		
		return T();
	}
}

template <typename T>
T Vector<T>::return_from(int location)const
{
	
	int lastIndex = count-1;
	if(location >= 0 && location <= lastIndex)
	{
		return storage[location];
	}
	
	else if (count == 0)
	{
		return T();
	}
	
	else
	{
		return T();
	}
}

template <typename T>
int Vector<T>::get_count()const
{
	
	return count;
}

