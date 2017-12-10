/*
 * This file contains miscelleneous functions to print HTML code
 * for the item book binary tree project for CSC161.
 * 
 * Written by Cathy Bishop, April 1998
 * Updated by Cathy Bishop, November, 2000
 * Updated by Julie Schneider, Nov., 2014
 *
 */
#include	"htmlfunc.h"

// Misc HTML functions

void	printHTMLhead(ostream &os, string title);
void	printHTMLend(ostream &os);

// File that will have the HTML index to my item book

ofstream	htmlIndex;

/*
 * Function: printHTMLindex(binTree<itemEntry> &book)
 *
 * This function takes the item book (which is a binary tree)
 * and prints the HTML index for the item book. The index
 * is in the file index.htm. You can open this file with your
 * browser to access your itemes.
 *
 * This function uses the inOrderTraverse() member function of the
 * binary tree template code to print the individual hrefs. It passes
 * the stand-alone function printHTMLrefs() to actually print them.
 *
 * Parameters:
 *
 *	book	- the item book (as a binary tree!)
 *
 * Returns:
 *
 * NONE
 *
 */

void	printHTMLindex(BinTree<Categorized_contact> &book)
{
	int counter = 0;
	htmlIndex.open("index.htm");
	printHTMLhead(htmlIndex, "Item Book Index");
	book.inOrderTraverse(printHTMLrefs(), counter);
	printHTMLend(htmlIndex);
	htmlIndex.close();
}

/*
 * Function: printHTMLpages(binTree<itemEntry> &book)
 *
 * This function takes the item book (which is a binary tree)
 * and prints the HTML pages for the item book. You can access
 * the pages by opening the index.htm file with your browser.
 *
 * This function uses the inOrderTraverse() member function of the
 * binary tree template code to print the individual pages. It passes
 * the stand-alone function printHTMLpage() to actually print them.
 *
 * Parameters:
 *
 *	book	- the item book (as a binary tree!)
 *
 * Returns:
 *
 * NONE
 *
 */

void	printHTMLpages(BinTree<Categorized_contact> &book)
{
	book.inOrderTraverse(printHTMLpage);
}

/*
 * Function: printHTMLhref(int counter, itemEntry &item)
 *
 * This function takes an item entry and prints the HTML
 * href to its page. The file for the page is named addrNNNN.htm,
 * where N is a counter. This counter should be passed by the
 * inOrderTraverse() member function of the binary tree template code.
 * The easiest way to generate this number is to make it a counter
 * that counts the nodes as they are being traversed.
 *
 * The output from this function will look like this:
 *
 * <p><a href=addr0001.htm> Cathy Bishop</a>
 *
 * Parameters:
 *
 *	counter	- the number used to generate a unique HTML file reference.
 *	item	- the item entry.
 *
 * Returns:
 *
 * NONE
 *
 */

void	printHTMLrefs(Categorized_contact &item, int counter)
{
	char		fileName[13];

	Name contact_name;

	sprintf_s(fileName, "addr%4.4d.htm", counter);

	contact_name = item.get_name();

	htmlIndex << "<p><a href=" << fileName << "> "
		<< contact_name.to_file() << "</a>\n";
}
// field Contact::nameLastCommaFirst() const;

/*
 * Function: printHTMLpage(int counter, itemEntry &item)
 *
 * This function takes an item entry and prints the HTML
 * page. The file for the page is named addrNNNN.htm,
 * where N is a counter. This counter should be passed by the
 * inOrderTraverse() member function of the binary tree template code.
 * The easiest way to generate this number is to make it a counter
 * that counts the nodes as they are being traversed.
 *
 * The output from this function will look like this:
 *
 * <p align=center> <H1>
 * Cathy Bishop</H1>
 * <body bgcolor=white>
 * </font><font size=+2>
 * <p>Red Rocks Community College
 * <br>Lakewood, CO 80026
 * <p><b>phone:</b> 914-6250
 * <p><b>email:</b> cbishop@pobox.com
 * <p><b>Birthday:</b> January 28
 * </font>
 * </body>
 * </html>
 *
 * Parameters:
 *
 *	counter	- the number used to generate a unique HTML file reference.
 *	item	- the item entry.
 *
 * Returns:
 *
 * NONE
 *
 */

void	printHTMLpage(Categorized_contact &item,
						int counter)
{
	Name contact_name;
	Address contact_address;
	char		fileName[13];
	ofstream	htmlPage;
	string		title;

	sprintf_s(fileName, "addr%4.4d.htm", counter);
	
	contact_name = item.get_name();

	htmlPage.open(fileName);
	if (!htmlPage)
	{
		cout << "Unable to write HTML page: " << fileName << endl;
		return;
	}

	// The person's name will be the title for the page

	title = contact_name.to_file();
	printHTMLhead(htmlPage, title);

	// Here's the formatted item

	htmlPage << "</font>";
	htmlPage << "<font size=+2>\n<p>";
	
	htmlPage << "<b>Category:</b> " << item.get_category() << "<br>" << endl;

	htmlPage << "<br><b>Address:</b><br>" << item.getFullAddress().getStreet() << "<br>"
		<< item.getFullAddress().getCity() << ", " << item.getFullAddress().getState()
		<< "<br>" << item.getFullAddress().getZip() << endl;

	// Here's the phone number

 	htmlPage << "<p><b>phone:</b> " << item.getPhone() << endl;

	// Here's the email item

 	// htmlPage << "<p><b>email:</b> " << item.email() << endl;
 	htmlPage << "<p><b>email:</b> <a href=mailto:" << item.getEmail()
		<< "> " << item.getEmail() << "</a>\n";

	// Here's the birthday

 	htmlPage << "<p><b>Birthday:</b> " << item.getBday() << endl;

	// Here's the optional picture

	if (item.getPicture() != " ")
 		htmlPage << "<p><img src=" << item.getPicture() 
			 << ">\n";

	htmlPage << "</font>";
	printHTMLend(htmlPage);
	htmlPage.close();
}

// This function prints the required HTML code to start a page

void		printHTMLhead(ostream &os, string title)
{
	string	pageTitle;

	if (title == "")
		pageTitle = "HTML Page";
	else
		pageTitle = title;

	os	<< "<html>\n<head>\n<title>" << pageTitle << "</title>\n" 
		<< "<p align=center> <h1>\n" 
		<< pageTitle << "</h1>\n<body bgcolor=white>\n";
}


// This function prints the required HTML code to end a page

void		printHTMLend(ostream &os)
{
	os << "</body>\n</html>\n";
}
