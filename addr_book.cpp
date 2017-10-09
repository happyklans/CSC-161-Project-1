#include "Addr_Book.h"



addr_book::addr_book()
{
	Contact address_book[MAX_SIZE];
}


void addr_book::add_contact(Contact itemToAdd)
{
	int used = 0; //determines the position at which the contact is to be inserted

	used = get_used();
	
	address_book[used] = itemToAdd;

	return;
}

void addr_book::remove_contact(Contact itemToRemove)
{
	Contact null_contact;

	int index_to_replace = 0;

	for (int i = 0; i < get_used(); i++)
	{
		index_to_replace = get_used() - 1;
		
		if (itemToRemove.to_string() == address_book[i].to_string())
		{
			address_book[i] = address_book[index_to_replace];
			
			address_book[index_to_replace] = null_contact;
			
			break;
		}
	}

	return;
}

int addr_book::find_contact(Contact itemToFind)
{
	bool found = false;
	
	Field search_value;

	Field possible_match;

	search_value = itemToFind.to_string();

	
	
	for (int i = 0; i < get_used(); i++)
	{
		possible_match = address_book[i].to_string();

		if (search_value == possible_match)
			found = true;
		else
			found = false;
		

		if (found == true)
			return i;
	}

	return -1;
}

bool addr_book::is_full()
{
	int used = 0; //used to find the next position in the book

	used = get_used();

	if (used == MAX_SIZE)
	{
		std::cout << "Your AddressBook is full. Please delete some of your contacts before trying to add any more." << std::endl;

		return true;
	}

	return false;
}

void addr_book::remove_contact_by_index(int indexToRemove)
{
	Contact null_contact;

	int index_to_replace = 0;

	index_to_replace = get_used() - 1;

	address_book[indexToRemove-1] = address_book[index_to_replace];

	address_book[index_to_replace] = null_contact;

	return;
}

void addr_book::print_all_contacts()
{
	for (int i = 0; i < get_used(); i++)
	{
		std::cout << i+1 << ")\n" << address_book[i].to_string() << std::endl;
	}

	return;
}

int addr_book::get_used()
{
	Contact null_contact;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (null_contact.to_string() == address_book[i].to_string())
			return i;

	}

	return MAX_SIZE;
}

int addr_book::get_max_size()
{
	return MAX_SIZE;
}

void addr_book::read_file(Field filename)
{

	std::fstream address_file; //long term stroage for our address book

	address_file.open(filename, std::ios::in); //open the csv for reading

	
		
	
	
	
	if (!address_file)
	{
		address_file.open(filename, std::ios::trunc | std::ios::out);
		address_file.close();
	}

	for (int h = 0; h < MAX_SIZE; h++)
	{
		/*
		illustrating the constructor flow
		/ first_name_constructor
		|---> <
		|      \ last_name_constructor
		/ name_constructor ---|
		[  ]  /						 /  address_constructor-|    / street_address_constructor
		[  ] <		constructor		<	phone_constructor   |-> <  city_constructor
		[  ]  \						 \  email_constructor        \ state_constructor
		...							  \ bday_constructor		   zip_constructor
		picture_file_constructor
		^					    ^						  ^
		|					    |					      |
		primary constructor   secondary constructors      tertiary constructors
		*/

		Field first_name_constructor; //tertiary constructor for constructing the secondary constructors

		Field last_name_constructor;//				"

		Field street_address_constructor; //				"

		Field city_constructor;//					"

		Field state_constructor;//					"

		Field zip_constructor;//					"

		Field phone_constructor; //secondary constructor for constructing the primary constructor

		Field email_constructor;//						"

		Field bday_constructor;//						"

		Field picture_file_constructor;//				"

		Field line;

		int field_tracker = 0; //tracks commas to determine the field being inputed


		if (std::getline(address_file, line, '\n'))
		{
			for (char i : line)
			{
				if (i != ',' && i != '\n')
				{
					switch (field_tracker)
					{
					case 0:
						last_name_constructor += i;

						break;
					case 1:
						first_name_constructor += i;

						break;
					case 2:
						street_address_constructor += i;

						break;
					case 3:
						city_constructor += i;

						break;
					case 4:
						state_constructor += i;

						break;
					case 5:
						zip_constructor += i;

						break;
					case 6:
						phone_constructor += i;

						break;
					case 7:
						email_constructor += i;

						break;
					case 8:
						bday_constructor += i;

						break;
					case 9:
						picture_file_constructor += i;

						break;
					}

				}

				else
				{
					field_tracker++;
				}
			}
		}
		else
		{
			break;
		}


		
		Name name_constructor(first_name_constructor, last_name_constructor); //secondary constructor for constructing the primary constructor

		Address address_constructor(street_address_constructor, city_constructor, state_constructor, zip_constructor);

		Contact contact_constructor(name_constructor, address_constructor, phone_constructor, email_constructor, bday_constructor, picture_file_constructor);

		address_book[h] = contact_constructor;

	}
	

	address_file.close();

	return;
}

void addr_book::write_file(Field filename)
{
	std::fstream out_file;

	out_file.open(filename, std::ios::out);

	for (int i = 0; i < get_used(); i++)
	{
		out_file << address_book[i].to_file_string();
	}

	out_file.close();

	return;
}

