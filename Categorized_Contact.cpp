#include "Categorized_Contact.h"

Categorized_contact::Categorized_contact() :Contact() 
{
	category;
}

Categorized_contact::Categorized_contact(Field contact_category, const Contact &contact) : Contact(contact)
{
	category = contact_category;	
}

void Categorized_contact::set_categorized_contact(Field contact_category, Name full_name_input, Address full_address_input, 
	Field phone_input, Field email_input, Field birthday_input, Field picture_file_input)
{
	category = contact_category;

	set_contact_info(full_name_input, full_address_input, phone_input, email_input, birthday_input, picture_file_input);

	return;
}


void Categorized_contact::get_categorized_contact() const
{
	std::cout << category << endl;

	get_contact_info();

	return;
}

Field Categorized_contact::get_category() const
{
	return category;
}

Field Categorized_contact::to_string() const
{
	Field output_field;

	output_field = "Category: " + category + '\n'
		+ Contact::to_string();

	return output_field;	
}

Field Categorized_contact::to_file_string() const
{
	Field to_file_field;

	to_file_field = category + ',' + Contact::to_file_string();

	return to_file_field;
}