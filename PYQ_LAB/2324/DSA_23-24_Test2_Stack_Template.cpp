/* Question : Array stack implementation for Car ShowRoom Simulation   */

// Name : 
// Matric Num : 

# include<iostream>
#include<string>
const int SIZE=7;

using namespace std;

class CarStack
{
    int top;
    public:
    string car[7];  
    CarStack()
    {
        top = -1;
    }
    
    
    void push(string x);
    void pop();
    bool isEmpty();
    bool isFull();
    string stackTop();
    void display();
	int checkSize();   
};


void CarStack::push(string x)
{
    if(isFull())
    {
        cout << "CarStack Overflow \n";
    }
    else
    {
    	top++;
        car[top] = x;
    }
}


void CarStack::pop()
{
    if(isEmpty())
        cout << "CarStack Underflow \n";
    else
        top--;
}


bool CarStack::isEmpty()   
{
    if(top < 0)
    {
        return true;
    }
    else
    {
     return false;
    }
}
    


bool CarStack::isFull() 
{
    if(top >SIZE-1)
    {
        return true;
    }
    else
    {
     return false;
    }
}
    
    
//*Task 1 : stackTop implementation - 8M
//-------------------------------------------


//*Task 2 : display implementation - 12M
//----------------------------------------------


//*Task 3 :   checkSize implementation 8M
//-------------------------------------------------    


// main function
int main() {

    CarStack s1;
    string theCars[7]={"Estima","Alphard","Velphire","Mazda","Nissan","Shilpy","Vios"};
    
     /*
        perform the operation that represent the output in the question 
    */
    
    //*Task 4 - in main function 
    //----------------------------------------------------------------------
    
	// i) Use the appropriate code that able to push theCars elements into the stack. 
	   // Display all the elements  - 8M 
	
       
   
    //ii) Use the appropriate code that able to remove and display the removed  
	     // 2 top elements in the stack - 6M
	
   
    //iii) Display all the elements in the stack.
		// Use the appropriate code that able to display the number of elements in the stack - //8M
	
   //-------------------------------------------------------------------------------------------
   return 0;
}
