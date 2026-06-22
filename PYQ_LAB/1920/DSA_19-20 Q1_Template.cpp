////////////////////////////////////////////////////////////////////////////////
// School of Computing, Faculty of Engineering, UTM
// SCSJ2013- Data Structures and Algorithms
// Semester 1, 2019/2020
// Lab Test  - Question 1 Linked List (30 marks)
// Name - XXXX (Please replace with your name)
// Matric Number - XXXX (Please replace with your matric no)
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std; 

//Represents node of the linked list 
class Node { 
      public:
	      int num1; 
          int num2; 
	      Node* next; 
	      
	      Node(int a, int b)
	      {
              num1 = a;
	          num2 = b;	
	          next = NULL;
          }
}; //Node

void display(Node *head)    //Function to display - GIVEN
{
    cout << "\nTraverse and display linklist data" << endl;
    Node *current = head;
	while (current)
	{
        cout <<"|"<< current->num1 <<" "<< current->num2 <<"|"<<"\t" ;
        current = current->next;
    }
    cout << endl << endl;
} //display

int main()
{
	int counter = 0, f = 1;
	int s = 5; 
	
	//Code to insert 3 nodes - GIVEN  
    Node *head, *last;
	
	head = last = new Node(f, s);
           
	while (counter < 3)
	{
	    if (counter != 0)
	    {
	       f++;
	       s++;
	       last->next = new Node(f, s); 
	       last = last->next;
        }
	    counter++;
   }   

   display(head);   

   /////////////////////////////////////////////////////////////////////////////     
   //Task 1 : Write the code to calculate and display the sum of num1 value for 
   //         first and second node [4 marks]
   
   cout << "\nExecuting Task 1 - calculate the sum of num1 value for the first and "
   	 	<< "second node" << endl;
   
   int sum = 0;
   
   //Calculate the value of sum
   //Answer Task 1 start here  
   
   
   
   
   
   cout << "\nSum of num1 value in first and second node is equal to: " << sum << endl;    
   //Task 1 end   
   /////////////////////////////////////////////////////////////////////////////     
   
   /////////////////////////////////////////////////////////////////////////////     
   //Task 2 : Write the code to add 3 to the num2 value in all the nodes in the 
   //         linklist [6 marks]
   
   cout << "\nExecuting Task 2 - add 3 to num2 value in all the nodes" << endl;
   
   //Answer Task 2 start here  
   
   
   
   
  
  
  
   //Task 2 end
   /////////////////////////////////////////////////////////////////////////////     
   
   display(head);   
   
   /////////////////////////////////////////////////////////////////////////////     
   //Task 3 : Write the code to create a new node with data num1 = 5 and num2 = 12 
   //         and set it is as the new head [4 marks]

   cout << "\nExecuting Task 3 - add new node(5, 12) as new head" << endl;
   
   //Answer Task 3 start here  
   
   
   
   
   
   //Task 3 end   
   /////////////////////////////////////////////////////////////////////////////     
   
   display(head);
 
   /////////////////////////////////////////////////////////////////////////////     
   //Task 4 : Write the code to move the head to become the last node and then 
   //         set the second node as the new head [4 marks]

   cout << "\nExecuting Task 4 - set head to last and set second node as new head" << endl;
   
   //Answer Task 4 start here  
   
   
   
   
   
   //Task 4 end
   /////////////////////////////////////////////////////////////////////////////     
   
   display(head);
   
   /////////////////////////////////////////////////////////////////////////////     
   //Task 5: Write the code to insert new node with data num1 = 4 and num2 = 11 
   //        before the last node [8 marks]
   cout << "\nExecuting Task 5 - insert new node(4, 11) before last node" << endl;
   
   //Answer Task 5 start here  







   
   
   //Task 5 end
   /////////////////////////////////////////////////////////////////////////////     
   
   
   display(head);
   
   /////////////////////////////////////////////////////////////////////////////     
   //Task 6: Write the code to delete the second node in the list [4 marks]
   cout << "\nExecuting Task 6 - delete the second node" << endl;
   
   //Answer Task 6 start here  
   
   
   
   
   
   //Task 6 end	
   /////////////////////////////////////////////////////////////////////////////     
   
   display(head);	

   return 0;	
} //main
