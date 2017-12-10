#ifndef LINKEDLISTTEMPLATE_H
#define LINKEDLISTTEMPLATE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

template<class Type>
	class Node;

template <class T>
	class LinkedList
	{
	public:

		LinkedList();
	
		LinkedList(const LinkedList & source);

		void operator = (const LinkedList& source);

		~LinkedList();

		void add_ascending(T datain);

		void add_descending(T datain);

		void remove_by_item_number(int item_number);

		void remove_by_item(T data_to_remove);

		int count_items();

		void read_file(std::string file_name);

		void write_file(std::string file_name);

		void print_all();

		void export_list(T * data_array);
	
	private:

		Node<T> *head;

		Node<T>* find_node(T datain);

		Node<T>* find_previous_node(T datain);

		void remove_first();

		void remove_node(Node<T>* address_to_remove);

		Node<T> * alloc_node(T & datain);

		void free_all_nodes();

	};

#include "LinkedListTemplate.tem"


#endif