#include "addr_book.h"



addr_book::addr_book()
{
	Contact address_book[MAX_SIZE];
}


void addr_book::add_contact(Contact itemToAdd)
{
	int used = 0; //used to find the next position in the book

	used = get_used();

	if (used == MAX_SIZE)
	{
		std::cout << "Your AddressBook is full. Please delete some of your contacts before trying to add any more." << std::endl;
	}
	else
		address_book[used] = itemToAdd;
}

void addr_book::remove_contact(Contact itemToRemove)
{
	Contact null_contact;

	for (int i = 0; i < get_used(); i++)
	{
		if (itemToRemove.to_string() == address_book[i].to_string())
		{
			address_book[i] = address_book[get_used() - 1];
			
			address_book[get_used() - 1] = null_contact;
			
			break;
		}
	}
}

int addr_book::find_contact(Contact itemToFind)
{
	bool found = false;
	
	std::string search_value;

	std::string possible_match;

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

void addr_book::remove_contact_by_index(int indexToRemove)
{
	Contact null_contact;

	address_book[indexToRemove] = null_contact;

	return;
}

void addr_book::print_all_contacts()
{
	for (int i = 0; i < get_used(); i++)
	{
		std::cout << i+1 << address_book[i].to_string() << std::endl;
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

void addr_book::read_file(std::string filename)
{
	std::ifstream address_book; //long term stroage for our address book

	int field_location = 0; //keeps track of which field is being read
	
	addr_book my_contacts;

	address_book.open(filename, std::ios::in); //open the csv for reading

	if (address_book)//does not enter the loop if the file is empty
	{
		do
		{
			/*
			illustrating the constructor flow
																			   / first_name_constructor @ [0]
															  |-------------> <
															  |                \ last_name_constructor @ [1]
										  / name_constructor -|
			[  ]  /						 /  address_constructor-----|          / street_address_constructor @ [2]
			[  ] <		constructor		<	phone_constructor @ [6] |-------> <  city_constructor	@ [3]
			[  ]  \						 \  email_constructor @ [7]            \ state_constructor @ [4]
			...							  \ bday_constructor @ [8]              \zip_constructor @ [5]
										   \picture_file_constructor @ [9]
					^								^						              ^
					|								|					                  |
			primary constructor				secondary constructors               tertiary constructors
			*/
			//------------------------------------------------------------------------//

			std::string line_from_file; // used to parse text from the csv

			std::string constructor_array[10];


			//-----------------------------------------------------------------------------------------//

			//read an entry from the .csv

			std::getline(address_book, line_from_file);

			for (char i : line_from_file)
			{
				if (i != ',' && i != '\n')
				{
					constructor_array[i] += i;
				}
				else if (i == ',')
				{
					field_location++;
					continue;
				}
				else
					break;
			}

			Name name_constructor(constructor_array[1], constructor_array[0]); //secondary constructor for 
																				//constructing the primary constructor

			Address address_constructor(constructor_array[2], constructor_array[3],
				constructor_array[4], constructor_array[5]); //secondary constructor for constructing the primary constructor

			//primary constructor
			Contact constructor(name_constructor, address_constructor, constructor_array[6], constructor_array[7],
				constructor_array[8], constructor_array[9]); //block scope 
																																						  //constructor variable for populating the my_contacts object

			my_contacts.add_contact(constructor);

		} while (address_book.peek() != EOF);


	}
	else
	{
		address_book.open(filename, std::ios::trunc|std::ios::out);
		address_book.close();
	}
	
	return;
}

void addr_book::write_file(std::string filename)
{
	std::ofstream out_file;

	out_file.open(filename, std::ios::out);

	for (int i = 0; i < get_used(); i++)
	{
		out_file << address_book[i].to_file_string();
	}

	out_file.close();

	return;
}

