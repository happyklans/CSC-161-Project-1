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

	friend istream & operator >> (istream &in, Contact &c);

	friend ostream & operator << (ostream &out, Contact &c);

	friend ifstream & operator >> (ifstream &out, Contact &c);

	friend ofstream & operator << (ofstream &out, Contact &c);

	friend bool operator == (const Contact &contact_on_left, const Contact &contact_on_right);

	friend bool operator != (const Contact &contact_on_left, const Contact &contact_on_right);

	friend bool operator < (const Contact &contact_on_left, const Contact &contact_on_right);

	friend bool operator > (const Contact &contact_on_left, const Contact &contact_on_right);

	friend bool operator <= (const Contact &contact_on_left, const Contact &contact_on_right);

	friend bool operator >= (const Contact &contact_on_left, const Contact &contact_on_right);

	void set_contact_info(Name full_name_input, Address full_address_input, Field phone_input, 
		Field email_input, Field birthday_input, Field picture_file_input); // populates the data members with user input
	
	void get_contact_info() const; //prints the data members

	Name get_name();

	Address get_address();

	Field get_phone();

	Field get_email();

	Field get_birthday();

	Field get_picture_file();

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