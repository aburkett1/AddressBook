#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std;

class Menu
{
public:
    // Constructors
    Menu();
    Menu(string title, vector<string>& options);
    ~Menu();

    // Adders
    void addTitle(string title);
    void addOptions(vector<string>& options);

    // Utility
    int displayMenu();
    int getUserSelection();
    bool verifySelection(int selection);

private:
    string title;
    vector<string> options;
};

#endif