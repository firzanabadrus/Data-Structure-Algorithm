#include <iostream>
#include <string>

using namespace std;

// List class definition
class List {
    private:
        Student *head, *last;
        
    public:
        List() { 
            // CONSTRUCTOR
            cout << "Create list...\n";
            head = NULL; last = NULL;
        }
        
        // INSERTNODE OPS
        void insertNode(Student *newStud) {
        	cout << "Insert " << newStud->getName() << "\n";

            if (head == NULL || head->getName() > newStud->getName()){
                newStud->setNext(head);
                head = newStud;

                if (last == NULL){
                    last = newStud;
                }
                return;
            }

            Student *current = head;
            while (current->getNext() != NULL && current->getNext()->getName() < newStud->getName()) {
                current = current->getNext();
            }

            newStud->setNext(current->getNext());
            current->setNext(newStud);
            
            if(newStud->getNext() == NULL) {
                last = newStud;
            }
        }
        
        // FINDNODE OPS
        Student *findNode(string name) {
            Student *current = head;
            // int currIndex = 1;
            while (current != NULL){
                if (current->getName() == name){
                    return current;
                }
                current = current->getNext();
            }
            return NULL;
        }

        // DELETENODE OPS
        void deleteNode(string name) {
            // Student *stud, *prev;
			// stud = head;
             if (head == NULL) {
            return;
        }

        if (head->getName() == name) {
            Student *temp = head;
            head = head->getNext();
            if (head == NULL) {
                last = NULL;
            }
            delete temp;
            return;
        }

        Student *current = head;
        while (current->getNext() != NULL && current->getNext()->getName() != name) {
            current = current->getNext();
        }

        if (current->getNext() == NULL) {
            return; // Node not found
        }

        Student *temp = current->getNext();
        current->setNext(temp->getNext());
        if (temp->getNext() == NULL) {
            last = current;
        }
        delete temp;
        }
            
            // DISPLAYLIST OPS
            void displayList() {
                Student *stud = head;
                
                while (stud != NULL) {
                    stud->printResult();
                    stud = stud->getNext();
                }
            }
        
        Student *getHead() { return head; }
        Student *getLast() { return last; }
        
        // DESTRUCTOR
        ~List() {
        	Student *stud = head;
        	cout << "Destroy list...\n";
        	while (stud != NULL) {
        		Student *prevStud = stud;
        		stud = stud->getNext();
                cout << "Destroy student object - " <<prevStud->getName() << "\n";
        		delete prevStud;
			}
		}
};
