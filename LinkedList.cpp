template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList & source)
{
	*this = source;
}

template<class T>
LinkedList & LinkedList::operator = (const LinkedList & source)
{
	if (&source == this)
		return *this;

	free_all_nodes();

	this->head = nullptr;

	copy_list(source.head);
}

template<class T>
LinkedList::~LinkedList()
{
	free_all_nodes();
}

template<class T>
void LinkedList::add(T datain)
{
	Node* item = alloc_node(datain);

	Node* tmp = head;

	head = item;

	if (head != nullptr)
	{
		item->link = tmp;
	}
}

template<class T>
void LinkedList<T>::remove_by_item_number(int item_number)
{
	Node * traverse = head;
	
	for (int i = 0; i < item_number; i++)
	{
		if (traverse == nullptr)
		{
			std::cout << item_number << < " is not a valid location." << endl;

			return;
		}
		else
		{
			traverse = traverse->link;
		}
	}

	remove_node(traverse);

	return;
}

template<class T>
void LinkedList<T>::remove_by_item(T data_to_remove)
{
	Node * node_to_remove = nullptr;


	node_to_remove = find_node(data_to_remove);

	if (node_to_remove != nullptr)
		remove_node(node_to_remove);
	else 
		std::cout << "No matches were found." << endl;

	return;

}

template<class T>
int LinkedList<T>::count_items()
{
	Node * traverse = head;

	int num_items = 0;

	while (traverse != nullptr)
	{
		traverse = traverse->link;

		counter++;
	}

	return counter;

}

template<class T>
void LinkedList<T>::read_file(string filename)
{
	ifstream source_book;

	T read_data;

	source_book.open(filename, ios::in);
	while (source_book.good())
	{
		source_book >> read_data;

		add(read_data);
	}

	source_book.close();

	return;
	
}

template<class T>
void LinkedList<T>::write_file(string filename)
{
	ofstream source_book;

	Node * traverse = head;



	source_book.open(filename, ios::out);


	for (int i = 0; i < count_items(); i++)
	{
		source_book << traverse->data;

		traverse = traverse->link;
	}

	source_book.close();

	return;
}

template<class T>
void LinkedList<T>::print_all()
{
	Node * traverse = head;

	int counter = 1;



	while (traverse != nullptr)
	{
		std::cout << counter << ") " << traverse->data;

		traverse = traverse->link;
	}

	return;
}

template<class T>
Node * LinkedList<T>::find_node(T data_to_find)
{
	Node * traverse = head;
	
	while (traverse != nullptr)
	{
		if (traverse->data == data_to_remove)
		{
			return traverse;
		}
		else
		{
			traverse = traverse->link;
		}
	}

	return traverse;
}

template<class T>
Node * LinkedList<T>::find_previous_node(T data_to_find)
{
	Node * traverse = head;

	Node * previous_node = nullptr;

	while (traverse != nullptr)
	{
		if (traverse->data == data_to_remove)
		{
			if (previous_node == nullptr)
				std::cout << "There are no previous nodes.";

			return previous_node;
		}
		else
		{
			previous_node = traverse;

			traverse = traverse->link;
		}
	}

	std::cout << "The item you searched for was not found in the list.";

	previous_node = nullptr;

	return previous_node;

}

template<class T>
void LinkedList<T>::remove_first()
{
	Node * temp = nullptr;

	Node * new_head = nullptr;

	new_head = head->link;
	
	temp = head;

	remove_node(temp);

	head = traverse;

	return;
}

template<class T>
void LinkedList<T>::remove_node(Node * node_to_remove)
{
	Node * previous_node = nullptr;

	previous_node = find_previous_node(node_to_remove->data);

	pervious_node->link = node_to_remove->link;

	delete node_to_remove;

	return;
}

template<class T>
Node * LinkedList<T>::alloc_node(T datain)
{
	Node * temp = new Node(datain);

	return temp;
}

template<class T>
void LinkedList<T>::free_all_nodes()
{
	Node * traverse = nullptr;

	Node * node_to_delete = nullptr;


	traverse = head->link;

	node_to_delete = head;

	while ( != nullptr)
	{

	}

}
