#include "Contact.h"

// =============================================================================
// MARK: Constructors
// =============================================================================

Contact::Contact() {
    name = "";
    email = "";
    phoneNumber = "";
    city = "";
    type = PERSON;
    groups = {};
    tags = {};
}

//Creates a new contact with the provided values for variables:
//      name, email, phoneNumber, city, and type
// 
// Groups & tags are both empty vector<string>
Contact::Contact(string newName, string newEmail, string newNumber, string newCity, ContactType newType)
{
    name = newName;
    email = newEmail;
    phoneNumber = newNumber;
    city = newCity;
    type = newType; 
}


// =============================================================================
// MARK: Adders
// =============================================================================

void Contact::addTag(string newTag) {
    tags.push_back(newTag);
}


// =============================================================================
// MARK: Removers
// =============================================================================

// Method takes a provided group (given by the name) and deletes it from the vector
void Contact::removeGroup(string groupKey)
{
    //find the item in the vector
    //erase the item in the vector

    //loop to iterate through groups assigned to a contact
    for(int i = 0; i < groups.size(); i++)
    {
        if(groups[i] == groupKey)
        {
            groups.erase(groups.begin()+i);
            return;
        }
    }

    //this statement will essentially work as an else case
    //executes only if the flow goes through the loop without finding the Key
    cout << "The contact is not a member of group: " << groupKey << endl
    << "Nothing was deleted." << endl << endl;
    return;

}


// =============================================================================
// MARK: Getters
// =============================================================================



// =============================================================================
// MARK: Console IO
// =============================================================================

// Prints info to console line by line
// Does not begin or end with a newline, caller is responsible for line formatting
void Contact::printInfo() const {
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "City: " << city << endl;
    cout << "Contact Type: " << ContactTypeToString(type) << endl;

    cout << "Groups: ";
    for (int i = 0; i < groups.size(); i++) {
        if (i < groups.size() - 1) {
            cout << groups[i] << ", ";
        } else {
            cout << groups[i];
        }
    }
    cout << endl;

    cout << "Tags: ";
    for (int i = 0; i < tags.size(); i++) {
        if (i < tags.size() - 1) {
            cout << tags[i] << ", ";
        } else {
            cout << tags[i];
        }
    }
}


// =============================================================================
// MARK: File IO
// =============================================================================

// Export contact to text file.
void Contact::exportToFile(ofstream& out)
{
    // Print to file non-vectors
    out << name << endl;
    out << email << endl;
    out << phoneNumber << endl;
    out << city << endl;
    out << type << endl;

    // Print vectors
    out << groups.size() << endl;
    for (int i = 0; i < groups.size(); i++)
    {
        out << groups[i]  << endl;
    }

    out << tags.size()  << endl;
    for (int i = 0; i < tags.size(); i++)
    {
        out << tags[i]  << endl;
    }
}

// Import contact from text file.
void Contact::importFromFile(ifstream& in)
{
    short contactType{};
    int groupSize{};
    string group{};
    int tagSize{};
    string tag{};
    
    // Import strings
    getline(in, name);
    getline(in, email);
    getline(in, phoneNumber);
    getline(in, city);

    // Import type
    in >> contactType;
    cin.ignore(10000, '\n');

    type = ContactType(contactType);

    // Import Groups
    in >> groupSize;
    cin.ignore(10000, '\n');

    for (int _ = 0; _ < groupSize; _++)
    {
        getline(in, group);
        groups.push_back(group);
    }

    // Import Tags
    in >> tagSize;
    cin.ignore(10000, '\n');

    for (int _ = 0; _ < tagSize; _++)
    {
        getline(in, tag);
        tags.push_back(tag);
    }
}


// =============================================================================
// MARK: UTILITIES
// =============================================================================

string ContactTypeToString(const ContactType& contactType) {
    switch (contactType) {
        case PERSON: return "Person";
        case BUSINESS: return "Business";
        case VENDOR: return "Vendor";
        case EMERGENCY: return "Emergency";
        default: return "";
    }
}