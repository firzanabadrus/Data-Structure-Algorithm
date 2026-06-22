// Lab 1 - SECJ2013 - 24251 (Student.h)
// Group Members:
// 1. NUR FIRZANA BINTI BADRUS HISHAM   A23CS0156
// 2. LUBNA AL HAANI BINTI RADZUAN      A23CS0107
 
#include <iostream>
#include <string>

using namespace std;

// Class defintion
class Student {
    private :
        string name;
        int cwMark, feMark;

    public :
        Student(string n, int c, int f){
            this->name = n;
            this->cwMark = c;
            this->feMark = f;
        }

        int getTotalMark() const {
            return (cwMark+feMark);
        }

        string getGrade() const{
            int totalMark = getTotalMark();
            
            if(totalMark >= 75 && totalMark <= 100){ return "A" ; }
            else if(totalMark >= 65){ return "B" ; }
            else if(totalMark >= 50){ return "C" ; }
            else if(totalMark >= 35){ return "D" ; }
            else if(totalMark >= 0){ return "E" ; }
            else { return "Invalid Total Mark" ; }
        }

        void printInfo() {
        cout << "Name: " << this->name << "\n";
        cout << "Coursework: " << this->cwMark << "\n";
        cout << "Final Exam: " << this->feMark << "\n\n";
        }

        void printResult(){
            cout << this->name << " " << getTotalMark() << " " << getGrade() << endl;
        }

        void printResultFile(fstream &out){
            out << this->name << " " << getTotalMark() << " " << getGrade() << endl;
        }

        ~Student(){
            cout << "Destroy student object - " << this->name << endl;
        }
};


