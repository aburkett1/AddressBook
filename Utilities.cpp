#include "Utilities.h"

// MARK: Application Setup
vector<Menu> setupMenus()
{
    // Variables
    vector<Menu> menus;

    /*
        MENU HIERARCHY
    
        Main Menu
            Manage Contacts
                Add a Contact
                Edit Contact Menu
                    Edit Contact
                    Delete Contact
                    Add a Group
                    Remove a Group
                    Add a Tag
                    Remove a Tag
                List All Contacts
            Search and Filter Contacts
                Search Contacts
                    By Name
                    By Email
                    By Number
                Filter Contacts
                    By Contact Type
                        Person
                        Business
                        Vendor
                        Emergency
                    By City
                    By Tag
            Import or Export Contacts
                Import File
                Export File
            Reports
                List by Type
                Incomplete Contacts
                Group Summaries
    */
    
    // Main Menu
    vector<string> mainMenuOptions = {
        "Manage Contacts", 
        "Search and Filter Contacts", 
        "Import or Export Contacts", 
        "Reports"
    };
    Menu mainMenu = Menu("MAIN MENU", mainMenuOptions);
    menus.push_back(mainMenu);

    // Manage Contacts
    vector<string> manageContactsMenuOptions = {
        "Add a Contact",
        "View Contact Details",
        "List All Contacts"
    };
    Menu manageContactsMenu = Menu("MANAGE CONTACTS", manageContactsMenuOptions);
    menus.push_back(manageContactsMenu);

    // View Contacts
    vector<string> editContactMenuOptions = {
        "Edit Contact",
        "Delete Contact",
        "Add a Group",
        "Remove a Group",
        "Add a Tag",
        "Remove a Tag"
    };
    Menu editContactMenu = Menu("EDIT CONTACT", editContactMenuOptions);
    menus.push_back(editContactMenu);

    // Find Contacts
    vector<string> findContactsMenuOptions = {
        "Search Contacts",
        "Filter Contacts"
    };
    Menu findContactsMenu = Menu("FIND CONTACTS", findContactsMenuOptions);
    menus.push_back(findContactsMenu);

    // Search Contacts
    vector<string> searchContactsMenuOptions = {
        "By Name",
        "By Email",
        "By Number"
    };
    Menu searchContactsMenu = Menu("SEARCH CONTACTS", searchContactsMenuOptions);
    menus.push_back(searchContactsMenu);

    // Filter Contacts
    vector<string> filterContactsMenuOptions = {
        "By Contact Type",
        "By City",
        "By Tag"
    };
    Menu filterContactsMenu = Menu("FILTER CONTACTS", filterContactsMenuOptions);
    menus.push_back(filterContactsMenu);

    // Contact Type
    vector<string> contactTypeMenuOptions = {
        "Person",
        "Business",
        "Vendor",
        "Emergency"
    };
    Menu contactTypeMenu = Menu("CONTACT TYPES", contactTypeMenuOptions);
    menus.push_back(contactTypeMenu);

    // File Menu
    vector<string> fileMenuOptions = {
        "Import File",
        "Export File"
    };
    Menu fileMenu = Menu("IMPORT OR EXPORT", fileMenuOptions);
    menus.push_back(fileMenu);

    // Report Menu
    vector<string> reportMenuOptions = {
        "List by Type",
        "Incomplete Contacts",
        "Group Summaries"
    };
    Menu reportMenu = Menu("IMPORT OR EXPORT", reportMenuOptions);
    menus.push_back(reportMenu);

    // Return vector of all Menus.
    return menus;
}


// MARK: User Input
Contact getContactDetails(Menu& typeMenu)
{
    string name{};
    string email{};
    string phoneNumber{};
    string city{};
    ContactType type{};
    int typeSelection{};
    
    cout << "Name: ";
    getline(cin, name);

    cout << "Email: ";
    getline(cin, email);

    cout << "Phone Number: ";
    getline(cin, phoneNumber);

    cout << "City: ";
    getline(cin, city);

    typeSelection = typeMenu.displayMenu();
    if (typeSelection != 0)
    {
        type = ContactType(typeSelection - 1);
    }

    return Contact(name, email, phoneNumber, city, type);
}

string getContactName()
{
    // Variables
    string name{};

    // Get name from user
    cout << "Name of Contact: ";
    getline(cin, name);

    return name;
}

string getEmail()
{
    // Variables
    string email{};

    // Get name from user
    cout << "Email of Contact: ";
    getline(cin, email);

    return email;
}

string getNumber()
{
    // Variables
    string number{};

    // Get name from user
    cout << "Number of Contact: ";
    getline(cin, number);

    return number;
}

string getCity()
{
    // Variables
    string city{};

    // Get name from user
    cout << "City: ";
    getline(cin, city);

    return city;
}

string getGroup()
{
    // Variables
    string group{};

    // Get group from user
    cout << "Group: ";
    getline(cin, group);

    return group;
}

string getTag()
{
    // Variables
    string tag{};

    // Get group from user
    cout << "Tag: ";
    getline(cin, tag);

    return tag;
}

string getFileName()
{
    // Variables
    string fileName{};

    // Get group from user
    cout << "File Name: ";
    getline(cin, fileName);

    return fileName;
}

int userSelection(vector<Contact>& results)
{
    // Variables
    int selection{};
    bool valid = false;

    while (!valid) {
        cout << "Select Contact Option (1-" << results.size() << "), enter 0 to cancel: ";

        // Check for numerical input
        if (!(cin >> selection)) {
            cin.clear();
            cin.ignore(10000, '\n');
            printLine();
            cout << "Invalid input.\nPlease select Contact Option (1-" << results.size() << "), enter 0 to cancel.\n";
            printLine();
        } else {
            cin.ignore(10000, '\n');

            // Allows for user to return to previous page
            if (selection == 0) return -1;

            if (selection < 1 || selection > results.size()) {
                printLine();
                cout << "Invalid input.\nPlease select Contact Option (1-" << results.size() << "), enter 0 to cancel.\n";
                printLine();
            } else {
                valid = true;
            }
        }
    }

    // Return index
    return selection - 1;
}

void pressEnterToContinue() {
    cout << "Press [ENTER] to continue...";
    cin.ignore(10000, '\n');
}


// MARK: Output
void printLine(int lineWidth)
{
    cout << setfill('-');
    cout << setw(lineWidth) << '-' << endl;
    cout << setfill(' ');
}

void displayResults(vector<Contact>& results)
{
    for (auto result : results)
    {
        printLine();
        result.printInfo();
    }

    printLine();
}

void displaySelection(vector<Contact>& results)
{
    displayTitle("SELECT CONTACT");
    
    for (int i = 0; i < results.size(); i++)
    {
        displayTitle(i+1);
        results[i].printInfo();
    }
}

void displayContact(Contact& selectedContact)
{
    printLine();
    selectedContact.printInfo();
    printLine();
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}