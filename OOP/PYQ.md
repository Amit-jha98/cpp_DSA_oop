# OOP Exam Answers

This document contains the complete set of exam questions and their corresponding answers for the Object-Oriented Programming using C++ exam.

---

## Part I – Multiple Choice Questions

*(Answer any seven of the following. Each question is worth 2 marks.)*

### (a) To prevent any method from being overridden we declare the method as:
- **(i)** static  
- **(ii)** final  
- **(iii)** const  
- **(iv)** None of the above  

**Correct Answer:** **(ii) final**  
**Explanation:** Declaring a method as **final** (in languages like Java) prevents a subclass from overriding it. Although static methods have fixed binding, they are not used to stop overriding, and `const` (in C++) only specifies that the method does not modify the object’s state.

---

### (b) Does constructor overloading include different return types for constructors to be overloaded?
- **(i)** yes, if return types are different, signature becomes different.
- **(ii)** yes, because return types can differentiate two functions.
- **(iii)** no, because return types cannot differentiate two functions.
- **(iv)** no, constructors don’t have any return type.

**Correct Answer:** **(iv) no, constructors don’t have any return type**  
**Explanation:** In both C++ and Java, constructors have no return type; their overloading is based solely on the number and types of parameters.

---

### (c) Which of the following type of class allows only one object of it to be created?
- **(i)** Virtual Class
- **(ii)** Abstract Class
- **(iii)** Singleton Class
- **(iv)** Friend Class

**Correct Answer:** **(iii) Singleton Class**  
**Explanation:** A **singleton class** is designed to ensure that only one instance is ever created and that a global point of access exists for that instance.

---

### (d) What will happen if the exception is not caught in the program?
- **(i)** Error one
- **(ii)** Program will execute
- **(iii)** Block of the code will not execute
- **(iv)** None of the above

**Correct Answer:** **(iii) Block of the code will not execute**  
**Explanation:** When an exception goes uncaught, the program’s normal flow is disrupted. Typically, the block (or even the entire program) terminates abnormally after stack unwinding.

---

### (e) In C++ dynamic memory allocation is accomplished with the operator:
- **(i)** new
- **(ii)** malloc
- **(iii)** this
- **(iv)** allocate

**Correct Answer:** **(i) new**  
**Explanation:** In C++, the `new` operator is used to allocate memory dynamically on the heap. (While `malloc` is available from C, it is not the standard C++ operator.)

---

### (f) Which of the following statement is correct?
- **(i)** base class pointer cannot point to derived class.
- **(ii)** derived class pointer cannot point to base class.
- **(iii)** pointer to derived class cannot be created.
- **(iv)** pointer to base class cannot be created.

**Correct Answer:** **(ii) derived class pointer cannot point to base class.**  
**Explanation:** In C++, a base class pointer can point to a derived class object (enabling polymorphism), but a pointer explicitly declared for a derived class cannot safely refer to a base class object.

---

### (g) You should make a function virtual if:
- **(i)** every class that is derived from this class uses all the member functions from this class.
- **(ii)** every class that is derived from this class needs to redefine this function.
- **(iii)** that function is an operator.
- **(iv)** defined only in the derived classes.

**Correct Answer:** **(ii) every class that is derived from this class needs to redefine this function.**  
**Explanation:** Declaring a function **virtual** signals that you expect each subclass to provide its own implementation, enabling runtime polymorphism.

---

### (h) Data members in a structure in C and a class in C++ are by default:
- **(i)** public, protected
- **(ii)** protected, public
- **(iii)** private, private
- **(iv)** public, private

**Correct Answer:** **(iv) public, private**  
**Explanation:** In C, the members of a structure are public by default; in C++, the members of a class are private by default.

---

### (i) Class Dog: public X, public Y is an example of:
- **(i)** multiple inheritance
- **(ii)** multilevel inheritance
- **(iii)** linear inheritance
- **(iv)** none of the above

**Correct Answer:** **(i) multiple inheritance**  
**Explanation:** Since class Dog inherits from more than one base class (X and Y), this is an example of multiple inheritance.

---

### (j) The compiler identifies a virtual function to be pure:
- **(i)** by the presence of the keyword pure.
- **(ii)** by its location in the program.
- **(iii)** if it is equated to 0.
- **(iv)** none of the above

**Correct Answer:** **(iii) if it is equated to 0.**  
**Explanation:** In C++, a virtual function becomes a pure virtual function when it is declared with `= 0` at the end of its declaration.

---

## Part II – Long Answer Questions

*(Answer any five questions. Each question is worth 7 marks.)*

### Q2(a) – Benefits of Object-Oriented Programming (OOP) over Procedural Programming
**Answer:**  
Object-Oriented Programming offers several advantages over Procedural Programming:
1. **Encapsulation:**  
   - Bundles data and functions together into classes, protecting the internal state and exposing only what is necessary.
2. **Inheritance and Reusability:**  
   - Allows classes to inherit properties and methods from other classes, reducing code duplication and enhancing reuse.
3. **Polymorphism:**  
   - Enables functions to use objects of different types through a common interface, allowing flexible and extendable code.
4. **Modularity:**  
   - Divides programs into discrete objects or modules, making maintenance and debugging easier.
5. **Extensibility and Maintainability:**  
   - Changes in one module have minimal impact on others, facilitating easier updates and bug fixes.

---

### Q2(b) – Constructors and Destructors with Example
**Answer:**  
A **constructor** is a special member function that initializes an object when it is created, while a **destructor** is called when the object is destroyed to free resources.

**Example Code:**
```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    // Constructor
    Demo() {
        cout << "Constructor: Object is created." << endl;
    }
    // Destructor
    ~Demo() {
        cout << "Destructor: Object is destroyed." << endl;
    }
};

int main() {
    Demo obj; // Constructor is called.
    return 0;
}


Q3(a) – Access Specifiers in C++
Answer:
C++ provides three main access specifiers:

Public: Members are accessible from any part of the program.
Private: Members are accessible only within the class.
Protected: Members are accessible within the class and its derived classes.
These specifiers enforce encapsulation by controlling the visibility of class members.

Q3(b) – Advantages of Passing by Reference and the zeroSmaller() Function
Answer:
Advantages of Passing by Reference:

Efficiency: No new copy of the variable is created.
Modifiability: The function can modify the original variable.
Memory Usage: Particularly beneficial for large objects, as copying them can be resource-intensive.
Example:

cpp
Copy code
#include <iostream>
using namespace std;

void zeroSmaller(int &a, int &b) {
    if (a < b)
        a = 0;
    else
        b = 0;
}

int main() {
    int x = 15, y = 20;
    cout << "Before: x = " << x << ", y = " << y << endl;
    zeroSmaller(x, y);
    cout << "After: x = " << x << ", y = " << y << endl;
    return 0;
}
Q4(a) – Dangers of Converting a Base Class Pointer to a Derived Class Pointer
Answer:
Downcasting (converting a base class pointer to a derived class pointer) is risky because:

The base pointer may not actually point to an object of the derived type.
It can lead to undefined behavior or runtime errors if accessed incorrectly.
Safe downcasting requires runtime type checking (e.g., using dynamic_cast).
Q4(b) – Finding a Substring in a String
Answer:
A common method to locate a substring is by using the find() function provided by the C++ string class.

Example:

cpp
Copy code
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello, World!";
    string substring = "World";
    
    if (text.find(substring) != string::npos)
        cout << "Substring found!" << endl;
    else
        cout << "Substring not found!" << endl;
    
    return 0;
}
The find() function returns the starting index of the substring if found; otherwise, it returns string::npos.

Q5(a) – Abstract Class vs. Interface
Answer:

Feature	Abstract Class	Interface
Method Implementation	May contain both implemented and pure virtual functions.	Contains only pure virtual functions (abstract methods).
Data Members	Can have instance variables.	Generally does not have instance variables (aside from constants).
Inheritance	Typically, a class can inherit from one abstract class.	A class can implement multiple interfaces.
Explanation:
Abstract classes allow sharing of code and state, whereas interfaces define a contract without implementation.

Q5(b) – Function Templates, Template Class vs. Class Template
Answer:

Function Template: Enables writing a generic function that works with any data type.

Example:

cpp
Copy code
template <typename T>
T add(T a, T b) {
    return a + b;
}
Class Template (or Template Class): A blueprint for creating classes that work with any data type.

Example:

cpp
Copy code
template <typename T>
class Container {
    T element;
public:
    Container(T arg) : element(arg) { }
    T getElement() { return element; }
};
Both approaches support generic programming by allowing code reuse with different data types.

Q6(a) – Different Forms of Inheritance with Examples
Answer:

Single Inheritance: One derived class inherits from one base class.
Example:

cpp
Copy code
class Base { };
class Derived : public Base { };
Multiple Inheritance: A class inherits from two or more base classes.
Example:

cpp
Copy code
class Base1 { };
class Base2 { };
class Derived : public Base1, public Base2 { };
Multilevel Inheritance: A class is derived from a class that is already derived.
Example:

cpp
Copy code
class Grandparent { };
class Parent : public Grandparent { };
class Child : public Parent { };
Hierarchical Inheritance: Multiple classes inherit from a single base class.
Example:

cpp
Copy code
class Base { };
class Derived1 : public Base { };
class Derived2 : public Base { };
Hybrid (Virtual) Inheritance: Combines multiple inheritance forms to resolve issues such as the diamond problem.
Example:

cpp
Copy code
class Base { };
class Derived1 : virtual public Base { };
class Derived2 : virtual public Base { };
class MostDerived : public Derived1, public Derived2 { };
Q6(b) – Friend Function and Overloading the Assignment Operator
Answer:
A friend function is declared inside a class but is not a member; it has access to private and protected members. However, the assignment operator should be implemented as a member function because it needs to modify the left-hand side object using the implicit this pointer—a context not available to a friend function.

Q7(a) – Overloading vs. Overriding
Answer:

Overloading: Multiple functions in the same scope share the same name but have different parameter lists (compile-time polymorphism).
Example:
cpp
Copy code
void print(int i) { cout << "Integer: " << i; }
void print(double d) { cout << "Double: " << d; }
Overriding: A derived class provides its own implementation of a virtual function defined in its base class (runtime polymorphism).
Example:
cpp
Copy code
class Base {
public:
    virtual void display() { cout << "Display from Base"; }
};
class Derived : public Base {
public:
    void display() override { cout << "Display from Derived"; }
};
Q7(b) – Overloading a Template Function
Answer:
Example:

cpp
Copy code
#include <iostream>
using namespace std;

template <typename T>
void show(T a) {
    cout << "Value: " << a << endl;
}

template <typename T>
void show(T a, T b) {
    cout << "Values: " << a << " and " << b << endl;
}

int main() {
    show(5);
    show(5, 10);
    return 0;
}
This demonstrates two overloaded versions of a template function based on the number of parameters.

Q8(a) – Checking Palindrome Using Function Overloading
Answer:
Example:

cpp
Copy code
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int num) {
    int original = num, reversed = 0;
    while(num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return (original == reversed);
}

bool isPalindrome(const string &str) {
    int start = 0, end = str.length() - 1;
    while(start < end) {
        if(str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int main() {
    int num = 121;
    string text = "radar";
    
    cout << num << (isPalindrome(num) ? " is a palindrome." : " is not a palindrome.") << endl;
    cout << "\"" << text << "\"" << (isPalindrome(text) ? " is a palindrome." : " is not a palindrome.") << endl;
    
    return 0;
}
This program overloads the isPalindrome() function for both integers and strings.

Q8(b) – Error vs. Exception and Multiple Catch Handlers
Answer:

Error: Severe issues that are often unrecoverable (e.g., hardware failures).
Exception: Conditions that can be caught and handled (e.g., invalid input, file not found).
Multiple Catch Handlers: Used when a try block may throw different types of exceptions, allowing each handler to manage a specific type.
Example:

cpp
Copy code
#include <iostream>
using namespace std;

int main() {
    try {
        throw 404;
    }
    catch (int errorCode) {
        cout << "Caught an integer exception with error code: " << errorCode << endl;
    }
    catch (...) {
        cout << "Caught an unknown exception." << endl;
    }
    return 0;
}
Q9 – Short Notes on Four Topics
Since the exam instructs to choose any two, here are complete notes on all four topics:

(a) Copy Constructor
A copy constructor is a special constructor used to create a new object as a copy of an existing object.
It is invoked during pass-by-value, return-by-value, or explicit copying.
It ensures that dynamically allocated resources are properly duplicated (deep copy).
(b) Pure Virtual Function
A pure virtual function is declared by assigning = 0 in its declaration.
It forces derived classes to override the function, making the base class abstract.
An abstract class cannot be instantiated.
(c) Object Pointer
An object pointer holds the memory address of an object.
It is used to access the object’s members and to achieve runtime polymorphism.
Base class pointers can point to derived class objects, enabling dynamic binding.
(d) Stack Unwinding
Stack unwinding is the process that occurs when an exception is thrown.
As the exception propagates, destructors for all local objects are called to free resources.
This process helps prevent resource leaks during abnormal program termination.