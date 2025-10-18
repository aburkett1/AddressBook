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
        switch (selection)
        {
        case 1: // MARK: Manage Contacts
            selection = manageContactsMenu.displayMenu();

            while (selection != 0)
            {
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

                    // Display results for selection
                    displayResults(searchResultsContacts);

                    // Get user selection (contactSelection self-verifies)
                    selectedIndex = contactSelection(searchResultsContacts);
                    selectedContact = searchResultsContacts[selectedIndex];

                    // Display the selected contact
                    displayContact(selectedContact);

                    // Display Edit Menu
                    selection = editContactMenu.displayMenu();
                    while (selection != 0)
                    {
                        switch (selection)
                        {
                        case 1: // Edit Contact
                            addressBook.editContact(getContactDetails(contactTypeMenu), selectedIndex);
                            break;

                        case 2: // Delete Contact
                            addressBook.removeContact(selectedIndex);
                            cout << "Contact Removed.";
                            break;

                        case 3: // Add a Group
                            addressBook.addGroupToContact(getGroup(), selectedIndex);
                            break;

                        case 4: // Remove a Group
                            addressBook.removeGroupFromContact(getGroup(), selectedIndex);
                            break;

                        case 5: // Add a Tag
                            addressBook.addTagToContact(getTag(), selectedIndex);
                            break;

                        case 6: // Remove a Tag
                            addressBook.removeTagFromContact(getTag(), selectedIndex);
                            break;
                        
                        default:
                            break;
                        }

                        if (selection == 2)
                        {
                            break;
                        }

                        selection = editContactMenu.displayMenu();
                    }
                    
                    break;

                case 3: // List All Contacts
                    addressBook.printContacts();
                    break;
                
                default:
                    break;
                }

                selection = manageContactsMenu.displayMenu();
            }

            break;

        case 2: // MARK: Search and Filter Contacts
            selection = findContactsMenu.displayMenu();
            while (selection != 0)
            {
                switch (selection)
                {
                case 1: // Search Contacts
                    selection = searchContactsMenu.displayMenu();
                    while (selection != 0)
                    {
                        switch (selection)
                        {
                        case 1: // By Name
                            searchResultsContacts = addressBook.searchByName(getContactName());
                            displayResults(searchResultsContacts);
                            break;
                        
                        case 2: // By Email
                            searchResultsContacts = addressBook.searchByEmail(getEmail());
                            displayResults(searchResultsContacts);
                            break;

                        case 3: // By Number
                            searchResultsContacts = addressBook.searchByNumber(getNumber());
                            displayResults(searchResultsContacts);
                            break;

                        default:
                            break;
                        }
                        
                        selection = searchContactsMenu.displayMenu();
                    }

                    break;

                case 2: // Filter Contacts
                    selection = filterContactsMenu.displayMenu();
                    while (selection != 0)
                    {
                        switch (selection)
                        {
                        case 1: // By Contact Type
                            selection = contactTypeMenu.displayMenu();

                            if (selection != 0)
                            {
                                searchResultsContacts = addressBook.filterByType(ContactType(selection - 1));
                                displayResults(searchResultsContacts);
                            }
                            
                            break;
                        
                        case 2: // By City
                            searchResultsContacts = addressBook.filterByCity(getCity());
                            displayResults(searchResultsContacts);
                            break;

                        case 3: // By Tag
                            searchResultsContacts = addressBook.filterByTag(getTag());
                            displayResults(searchResultsContacts);
                            break;
                        
                        default:
                            break;
                        }

                        selection = filterContactsMenu.displayMenu();
                    }

                    break;
                
                default:
                    break;
                }

                selection = findContactsMenu.displayMenu();
            }

            break;

        case 3: // MARK: Import or Export Contacts
            selection = fileMenu.displayMenu();
            while (selection != 0)
            {
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

                selection = fileMenu.displayMenu();
            }

            break;

        case 4: // MARK: Reports
            selection = reportMenu.displayMenu();
            while (selection != 0)
            {
                switch (selection)
                {
                case 1: // List by Type
                    addressBook.listReportContacts();
                    break;
                
                case 2: // Incomplete Contacts
                    searchResultsContacts = addressBook.filterByMissing();
                    displayResults(searchResultsContacts);
                    break;

                case 3: // Group Summaries
                    addressBook.reportGroupSummaries();
                    break;

                default:
                    break;
                }

                selection = reportMenu.displayMenu();
            }

            break;
        
        default:
            break;
        }

        selection = mainMenu.displayMenu();
    }


    
    return 0;
} // end of main()
// =============================================================================