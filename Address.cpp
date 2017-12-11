#include "Address.h"


// default constructor
Address::Address()
{
	street_address;
	city;
	state;
	zip;
}

// secondary constructor
Address::Address(Field street_address, Field city, Field state, Field zip)
{
	Address::street_address = street_address;
	Address::city = city;
	Address::state = state;
	Address::zip = zip;
}

// populates data members with user entered values
void Address::set_full_address(Field street_address_input, Field city_input, Field state_input, Field zip_input)
{
	street_address = street_address_input;

	city = city_input;

	state = state_input;

	zip = zip_input;

	return;
}

// prints the data members
void Address::get_full_address() const
{
	std::cout << street_address << std::endl << city << ", " << 
		state << " " << zip << std::endl;
	return;
}

Field Address::get_street()
{
	return street_address;
}

Field Address::get_city()
{
	return city;
}

Field Address::get_state()
{
	return state;
}

Field Address::get_zip()
{
	return zip;
}
// returns formatted data members for output
Field Address::to_string() const
{
	Field output_string;

	output_string = " Address: " + street_address + "\n" + "          " + city + ", " + state + " " + zip;
					
	return output_string;
}

//returns formatted data members for output to file
Field Address::to_file() const
{
	Field output_string;

	output_string = street_address + "," + city + "," + state + "," + zip;

	return output_string;
}

/*----------------------------friend functions-----------------------------------*/
istream & operator >> (istream &in, Address &a)
{
	in >> a.street_address;

	in >> a.city;

	in >> a.state;

	in >> a.zip;

	return in;
}

ostream & operator << (ostream &out, Address &a)
{
	out << a.to_string();

	return out;
}

ifstream & operator >> (ifstream &in, Address &a)
{
	in >> a.street_address;

	in >> a.city;

	in >> a.state;

	in >> a.zip;

	return in;
}

ofstream & operator << (ofstream &out, Address &a)
{
	out << a.to_file();

	return out;
}





