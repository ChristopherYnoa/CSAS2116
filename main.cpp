// Project 1 - Database Management using Arrays

#include <iostream>
#include <fstream> //header file for file handling system
#include <string>
using namespace std;

// create the structure for ssn and name
struct ssninfo
{
    string ssn;
    string name;
};

// exist : string -> boolean
// purpose : To check whether the given ssn is exist or not
bool exist(string ssn)
{
}
// insert : string, string -> boolean
// purpose : To add ssn and name in the array
bool insert(string ssn, string name)
{
}

// del : string -> boolean
// purpose : To delete name from the array based on ssn
bool del(string ssn)
{
}
// implemet retrive function

// implement the file open codes bason the reference document given
int main()
{
    fstream newfile;
    newfile.open("500-idr", ios::in); // open the file

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
