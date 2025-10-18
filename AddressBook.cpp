#include "AddressBook.h"

// =============================================================================
// MARK: Constructors
// =============================================================================

AddressBook::AddressBook()
{
    //nothing needed; contacts is already an empty vector
}

// =============================================================================
// MARK: Contact Manipulation
// =============================================================================

void AddressBook::addContact(Contact newContact)
{
    contacts.push_back(newContact);
}

// Removes only first instace of nameKey. Case Sensitive
bool AddressBook::removeContact(string nameKey) {
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getName() == nameKey) {
            contacts.erase(contacts.begin() + i);
            return true;
        }
    }
    return false;
}


// =============================================================================
// MARK: SEARCH
// =============================================================================

// Returns empty vector of Contacts if search fails
vector<Contact> AddressBook::searchByName(string nameKey) const {
    vector<Contact> temp;
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getName() == nameKey) {
            temp.push_back(contacts[i]);
        }
    }

    return temp;
}

// When we return Contact(), we are providing a default constructed contact AN EMPTY CONTACT
vector<Contact> AddressBook::searchByEmail(string emailKey) const
{
    vector<Contact> temp;
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getEmail() == emailKey) {
            temp.push_back(contacts[i]);
        }
    }
    
    return temp;
}

// Search for contact by phone number.
vector<Contact> AddressBook::searchByNumber(string numberKey) const
{
    // Variables
    vector<Contact> matches = {};
    
    // For each contact, check the number. If correct, add it to the
    // matches vector.
    for (auto contact : contacts)
    {
        if (contact.getPhoneNumber() == numberKey)
        {
            matches.push_back(contact);
        }
    }

    // Return the vector of matched numbers.
    return matches;
}


// =============================================================================
// MARK: FILTER
// =============================================================================

vector<Contact> AddressBook::filterByCity(string cityKey) const {

    vector<Contact> temp;

    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getCity() == cityKey){
            {
                temp.push_back(contacts[i]);
                break;
            }
        }
    }
    return temp;
}

// Returns empty vector if contact vector is empty, or if there are no matches
vector<Contact> AddressBook::filterByType(ContactType typeKey) const {
    vector<Contact> temp;
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getType() == typeKey) {
            temp.push_back(contacts[i]);
        }
    }

    return temp;
}


/*
    For each contact:
        checking all tags for each contact,
                if contact contains tagkey then move the contact to temp and iterate to next contact
                else check next tag
        
        if it makes it out of the loop then move onto next contact

    after all contacts have been looked at and sorted input into temp return temp
*/
vector<Contact> AddressBook::filterByTag(string tagKey) const
{
    vector<Contact> temp;

    // for loop moves through all contacts
    for (int i = 0; i < contacts.size(); i++) {
        
        // loop to move through all elements of the vector tags inside of contact[i]
        for(int j = 0; j < contacts[i].getTags().size(); j++)
        {
            if(contacts[i].getTags()[j] == tagKey)
            {
                temp.push_back(contacts[i]);
                break;
            }
        }
    }

    return temp;
}

// Filter contacts by missing information.
vector<Contact> AddressBook::filterByMissing() const
{
    // Variables
    vector<Contact> missing = {};

    // For each contact, if the phone number or the email is missing, add it to
    // the missing vector.
    for (auto contact : contacts)
    {
        if (contact.getPhoneNumber() == "" ||
            contact.getEmail() == "")
        {
            missing.push_back(contact);
        }
    }

    // Return vector of contacts with missing information.
    return missing;
}


// =============================================================================
// MARK: MISC
// =============================================================================

    //loops through vector looking for one type at a time
    //and calling printInfo(); if it is the matching type.
void AddressBook::listReportContacts() const {

    cout << "Person" << endl;
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getType() == PERSON)
            contacts[i].printInfo();
    }

    cout << "Business" << endl;
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getType() == BUSINESS)
            contacts[i].printInfo();
    }

    cout << "Vendor" << endl;
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getType() == VENDOR)
            contacts[i].printInfo();
    }

    cout << "Emergency" << endl;
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getType() == EMERGENCY)
        contacts[i].printInfo();
    }
}

//loops through contacts vector calling printInfo() for every
//contact in the vector.
void AddressBook::printContacts() const {
    for (int i = 0; i < contacts.size(); i++) {
        contacts[i].printInfo();
    }
}


// =============================================================================
// MARK: File IO
// =============================================================================

// Export contacts vector to txt file.
void AddressBook::exportToFile(ofstream& out)
{
    // Export contacts vector size
    out << contacts.size();

    // Export each contact in contacts
    for (auto contact : contacts)
    {
        contact.exportToFile(out);
    }
}

// Import contacts from text file into vector.
void AddressBook::importFromFile(ifstream& in)
{
    // Variables
    int contactsSize{};
    Contact contact = Contact();
    
    // Get number of contacts
    in >> contactsSize;
    cin.ignore(10000, '\n');

    for (int _ = 0; _ < contactsSize; _++)
    {
        // Import contact.
        contact.importFromFile(in);

        // Push contact into contacts vector.
        contacts.push_back(contact);

        // Reset contact data.
        contact = Contact();
    }
}