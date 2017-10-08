#include "Field.h"

Field::Field() // default  constructor
	: string()  // calls the string default constructor
{
// no data in private for Field - so no initialization
}
Field::Field(string str)
	: string(str) // calls the string copy constructor
{
	// no data in private for Field - so no initialization
}
Field::Field(const char* cStr)
	: string(cStr)  // calls the constructor passes const char*
{
	// no data in private for Field - so no initialization
}


istream& operator>>(istream& is, Field & fld)
{
	if (is.peek() == '\n')
		is.ignore();
	getline(is, fld, '\n');
	return is;
}
ifstream& operator>>(ifstream& ifs, Field & fld)
{
	if (ifs.peek() == '\n')
		ifs.ignore();
	getline(ifs, fld, ',');
	return ifs;
}

