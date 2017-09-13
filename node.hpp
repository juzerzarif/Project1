
template <typename T>
node<T>::node()
{
	//constructor initilizes each node to a value of 0 and the pointer to null
	m_next = nullptr;
	m_prev = nullptr;
}

template <typename T>
void node<T>::setValue(T val)
{
	m_value = val;
}

template <typename T>
T node<T>::getValue() const
{
	return(m_value);
}

template <typename T>
void node<T>::setNext(node<T>* next)
{
	m_next = next;
}

template <typename T>
node<T>* node<T>::getNext() const
{
	return(m_next);
}

template <typename T>
void node<T>::setPrev(node<T>* prev)
{
	m_prev = prev;
}

template <typename T>
node<T>* node<T>::getPrev() const
{
	return(m_prev);
}
