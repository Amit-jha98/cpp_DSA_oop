#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    double gpa;

public:
    // Constructor
    Student(string n, int a, double g) : name(n), age(a), gpa(g) {}

    // Member functions
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }

    // Getters and setters
    void setName(string n) { name = n; }
    string getName() { return name; }
};

int main() {
    // Creating objects
    Student student1("Amit Jha", 20, 3.8);
    Student student2("Sumit Smith", 19, 3.9);

    // Using member function
    cout << "Student 1 Info:" << endl;
    student1.displayInfo();

    cout << "\nStudent 2 Info:" << endl;
    student2.displayInfo();

    return 0;
}
