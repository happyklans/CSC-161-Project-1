#include "Contact.h"


//default constructor
Contact::Contact()
{
	Contact::full_name;
	
	Contact::full_address;
	
	Contact::phone;
	
	Contact::email;
	
	Contact::birthday;
	
	Contact::picture_file;
}

//secondary constructor 
Contact::Contact(Name full_name, Address full_address, std::string phone, std::string email, std::string birthday, std::string picture_file)
{
	Contact::full_name = full_name;

	Contact::full_address = full_address;

	Contact::phone = phone;

	Contact::email = email;

	Contact::birthday = birthday;

	Contact::picture_file = picture_file;
}

//populate data members with user entered values
void Contact::set_contact_info()
{
	
	full_name.set_full_name();

	full_address.set_full_address();

	std::cout << "Enter the phone number (i.e. 012-345-6789): ";

	std::cin >> phone;

	std::cout << "Enter the email address (i.e. johndoe@gmail.com): ";

	std::cin >> email;

	std::cout << "Enter the birthday (mm/dd/yy):";

	std::cin >> birthday;

	std::cout << "Enter the name of the picture file (i.e. john_doe.jpg): ";

	std::cin >> picture_file;

	return;
}

//prints the data members
void Contact::get_contact_info() const
{
	full_name.get_full_name();

	full_address.get_full_address();
	
	std::cout << phone << std::endl << email 
		<< std::endl << birthday << std::endl << picture_file << std::endl;
	
	return;
}

//returns the formatted data members for output
std::string Contact::to_string() const
{
	std::string output_string;

	output_string = full_name.to_string() + full_address.to_string() +
		+"\n" + phone + "\n" + email + "\n" + birthday + "\n" + picture_file + "\n";

	return output_string;
}

//returns the formatted data members for output
std::string Contact::to_file_string() const
{
	std::string output_string;

	output_string = full_name.to_file() + ',' + full_address.to_file() + ","
		+ phone + "," + email + "," + birthday + "," + picture_file + "\n";

	return output_string;
}