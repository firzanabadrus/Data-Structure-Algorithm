// Lab 1 - SECJ2013 - 24251 (Lab1.cpp)
// Group Members:
// 1. NUR FIRZANA BINTI BADRUS HISHAM   A23CS0156
// 2. LUBNA AL HAANI BINTI RADZUAN      A23CS0107

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

// main function
int main() {
    const int LIST_SIZE = 10;
    Student* studList[LIST_SIZE];
    string n;
    int c, f;

    fstream inFile("Marks.txt", ios::in );
    cout << "Student mark info: " << endl;

    int i = 0;
    while( i < LIST_SIZE && (inFile >> n >> c >> f) ){
        studList[i] = new Student(n, c, f);
        studList[i]->printInfo();
        i++ ;
    }

    fstream outFile("Results.txt", ios::out) ;
    cout << "\nPrint and save result to file: " << endl;
    
    for(int c = 0 ; c < i ; ++c ){
        studList[c]->printResult();
        studList[c]->printResultFile(outFile);
        delete studList[c];
    }

    inFile.close();
    outFile.close();

    system("pause");
    return 0;
}
