#include "addr_book.h"



addr_book::addr_book()
{
	Contact address_book[MAX_SIZE];
}


void addr_book::add_contact(Contact itemToAdd)
{
	int used = 0; //used to find the next position in the book
		
	used = get_used();

	address_book[used] = itemToAdd;
}

void addr_book::remove_contact(Contact itemToRemove)
{
	Contact null_contact;
	
	for (int i = 0; i < get_used(); i++)
	{
		if (itemToRemove.to_string() == address_book[i].to_string)
			address_book[i] = null_contact;
	}
}

int addr_book::find_contact(Contact itemToFind)
{
	for (int i = 0; i < get_used(); i++)
	{
		if (itemToFind.to_string() == address_book[i].to_string)
			return i;
		else
		{
			return -1;
		}
	}
}

void addr_book::remove_contact_by_index(int indexToRemove)
{
	Contact null_contact;

	address_book[indexToRemove] = null_contact;
}

void addr_book::print_all_contacts()
{
	for (int i = 0; i < get_used(); i++)
	{
		std::cout << address_book[i].to_string() << endl;
	}
}

int addr_book::get_used()
{
	Contact null_contact;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (null_contact.to_string() == address_book[i].to_string())

	}
}
