#ifndef ADDR_BOOK_H
#define ADDR_BOOK_H

#define MAX_SIZE 5

#include <iostream>
#include <fstream>
#include "Categorized_contact.h"



class Addr_Book
{
public:

	Addr_Book(); //default constructor

	void add_contact(Categorized_contact itemToAdd); // adds a contact to the address book
	
	void remove_contact(Categorized_contact itemToRemove); // removes a contact from the address book
	
	int find_contact(Categorized_contact itemToFind) const; // find a contact in the address book

	bool is_full() const; //checks to see if the array is full
	
	void remove_contact_by_index(int indexToRemove); // remove a contact by its index in the address book
	
	void print_all_contacts() const; // print all contacts 

	void print_by_category(Field category) const; //prints all contacts of a certain category
	
	int get_used() const; // returns number of contacts in the address book

	int get_max_size() const; //returns the max size of the address book
	
	void read_file(Field fileName); //reads the address book from a csv
	
	void write_file(Field fileName) const; // write the address book to a csv

private:

	Categorized_contact address_book [MAX_SIZE];

};

#endif