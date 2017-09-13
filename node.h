#ifndef NODE
#define NODE

template <typename T>
class node
{
	private:
	T m_value;	//value in the node
	node<T>* m_next;	//pointer to another node

	public:
	//constructor for each node includes a value and a pointer to another node
	node();

	//set and get methods for the value within the node
	void setValue(T val);
	T getValue() const;

	//set and get methods for the pointer of each node
	void setNext(node<T>* prev);
	node<T>* getNext() const;
};

#include "node.hpp"

#endif
