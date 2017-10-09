#include "Contact.h"


//default constructor
Contact::Contact()
{
	full_name;
	
	full_address;
	
	phone;
	
	email;
	
	birthday;
	
	picture_file;
}

//secondary constructor 
Contact::Contact(Name full_name, Address full_address, Field phone, Field email, Field birthday, Field picture_file)
{
	Contact::full_name = full_name;

	Contact::full_address = full_address;

	Contact::phone = phone;

	Contact::email = email;

	Contact::birthday = birthday;

	Contact::picture_file = picture_file;
}

//populate data members with user entered values
void Contact::set_contact_info(Name full_name_input, Address full_address_input, Field phone_input,
	Field email_input, Field birthday_input, Field picture_file_input)
{
	
	full_name = Name(full_name_input);

	full_address = Address(full_address_input);

	phone = phone_input;

	email = email_input;

	birthday = birthday_input;

	picture_file = picture_file_input;

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
Field Contact::to_string() const
{
	Field output_string;

	output_string = full_name.to_string() + full_address.to_string() +
		+"\n" + "   Phone: " + phone + "\n" + "   Email: " + email + "\n" + "Birthday: " + 
		birthday + "\n" + "PictFile: " + picture_file + "\n";
	
	return output_string;
}

//returns the formatted data members for output
Field Contact::to_file_string() const
{
	Field output_string;

	output_string = full_name.to_file() + ',' + full_address.to_file() + ","
		+ phone + "," + email + "," + birthday + "," + picture_file + "\n";

	return output_string;
}