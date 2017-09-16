#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream> 
#include <string>


class Address
{

public:
	Address(); //default constructor
	
	Address(std::string street_address, std::string city, std::string state, std::string zip); //secondary constructor

	void set_full_address(); //uses user input to set data members

	void get_full_address() const; //outputs data members to console
	
	std::string to_string() const; //returns formatted data for output

	std::string to_file() const; //returns formatted data for writing to a file


private:
	std::string street_address;
	
	std::string city;
	
	std::string state;
	
	std::string zip;
};

#endif