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
using namespace std;


int main()
{
	int menu_choice = 0; // user entered selection for initiating the correct function 
	string input_validator; // used to ensure valid input

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
		default:
			break;
		}
	}

	return 0;
}
