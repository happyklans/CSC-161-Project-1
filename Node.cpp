
template<class T>
Node<T>::Node()
{
	T data;

	link = nullptr;
}

template<class T>
Node<T>::Node(const T & source)
{
	data = source;

	link = nullptr;
}