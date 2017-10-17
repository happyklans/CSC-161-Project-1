/*Benjamin Stanton
Address Book Project 1
Due 9/20/17
CSC 161
Sources:
Bag Demo/Primes
Data Structures and Other Objects Using C++ (Authors: Michael Main/Walter Savitch)


Requirements
1. Add a new Categorized Contact to the AddressBook
Prompt for Category by using menu items below:
(a) Work
(b) Family
(c) Friends
(d) Other
Prompt for First Name
Prompt for Last Name
Prompt for Street Address
Prompt for City Address
Prompt for State Address
Prompt for Zip Address
Prompt for Phone Number
Prompt for Email Address
Prompt for Birthday
Prompt for Picture File
2. Find out how many items are in the AddressBook
3. Print out all the items in the AddressBook based upon category selection from menu below:
(Print a counter in front of each contact - starting at 1)
(a) Work
(b) Family
(c) Friends
(d) Other
(e) All Contacts
4. Delete an item from the AddressBook
Prompt for the item number to delete (counting number starting at 1)
5. Exit the Program
*/


#include <iostream>
#include <iomanip> //provides setw function
#include "Addr_Book.h"
using namespace std;

const int consoleWidth = 100;



void infoPrompt(Addr_Book& addrbook);

int main()
{
	//variables
	int userAns = 0;
	
	int numSelected = 0;

	Field category_choice;

	Field good_inputs = "abcdef";

	bool valid_input = false;
	
	Addr_Book addrbook;
	
	Contact new_contact;

	addrbook.read_file("address.csv");

	//Menu Prompt
	do
	{
		cout << setw(consoleWidth / 2) << " " << "~~~~~ADDRESS BOOK~~~~~" << endl;
		cout << "MAIN MENU" "\n" << endl;
		cout << "1. Enter New Contact" << endl;
		cout << "2. Print Number of Contacts in Address Book" << endl;
		cout << "3. Print All Contacts in Address Book" << endl;
		cout << "4. Delete Contact from Address Book" << endl;
		cout << "5. Exit Address Book" << endl;
		cout << endl;
		cout << "Please choose an option by selecting the number of the action: " << endl;
		cin >> userAns;
		switch (userAns)//send user answer through switch
		{
		case 1:

			infoPrompt(addrbook);

			break;
		case 2:
			//prints number of contacts entered
			cout << "The number of contacts that are in your Address Book are " << addrbook.get_used() << "." << endl;
			break;
		case 3:
			//prints a user selected group of contacts, possibly all of them

			valid_input = false;

			while (valid_input == false)
			{
				std::cout << "Choose a category from the list below:\n"
					<< "a) Family\n"
					<< "b) Work\n"
					<< "c) School\n"
					<< "d) Friend\n"
					<< "e) Other\n"
					<< "f) All Contacts\n";

				std::cin >> category_choice;

				if (category_choice.length() > 1 || category_choice.length() == 0)
				{
					cout << "That is not a valid input. Please try again\n";
				}
				else if (good_inputs.find(category_choice) == -1)
				{
					cout << "That is not a valid input. Please try again\n";

					continue;
				}
				else
				{
					valid_input = true;

					switch (static_cast<int>(category_choice[0]))
					{
					case 97:
						addrbook.print_by_category("Family");//print contacts by category

						break;

					case 98:
						addrbook.print_by_category("Work");//			""

						break;

					case 99:
						addrbook.print_by_category("School");//			""

						break;

					case 100:
						addrbook.print_by_category("Friend");//			""

						break;

					case 101:
						addrbook.print_by_category("Other");//			""

						break;

					case 102:
						addrbook.print_all_contacts();//print all contacts
					
						break;

					default:
						break;
					}
				}
			}

			break;

		case 4:
			//remove contact
			addrbook.print_all_contacts(); //prints contacts
			cout << "Select the number of the contact that you would like to remove: ";
			cin >> numSelected;
	
			addrbook.remove_contact_by_index(numSelected);//removes contact
			cout << "Contact " << numSelected + 1 << " has been removed." << endl;
			break;
		case 5:
			//writes to file and exits program
			addrbook.write_file("address.csv");
			break;
		default:
			//error message - loops back up to menu
			cout << "Invalid Response, Try Again!" << endl;
		}
	} while (userAns != 5);//loops until user selects 5
	cin.get();
	return 0;
}
void infoPrompt(Addr_Book& addrbook)//prompting function
{
	Field category_choice;
	Field good_inputs = "abcde";
	bool valid_input = false;
	Field tFirstName;
	Field tLastName;
	Field tStreetAddress;
	Field tCityAddress;
	Field tStateAddress;
	Field tZip;
	Field tPhoneNum;
	Field tEmail;
	Field tBirthday;
	Field tPicFile;

	
	while (valid_input == false)
		{
			std::cout << "Choose a category from the list below:\n"
				<< "a) Family\n"
				<< "b) Work\n"
				<< "c) School\n"
				<< "d) Friend\n"
				<< "e) Other\n";

			std::cin >> category_choice;

			if (category_choice.length() > 1 || category_choice.length() == 0)
			{
				cout << "That is not a valid input. Please try again\n";
			}//input validation
			else if (good_inputs.find(category_choice) == -1)
			{
				cout << "That is not a valid input. Please try again\n";

				continue;
			}//input validation
			else
			{
				valid_input = true;

				switch (static_cast<int>(category_choice[0]))
				{
				case 97:
					category_choice = "Family";

					break;

				case 98:
					category_choice = "Work";

					break;

				case 99:
					category_choice = "School";

					break;

				case 100:
					category_choice = "Friend";

					break;

				case 101:
					category_choice = "Other";

					break;

				default:
					break;
				}
			




			cout << "Enter the following information:" << endl;
			cout << "First Name: " << endl;
			cin >> tFirstName;
			cout << "Last Name: " << endl;
			cin >> tLastName;
			cout << "Street Address: " << endl;

			getline(cin, tStreetAddress);//allows spaces  
			cout << "City: " << endl;
			cin >> tCityAddress;
			cout << "State: " << endl;
			cin.ignore();
			getline(cin, tStateAddress);//allows spaces
			cout << "Zip Code: " << endl;
			cin >> tZip;
			cout << "Phone Number (xxx-xxxx-xxxx): " << endl;
			cin >> tPhoneNum;
			cout << "Email Address: " << endl;
			cin >> tEmail;
			cout << "Birthday (00/00/0000): " << endl;;
			cin >> tBirthday;
			cout << "Add Picture file (pic.jpg): " << endl;
			cin >> tPicFile;
			cout << endl;
			cout << "You entered: " << endl
				<< tFirstName << " " << tLastName << endl <<
				tStreetAddress << tCityAddress << " " << tStateAddress << " " << tZip << endl <<
				tPhoneNum << endl <<
				tEmail << endl <<
				tBirthday << endl <<
				tPicFile << endl;

			valid_input = true;
		}
	}
	
	Name name_contact(tFirstName, tLastName);
	Address addr_contact(tStreetAddress, tCityAddress, tStateAddress, tZip);
	Contact temp_contact(name_contact, addr_contact, tPhoneNum, tEmail, tBirthday, tPicFile);
	Categorized_contact contact_to_add(category_choice, temp_contact);
	addrbook.add_contact(contact_to_add);
}