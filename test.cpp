// Project 1 - Array implementation using File handing system
//  Prof. Shajina Anand
//  Course : CSAS2126

// Sample code for count insert/delete and retrive operation from the given file
// Make sure the files 15-idr/500-idr are kept in the same place where the source.cpp file's location

#include <iostream>
#include <fstream> //header file for file handling system
#include <string>
using namespace std;

int main()
{
    fstream newfile;
    newfile.open("15-idr", ios::in); // open the file

    int iCounter = 0;
    int dCounter = 0;
    int rCounter = 0;

    if (!newfile)
    {
        cout << "No such file";
    }
    else
    {
        if (newfile.is_open())
        { // checking whether the file is open
            string tp;
            while (getline(newfile, tp))
            { // read data from file object and put it into string.

                string op = tp.substr(0, 1); // get the operation - insert/delete/replace

                string ssn = tp.substr(2, 10);
                string ssn_array[15];

                string name = tp.substr(11);
                cout << op << " : " << ssn << " " << name << "\n"; // print the data of the string

                if (op.compare("i") == 0)
                {

                    iCounter++;
                }

                else if (op.compare("d") == 0)
                {

                    dCounter++;
                }

                else if (op.compare("r") == 0)
                {
                    rCounter++;
                }
            }
            newfile.close(); // close the file object.
            cout << " iCounter " << iCounter << endl;
            cout << " dCounter " << dCounter << endl;
            cout << " rCounter " << rCounter << endl;
        }
    }
    newfile.close();
    return 0;
}