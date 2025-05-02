/*....OUTPUT....
Number is: 1
Number is: 2
Number is: 3
Number is: 4
Number is: 5
Number is: 10
Number is: 30

All data Destroyed

All data Destroyed

All data Destroyed

*/

#include<iostream>
using namespace std;

class Amit{
private:
    static int num;
    int num1;
public: 

   //constructor construct object (it is parameterized constructor)
    Amit(int n) : num1(n) {}

    
        // Overloading '+' operator
        Amit operator+(const Amit& obj) {
            return Amit(this->num1 + obj.num1);
        }

    // Static method implementation
    static void numadd(){
        while(num != 5){
        num = num + 1;
        cout << "Number is: " << num << endl;
        }
    }

    //created friend function
    friend void print(const Amit& obj);
    // num1 = num;

    // Destructor Destroying objects
    ~Amit(){
        cout << "\nAll data Destroyed" <<  endl;
    }
};

void print(const Amit& obj){
    cout << "Number is: " << obj.num1 << endl;
}

// Define static member variable
int Amit::num = 0;  // Initialize with a default value

int main(){
    Amit a1 = {10};
    // Correct way to call static method (with parameter) 
    Amit ::numadd();
    print(a1);
    Amit a2 = {20};
    Amit a3 = a1 + a2;
    print(a3);
    return 0;
}