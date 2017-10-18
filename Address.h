#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream> 
#include "Field.h"


class Address
{

public:
	Address(); //default constructor
	
	Address(Field street_address, Field city, Field state, Field zip); //secondary constructor

	friend istream & operator >> (istream &in, Address &n1);

	friend ostream & operator << (ostream &out, Address &n1);

	friend ifstream & operator >> (ifstream &out, Address &n1);

	friend ofstream & operator << (ofstream &out, Address &n1);

	void set_full_address(Field street_address_input, Field city_input, Field state_input, Field zip_input); //uses user input to set data members

	void get_full_address() const; //outputs data members to console
	
	Field to_string() const; //returns formatted data for output

	Field to_file() const; //returns formatted data for writing to a file


private:
	Field street_address;
	
	Field city;
	
	Field state;
	
	Field zip;
};

#endif