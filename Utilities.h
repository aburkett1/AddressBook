#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "Menu.h"
#include "AddressBook.h"
#include "Contact.h"

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
int contactSelection(vector<Contact>& results);
void pressEnterToContinue();

// IO
template <typename T>
void displayTitle(T title);
void displayResults(vector<Contact>& results);
void displayContact(Contact& selectedContact);
void clearScreen();

#endif