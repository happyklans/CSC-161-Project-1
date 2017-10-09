#ifndef ADDR_BOOK_H
#define ADDR_BOOK_H

#define MAX_SIZE 5

#include <iostream>
#include <fstream>
#include "Contact.h"



class addr_book
{
public:

	addr_book(); //default constructor

	void add_contact(Contact itemToAdd); // adds a contact to the address book
	
	void remove_contact(Contact itemToRemove); // removes a contact from the address book
	
	int find_contact(Contact itemToFind); // find a contact in the address book

	bool is_full(); //checks to see if the array is full
	
	void remove_contact_by_index(int indexToRemove); // remove a contact by its index in the address book
	
	void print_all_contacts(); // print all contacts 
	
	int get_used(); // returns number of contacts in the address book

	int get_max_size(); //returns the max size of the address book
	
	void read_file(Field fileName); //reads the address book from a csv
	
	void write_file(Field fileName); // write the address book to a csv

private:

	Contact address_book [MAX_SIZE];

};

#endif