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
		std::cout << address_book[i].to_string() << std::endl;
	}
}

int addr_book::get_used()
{
	Contact null_contact;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (null_contact.to_string() == address_book[i].to_string())
			return (i + 1);

	}

	return MAX_SIZE;
}

int addr_book::get_max_size()
{
	return MAX_SIZE;
}

void read_file()
{
	std::ifstream address_book("address.csv"); //long term stroage for our address book
	
	addr_book my_contacts;

	address_book.open("address.csv", std::ios::out); //open the csv for reading

	if (address_book.eof == false)//does not enter the loop if the file is empty
	{
		do
		{
			/*
			illustrating the constructor flow
			/ first_name_constructor
			|---> <
			|      \ last_name_constructor
			/ name_constructor -|
			[  ]  /						 /  address_constructor-|    / street_address_constructor
			[  ] <		constructor		<	phone_constructor   |-> <  city_constructor
			[  ]  \						 \  email_constructor        \ state_constructor
			...							  \ bday_constructor		   zip_constructor
			picture_file_constructor
			^					    ^						  ^
			|					    |					      |
			primary constructor   secondary constructors      tertiary constructors
			*/
			int i = 0; //iterator position

			std::string first_name_constructor; //tertiary constructor for constructing the secondary constructors

			std::string last_name_constructor;//				"

			std::string street_address_constructor; //				"

			std::string city_constructor;//					"

			std::string state_constructor;//					"

			std::string zip_constructor;//					"

			std::string phone_constructor; //secondary constructor for constructing the primary constructor

			std::string email_constructor;//						"

			std::string bday_constructor;//						"

			std::string picture_file_constructor;//				"

			address_book >> first_name_constructor >> last_name_constructor >> street_address_constructor
				>> city_constructor >> state_constructor >> zip_constructor >> phone_constructor >> email_constructor
				>> bday_constructor >> picture_file_constructor;

			Name name_constructor(first_name_constructor, last_name_constructor); //secondary constructor for constructing the primary constructor

			Address address_constructor(street_address_constructor, city_constructor, state_constructor, zip_constructor); //secondary constructor for constructing the 
																														   //primary constructor

			Contact constructor(name_constructor, address_constructor, phone_constructor, email_constructor, bday_constructor, picture_file_constructor); //block scope 
																																						  //constructor variable for populating the my_contacts object

			my_contacts.add_contact(constructor);

		} while (address_book.peek() != EOF);
	}
}

