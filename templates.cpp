#include <iostream>
#include <type_traits>
using namespace std;

// Basic Function Template
template<typename T>
T maximum(T x, T y) {
    return (x > y) ? x : y;
}

// Class Template
template<typename T, int Size>
class Array {
private:
    T arr[Size];
public:
    void setElement(int index, T value) {
        if(index < Size) arr[index] = value;
    }
    
    T getElement(int index) {
        return (index < Size) ? arr[index] : T();
    }
    
    int getSize() { return Size; }
};

// Variadic Template
template<typename T>
T sum(T t) {
    return t;
}

template<typename T, typename... Args>
T sum(T first, Args... args) {
    return first + sum(args...);
}

// SFINAE Example
template<typename T>
typename enable_if<is_integral<T>::value, bool>::type
isEven(T number) {
    return number % 2 == 0;
}

int main() {

    cout << "Max of 10, 20: " << maximum(10, 20) << endl;
    cout << "Max of 3.14, 2.78: " << maximum(3.14, 2.78) << endl;
    

    Array<int, 5> intArray;
    intArray.setElement(0, 10);
    intArray.setElement(1, 20);
    cout << "\nArray elements: " << intArray.getElement(0) 
         << ", " << intArray.getElement(1) << endl;
    

    cout << "\nSum of numbers: " << sum(1, 2, 3, 4, 5) << endl;
    

    cout << "\nIs 4 even? " << (isEven(4) ? "Yes" : "No") << endl;
    
    return 0;
}
