#include"node.h"

node::node()
{
	//constructor initilizes each node to a value of 0 and the pointer to null	
	m_value = 0;
	m_next = nullptr; 
}

void node::setValue(int val)
{
	m_value = val;
}

int node::getValue() const
{
	return(m_value);
}

void node::setNext(node* prev)
{
	m_next = prev; 
}

node* node::getNext() const
{
	return(m_next);
}