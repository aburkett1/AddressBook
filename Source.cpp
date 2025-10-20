#include "AddressBook.h"
#include "Utilities.h"

// ==== main ===================================================================
//
// =============================================================================
int main()
{
    // Variables
    int selection{};
    AddressBook addressBook = AddressBook();
    Contact selectedContact{};
    int selectedIndex{};
    vector<Contact> searchResultsContacts;
    vector<int> searchResultsIndexes;
    ifstream fin;
    ofstream fout;


    
    // MARK: Menu Creation
    vector<Menu> menus = setupMenus();
    Menu mainMenu = menus[0];
    Menu manageContactsMenu = menus[1];
    Menu editContactMenu = menus[2];
    Menu findContactsMenu = menus[3];
    Menu searchContactsMenu = menus[4];
    Menu filterContactsMenu = menus[5];
    Menu contactTypeMenu = menus[6];
    Menu fileMenu = menus[7];
    Menu reportMenu = menus[8];

    /*
        MARK: MENU HIERARCHY
    
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

    selection = mainMenu.displayMenu();

    while (selection != 0)
    {
        clearScreen();
        switch (selection)
        {
        case 1: // MARK: Manage Contacts
            clearScreen();
            selection = manageContactsMenu.displayMenu();

            while (selection != 0)
            {
                clearScreen();
                switch (selection)
                {
                case 1: // Add a Contact
                    addressBook.addContact(getContactDetails(contactTypeMenu));
                    break;
                
                case 2: // View Contact Details
                    // Search for Contact
                    displayTitle("VIEW CONTACT");

                    // Get name from user, Search by that name, and Store the results.
                    addressBook.searchByName(getContactName(), searchResultsContacts, searchResultsIndexes);

                    // Verify search results
                    if (searchResultsContacts.empty()) {
                        clearScreen();
                        cout << "No contacts found with that name.\n";
                        pressEnterToContinue();
                        break;
                    }

                    // Display results for selection
                    clearScreen();
                    displayResults(searchResultsContacts);

                    // Get user selection (contactSelection self-verifies)
                    selectedIndex = contactSelection(searchResultsContacts);

                    // Return to previous page if user enters 0
                    if (selectedIndex == -1) {
                        clearScreen();
                        break;
                    }

                    // Verify valid index
                    if (selectedIndex < 0 || selectedIndex >= searchResultsContacts.size()) {
                        clearScreen();
                        cout << "Invalid selection. Please enter number associated with available contacts.\n";
                        pressEnterToContinue();
                        break;
                    }

                    // Load and display selected contact
                    selectedContact = searchResultsContacts[selectedIndex];
                    displayContact(selectedContact);

                    // Display Edit Menu
                    clearScreen();
                    selection = editContactMenu.displayMenu();
                    while (selection != 0)
                    {
                        clearScreen();
                        switch (selection)
                        {
                        case 1: // Edit Contact
                            addressBook.editContact(getContactDetails(contactTypeMenu), searchResultsIndexes[selectedIndex]);
                            break;

                        case 2: // Delete Contact
                            addressBook.removeContact(searchResultsIndexes[selectedIndex]);
                            cout << "Contact Removed.";
                            break;

                        case 3: // Add a Group
                            addressBook.addGroupToContact(getGroup(), searchResultsIndexes[selectedIndex]);
                            break;

                        case 4: // Remove a Group
                            addressBook.removeGroupFromContact(getGroup(), searchResultsIndexes[selectedIndex]);
                            break;

                        case 5: // Add a Tag
                            addressBook.addTagToContact(getTag(), searchResultsIndexes[selectedIndex]);
                            break;

                        case 6: // Remove a Tag
                            addressBook.removeTagFromContact(getTag(), searchResultsIndexes[selectedIndex]);
                            break;
                        
                        default:
                            break;
                        }

                        // If contact was deleted, go back to previous menu instead of
                        // continuing in the edit menu.
                        if (selection == 2)
                        {
                            break;
                        }

                        clearScreen();
                        selection = editContactMenu.displayMenu();
                    }
                    
                    break;

                case 3: // List All Contacts
                    clearScreen();
                    addressBook.printContacts();
                    pressEnterToContinue();

                    break;
                
                default:
                    break;
                }

                clearScreen();
                selection = manageContactsMenu.displayMenu();
            }

            break;

        case 2: // MARK: Search and Filter Contacts
            clearScreen();
            selection = findContactsMenu.displayMenu();
            while (selection != 0)
            {
                clearScreen();
                switch (selection)
                {
                case 1: // Search Contacts
                    clearScreen();
                    selection = searchContactsMenu.displayMenu();
                    while (selection != 0)
                    {
                        clearScreen();
                        switch (selection)
                        {
                        case 1: // By Name
                            searchResultsContacts = addressBook.searchByName(getContactName());
                            displayResults(searchResultsContacts);
                            pressEnterToContinue();
                            break;
                        
                        case 2: // By Email
                            searchResultsContacts = addressBook.searchByEmail(getEmail());
                            displayResults(searchResultsContacts);
                            pressEnterToContinue();
                            break;

                        case 3: // By Number
                            searchResultsContacts = addressBook.searchByNumber(getNumber());
                            displayResults(searchResultsContacts);
                            pressEnterToContinue();
                            break;

                        default:
                            break;
                        }
                        
                        clearScreen();
                        selection = searchContactsMenu.displayMenu();
                    }

                    break;

                case 2: // Filter Contacts
                    clearScreen();
                    selection = filterContactsMenu.displayMenu();
                    while (selection != 0)
                    {
                        clearScreen();
                        switch (selection)
                        {
                        case 1: // By Contact Type
                            selection = contactTypeMenu.displayMenu();

                            if (selection != 0)
                            {
                                searchResultsContacts = addressBook.filterByType(ContactType(selection - 1));
                                displayResults(searchResultsContacts);
                                pressEnterToContinue();
                            }
                            
                            break;
                        
                        case 2: // By City
                            searchResultsContacts = addressBook.filterByCity(getCity());
                            displayResults(searchResultsContacts);
                            pressEnterToContinue();
                            break;

                        case 3: // By Tag
                            searchResultsContacts = addressBook.filterByTag(getTag());
                            displayResults(searchResultsContacts);
                            pressEnterToContinue();
                            break;
                        
                        default:
                            break;
                        }

                        clearScreen();
                        selection = filterContactsMenu.displayMenu();
                    }

                    break;
                
                default:
                    break;
                }

                clearScreen();
                selection = findContactsMenu.displayMenu();
            }

            break;

        case 3: // MARK: Import or Export Contacts
            clearScreen();
            selection = fileMenu.displayMenu();
            while (selection != 0)
            {
                clearScreen();
                switch (selection)
                {
                case 1: // Import File
                    fin.open(getFileName());
                    addressBook.importFromFile(fin);
                    fin.close();
                    break;

                case 2: // Export File
                    fout.open(getFileName());
                    addressBook.exportToFile(fout);
                    fout.close();
                    break;

                default:
                    break;
                }

                clearScreen();
                selection = fileMenu.displayMenu();
            }

            break;

        case 4: // MARK: Reports
            clearScreen();
            selection = reportMenu.displayMenu();
            while (selection != 0)
            {
                clearScreen();
                switch (selection)
                {
                case 1: // List by Type
                    addressBook.listReportContacts();
                    pressEnterToContinue();
                    break;
                
                case 2: // Incomplete Contacts
                    searchResultsContacts = addressBook.filterByMissing();
                    displayResults(searchResultsContacts);
                    pressEnterToContinue();
                    break;

                case 3: // Group Summaries
                    addressBook.reportGroupSummaries();
                    pressEnterToContinue();
                    break;

                default:
                    break;
                }

                clearScreen();
                selection = reportMenu.displayMenu();
            }

            break;
        
        default:
            break;
        }

        clearScreen();
        selection = mainMenu.displayMenu();
    }


    
    return 0;
} // end of main()
// =============================================================================