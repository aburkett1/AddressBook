#ifndef CONTACT_H_
#define CONTACT_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// =============================================================================
// MARK: Contact Type
// =============================================================================

enum ContactType {
    PERSON = 0,
    BUSINESS,
    VENDOR,
    EMERGENCY
};


// =============================================================================
// MARK: Contact Class
// =============================================================================

class Contact {
public:
    // Constructors
    Contact();
    Contact(string newName, string newEmail, string newNumber, string newCity, ContactType newType);

    // Setters
    void setName(string newName);
    void setEmail(string newEmail);
    void setPhoneNumber(string newNumber);
    void setCity(string newCity);
    void setType(ContactType newType);

    // Adders
    void addGroup(string newGroup);
    void addTag(string newTag);

    // Removers
    void removeGroup(string groupKey);
    void removeTag(string tagKey);

    // Getters
    string getName() const;
    string getEmail() const;
    string getPhoneNumber() const;
    string getCity() const;
    ContactType getType() const;
    const vector<string>& getGroups() const;
    const vector<string>& getTags() const;

    // Console IO
    void printInfo() const;

    // File IO
    void exportToFile(ofstream&);
    void importFromFile(ifstream&);

private:
    string name;
    string email;
    string phoneNumber;
    string city;
    ContactType type;
    vector<string> groups;
    vector<string> tags;
};


// =============================================================================
// MARK: UTILITIES
// =============================================================================

string ContactTypeToString(const ContactType& contactType);

#endif