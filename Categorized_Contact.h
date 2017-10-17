#ifndef CATEGORIZED_CONTACT_H
#define CATEGORIZED_CONTACT

#include "Contact.h"
#include <iostream>

class Categorized_contact : public Contact
{
	public:
		Categorized_contact(); // default constructor

		Categorized_contact(Field contact_category, const Contact &contact); //parameterized constructor

		void set_categorized_contact(Field contact_category, Name full_name_input, Address full_address_input, Field phone_input,
			Field email_input, Field birthday_input, Field picture_file_input); //mutator

		void get_categorized_contact() const; //assesor, prints to console
		
		Field get_category() const; // assesor for the superclass data members only
		
		Field to_string() const; // formats input into a field for output
		
		Field to_file_string() const; // formats input into a field for file output
	
	private:
		Field category;
};

#endif // !CATEGORIZED_CONTACT_H
