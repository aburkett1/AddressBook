#include "Menu.h"


// MARK: Constructors
Menu::Menu() 
{
    title = "";
}

Menu::Menu(string title, vector<string>& options)
{
    this->title = title;
    this->options = options;
}

Menu::~Menu() {}


// MARK: Adders
void Menu::addTitle(string title)
{
    this->title = title;
}

void Menu::addOptions(vector<string>& options)
{
    for (int i = 0; i < options.size(); i++)
    {
        this->options.push_back(options[i]);
    }
}


// MARK: Utility
int Menu::displayMenu()
{
    // Variables
    int selection{};
    
    // Set Fill Character
    cout << setfill('-');

    // Display Title
    cout << setw(79) << '-' << endl;
	cout << "   " << title << endl;
	cout << setw(79) << '-' << endl;

	// Display Options
    for (int i = 0; i < options.size(); i++)
    {
        cout << i + 1 << " - " << options[i] << endl;
    }

    // Display Exit / Return
    cout << 0 << " - " << (title == "MAIN MENU" ? "Exit Program" : "Return to Previous Page") << endl;

    // Get User Selection
    selection = getUserSelection();

    // Print line & Reset Fill
    cout << setw(79) << '-' << endl;
    cout << setfill(' ');

    return selection;
}

int Menu::getUserSelection()
{
    // Variables
    int selection{};

    while(true) {
        // Print line
        cout << setw(79) << '-' << endl;

        // Get Selection from User
        cout << "Please Select Option: ";
        if (cin >> selection && verifySelection(selection)) {
            cin.ignore(10000, '\n');
            return selection;
        }

        // Print line
        cout << setw(79) << '-' << endl;

        cout << "Invalid input.\nPlease select the option you wish to perform by the number to its left.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

bool Menu::verifySelection(int selection)
{
    return selection >= 0 && selection <= options.size();
}
