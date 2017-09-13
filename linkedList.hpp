

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
		while(temp->getNext() != nullptr)
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
	node<T>* newNode = new node<T>();
	newNode->setValue(value);
	newNode->setNext(nullptr);
	if(isEmpty())
	{
		m_front = newNode;
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		temp->setNext(newNode);
	}
	m_size++;
}

template <typename T>
void linkedList<T>::addFront(T value)
{
	//create a new node with data input and set to nullptr
	node<T>* newNode = new node<T>();
	newNode-> setValue(value);
	newNode-> setNext(nullptr);

	//adds 1 new node to front of the list
	newNode-> setNext(m_front); //set the new node point to the current front
	m_front = newNode; //set the new front as the new node

	m_size ++;//increment size

}

//DOESN'T WORK YET. WOKRING ON sortList instead
template <typename T>
void linkedList<T>::addInOrder(T value)
{

	node<T>* newNode = new node<T>;
	newNode->setValue(value);

	node<T>* currentNode = m_front;
	node<T>** prevNode = &m_front;
	while(currentNode->getValue().getYear() >  newNode->getValue().getYear()) //&& currentNode->getNext() != nullptr)
	{
	   *prevNode = currentNode->getNext();
	   currentNode = currentNode->getNext();
	}
	*prevNode = newNode;
	newNode->setNext(currentNode);
}

//TODO bubble sort
template <typename T>
void linkedList<T>::sortList()
{
  node<T>* counterNode = m_front;
  node<T>* currentNode = nullptr;
  node<T>* prevNode = nullptr;
  node<T>* temp = nullptr;

	int counter = 0;

  while(counterNode->getNext() != nullptr)
	{
    counter++;
   	counterNode = counterNode->getNext();
  }

  for(int i = 0; i <= counter; i++)
	{
		currentNode = m_front;
		prevNode = m_front;

    while(currentNode->getNext() != nullptr)
		{
      if (currentNode->getValue().getYear() < currentNode->getNext()->getValue().getYear())
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
