#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <fstream>   // ifstream
#include <iostream>  // istream
using namespace std;

// Field (sub) is a string (super)
class Field : public string
{
public:
	// constructors
	Field(); // default  constructor
	Field(string str);
	Field(const char* cStr);
private:
		// nothing here - no new data 
		// inherits the data from string
};

istream& operator>>(istream& is, Field & fld);
ifstream& operator>>(ifstream& ifs, Field & fld);

#endif




