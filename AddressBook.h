#ifndef ADDRESSBOOK_H_
#define ADDRESSBOOK_H_

#include "Contact.h"

class AddressBook {
public:
    // Constructor
    AddressBook();

    // Contact Manipulation
    void addContact(Contact newContact);
    void editContact(Contact revisedContact, int index);
    void removeContact(int index);
    void addGroupToContact(string group, int index);
    void removeGroupFromContact(string group, int index);
    void addTagToContact(string tag, int index);
    void removeTagFromContact(string tag, int index);

    // Search Methods
    vector<Contact> searchByName(string nameKey) const;
    void searchByName(string nameKey, vector<Contact>& results, vector<int>& indexes);
    vector<Contact> searchByEmail(string emailKey) const;
    vector<Contact> searchByNumber(string numberKey) const;
    Contact searchByIndex(int index);

    // Filter Methods
    vector<Contact> filterByCity(string cityKey) const;   
    vector<Contact> filterByType(ContactType typeKey) const;
    vector<Contact> filterByTag(string tagKey) const;
    vector<Contact> filterByMissing() const;
    
    // MISC Methods
    void listReportContacts() const;
    void reportGroupSummaries();
    void printContacts() const;
    void printContacts(vector<Contact>& contacts) const;
    void printReportGroup(vector<Contact>& contacts, string group);

    // File IO
    void exportToFile(ofstream&);
    void importFromFile(ifstream&);

private:
    vector<Contact> contacts;
    vector<string> allGroups;
};

#endif