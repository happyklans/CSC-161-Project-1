#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
#include <fstream>


template <class T>
	class LinkedList
	{
		friend class Node;

		LinkedList();
	
		LinkedList(const LinkedList & source);

		LinkedList & operator = (const LinkedList& source);

		~LinkedList();

		void add(T datain);

		void remove_by_item_number(int item_number);

		void remove_by_item(T data_to_remove);

		int count_items();

		void read_file(std::string file_name);

		void write_file(std::string file_name);

		void print_all();
	
	private:

		Node* head;

		Node* find_node(T datain);

		Node* find_previous_node(T datain);

		void remove_first();

		void remove_node(Node* address_to_remove);

		Node * alloc_node(T datain);

		void free_all_nodes();

	};

#endif