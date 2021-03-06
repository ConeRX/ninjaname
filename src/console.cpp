#include <iostream>
#include <string>
#include <sstream>
#include "file_operations.h"
#include "name.h"
#include "console.h"
using namespace std;

void consoleOutput() {
    bool menu = true;

    while(menu)
    {
        cout << "Menu: \n";
        cout << "1 - Morph your firstname into a Ninja name.\n";
        cout << "2 - Demorph your Ninja name back into your firstname. \n";
        cout << "3 - Look up history. \n";
        cout << "4 - Exit.\n";

        string test;
        getline(cin, test);

        if (test.compare("1") == 0)
        {
            char firstname[256];
            do
            {
                cout << "Please enter your first name: ";
                cin.getline(firstname, 256);
            } while (isValid(firstname) == false);

            string genninja = morph(firstname);

            cout << genninja << endl;

            writeFile("history.txt", genninja + '\n');
        }

        else if (test.compare("2") == 0)
        {
            char ninjaname[256];
            do
            {
                cout << "Please enter your Ninja name: ";
                cin.getline(ninjaname, 256);
            } while (isValid(ninjaname) == false);

            string tmp = ninjaname;

            try
            {
                string genvor = demorph(tmp);
                cout << genvor << endl;
            } catch (const char * msg) { cerr << msg << endl; }
        }

	else if (test.compare("3") == 0)
	{
	    readFile("history.txt");
	}

        else if (test.compare("4") == 0)
        {
            cout << "Program will exit now.\n";
            menu  = false;
        }

        else
        {
            cout << "Invalid input. Repeat input.\n";
        }
    }
}
