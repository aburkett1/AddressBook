// Group Project: Address Book
// Name: Hien, Cade, Noah, Austin, Isaiah, Nicholas
// Date: 10/14/2025
// Class: MW 6-6:50PM

// Contact.cpp
#include "Contact.h"

// Setter for name of the contact
void Contact::setName(string newName)
{
    name = newName;
}

// Setter for email in the contact
void Contact::setEmail(string newEmail)
{
    email = newEmail;
}

// Setter for phone number in the contact
void Contact::setPhoneNumber(string newNumber)
{
    phoneNumber = newNumber;
}

// Setter for city in the contact
void Contact::setCity(string newCity)
{
    city = newCity;
}

// Setter for contact type in the contact
void Contact::setType(ContactType newType)
{
    type = newType;
}

// Getter for name in the contact
string Contact::getName() const
{
    return name;
}

// Getter for email in the contact
string Contact::getEmail() const
{
    return email;
}

// Getter for phone number in the contact
string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

// Getter for city in the contact
string Contact::getCity() const
{
    return city;
}

// Getter for contact type in the contact
ContactType Contact::getType() const
{
    return type;
}

// Getter for group of the contact in the contact
const vector<string>& Contact::getGroups() const
{
    return groups;
}

// Getter for the tag of the contact in the contact
const vector<string>& Contact::getTags() const
{
    return tags;
}