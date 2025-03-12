
# OOP Exam Answers


---

## Part I – Multiple Choice Questions

*Instructions: Answer any seven of the following. Each question is worth 2 marks.*

### (a) To prevent any method from being overridden, we declare the method as:
- **(i)** static  
- **(ii)** final  
- **(iii)** const  
- **(iv)** None of the above  

**Correct Answer:** **(ii) final**  
**Explanation:** In C++ (since C++11), the `final` specifier is used with virtual functions to prevent them from being overridden in derived classes. For example, `virtual void func() final;` ensures no derived class can redefine `func`. The `static` keyword binds a method at compile time (not subject to overriding), `const` prevents state modification but not overriding, and "None of the above" is incorrect since `final` fits the requirement.

---

### (b) Does constructor overloading include different return types for constructors to be overloaded?
- **(i)** Yes, if return types are different, signature becomes different.  
- **(ii)** Yes, because return types can differentiate two functions.  
- **(iii)** No, because return types cannot differentiate two functions.  
- **(iv)** No, constructors don’t have any return type.  

**Correct Answer:** **(iv) No, constructors don’t have any return type**  
**Explanation:** Constructors in C++ do not have return types—not even `void`. Overloading is achieved through differences in parameter lists (e.g., `ClassName(int)` vs. `ClassName(double)`), making (iv) the correct choice. Options involving return types are irrelevant to constructors.

---

### (c) Which of the following type of class allows only one object of it to be created?
- **(i)** Virtual Class  
- **(ii)** Abstract Class  
- **(iii)** Singleton Class  
- **(iv)** Friend Class  

**Correct Answer:** **(iii) Singleton Class**  
**Explanation:** A Singleton Class restricts instantiation to one object, typically using a private constructor and a static method (e.g., `getInstance()`). Abstract classes prevent direct instantiation but allow multiple derived objects, while "Virtual Class" and "Friend Class" are not standard terms for this purpose.

---

### (d) What will happen if the exception is not caught in the program?
- **(i)** Error one  
- **(ii)** Program will execute  
- **(iii)** Block of the code will not execute  
- **(iv)** None of the above  

**Correct Answer:** **(iii) Block of the code will not execute**  
**Explanation:** If an exception is uncaught in C++, it propagates up the call stack. If no handler catches it, `std::terminate` is called, halting execution. The code block following the exception point (e.g., in a `try` block) does not execute, making (iii) correct, though the program ultimately terminates.

---

### (e) In C++, dynamic memory allocation is accomplished with the operator:
- **(i)** new  
- **(ii)** malloc  
- **(iii)** this  
- **(iv)** allocate  

**Correct Answer:** **(i) new**  
**Explanation:** The `new` operator in C++ allocates memory on the heap and invokes constructors for objects (e.g., `int* ptr = new int(5);`). While `malloc` (from C) allocates raw memory, it doesn’t call constructors, making `new` the standard C++ choice. `this` and `allocate` are unrelated.

---

### (f) Which of the following statement is correct?
- **(i)** Base class pointer cannot point to derived class.  
- **(ii)** Derived class pointer cannot point to base class.  
- **(iii)** Pointer to derived class cannot be created.  
- **(iv)** Pointer to base class cannot be created.  

**Correct Answer:** **(ii) Derived class pointer cannot point to base class.**  
**Explanation:** A base class pointer can point to a derived class object (polymorphism), but a derived class pointer cannot point to a base class object without unsafe casting (e.g., `static_cast`). Options (iii) and (iv) are false as pointers can be created for any class.

---

### (g) You should make a function virtual if:
- **(i)** Every class that is derived from this class uses all the member functions from this class.  
- **(ii)** Every class that is derived from this class needs to redefine this function.  
- **(iii)** That function is an operator.  
- **(iv)** Defined only in the derived classes.  

**Correct Answer:** **(ii) Every class that is derived from this class needs to redefine this function.**  
**Explanation:** A `virtual` function enables runtime polymorphism, allowing derived classes to override it (e.g., `virtual void func() {}`). This is necessary when derived classes need custom implementations, as in (ii). Other options do not justify the use of `virtual`.

---

### (h) Data members in a structure in C and a class in C++ are by default:
- **(i)** public, protected  
- **(ii)** protected, public  
- **(iii)** private, private  
- **(iv)** public, private  

**Correct Answer:** **(iv) public, private**  
**Explanation:** In C, `struct` members are `public` by default. In C++, `class` members are `private` by default (unlike `struct` in C++, which is `public`). Thus, (iv) correctly describes the defaults for a C structure and a C++ class.

---

### (i) Class Dog: public X, public Y is an example of:
- **(i)** Multiple inheritance  
- **(ii)** Multilevel inheritance  
- **(iii)** Linear inheritance  
- **(iv)** None of the above  

**Correct Answer:** **(i) Multiple inheritance**  
**Explanation:** The syntax `class Dog: public X, public Y` shows `Dog` inheriting from two base classes (`X` and `Y`), which is multiple inheritance. Multilevel inheritance involves a chain (e.g., `A → B → C`), and "linear inheritance" is not a standard term.

---

### (j) The compiler identifies a virtual function to be pure:
- **(i)** By the presence of the keyword pure.  
- **(ii)** By its location in the program.  
- **(iii)** If it is equated to 0.  
- **(iv)** None of the above  

**Correct Answer:** **(iii) If it is equated to 0.**  
**Explanation:** A pure virtual function in C++ is declared with `= 0` (e.g., `virtual void func() = 0;`), making the class abstract and requiring derived classes to override it. There is no `pure` keyword, and location is irrelevant.

---

## Part II – Long Answer Questions

*Instructions: Answer any five questions. Each question is worth 7 marks.*

### Q2(a) – Explain the benefits of Object-Oriented Programming (OOP) over Procedural Programming.
**Answer:**  
Object-Oriented Programming (OOP) offers several advantages over Procedural Programming:

1. **Encapsulation:** Bundles data and methods into classes, hiding internal details and exposing only necessary interfaces (e.g., `private` members), improving security and modularity.
2. **Inheritance:** Allows code reuse by letting classes inherit from others (e.g., `class B : public A`), reducing duplication.
3. **Polymorphism:** Enables methods to behave differently based on object type (e.g., virtual functions), enhancing flexibility.
4. **Modularity:** Divides programs into independent objects, easing maintenance compared to procedural code’s linear structure.
5. **Abstraction:** Focuses on what an object does, not how (e.g., abstract classes), simplifying complex system design.

Procedural Programming’s top-down approach often leads to less reusable, harder-to-maintain code, especially in large projects.

---

### Q2(b) – Define constructors and destructors with an example.
**Answer:**  
- **Constructors:** Special member functions called automatically when an object is created to initialize its data.  
- **Destructors:** Special member functions called when an object is destroyed to release resources.

**Example:**
```cpp
#include <iostream>
using namespace std;

class Demo {
    int* ptr;
public:
    Demo() {  // Constructor
        ptr = new int(10);
        cout << "Constructor called: Memory allocated." << endl;
    }
    ~Demo() {  // Destructor
        delete ptr;
        cout << "Destructor called: Memory freed." << endl;
    }
};

int main() {
    Demo obj;  // Constructor called
    return 0;  // Destructor called
}
```
**Output:**
```
Constructor called: Memory allocated.
Destructor called: Memory freed.
```

```markdown
# OOP Exam Answers – Long Answer Questions

*Instructions: Answer any five questions. Each question is worth 7 marks.*

This document provides detailed explanations and examples for the long-answer questions (Q2–Q9) from the Object-Oriented Programming using C++ exam.

---

## Q2 – Benefits of OOP and Constructors/Destructors

### Q2(a) – Explain the benefits of Object-Oriented Programming (OOP) over Procedural Programming.

**Answer:**  
Object-Oriented Programming (OOP) provides several advantages over Procedural Programming, including:

- **Encapsulation:**  
  - Bundles data and functions together into classes.
  - Hides internal implementation details from the outside world, exposing only what is necessary via public interfaces.
  - Improves security and modularity by controlling access with access specifiers.

- **Inheritance:**  
  - Allows new classes to be defined based on existing classes.
  - Promotes code reuse and reduces redundancy.
  - For example, a base class `Vehicle` can be extended by derived classes like `Car` and `Truck`.

- **Polymorphism:**  
  - Enables a single interface to represent different underlying data types.
  - Achieved through virtual functions in C++, allowing runtime method binding.
  - Improves flexibility and maintainability.

- **Modularity:**  
  - Breaks a complex program into smaller, manageable, and independent modules (classes).
  - Simplifies debugging, testing, and maintenance.

- **Abstraction:**  
  - Focuses on essential features while hiding complex implementation details.
  - Simplifies design and implementation by providing high-level models of real-world entities.

---

### Q2(b) – Define constructors and destructors with an example.

**Answer:**  
- **Constructor:**  
  - A special member function called automatically when an object is created.
  - Initializes the object’s data members.
  - Can be overloaded to initialize objects in different ways.

- **Destructor:**  
  - A special member function called automatically when an object is destroyed.
  - Used to release resources (such as dynamically allocated memory) and perform cleanup tasks.
  - There is only one destructor per class, and it cannot be overloaded.

**Example:**
```cpp
#include <iostream>
using namespace std;

class Demo {
    int* data;
public:
    // Constructor: Allocates memory and initializes data
    Demo() {
        data = new int(10);
        cout << "Constructor called: Memory allocated." << endl;
    }
    // Destructor: Releases allocated memory
    ~Demo() {
        delete data;
        cout << "Destructor called: Memory freed." << endl;
    }
};

int main() {
    Demo obj;  // Constructor is called here.
    return 0;  // Destructor is called when obj goes out of scope.
}
```
*Output:*
```
Constructor called: Memory allocated.
Destructor called: Memory freed.
```

---

## Q3 – Access Specifiers and Passing by Reference

### Q3(a) – Discuss access specifiers in C++ with an example.

**Answer:**  
C++ uses three main access specifiers to control the visibility of class members:

- **Public:**  
  - Members declared as public are accessible from anywhere in the program.
  
- **Private:**  
  - Members declared as private are accessible only within the class in which they are declared.
  
- **Protected:**  
  - Members declared as protected are accessible within the class and its derived classes.

**Example:**
```cpp
#include <iostream>
using namespace std;

class Example {
public:
    int publicVar;     // Accessible everywhere
private:
    int privateVar;    // Accessible only within Example
protected:
    int protectedVar;  // Accessible within Example and derived classes
};

int main() {
    Example obj;
    obj.publicVar = 10;    // Allowed
    // obj.privateVar = 20; // Error: private
    // obj.protectedVar = 30; // Error: protected
    return 0;
}
```
This example illustrates how access specifiers restrict or allow access to class members.

---

### Q3(b) – Explain the advantages of passing arguments by reference and implement the `zeroSmaller()` function.

**Answer:**  
**Advantages of Passing by Reference:**
- **Efficiency:**  
  - No copies of the data are made; only references are passed.
- **Modifiability:**  
  - The function can modify the original arguments.
- **Memory Savings:**  
  - Particularly useful for large objects where copying would be costly.

**Implementation of `zeroSmaller()`:**
```cpp
#include <iostream>
using namespace std;

void zeroSmaller(int &a, int &b) {
    if (a < b)
        a = 0;
    else
        b = 0;
}

int main() {
    int x = 5, y = 10;
    cout << "Before: x = " << x << ", y = " << y << endl;
    zeroSmaller(x, y);
    cout << "After: x = " << x << ", y = " << y << endl;
    return 0;
}
```
In this function, the smaller of the two integers is set to zero by directly modifying the original variables.

---

## Q4 – Downcasting and Substring Searching

### Q4(a) – Describe the dangers of converting a base class pointer to a derived class pointer.

**Answer:**  
Downcasting (converting a base class pointer to a derived class pointer) is dangerous because:
- **Type Mismatch:**  
  - A base pointer may not actually point to an object of the derived class.
- **Undefined Behavior:**  
  - Accessing members specific to the derived class through an incorrect pointer can lead to runtime errors or crashes.
- **Safety:**  
  - Without runtime type checking (e.g., using `dynamic_cast` in C++), the conversion is unsafe and may result in undefined behavior.

**Unsafe Example:**
```cpp
class Base { };
class Derived : public Base { public: int value = 42; };

int main() {
    Base* b = new Base();
    Derived* d = static_cast<Derived*>(b); // Unsafe: b is not actually a Derived
    // Accessing d->value would lead to undefined behavior.
    return 0;
}
```
Using `dynamic_cast` can help ensure the pointer conversion is valid.

---

### Q4(b) – Write a C++ program to find a substring in a string.

**Answer:**  
The `std::string::find()` method is used to locate a substring within a string. It returns the starting index if the substring is found; otherwise, it returns `string::npos`.

**Example Code:**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello, World!";
    string substr = "World";
    size_t pos = text.find(substr);
    if (pos != string::npos)
        cout << "Substring found at position: " << pos << endl;
    else
        cout << "Substring not found." << endl;
    return 0;
}
```
This program demonstrates how to search for a substring and output its position.

---

## Q5 – Abstract Classes/Interfaces and Templates

### Q5(a) – Differentiate between an abstract class and an interface.

**Answer:**  
- **Abstract Class:**  
  - Can include both fully implemented functions and pure virtual functions.
  - May contain data members.
  - Provides a partial implementation that can be shared among derived classes.
  
- **Interface (Pure Abstract Class in C++):**  
  - Contains only pure virtual functions, offering no implementation.
  - Typically does not have data members (except constants).
  - Enforces a strict contract that derived classes must implement.

**Example:**
```cpp
// Abstract Class
class AbstractClass {
public:
    virtual void pureFunction() = 0; // Pure virtual function
    void implementedFunction() { /* shared implementation */ }
};

// Interface (using pure abstract class in C++)
class Interface {
public:
    virtual void function1() = 0;
    virtual void function2() = 0;
};
```

---

### Q5(b) – Explain function templates and the difference between a template class and a class template.

**Answer:**  
- **Function Template:**  
  - A generic function that works with any data type.
  
  **Example:**
  ```cpp
  template <typename T>
  T max(T a, T b) {
      return (a > b) ? a : b;
  }
  ```

- **Class Template (Template Class):**  
  - A blueprint for creating classes that can operate on different data types.
  
  **Example:**
  ```cpp
  template <typename T>
  class Container {
      T element;
  public:
      Container(T arg) : element(arg) { }
      T getElement() { return element; }
  };
  ```
  
The terms "template class" and "class template" are often used interchangeably. Both approaches support generic programming.

---

## Q6 – Inheritance and Friend Functions

### Q6(a) – Describe different forms of inheritance with examples.

**Answer:**  
1. **Single Inheritance:**  
   - One derived class inherits from one base class.
   ```cpp
   class Base { };
   class Derived : public Base { };
   ```

2. **Multiple Inheritance:**  
   - A class inherits from two or more base classes.
   ```cpp
   class Base1 { };
   class Base2 { };
   class Derived : public Base1, public Base2 { };
   ```

3. **Multilevel Inheritance:**  
   - A class is derived from another derived class.
   ```cpp
   class Grandparent { };
   class Parent : public Grandparent { };
   class Child : public Parent { };
   ```

4. **Hierarchical Inheritance:**  
   - Multiple classes inherit from a single base class.
   ```cpp
   class Base { };
   class Derived1 : public Base { };
   class Derived2 : public Base { };
   ```

5. **Hybrid (Virtual) Inheritance:**  
   - Combines multiple inheritance forms to resolve issues like the diamond problem.
   ```cpp
   class Base { };
   class Derived1 : virtual public Base { };
   class Derived2 : virtual public Base { };
   class MostDerived : public Derived1, public Derived2 { };
   ```

---

### Q6(b) – Explain friend functions and why the assignment operator should be overloaded as a member function.

**Answer:**  
- **Friend Function:**  
  - A function declared with the `friend` keyword inside a class.
  - Although not a member, it can access private and protected members.
  
- **Assignment Operator Overloading:**  
  - Should be implemented as a member function because it needs to modify the object on the left-hand side using the implicit `this` pointer.
  - A friend function lacks direct access to the object’s own state via `this`, making it unsuitable for the assignment operator.

**Example (Assignment Operator):**
```cpp
class MyClass {
    int data;
public:
    MyClass(int d = 0) : data(d) {}
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }
};
```

---

## Q7 – Overloading, Overriding, and Template Function Overloading

### Q7(a) – Differentiate between overloading and overriding with examples.

**Answer:**  
- **Overloading:**  
  - Occurs when functions with the same name have different parameter lists within the same scope.
  - Resolved at compile time (static polymorphism).

  **Example:**
  ```cpp
  void print(int i) { cout << "Integer: " << i; }
  void print(double d) { cout << "Double: " << d; }
  ```

- **Overriding:**  
  - Occurs when a derived class provides its own implementation of a virtual function defined in the base class.
  - Resolved at runtime (dynamic polymorphism).

  **Example:**
  ```cpp
  class Base {
  public:
      virtual void display() { cout << "Display from Base"; }
  };
  class Derived : public Base {
  public:
      void display() override { cout << "Display from Derived"; }
  };
  ```

---

### Q7(b) – Explain overloading a template function with an example.

**Answer:**  
Template functions can be overloaded by providing multiple definitions that differ in parameter lists.

**Example:**
```cpp
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
    show(5);         // Calls the single-parameter version.
    show(5, 10);     // Calls the two-parameter version.
    return 0;
}
```
This demonstrates how the correct template function is chosen based on the number of parameters passed.

---

## Q8 – Palindrome Checking and Exception Handling

### Q8(a) – Write a program to check if a string or number is a palindrome using function overloading.

**Answer:**  
The following program overloads the `isPalindrome()` function to check both strings and integers.

**Example:**
```cpp
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &str) {
    int start = 0, end = str.length() - 1;
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

bool isPalindrome(int num) {
    if (num < 0) return false; // Negative numbers are not palindromes
    int original = num, reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    cout << "Is 'radar' a palindrome? " 
         << (isPalindrome("radar") ? "Yes" : "No") << endl;
    cout << "Is 12321 a palindrome? " 
         << (isPalindrome(12321) ? "Yes" : "No") << endl;
    return 0;
}
```

---

### Q8(b) – Differentiate between error and exception, and explain multiple catch handlers with an example.

**Answer:**  
- **Error:**  
  Refers to severe issues (e.g., hardware failure) that are typically unrecoverable and not meant to be handled by the program.
  
- **Exception:**  
  Represents conditions (e.g., invalid input, file not found) that can be caught and handled gracefully within a program.

- **Multiple Catch Handlers:**  
  Allow a `try` block to catch different types of exceptions, enabling specific handling based on the exception type.

**Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        // Simulate an exception
        throw 404;
    } catch (int errorCode) {
        cout << "Caught an integer exception with error code: " << errorCode << endl;
    } catch (...) {
        cout << "Caught an unknown exception." << endl;
    }
    return 0;
}
```
In this example, the first catch block handles an integer exception, and the second is a catch-all handler.

---

## Q9 – Short Notes on Four Topics

*Instructions: Choose any two topics to write short notes (each topic is 5 marks). Here are detailed notes for all four topics:*

#### (a) Copy Constructor
- A copy constructor initializes a new object as a copy of an existing object.
- It is automatically invoked when an object is passed by value, returned from a function, or explicitly copied.
- Proper implementation is necessary for deep copying when dynamic memory allocation is involved.

#### (b) Pure Virtual Function
- A pure virtual function is declared by assigning `= 0` in its declaration.
- It forces derived classes to provide an implementation, making the base class abstract.
- An abstract class (with at least one pure virtual function) cannot be instantiated directly.

#### (c) Object Pointer
- An object pointer holds the memory address of an object.
- It is commonly used to allocate objects dynamically and for implementing polymorphism (e.g., using base class pointers to refer to derived class objects).
- This mechanism supports dynamic binding of virtual functions.

#### (d) Stack Unwinding
- Stack unwinding is the process during exception handling where all local objects are destroyed in the reverse order of their construction.
- It ensures that resources are properly released (e.g., memory, file handles) even when an exception occurs.
- This mechanism helps prevent resource leaks and maintains program stability.

---

``

---
