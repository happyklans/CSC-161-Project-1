#ifndef CATEGORIZED_CONTACT_H
#define CATEGORIZED_CONTACT

#include "Contact.h"

class Categorized_contact : public Contact
{
	public:
		void set_category();
		
		void get_category();
		
		Field to_string();
		
		Field to_file();
	
	private:
		Field category;
};

#endif // !CATEGORIZED_CONTACT_H
