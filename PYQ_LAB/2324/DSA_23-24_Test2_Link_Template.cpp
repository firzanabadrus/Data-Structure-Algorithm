//////////////////// Test 2, 2023/2024 (Sem 1) //////////////////////
// Name:
// Matrics No: 
// Date/ Day: 3rd January 2024 (Wednesday)
// Circular Linked-list
/////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Node {
    char ch;

public:
    Node* next;
    Node(char c) { ch = c; next = NULL; }
    char getChar() { return ch; }
};

class List {
    Node* head;

public:
    List() { head = NULL; }
    bool isEmpty() { return head == NULL; }

    void insertNode(Node*);
    void deleteNode();
    string findNode(char);
    void displayList();
};

// Question 1 - 2 a): Implement insertNode function
//-------------------------------------------


// End of Question 1 - 2 a)

// Question 1 - 2 b): Implement deleteNode function
//-------------------------------------------



// End of Question 1 - 2 b)

// Question 1 - 2 c): Implement findNode function
//-------------------------------------------



// End of Question 1 - 2 c)

// Question 1 - 2 d): Implement displayList function
//-------------------------------------------



// End of Question 1 - 2 d)

int main() {
    // Question 1 - 3 a): Create List
    //-------------------------------------------

    // End of Question 1 - 3 a)


    // Question 1 - 3 b): Write your answer here
    //-------------------------------------------
    

    // End of Question 1 - 3 b)
    
    return 0;
}
