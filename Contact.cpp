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

// Copy Constructor
// Does not override groups and tags
Contact::Contact(const Contact& other)
{
    name = other.getName();
    email = other.getEmail();
    phoneNumber = other.getPhoneNumber();
    city = other.getCity();
    type = other.getType();

    for (auto group : other.groups)
    {
        groups.push_back(group);
    }

    for (auto tag : other.tags)
    {
        tags.push_back(tag);
    }
}


// =============================================================================
// MARK: Setters
// =============================================================================

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


// =============================================================================
// MARK: Adders
// =============================================================================

void Contact::addTag(string newTag) {
    // Variable
    bool hasTag = false;

    // Check to see if the contact already has the tag.
    for (int i = 0; i < tags.size(); i++)
    {
        if (tags[i] == newTag)
        {
            hasTag = true;
        }
    }

    // If it is not included, add it.
    if (!hasTag)
    {
        tags.push_back(newTag);
    }
}

void Contact::addGroup(string newGroup) {
    // Variable
    bool hasGroup = false;
    
    // Check to see if allGroups already has the new group.
    for (int i = 0; i < groups.size(); i++)
    {
        if (groups[i] == newGroup)
        {
            hasGroup = true;
        }
    }

    // If it is not included, add it.
    if (!hasGroup)
    {
        groups.push_back(newGroup);
    }
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

void Contact:: removeTag(string tagKey) {
    for (int i = 0; i < tags.size(); i++) {
        if (tags[i] == tagKey) {
            tags.erase(tags.begin() + i);
            return;
        }
    }
}


// =============================================================================
// MARK: Getters
// =============================================================================

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


// =============================================================================
// MARK: Console IO
// =============================================================================

// Prints info to console line by line
void Contact::printInfo() const {
    // Constants
    const int COL_WIDTH = 12;

    cout << left;
    cout << setw(COL_WIDTH) << "Name" << ": " << name << endl;
    cout << setw(COL_WIDTH) << "Email" << ": " << email << endl;
    cout << setw(COL_WIDTH) << "Phone Number" << ": " << phoneNumber << endl;
    cout << setw(COL_WIDTH) << "City" << ": " << city << endl;
    cout << setw(COL_WIDTH) << "Contact Type" << ": " << ContactTypeToString(type) << endl;

    cout << setw(COL_WIDTH) << "Groups" << ": ";
    for (int i = 0; i < groups.size(); i++) {
        if (i < groups.size() - 1) {
            cout << groups[i] << ", ";
        } else {
            cout << groups[i];
        }
    }
    cout << endl;

    cout << setw(COL_WIDTH) << "Tags" << ": ";
    for (int i = 0; i < tags.size(); i++) {
        if (i < tags.size() - 1) {
            cout << tags[i] << ", ";
        } else {
            cout << tags[i];
        }
    }
    cout << endl;
    cout << right;
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
    in.ignore(10000, '\n');

    type = ContactType(contactType);

    // Import Groups
    in >> groupSize;
    in.ignore(10000, '\n');

    for (int _ = 0; _ < groupSize; _++)
    {
        getline(in, group);
        groups.push_back(group);
    }

    // Import Tags
    in >> tagSize;
    in.ignore(10000, '\n');

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