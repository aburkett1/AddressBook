#ifndef ADDRESSBOOK_H_
#define ADDRESSBOOK_H_

#include "Contact.h"

class AddressBook {
public:
    // Constructor
    AddressBook();

    // Contact Manipulation
    void addContact(Contact newContact);
    bool removeContact(string nameKey);

    // Search Methods
    vector<Contact> searchByName(string nameKey) const;
    vector<Contact> searchByEmail(string emailKey) const;
    vector<Contact> searchByNumber(string numberKey) const;

    // Filter Methods
    vector<Contact> filterByCity(string cityKey) const;   
    vector<Contact> filterByType(ContactType typeKey) const;
    vector<Contact> filterByTag(string tagKey) const;
    vector<Contact> filterByMissing() const;
    
    // MISC Methods
    void listReportContacts() const;
    void printContacts() const;

    // File IO
    void exportToFile(ofstream&);
    void importFromFile(ifstream&);

private:
    vector<Contact> contacts;
};

#endif