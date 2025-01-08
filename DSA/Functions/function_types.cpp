#include <iostream>
#include <vector>
using namespace std;

//....TYPE OF FUNCTION....

//...Based on return Type...

// 1st Void Function
void printSomething() {
    cout << "How are you.. (-:" << endl;
}

// Value-returning Function
int sum(int a, int b) {
    return a + b;
}

// Reference-returning functions
int& getElement(vector<int>& arr, int index) {
    return arr[index];
}

//...Based On parameter...

// No Parameters
void sayHello() {
    cout << "Hello!" << endl;
}

// Value Parameters
int square(int x) {
    return x * x;
}

// Reference Parameters
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Const Parameters
double calculateArea(const double radius) {
    return 3.14159 * radius * radius;
}

int main() {
    // Testing the functions

    // Void Function
    printSomething();

    // Value-returning Function
    int result = sum(5, 3);
    cout << "Sum: " << result << endl;

    // Reference-returning Function
    vector<int> arr = {1, 2, 3, 4, 5};

    // Modify the third element
    getElement(arr, 2) = 10; 
    cout << "Modified array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // No Parameters
    sayHello();

    // Value Parameters
    int sq = square(4);
    cout << "Square: " << sq << endl;

    // Reference Parameters
    int x = 10, y = 20;
    swap(x, y);
    cout << "Swapped values: x = " << x << ", y = " << y << endl;

    // Const Parameters
    double area = calculateArea(5.0);
    cout << "Area: " << area << endl;

    return 0;
}