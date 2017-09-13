

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

/*
void linkedList::printList() const
{
	
	
	//Node* tempNode = new Node(); //head node
	
	node<T>* tempNode = m_front; //pointer to headnode 
	
	//prints the list to the console
	//if list is empty print empty string 
	if(m_size == 0)
	{
		std::cout << "";
	}
	else
	{
		std::cout << tempNode -> getValue() << '\n'; 		
		while(tempNode-> getNext() != nullptr)
		{
			tempNode = tempNode -> getNext();			
			std::cout << tempNode-> getValue() << '\n'; 
			
		}
	}

}
*/

template <typename T>
void linkedList<T>::addBack(T value)
{
	//create a new node with data input and set to nullptr
	node<T>* newNode = new node<T>();
	newNode-> setValue(value);
	newNode-> setNext(nullptr); 
	
	//adds 1 new node to the end of the list
	if(m_front == nullptr) //if list is empty create a new node 
	{
		m_front = newNode; 
	}
	else //else traverse list till last ndoe then set next node  
	{
		node<T>* lastNode = m_front; 		
		while(lastNode-> getNext() != nullptr)
		{
			lastNode = lastNode-> getNext();				
		}
		lastNode->setNext(newNode);
		
	}

	m_size ++;//increment size

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