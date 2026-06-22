// Assignment 1 - SECJ2013 - 23241 (Assg1.cpp)
// Group Members:
// 1. ???
// 2. ???
// 3. ???

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

// function headers
void listStudent(Student *[], int);
void sortName(Student *[], int);
void sortGrade(Student *[], int);

// main function
int main()
{
    const int LIST_SIZE = 10;
    string name;
    int cw, fe, idx = 0;
    Student *studList[LIST_SIZE];

    fstream fileIn("Marks.txt", ios::in);

    if (!fileIn)
    {
        cout << "File input/output error!\n";
        return 1;
    }
    else
    {
        while (fileIn >> name >> cw >> fe)
        {
            studList[idx] = new Student(name, cw, fe);
            idx++;
        }

        int opt = 0;

        while (opt != 4)
        {
            cout << "\n1. List results (original list)";
            cout << "\n2. List results (sort by name)";
            cout << "\n3. List results (sort by grade)";
            cout << "\n4. Exit\n\n";

            cout << "Enter your choice [1, 2, 3, 4]: ";
            cin >> opt;

            if (opt == 1)
            {
                listStudent(studList, idx);
            }
            else if (opt == 2)
            {
                sortName(studList, idx);
                listStudent(studList, idx);
            }
            else if (opt == 3)
            {
                sortGrade(studList, idx);
                listStudent(studList, idx);
            }

            if (opt != 4)
                system("pause");
        }

        fileIn.close();
    }

    return 0;
}

// function implementation
void listStudent(Student *sl[], int size)
{
    for (int i = 0; i < size; i++)
    {
        sl[i]->printResult();
    }
}

void sortName(Student *sl[], int size)
{
    bool sorted = false;
    for (int i = 0; i < size - 1; i++)
    {
        sorted = true;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (sl[j]->getName() > sl[j + 1]->getName())
            {
                Student *temp = sl[j];
                sl[j] = sl[j + 1];
                sl[j + 1] = temp;
                sorted = false;
            }
        }
    }
}

void sortGrade(Student *sl[], int size)
{
    bool sorted = false;
    for (int i = 0; i < size; i++)
    {
        sorted = true;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (sl[j]->getGrade() > sl[j + 1]->getGrade())
            {
                Student *temp = sl[j];
                sl[j] = sl[j + 1];
                sl[j + 1] = temp;
                sorted = false;
            }
        }
    }
}
