#ifndef NODETEMPLATE_H
#define NODETEMPLATE_H

template <class Type>
	class Node
	{
	friend class LinkedList<Type>;
	public:
			Node(); //default constructor
			Node(Type & source); //parameterized constructor
	private:
			Type data;
			Node * link;
	};
	
#include "NodeTemplate.tem"

#endif 