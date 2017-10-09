#include "Address.h"


// default constructor
Address::Address()
{
	Address::street_address;
	Address::city;
	Address::state;
	Address::zip;
}

// secondary constructor
Address::Address(std::string street_address, std::string city, std::string state, std::string zip)
{
	Address::street_address = street_address;
	Address::city = city;
	Address::state = state;
	Address::zip = zip;
}

// populates data members with user entered values
void Address::set_full_address()
{
	std::cout << "Enter the street address (i.e. '1234 Main St'): ";

	if (std::cin.peek() == '\n')
		std::cin.ignore();

	std::getline(std::cin, street_address);

	std::cout << "Enter the city: ";

	std::getline(std::cin, city);

	std::cout << "Enter the state (i.e. CO): ";

	std::getline(std::cin, state);

	std::cout << "Enter the six-digit zip: ";

	std::cin >> zip;

	return;
}

// prints the data members
void Address::get_full_address() const
{
	std::cout << street_address << std::endl << city << ", " << 
		state << " " << zip << std::endl;
	return;
}

// returns formatted data members for output
std::string Address::to_string() const
{
	std::string output_string;

	output_string = street_address + "\n" + city + ", " + state + " " + zip;

	return output_string;
}

//returns formatted data members for output to file
std::string Address::to_file() const
{
	std::string output_string;

	output_string = street_address + "," + city + "," + state + "," + zip;

	return output_string;
}







