/*
Benjamin Stanton
CSC 161, Prof. Julie Schneider
09/13/2017
Menu program for the address book aplication
*/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "addr_book.h"
using namespace std;


int main()
{
	int menu_choice = 0; // user entered selection for initiating the correct function 

	int index_to_remove = 0;
	
	string input_validator; // used to ensure valid input

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

	//populate address book from file
	my_contacts.read_file("address.csv");

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
			cout << "Enter the index of the contact you would like to remove, or,"
				<< " if you are unsure, enter -1 to return to the menu: ";

			cin >> index_to_remove;

			if (index_to_remove == -1)
				break;
			else if (index_to_remove < 0 || index_to_remove >= my_contacts.get_max_size())
				cout << "Sorry, I couldn't find the contact at that location." <<
				" Print all contacts to from the main menu to find the righ index";
			else
			{
				my_contacts.remove_contact_by_index(index_to_remove);
			}

			break;

		case 5:
			break;

		default:
			cout << "Sorry, that's not a valid option, please try again." << endl << endl;
			break;
		}
	}
	

	return 0;
}
