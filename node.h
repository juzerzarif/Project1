#ifndef NODE
#define NODE

class node
{
	private:
	int m_value;	//value in the node 
	node* m_next;	//pointer to another node

	public:
	//constructor for each node includes a value and a pointer to another node	
	Node();

	//set and get methods for the value within the node
	void setValue(int val);
	int getValue() const;
	
	//set and get methods for the pointer of each node 
	void setNext(Node* prev);
	Node* getNext() const;
};

#endif