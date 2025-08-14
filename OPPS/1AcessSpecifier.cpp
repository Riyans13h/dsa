#include <iostream>
#include <string>
using namespace std;
///   this  code is for the public   and  private 
class Teacher {
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    void changeDepartment(string d) {
        dept = d;
    }
// getter for private value to  get from the out side of the  class
    double getsallary() {
        return salary;
    }
//  setter -- to set the private value  from the out side of the class

    void setsallary(double sal) {
        salary = sal;
    }
};

class Student {
public:
    string name;
    int rollno;
    int age;
};

int main() {
    Teacher t1;
    Student s1;

    s1.name = "Riyansh";
    s1.rollno = 10;
    s1.age = 20;
    t1.setsallary( 10000.00);
    cout << "salary:" << t1.getsallary() << "\n";

    cout << s1.name << " " << s1.rollno << endl;
    return 0;
}
