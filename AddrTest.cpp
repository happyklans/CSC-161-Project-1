/*
Benjamin Stanton
CSC 161, Prof. Julie Schneider
09/13/2017
Menu program for the address book aplication
*/

#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include "addr_book.h"
#include "Address.h"
#include "Contact.h"
#include "Name.h"
using namespace std;


int main()
{
	int menu_choice = 0; // user entered selection for initiating the correct function 
	
	string input_validator; // used to ensure valid input

	fstream address_book("address.csv"); //long term stroage for our address book

	addr_book my_contacts;

	// opening graphic for flourish
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << "Welcome to AddressBook!";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout <<endl << endl << "Opening your AddressBook";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	cout << ".";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	cout << ".";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	cout << ".";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	cout << endl << endl;

	address_book.open("address.csv", ios::out); //open the csv for reading

	/*
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	MOVE TO BE THE READ_FILE METHOD IN THE ADDR_BOOK CLASS ONCE CHANGES ARE COMMITED
	DO NOT LEAVE IN MAIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/

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

			string first_name_constructor; //tertiary constructor for constructing the secondary constructors

			string last_name_constructor;//				"

			string street_address_constructor; //				"

			string city_constructor;//					"

			string state_constructor;//					"

			string zip_constructor;//					"

			string phone_constructor; //secondary constructor for constructing the primary constructor

			string email_constructor;//						"

			string bday_constructor;//						"

			string picture_file_constructor;//				"

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
	/*
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/
	
	
	
	//actual menu and input validation
	while (menu_choice != 5)
	{
		//menu
		cout << " 1. Add a new Contact to your AddressBook\n\n"
			
			" 2. Find out how many Contacts are in your AddressBook\n\n"
			
			" 3. Print out all the Contacts in your AddressBook\n\n"
			
			" 4. Delete a Contact from your AddressBook\n\n"
			
			" 5. Exit the Program\n\n"
			
			" Please enter the action you would like to execute (1-5): ";

		cin >> input_validator;


		//input validation, only allows ints 1-5 past
		if (input_validator.length() > 1 || input_validator.length() == 0)
		{
			cout << endl << " " << input_validator << " is not a valid selection, please enter an action selection from 1-5." << endl << endl;
			continue;
			
		}

		if (static_cast<int>(input_validator[0]) < 49 || static_cast<int>(input_validator[0]) > 53)
		{
			cout << endl << " " << input_validator << " is not a valid selection, please enter an action selection from 1-5." << endl << endl;
			continue;
		}

		menu_choice = stoi(input_validator);


		switch (menu_choice)
		{
		case 1:
		{
			Contact to_be_added; //block scope object to be added to the address_book

			to_be_added.set_contact_info();

			my_contacts.add_contact(to_be_added);

			break;
		}
		case 2:
			cout << "your AddressBook has " << my_contacts.get_used() << " contacts in it." << endl;

			break;
		case 3:
			my_contacts.print_all_contacts();

			break;
		case 4:
			my_contacts.remove_contact_by_index()
				
		default:
			break;
		}
	}

	return 0;
}
