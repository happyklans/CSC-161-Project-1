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

Name Contact::get_name()
{
	return full_name;
}

Address Contact::get_address()
{
	return full_address;
}

Field Contact::get_phone()
{
	return phone;
}

Field Contact::get_birthday()
{
	return birthday;
}

Field Contact::get_email()
{
	return email;
}

Field Contact::get_picture_file()
{
	return picture_file;
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
		+ phone + "," + email + "," + birthday + "," + picture_file + ",\n";

	return output_string;
}

/*---------------------friend functions-----------------------------*/
//logical operators
bool operator == (const Contact &contact_on_left, const Contact &contact_on_right)
{
	if (contact_on_left.full_name == contact_on_right.full_name)
		return true;
	else
		return false;

}

bool operator != (const Contact &contact_on_left, const Contact &contact_on_right)
{
	return !(contact_on_left == contact_on_right);
}

bool operator < (const Contact &contact_on_left, const Contact &contact_on_right)
{
	if (contact_on_left.full_name < contact_on_right.full_name)
		return true;
	else
		return false;
}

bool operator > (const Contact &contact_on_left, const Contact &contact_on_right)
{
	if (contact_on_left.full_name > contact_on_right.full_name)
		return true;
	else
		return false;
}

bool operator <= (const Contact &contact_on_left, const Contact &contact_on_right)
{
	if (contact_on_left.full_name == contact_on_right.full_name || contact_on_left.full_name < contact_on_right.full_name)
		return true;
	else
		return false;
}

bool operator >= (const Contact &contact_on_left, const Contact &contact_on_right)
{
	if (contact_on_left.full_name == contact_on_right.full_name || contact_on_left.full_name > contact_on_right.full_name)
		return true;
	else
		return false;
}
//stream operators
istream & operator >> (istream &in, Contact &c)
{
	in >> c.full_name;

	in >> c.full_address;

	in >> c.phone;

	in >> c.email;

	in >> c.birthday;

	in >> c.picture_file;

	return in;
}

ostream & operator << (ostream &out, Contact &c)
{
	out << c.to_string();

	return out;
}

ifstream & operator >> (ifstream &in, Contact &c)
{
	in >> c.full_name;

	in >> c.full_address;

	in >> c.phone;

	in >> c.email;

	in >> c.birthday;

	in >> c.picture_file;

	return in;
}

ofstream & operator << (ofstream &out, Contact &c)
{
	out << c.to_file_string();

	return out;
}