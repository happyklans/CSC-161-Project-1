#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <fstream>

using namespace std;

template <class Type>
	class BinNode;

template <class T>
class BinTree
{
public:
	
	BinTree();
	
	BinTree(const BinTree & source);
	
	BinTree<T> & operator=(const BinTree& source);
	
	~BinTree();
	
	void Add(T dataIn);
	
	void Print();  // inorder
	
	void export_list(T * data);
	
	void WriteFile(std::string fileName);
	
	void ReadFile(std::string fileName);
	
	int CountItems();
	
	// RemoveByItemNumber, RemoveByItem - BONUS
	
	void inOrderTraverse(void process(T &, int));

private:
	
	BinNode<T>* root;
	
	BinNode<T>* alloc(T dataIn);
	
	void free(BinNode<T>* cursor);
	
	void print(BinNode<T>* cursor);
	
	void copyTree(BinNode<T>* cursor);
	
	void inOrderTraverse(BinNode<T>* cursor, void process(T &, int&), int &);
	
	void writeFile(BinNode<T>* cursor, std::ofstream& ofs);
	
	int countItems(BinNode<T>* cursor);
};

//#include "BinaryTree.cpp"

#endif

