#ifndef NAME_H
#define NAME_H

#include <string>
#include <iostream>

class Name
{
public:
	Name(); // default constructor
	Name(std::string fname, std::string lname); // secondary constructor with arguments
	void set_full_name(); // set both data members
	void get_full_name() const; //prints both data members
	std::string to_string() const; // output both data members as a string
	std::string to_file() const;	//				"
private:
	std::string first_name;
	std::string last_name;
};
#endif // !NAME_H

