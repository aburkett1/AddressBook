#include "Utilities.h"

vector<Menu> setupMenus()
{
    // Variables
    vector<Menu> menus;
    
    // Main Menu
    vector<string> mainMenuOptions = {
        "Manage Contacts", 
        "Search Contacts", 
        "Import or Export Contacts", 
        "Display Contacts"
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
    vector<string> viewContactsMenuOptions = {
        "Edit Existing Contact",
        "Delete Contact",
        "Set Contact Group",
        "Add a Tag",
        "Remove a Tag"
    };
    Menu viewContactsMenu = Menu("VIEW CONTACTS", viewContactsMenuOptions);
    menus.push_back(viewContactsMenu);

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