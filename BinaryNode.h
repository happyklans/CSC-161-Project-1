#ifndef BINARYNODE_H
#define BINARYNODE_H

template <class Type>
	class BinNode
	{
	friend class BinTree<Type>;
	public:
	
		BinNode();
		
		BinNode(Type & source);
	
	private:
		
		BinNode * RightNode;
		
		BinNode * LeftNode;

		Type data;

	};

#include "BinaryNode.cpp"


#endif // !BINNODE_H

