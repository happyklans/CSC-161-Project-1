#include "Name.h"


// default constructor
Name::Name()
{
	first_name;
	last_name;
}

// secondary argumented constructor
Name::Name(Field fname, Field lname)
{
	Name::first_name = fname;
	Name::last_name = lname;
}

// gets user input for first and last name
void Name::set_full_name(Field first_name_input, Field last_name_input)
{
	first_name = first_name_input;

	last_name = last_name_input;
}

//prints full name
void Name::get_full_name() const
{
	std::cout << last_name << "," << first_name << std::endl;
	return;
}

// returns formatted data for output to console
Field Name::to_string() const
{
	Field output_string;
	
	output_string = "    Name: " + last_name + ", " + first_name + '\n';

	return output_string;
}

//retruns formatted data for output to file
Field Name::to_file() const
{
	Field output_string;

	output_string =  first_name + "," + last_name;

	return output_string;
}

/*----------------friend functions----------------------*/
//logical operators
bool operator == (const Name &name_on_left, const Name &name_on_right)
{
	if (name_on_left.to_string() == name_on_right.to_string())
		return true;
	else
		return false;

}

bool operator != (const Name &name_on_left, const Name &name_on_right)
{
	return !(name_on_left == name_on_right);
}

bool operator < (const Name &name_on_left, const Name &name_on_right)
{
	if (name_on_left.to_string() < name_on_right.to_string())
		return true;
	else
		return false;
}

bool operator > (const Name &name_on_left, const Name &name_on_right)
{
	if (name_on_left.to_string() > name_on_right.to_string())
		return true;
	else
		return false;
}

bool operator <= (const Name &name_on_left, const Name &name_on_right)
{
	if (name_on_left == name_on_right || name_on_left < name_on_right)
		return true;
	else
		return false;
}

bool operator >= (const Name &name_on_left, const Name &name_on_right)
{
	if (name_on_left == name_on_right || name_on_left > name_on_right)
		return true;
	else
		return false;
}
//stream operators
istream & operator >> (istream &in, Name &n)
{
	in >> n.last_name;

	in >> n.last_name;

	return in;
}

ostream & operator << (ostream &out, Name &n)
{
	out << n.to_string();

	return out;
}

ifstream & operator >> (ifstream &in, Name &n)
{
	in >> n.first_name;

	in >> n.last_name;

	return in;
}

ofstream & operator << (ofstream &out, Name &n)
{
	out << n.to_file();

	return out;
}