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

// returns formatted data for output to console
std::string Name::to_string() const
{
	std::string output_string;
	
	output_string = last_name + ", " + first_name;

	return output_string;
}


