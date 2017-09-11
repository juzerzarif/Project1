#include"linkedList.h"
#include"node.h"
#include<iostream>

linkedList::linkedList()
{
	m_front= nullptr; 
	m_size = 0; 
}

linkedList::~linkedList()
{
	//deletes all nodes in the list avoid memory errors
	if(isEmpty())
	{
		m_front = nullptr;
	}
	else
	{
		node* tempNode = m_front; 
		
		while(m_front->getNext() != nullptr)//loops until only one node remaining 
		{
			tempNode = m_front->getNext();//sets tempNode to point to the second Node
			delete(m_front); //deletes the current front node
			m_front = tempNode; //new front is node behind first
		}
		delete(m_front); //deletes final node
		m_front = nullptr;
	}
}

bool linkedList::isEmpty() const
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

int linkedList::size() const
{
	return(m_size); 
}

bool linkedList::search(int value) const
{
	node* tempNode = m_front; //pointer to headnode //pointer to headnode 

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

void linkedList::printList() const
{
	
	
	//Node* tempNode = new Node(); //head node
	
	node* tempNode = m_front; //pointer to headnode 
	
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

void linkedList::addBack(int value)
{
	//create a new node with data input and set to nullptr
	node* newNode = new node();
	newNode-> setValue(value);
	newNode-> setNext(nullptr); 
	
	//adds 1 new node to the end of the list
	if(m_front == nullptr) //if list is empty create a new node 
	{
		m_front = newNode; 
	}
	else //else traverse list till last ndoe then set next node  
	{
		node* lastNode = m_front; 		
		while(lastNode-> getNext() != nullptr)
		{
			lastNode = lastNode-> getNext();				
		}
		lastNode->setNext(newNode);
		
	}

	m_size ++;//increment size

}

void linkedList::addFront(int value)
{
	//create a new node with data input and set to nullptr
	node* newNode = new node();
	newNode-> setValue(value);
	newNode-> setNext(nullptr); 

	//adds 1 new node to front of the list
	newNode-> setNext(m_front); //set the new node point to the current front
	m_front = newNode; //set the new front as the new node
	
	m_size ++;//increment size	
		
}

bool linkedList::removeBack()
{
	
	node* tempNode = m_front;

	//One element is removed from the back of the list.
	//Returns true if the back element was removed, false if the list is empty.
	if(m_front == nullptr)
	{
		return(false); 
	}
	else
	{
		
		node* lastNode = m_front;
		
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

bool linkedList::removeFront()
{
	
	node* tempNode = m_front;

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

std::vector<int> linkedList::toVector() const
{
 
	std::vector<int> listContents;//creates new vector to hold values
	

	if(m_front != nullptr)
	{
		node* tempNode = m_front; 
				
		for(int i=0; i<m_size; i++)//traverse list and input values into vector
		{
			listContents.push_back(tempNode->getValue());
			tempNode = tempNode->getNext(); 
		}
		
	}

	return(listContents); 
}