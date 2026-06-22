#include <iostream>
#include <string>

using namespace std;

class Node {
  public:
    char data;
    Node *next, *prev;
};

int main() {
  Node *head = NULL, *last = NULL;
  char items[] = {'U','C','M','T','K'};

  for (int i = 0; i < 5; i++) {
    Node *nn = new Node();
    nn->data = items[i];

    if (head == NULL) {
      head = nn;

    } else {
      last->next = nn;
      nn->prev = last;
    }

    head->next = NULL;
    nn->prev = head;

    last = nn;
  }
  system("pause");
  
}