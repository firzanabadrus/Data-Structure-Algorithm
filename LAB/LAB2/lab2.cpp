// Lab 2 - SECJ2013 - 23241 (Lab2.cpp)
// Group Members:
// 1. Firzana
// 2. [Partner's Name]

#include <iostream>
using namespace std;

// Recursive function to print stars
void printStar(int n) {
    if (n <= 0) 
		return;
    cout << "*";
    printStar(n - 1);
}

// Recursive function to print numbers and corresponding stars
void printNum(int n, int current = 1) {
    if (current > n) 
		return;
    cout << current << " - ";
    printStar(current);
    cout << endl;
    printNum(n, current + 1);
}

// Recursive function to calculate the sum of odd numbers
int totalOdd(int list[], int n, int index = 0, int total = 0) {
    if (index >= n) 
		return total;
    if (list[index] % 2 != 0) {
        cout << list[index] << " ";
        total += list[index];
    }
    return totalOdd(list, n, index + 1, total);
}

// Main function
int main() {
    // Printing stars based on the numbers
    printNum(6);

    cout << "\n\n";

    // List of numbers to find the sum of odd numbers
    int num[6] = {0, 1, 2, 3, 4, 5};
    int result = totalOdd(num, 6);
    cout << "= " << result << endl;

    system("pause");
    return 0;
}
