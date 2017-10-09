#include "Name.h"


// default constructor
Name::Name()
{
	Name::first_name;
	Name::last_name;
}

// secondary argumented constructor
Name::Name(std::string fname, std::string lname)
{
	Name::first_name = fname;
	Name::last_name = lname;
}

// gets user input for first and last name
void Name::set_full_name()
{
	std::cout << "Enter the first name: ";
	
	std::cin >> first_name;
	
	if (std::cin.peek() == '\n')
		std::cin.ignore();
	
	std::cout << "Enter the last name: ";
	
	std::cin >> last_name;
	
	return;
}
//prints full name
void Name::get_full_name() const
{
	std::cout << last_name << "," << first_name << std::endl;
	return;
}

// returns formatted data for output to console
std::string Name::to_string() const
{
	std::string output_string;
	
	output_string = last_name + ", " + first_name + '\n';

	return output_string;
}

//retruns formatted data for output to file
std::string Name::to_file() const
{
	std::string output_string;

	output_string = last_name + "," + first_name;

	return output_string;
}
