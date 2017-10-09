#ifndef CATEGORIZED_CONTACT_H
#define CATEGORIZED_CONTACT

#include "Contact.h"
#include <iostream>

class Categorized_contact : public Contact
{
	public:
		Categorized_contact();

		Categorized_contact(Field contact_category, const Contact &contact);

		void set_categorized_contact(Field contact_category, Name full_name_input, Address full_address_input, Field phone_input,
			Field email_input, Field birthday_input, Field picture_file_input);

		void get_categorized_contact() const;
		
		Field get_category() const;
		
		Field to_string() const;
		
		Field to_file_string() const;
	
	private:
		Field category;
};

#endif // !CATEGORIZED_CONTACT_H
