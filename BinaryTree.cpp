#include "BinaryTree.h"

template<class T>
BinTree<T>::BinTree()
{
	root = nullptr;
}

template<class T>
BinTree<T>::BinTree(const BinTree & source)
{
	this->root = nullptr;
	*this = source;
}

template<class T>
BinTree<T> & BinTree<T>::operator=(const BinTree & source)
{
	// self assignment
	if (this == &source)
		return *this;
	// free existing memory
	free(root);
	copyTree(source.root);
}

template<class T>
BinTree<T>::~BinTree()
{
	free(root);
}

template<class T>
void BinTree<T>::Add(T dataIn)
{
	BinNode<T> * leaf = alloc(dataIn);
	BinNode<T> * cursor = root;
	if (root == nullptr)  // empty tree
	{
		root = leaf;
		return;
	}
	while (cursor != nullptr)
	{
		if (dataIn <= cursor->data)   // leftLink
		{
			if (cursor->leftLink == nullptr)   // its open so add it
			{
				cursor->leftLink = leaf;
				return;
			}
			else                                // not open move down the branch
				cursor = cursor->leftLink;
		}
		else							// rightLink
		{
			if (cursor->rightLink == nullptr)   // its open so add it
			{
				cursor->rightLink = leaf;
				return;
			}
			else                                // not open move down the branch
				cursor = cursor->rightLink;
		}
	}
}

template<class T>
void BinTree<T>::Print()
{
	print(root);
}

template<class T>
void BinTree<T>::WriteFile(std::string fileName)
{
	std::ofstream out(fileName.c_str());
	writeFile(root, out);
	out.close();
}

template<class T>
void BinTree<T>::ReadFile(std::string fileName)
{
	ifstream source_book;

	T read_data;

	source_book.open(filename, ios::in);



	while (source_book.good())
	{
		if (source_book.peek() == EOF)
			return;

		source_book >> read_data;

		Add(read_data);
	}

	source_book.close();

	return;
}

template<class T>
int BinTree<T>::CountItems()
{
	return countItems(root);
}

template<class T>
void BinTree<T>::inOrderTraverse(void process(T &, int))
{
	int count = 1;
	inOrderTraverse(root, process, count);
}

template<class T>
BinNode<T> * BinTree<T>::alloc(T dataIn)
{
	BinNode<T>* leaf = new BinNode(dataIn);
	return leaf;
}

template<class T>
void BinTree<T>::free(BinNode<T> * cursor)
{
	if (cursor != nullptr)
	{
		// post-order: left, right, process
		free(cursor->leftLink);
		free(cursor->rightLink);
		delete cursor;
	}
}

template<class T>
void BinTree<T>::print(BinNode<T> * cursor)
{
	if (cursor != nullptr)
	{
		// in-order: leftLink, process cursor, rightLink
		print(cursor->leftLink);    // recursion
		cout << cursor->data << "\t" << cursor << std::endl;
		print(cursor->rightLink);   // recursion
	}
}

template<class T>
void BinTree<T>::export_list(T * datain)
{
	if (cursor != nullptr)
	{
		inOrderTraverse(cursor->leftLink,
			process, count);
		//process
		process(cursor->data, count);
		//count++;
		inOrderTraverse(cursor->rightLink,
			process, count);
	}

	*datain[count-1] = cursor->data;

	count--;

}

template<class T>
void BinTree<T>::copyTree(BinNode<T> * cursor)
{
	if (cursor != nullptr)
	{
		Add(cursor->data);  // process
		copyTree(cursor->leftLink);
		copyTree(cursor->rightLink);
	}
}

template<class T>
void BinTree<T>::inOrderTraverse(BinNode<T> * cursor, void process(T &, int), int & count)
{
	if (cursor != nullptr)
	{
		inOrderTraverse(cursor->leftLink,
			process, count);
		//process
		process(cursor->data, count);
		//count++;
		inOrderTraverse(cursor->rightLink, process, count);
	}
}

template<class T>
void BinTree<T>::writeFile(BinNode<T>* cursor, std::ofstream& ofs)
{
	if (cursor != nullptr)
	{
		// pre-order
		ofs << cursor->data;
		writeFile(cursor->leftLink, ofs);
		writeFile(cursor->rightLink, ofs);
	}
}

template<class T>
int BinTree<T>::countItems(BinNode<T> * cursor)
{
	if (cursor != nullptr)
	{
		// process
		return countItems(cursor->leftLink) + countItems(cursor->rightLink) + 1;
	}
}