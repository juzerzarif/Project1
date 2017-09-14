

template <typename T>
linkedList<T>::linkedList()
{
	m_front= nullptr;
	m_size = 0;
}

template <typename T>
linkedList<T>::~linkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool linkedList<T>::isEmpty() const
{
	//returns true if list is empty
	//returns false otherwise
	if(m_size == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}

}


template <typename T>
int linkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool linkedList<T>::search(T value) const
{
	node<T>* tempNode = m_front; //pointer to headnode //pointer to headnode

	//returns true if the value exists in any node
	//returns false otherwise
	if(m_size == 0)
	{
		return(false);
	}
	else
	{
		do
		{
			if(tempNode -> getValue() == value)
			{
				return(true);
			}
			tempNode = tempNode -> getNext();

		}while(tempNode-> getNext() != nullptr);

		if(tempNode -> getValue() == value)
		{
				return(true);
		}
		return(false);
	}
}

template <typename T>
void linkedList<T>::printList() const
{

	node<T>* temp = m_front;

	if(temp == nullptr)
	{
		std::cout << "Nothing here to print. Empty List...";
	}
	else
	{
		while(temp != nullptr)
		{
			std::cout << "Event Info: " << temp->getValue().getYear() << " " <<
			temp->getValue().getMonth() << " " << temp->getValue().getDay() << " " <<
			temp->getValue().getTime() << " " << temp->getValue().getEvent() << " " <<
			temp->getValue().getAttendance() << '\n' << '\n';

			temp = temp->getNext();
		}
	}
}

template <typename T>
void linkedList<T>::addBack(T value)
{
	node<T>* temp = nullptr;
	
	if(isEmpty())
	{
		m_front = new node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		temp->setNext(new node<T>(value));
	}
	m_size++;
}

template <typename T>
void linkedList<T>::addFront(T value)
{
	node<T>* temp = m_front;
	m_front = new node<T>(value);
	m_front->setNext( temp );
	m_size++;
}


template <typename T>
void linkedList<T>::sortList()
{
  node<T>* currentNode = nullptr;
  node<T>* prevNode = nullptr;
  node<T>* temp = nullptr;

  for(int i = 0; i <= size(); i++)
	{
		currentNode = m_front;
		prevNode = m_front;

    while(currentNode->getNext() != nullptr)
	{
      if (compareDates(currentNode->getValue(), currentNode->getNext()->getValue()) == true)
		{
        temp = currentNode->getNext();
        currentNode->setNext(currentNode->getNext()->getNext());
        temp->setNext(currentNode);
        
        if(currentNode == m_front)
				{
					prevNode = temp;
					m_front = prevNode;
				}
        else
				{
					prevNode->setNext(temp);
        	currentNode = temp;
				}
    	}
      prevNode = currentNode;
      currentNode = currentNode->getNext();
    }
  }
}

template <typename T>
bool linkedList<T>::compareDates(T value0, T value1)
{
	bool comparer = false;
  
	if(value0.getYear() < value1.getYear())
	{
		comparer = true;
		return(comparer);
	}
	if(value0.getYear() == value1.getYear() && value0.getMonth() < value1.getMonth())
	{
		comparer = true;
		return(comparer);
	}
	if(value0.getYear() == value1.getYear() && value0.getMonth() == value1.getMonth() && value0.getDay() < value1.getDay())
	{
		comparer = true;
		return(comparer);
	}
	  
	return(comparer);
}

template <typename T>
bool linkedList<T>::removeBack()
{

	node<T>* tempNode = m_front;

	//One element is removed from the back of the list.
	//Returns true if the back element was removed, false if the list is empty.
	if(m_front == nullptr)
	{
		return(false);
	}
	else
	{

		node<T>* lastNode = m_front;

		while(lastNode-> getNext() != nullptr)
		{
			lastNode = lastNode-> getNext();//sets lastNode to last Node
			if(lastNode-> getNext() != nullptr)
			{
				tempNode = tempNode-> getNext();//sets tempNode to node before last
			}
		}

		delete(lastNode);
		tempNode->setNext(nullptr);
		lastNode = nullptr;
		m_size --; //decrement size
	}

	if(m_size == 0)
	{
		return(false);
	}
	else
	{
		return(true);
	}
}

template <typename T>
bool linkedList<T>::removeFront()
{

	node<T>* tempNode = m_front;

	//One element is removed from the front of the list.
	//Returns true if the front element was removed, false if the list is empty.
	if(m_front == nullptr)
	{
		delete(tempNode);//free the memory
		tempNode = nullptr;
		return(false);
	}
	else if(tempNode-> getNext() == nullptr)//case if only one item in list
	{
		delete(m_front);
		m_front = nullptr;
		m_size --; //decrement size
		delete(tempNode);//free the memory
		tempNode = nullptr;
		return(false);
	}
	else
	{
		m_front = tempNode->getNext(); //sets front pointer to the next node
		delete(tempNode);//free the memory
		tempNode = nullptr;
		m_size --; //decrement size
		return(true);
	}
}

template <typename T>
std::vector<T> linkedList<T>::toVector() const
{
	std::vector<T> vec;
	node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template<typename T>
bool linkedList<T>::insert(int position, T value)
{

  if(position > m_size || position < 1) 
  { 
	  return(false); 
  }
  else if(position == 1) //If the position is at the front we use addfront instead
  {
    addFront(value);
    return(true);

  }
  else
  {
    node<T>* newNode = new node<T>(value);
    node<T>* temp = m_front;
    int tempPos = 1;

    while(tempPos < (position-1))
    {
		temp = temp->getNext();
		tempPos++;
    }
    newNode->setNext(temp->getNext());
    temp->setNext(newNode);
	m_size++; //Keeps track of the length
    return(true);
  }
}

template<typename T>
T linkedList<T>::getEntry(int position) const
{
	node<T>* temp = m_front;
	int tempPos = 1;
	while(tempPos < position) //Traverses list and gets entry
	{
		temp = temp->getNext(); 
		tempPos++; 
	}
	return temp->getValue();
}