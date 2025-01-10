#include <iostream>
#include <stdexcept>
using namespace std;

// Custom Exception Class
class DivideByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "Division by zero attempted!";
    }
};

class Calculator {
public:
    double divide(double a, double b) {
        if(b == 0) {
            throw DivideByZeroException();
        }
        return a / b;
    }
    
    void processArray(int arr[], int size, int index) {
        if(index >= size) {
            throw out_of_range("Index out of bounds!");
        }
        cout << "Value at index: " << arr[index] << endl;
    }
};

int main() {
    Calculator calc;
    
    // Basic Exception Handling
    try {
        cout << calc.divide(10, 0) << endl;
    } catch(const DivideByZeroException& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Multiple Exception Types
    int arr[] = {1, 2, 3};
    try {
        calc.processArray(arr, 3, 5);
    } catch(const out_of_range& e) {
        cout << "Array Error: " << e.what() << endl;
    } catch(...) {
        cout << "Unknown error occurred" << endl;
    }
    
    // Resource Management with RAII
    try {
        int* ptr = new int[1000000000000];  // Intentional bad allocation
        delete[] ptr;
    } catch(const bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << endl;
    }
    
    return 0;
}
