#ifndef ADDR_BOOK_H
#define ADDR_BOOK_H
#define _SCL_SECURE_NO_WARNINGS


#include <iostream>
#include <fstream>
#include "Categorized_contact.h"



class Addr_Book
{
public:

	// CONSTRUCTOR
	Addr_Book();
	
	~Addr_Book();   // destructor

			  // value semantics
			  // copy constructor
	Addr_Book(const Addr_Book& source);

	// assignment operator
	Addr_Book& operator=(const Addr_Book& source);

	void add_contact(const Categorized_contact &itemToAdd); // adds a contact to the address book
	
	void remove_contact(Categorized_contact itemToRemove); // removes a contact from the address book
	
	int find_contact(Categorized_contact itemToFind) const; // find a contact in the address book
	
	void remove_contact_by_index(int indexToRemove); // remove a contact by its index in the address book
	
	void print_all_contacts() const; // print all contacts 

	void print_by_category(Field category) const; //prints all contacts of a certain category
	
	int get_used() const; // returns number of contacts in the address book

	void read_file(Field fileName); //reads the address book from a csv
	
	void write_file(Field fileName) const; // write the address book to a csv

private:

	Categorized_contact * address_book;  // The pointer to array to store items
	
	int used;             // How much of array is used
	
	int capacity;		// size of array that can change
	
	void alloc(int increaseSize);
	
	void free();
	
	bool debug;

};

#endif