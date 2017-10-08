/*Benjamin Stanton
Address Book Project 1
Due 9/20/17
CSC 161
Sources:
Bag Demo/Primes
Data Structures and Other Objects Using C++ (Authors: Michael Main/Walter Savitch)


Requirements
1. Add a new Contact to the AddressBook
Prompt for First Name
Prom    pt for Last Name
Prompt for Street Address
Prompt for City Address
Prompt for State Address
Prompt for Zip Address
Prompt for Phone Number
Prompt for Email Address
Prompt for Birthday
Prompt for Picture File (ex. julie.jpg)
2. Find out how many Contacts are in the AddressBook
3. Print out all the Contacts in the AddressBook
(Print a counter in front of each contact - starting at 1)
4. Delete a Contact from the AddressBook
Prompt for the item number to delete (counting number starting at 1)
5. Exit the Program
*/


#include <iostream>
#include <string>
#include <iomanip> //provides setw function
#include "addr_book.h"
using namespace std;

const int consoleWidth = 100;



void infoPrompt(addr_book& addrbook);

int main()
{
	//variables
	int userAns = 0;
	
	int numSelected = 0;
	
	addr_book addrbook;
	
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
			//prompts user
			infoPrompt(addrbook);
			break;
		case 2:
			//prints number of contacts entered
			cout << "The number of contacts that are in your Address Book are " << addrbook.get_used() << "." << endl;
			break;
		case 3:
			//pring all contacts
			addrbook.print_all_contacts();
			break;
		case 4:
			//remove contact
			addrbook.print_all_contacts(); //prints contacts
			cout << "Select the number of the contact that you would like to remove: ";
			cin >> numSelected;
			numSelected--;
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
void infoPrompt(addr_book& addrbook)//prompting function
{
	string tFirstName;
	string tLastName;
	string tStreetAddress;
	string tCityAddress;
	string tStateAddress;
	string tZip;
	string tPhoneNum;
	string tEmail;
	string tBirthday;
	string tPicFile;

	if (addrbook.get_used() < addrbook.get_max_size()) //does not let user add if used space in file is more than capacity
	{
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
	}
	else
	{
		cout << "Address Book is full, your contact cannot be added." << endl;
	}
	Name nameContact = Name::Name(tFirstName, tLastName);
	Address addrContact = Address::Address(tStreetAddress, tCityAddress, tStateAddress, tZip);
	Contact numContact = Contact::Contact(nameContact, addrContact, tPhoneNum, tEmail, tBirthday, tPicFile);
	addrbook.add_contact(numContact);
}