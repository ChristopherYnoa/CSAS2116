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

int arr_size = 1000;
int array_length = 0;

// exist : string -> boolean
// purpose : To check whether the given ssn is exist or not
bool exist(string ssn, struct ssninfo array[])
{
    for (int i = 0; i < arr_size; i++)
        if (array[i].ssn == ssn)
            return true;
        else
        {
            return false;
        }
}

int existLocation(string ssn, struct ssninfo array[])
{

    if (exist(ssn, array))
    {

        for (int i = 0; i < arr_size; i++)
            if (array[i].ssn == ssn)
                return i;
    }
}

// insert : string, string -> boolean
// purpose : To add ssn and name in the array
bool insert(string ssn, string name, struct ssninfo array[])
{
    bool a = exist(ssn, array);
    if (a == true)
    {
        return false;
    }
    else
    {
        if (array_length >= arr_size)
        {
            arr_size = 2 * arr_size;
            array[array_length].ssn = ssn;
            array[array_length].name = name;
        }
        else
        {

            array[array_length].ssn = ssn;
            array[array_length].name = name;
        }
        array_length++;
        return true;
    }
}

// del : string -> boolean
// purpose : To delete name from the array based on ssn
bool del(string ssn, struct ssninfo array[])
{ /*
     for (int i = 0; i < arr_size; i++)
         if (array[i].ssn == ssn)
         {
             array[i].ssn = ' ';
             return true;
         }*/
    if (exist(ssn, array) == true)
    {
        int temp = existLocation(ssn, array);

        // string temp = array[];

        for (int i = temp; i < (array_length - 1); ++i)
        {
            array[i] = array[i + 1];
        }

        array[array_length - 1] = {};
        array_length--;
        return true;
    }
    return false;
}
// retrive: string, string, array -> bool
// purpose: To retrive ssn and name from the array
bool retrive(string ssn, string name, struct ssninfo array[])
{
    bool a = (exist(ssn, array));

    if (a != true)
    {
        return false;
    }
    else
    {
        for (int i = 0; i <= arr_size; i++)
            if (array[i].name == name)
            {
                return true;
            }
            else
            {
                return false;
            }
    }
}

// implement the file open codes bason the reference document given
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
            int i = 0;
            while (getline(newfile, tp))
            { // read data from file object and put it into string.

                string op = tp.substr(0, 1); // get the operation - insert/delete/replace

                string ssn = tp.substr(2, 10);
                string name = tp.substr(11);
                // cout << op << " : " << ssn << " " << name << "\n"; // print the data of the string
                ssninfo *array = new ssninfo[1000];

                if (op.compare("i") == 0)
                {

                    // cout << "SSN: " << array[i].ssn << "Name:" << array[i].name << endl;
                    if (insert(ssn, name, array) == true)
                    {
                        iCounter++;
                    }
                }

                /* else if (op.compare("d") == 0)
                         {
                             if (del(ssn, array) == true)
                             {
                                 dCounter++;

                             }


                         }*/

                else if (op.compare("r") == 0)
                {
                    if (retrive(ssn, name, array) == true)
                    {
                        rCounter++;
                    }
                }
                i++;
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
// TEST(TestCaseName, TestName)
// {
//     string ssn("631213674"); // this ssn is not present already
//     string name("Mike Hussey");
//     ssninfo* array = new ssninfo[1000];

//   //INSERT
//   EXPECT_EQ(true, insert(ssn, name, array));
//   EXPECT_EQ(false, insert(ssn, name, array));

//   //RETRIVE
//   EXPECT_EQ(true, retrive(ssn, name, array));

//   //DEL
//   EXPECT_EQ(true, del(ssn, array));
//   EXPECT_EQ(false, del(ssn, array));

// }