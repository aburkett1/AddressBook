#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "Menu.h"
#include "AddressBook.h"
#include "Contact.h"

// Constants
const int LINE_WIDTH = 79;

// Application setup
vector<Menu> setupMenus();

// User Input
Contact getContactDetails(Menu& typeMenu);
string getContactName();
string getEmail();
string getNumber();
string getCity();
string getGroup();
string getTag();
string getFileName();
int userSelection(vector<Contact>& results);
void pressEnterToContinue();

// Output
void printLine(int lineWidth = LINE_WIDTH);

template <typename T>
void displayTitle(T title)
{
    // Display Title
    printLine();
	cout << "   " << title << endl;
	printLine();
}

void displayResults(vector<Contact>& results);
void displaySelection(vector<Contact>& results);
void displayContact(Contact& selectedContact);
void clearScreen();

#endif