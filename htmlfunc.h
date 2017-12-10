/*
 * This file contains the prototypes fo miscelleneous functions to
 * print HTML code for the address book binary tree project for CSC161.
 * 
 * Written by Cathy Bishop, April 1998
 * Updated by Cathy Bishop, November, 2000
 * Updated by Julie Schneider, Nov. 2014
 *
 */

#ifndef HTMLFUNC_H
#define HTMLFUNC_H

#include	<fstream>
#include	<iostream>
#include	<cstdio>
#include 	<string>
#include	<string.h>
#include	<cstdlib>
using namespace std;
#include	"Categorized_Contact.h"
#include	"BinaryNode.h"
#include	"BinaryTree.h"

#define _CRT_SECURE_NO_WARNINGS

// Takes the binary tree of addresses and prints the HTML index file.

void	printHTMLindex(BinTree<Categorized_contact> &book);

// Takes binary tree of addresses and prints the HTML page for each address.

void	printHTMLpages(BinTree<Categorized_contact> &book);

// Takes an address and prints an HTML reference to its HTML page.

void	printHTMLrefs(Categorized_contact &item,
						int counter);

// Takes an address and prints an HTML page.

void	printHTMLpage(Categorized_contact &item,
					int counter);

#endif
