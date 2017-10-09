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

	void set_contact_info(Name full_name_input, Address full_address_input, Field phone_input, 
		Field email_input, Field birthday_input, Field picture_file_input); // populates the data members with user input
	
	void get_contact_info() const; //prints the data members

	Field to_string() const; //returns the formatted data members for output

	Field to_file_string() const; //retruns the formatted data members for output to file

protected:
	
	Name full_name;
	
	Address full_address;
	
	Field phone;
	
	Field email;
	
	Field birthday;
	
	Field picture_file;

private:

};

#endif