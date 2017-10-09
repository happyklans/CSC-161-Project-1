
#ifndef CONTACT_H
#define CONTACT_H


#include <iostream>
#include "Name.h"
#include "Address.h"

class Contact
{
public:
	
	Contact(); //default constructor
	
	Contact(Name full_name, Address full_address, Field phone, Field email, Field birthday, Field picture_file); //secondary constructor

	void set_contact_info(); // populates the data members with user input
	
	void get_contact_info() const; //prints the data members

	Field to_string() const; //returns the formatted data members for output

	Field to_file_string() const; //retruns the formatted data members for output to file

private:
	
	Name full_name;
	
	Address full_address;
	
	Field phone;
	
	Field email;
	
	Field birthday;
	
	Field picture_file;
};

#endif