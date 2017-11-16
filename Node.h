#ifndef NODE_H
#define NODE_H

template <class T>
	class Node
	{
	public:
		Node(); //default constructor
		Node(const T & source); //parameterized constructor
	private:
		T data;
		Node * link;
	};

#endif 