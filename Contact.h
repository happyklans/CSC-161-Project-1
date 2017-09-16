#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include "Name.h"
#include "Address.h"

class Contact
{
public:
	
	Contact(); //default constructor
	
	Contact(Name full_name, Address full_address, std::string phone, std::string email, std::string birthday, std::string picture_file); //secondary constructor

	void set_contact_info(); // populates the data members with user input
	
	void get_contact_info() const; //prints the data members

	std::string to_string() const; //returns the formatted data members for output

	std::string to_file_string() const; //retruns the formatted data members for output to file

private:
	
	Name full_name;
	
	Address full_address;
	
	std::string phone;
	
	std::string email;
	
	std::string birthday;
	
	std::string picture_file;
};

#endif