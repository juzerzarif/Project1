
template <typename T>
node<T>::node()
{
	//constructor initilizes each node to a value of 0 and the pointer to null
	m_next = nullptr;
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
void node<T>::setNext(node<T>* prev)
{
	m_next = prev;
}

template <typename T>
node<T>* node<T>::getNext() const
{
	return(m_next);
}
