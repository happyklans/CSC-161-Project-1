#ifndef ADDR_BOOK_H
#define ADDR_BOOK_H

#define MAX_SIZE 5

#include <iostream>
#include <string>
#include "Contact.h"



class addr_book
{
public:

	addr_book(); //default constructor

	void add_contact(Contact itemToAdd); // adds a contact to the address book
	
	void remove_contact(Contact itemToRemove); // removes a contact from the address book
	
	int find_contact(Contact itemToFind); // find a contact in the address book
	
	void remove_contact_by_index(int indexToRemove); // remove a contact by its index in the address book
	
	void print_all_contacts(); // print all contacts 
	
	int get_used(); // returns number of contacts in the address book
	
	void read_file(std::string fileName); //reads the address book from a csv
	
	void write_file(std::string fileName); // write the address book to a csv

private:

	Contact address_book [MAX_SIZE];

};

#endif