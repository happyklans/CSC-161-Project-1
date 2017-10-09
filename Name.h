#ifndef NAME_H
#define NAME_H

#include "Field.h"
#include <iostream>

class Name
{
public:
	Name(); // default constructor
	Name(Field fname, Field lname); // secondary constructor with arguments
	void set_full_name(Field first_name_input, Field last_name_input); // set both data members
	void get_full_name() const; //prints both data members
	Field to_string() const; // output both data members as a string
	Field to_file() const;	//				"
private:
	Field first_name;
	Field last_name;
};
#endif // !NAME_H

