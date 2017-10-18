#include "Addr_Book.h"

// default constructor
Addr_Book::Addr_Book()
{
	used = 0;
	capacity = 0;
	address_book = nullptr;
	debug = false;
}

Addr_Book::~Addr_Book()  // destructor
{
	free();
}

Addr_Book::Addr_Book(const Addr_Book& source) // copy constructor
{
	used = 0;
	capacity = 0;
	address_book = nullptr;
	capacity = source.capacity;
	address_book = new Categorized_contact[capacity];
	for (int i = 0; i < source.used; i++)
		add_contact(source.address_book[i]);

	if (debug)
		cout << "In copy constructor: " << address_book << endl;

}
// assignment operator
Addr_Book& Addr_Book::operator=(const Addr_Book& source)
{
	// check for self assignment
	if (this == &source)  // check to see if address
						  // of source equals address
						  // of this that invoked the
						  // member function
		return *this;

	// free any existing memory before making the assignment
	free();
	used = capacity = 0;

	capacity = source.capacity;
	address_book = new Categorized_contact[capacity];
	for (int i = 0; i < source.used; i++)
		add_contact(source.address_book[i]);
}

void Addr_Book::add_contact(const Categorized_contact &itemToAdd)
{
	if (get_used() == capacity)
		alloc(2); // call alloc to create more memory
	address_book[used] = itemToAdd;
	++used;
}

void Addr_Book::remove_contact(Categorized_contact itemToRemove)
{
	Categorized_contact null_contact;

	int index_to_replace = 0;

	for (int i = 0; i < get_used(); i++)
	{
		index_to_replace = get_used() - 1;
		
		if (itemToRemove.to_string() == address_book[i].to_string())
		{
			address_book[i] = address_book[index_to_replace];
			
			address_book[index_to_replace] = null_contact;
			
			break;
		}
	}

	return;
}

int Addr_Book::find_contact(Categorized_contact itemToFind) const
{
	bool found = false;
	
	Field search_value;

	Field possible_match;

	search_value = itemToFind.to_string();

	
	
	for (int i = 0; i < get_used(); i++)
	{
		possible_match = address_book[i].to_string();

		if (search_value == possible_match)
			found = true;
		else
			found = false;
		

		if (found == true)
			return i;
	}

	return -1;
}

void Addr_Book::remove_contact_by_index(int indexToRemove)
{
	Categorized_contact null_contact;

	int index_to_replace = 0;

	index_to_replace = get_used() - 1;

	address_book[indexToRemove-1] = address_book[index_to_replace];

	address_book[index_to_replace] = null_contact;

	return;
}

void Addr_Book::print_all_contacts() const
{
	for (int i = 0; i < get_used(); i++)
	{
		std::cout << i+1 << ")\n" << address_book[i].to_string() << std::endl;
	}

	return;
}

void Addr_Book::print_by_category(Field category) const
{
	for (int i = 0; i < get_used(); i++)
	{
		if (address_book[i].get_category() == category)
			std::cout << i + 1 << ")\n" << address_book[i].to_string() << std::endl;
		else continue;
	}

	return;
}

int Addr_Book::get_used() const
{
	Categorized_contact null_contact;

	for (int i = 0; i < capacity; i++)
	{
		if (null_contact.to_string() == address_book[i].to_string())
			return i;

	}

	return capacity;
}

void Addr_Book::read_file(Field filename)
{

	std::fstream address_file; //long term stroage for our address book

	Field line;

	address_file.open(filename, std::ios::in); //open the csv for reading
	
	if (!address_file)
	{
		address_file.open(filename, std::ios::trunc | std::ios::out);
		address_file.close();
	}


	while (std::getline(address_file, line))
	{
		
			Field category_constructor; // primary constructor 

			Field first_name_constructor; //tertiary constructor for constructing the secondary constructors

			Field last_name_constructor;//				"

			Field street_address_constructor; //				"

			Field city_constructor;//					"

			Field state_constructor;//					"

			Field zip_constructor;//					"

			Field phone_constructor; //secondary constructor for constructing the primary constructor

			Field email_constructor;//						"

			Field bday_constructor;//						"

			Field picture_file_constructor;//				"

			

			int field_tracker = 0; //tracks commas to determine the field being inputed

			for (char i : line)
				{
					if (i != ',' && i != '\n')
					{
						switch (field_tracker)
						{
						case 0:
							category_constructor += i;

							break;

						case 1:
							first_name_constructor += i;

							break;
						case 2:
							last_name_constructor += i;

							break;
						case 3:
							street_address_constructor += i;

							break;
						case 4:
							city_constructor += i;

							break;
						case 5:
							state_constructor += i;

							break;
						case 6:
							zip_constructor += i;

							break;
						case 7:
							phone_constructor += i;

							break;
						case 8:
							email_constructor += i;

							break;
						case 9:
							bday_constructor += i;

							break;
						case 10:
							picture_file_constructor += i;

							break;
						}

					}

					else
					{
						field_tracker++;
					}
				}
			
			Name name_constructor(first_name_constructor,
				last_name_constructor); //secondary constructor for constructing the primary constructor

			Address address_constructor(street_address_constructor,
				city_constructor, state_constructor, zip_constructor); // "

			Contact contact_constructor(name_constructor, address_constructor, phone_constructor,
				email_constructor, bday_constructor, picture_file_constructor); // primary constructor

			Categorized_contact contact_to_add(category_constructor, contact_constructor); // element to be added

			add_contact(contact_to_add);

	}

	address_file.close();

	return;
}

void Addr_Book::write_file(Field filename) const
{
	std::fstream out_file;

	out_file.open(filename, std::ios::out);

	for (int i = 0; i < get_used(); i++)
	{
		out_file << address_book[i].to_file_string();
	}

	out_file.close();

	return;
}

void Addr_Book::alloc(int increaseSize)
{
	Categorized_contact* temp_contact = nullptr;
	capacity += increaseSize; // increase capacity
	temp_contact = new Categorized_contact[capacity]; // create tmpData of new capacity
	copy(address_book, address_book + used, temp_contact); // copy original to tmpData
	free();  // destroy all memory of original
	address_book = temp_contact;
}

void Addr_Book::free()
{
	if (address_book != nullptr)
	{
		delete[] address_book;
		address_book = nullptr;
	}
}