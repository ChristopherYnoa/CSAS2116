#include "pch.h"
// Project 1 - Database Management using Arrays

#include <iostream>
#include <fstream> //header file for file handling system
#include <string>
#include <cstdio>
#include <ctime>
using namespace std;

// create the structure for ssn and name
struct ssninfo
{
    string ssn;
    string name;
};

int arr_size = 500;
int array_length;

// exist : string, struct, int -> boolean
// purpose : To check whether the given ssn is exist or not
bool exist(string ssn, struct ssninfo array[], int arr_size)
{
    int i = 0;
    while (i != arr_size)
    {
        if (ssn == array[i].ssn)
        {
            return true;
        }
        i++;
    }
    return false;
}

int existLocation(string ssn, struct ssninfo array[], int arr_size)
{

    if (exist(ssn, array, arr_size))
    {

        for (int i = 0; i < arr_size; i++)
            if (array[i].ssn == ssn)
                return i;
    }
}

// insert : string, string, struct, int -> boolean
// purpose : To add ssn and name in the array
bool insert(string ssn, string name, struct ssninfo array[], int arr_size)
{
    bool a = exist(ssn, array, arr_size);
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

// del : string, struct, int -> boolean
// purpose : To delete name from the array based on ssn
bool del(string ssn, struct ssninfo array[], int arr_size)
{
    if (exist(ssn, array, arr_size) == true)
    {
        int temp = existLocation(ssn, array, arr_size);

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
// retrive: string, string, struct, int -> bool
// purpose: To retrive ssn and name from the array
bool retrive(string ssn, string name, struct ssninfo array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        if ((array[i].ssn == ssn) && !name.compare(array[i].name))
        {
            return true;
        }
    }
    return false;
}

// implement the file open codes bason the reference document given
int main()
{
    clock_t start, end;
    double duration;

    start = clock();
    fstream newfile;

    newfile.open("15-idr", ios::in); // open the file

    int iCounter = 0;
    int dCounter = 0;
    int rCounter = 0;

    // int arr_size = 500;

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
            ssninfo *array = new ssninfo[arr_size];
            while (getline(newfile, tp))
            { // read data from file object and put it into string.

                string op = tp.substr(0, 1); // get the operation - insert/delete/replace
                string ssn = tp.substr(2, 10);
                string name = tp.substr(11);

                if (op.compare("i") == 0)
                {

                    if (insert(ssn, name, array, arr_size) == true)
                    {
                        iCounter++;
                    }
                }

                else if (op.compare("d") == 0)
                {
                    if (del(ssn, array, arr_size) == true)
                    {
                        dCounter++;
                    }
                }

                else if (op.compare("r") == 0)
                {

                    if (retrive(ssn, name, array, array_length) == true)
                    {
                        rCounter++;
                    }
                }
                i++;
            }
            newfile.close(); // close the file object.

            cout << " The Number of Valid Insertion: " << iCounter << endl;
            cout << " The Number of Valid Deletion: " << dCounter << endl;
            cout << " The Number of Valid Retireval: " << rCounter << endl;
            cout << " Item numbers in the array: " << iCounter - dCounter << endl;
            cout << " Array Size is: " << arr_size << endl;

            end = clock();
            duration = (end - start) / (double)CLOCKS_PER_SEC;

            cout << " Time elapsed: " << duration << '\n';
        }
    }
    newfile.close();
    return 0;
}

// test case to check whether it exist or not
TEST(FriendlyIRS_sample_idr, existcheck)
{
    string ssn("631213674"); // this ssn is not present already
    string ssn1("238713674");
    string name("Mike Hussey");
    ssninfo *array = new ssninfo[1000];
    int arr_size = 500;

    insert(ssn, name, array, arr_size);
    EXPECT_EQ(true, exist(ssn, array, arr_size));
    EXPECT_EQ(false, exist(ssn1, array, arr_size));
}

// test case for addition check
TEST(FriendlyIRS_sample_idr, additioncheck)
{
    string ssn("631213674"); // this ssn is not present already
    string ssn1("238713674");
    string name("Mike Hussey");
    ssninfo *array = new ssninfo[1000];
    int arr_size = 500;

    EXPECT_EQ(true, insert(ssn, name, array, arr_size));
    EXPECT_EQ(false, insert(ssn, name, array, arr_size));
}

// test cast for deletion check
TEST(FriendlyIRS_sample_idr, deletioncheck)
{
    string ssn("631213674"); // this ssn is not present already
    string ssn1("238713674");
    string name("Mike Hussey");
    ssninfo *array = new ssninfo[1000];
    int arr_size = 500;

    insert(ssn, name, array, arr_size);
    EXPECT_EQ(true, del(ssn, array, arr_size));
    EXPECT_EQ(false, del(ssn, array, arr_size));
}