#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <iomanip>
using namespace std;

class Menu
{
public:
    Menu();
    Menu(string title, vector<string>& options);
    ~Menu();

    void addTitle(string title);
    void addOptions(vector<string>& options);
    int displayMenu();
    bool verifySelection(int selection);

private:
    string title;
    vector<string> options;
};

#endif