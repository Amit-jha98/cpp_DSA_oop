
# OOP Exam Answers-2023


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

### Q8(b) – Differentiate between Error and Exception, and Explain Multiple Catch Handlers with an Example

**Key Points:**

- **Error:**
  - **Definition:**  
    - Refers to severe, unrecoverable issues (e.g., hardware failures, out-of-memory conditions).  
    - In C++, errors also include compile-time problems like syntax, semantic, and linker errors, which are detected before runtime.
  - **Handling:**  
    - Not meant to be caught by a program’s exception handling mechanisms.

- **Exception:**
  - **Definition:**  
    - Represents abnormal conditions that occur during program execution (e.g., invalid input, file not found).  
    - These are recoverable situations that the program can handle gracefully.
  - **Handling:**  
    - Thrown using the `throw` keyword and caught using `try-catch` blocks.

- **Multiple Catch Handlers:**
  - **Purpose:**  
    - Allow a single `try` block to handle different types of exceptions with different catch blocks.
  - **Mechanism:**  
    - Each catch block specifies a particular type of exception.
    - The catch blocks are evaluated in order; the first matching handler processes the exception.
    - A catch-all handler (`catch(...)`) can be used to catch any exception not matched by earlier handlers.

**Example Code:**

```cpp
#include <iostream>
#include <stdexcept>  // For std::runtime_error
using namespace std;

int main() {
    try {
        // Uncomment one of the following lines to simulate different exceptions:

        // Simulate an integer exception:
        // throw 404;

        // Simulate a runtime error:
        throw runtime_error("A runtime error occurred");

    } catch (const int errorCode) {
        cout << "Caught an integer exception with error code: " << errorCode << endl;
    } catch (const runtime_error& e) {
        cout << "Caught runtime_error: " << e.what() << endl;
    } catch (...) {
        cout << "Caught an unknown exception." << endl;
    }
    return 0;
}
```

**Explanation of the Code:**

- **`try` Block:**  
  - Contains the code that may throw an exception.
  - In this example, it simulates throwing an exception (either an integer or a `runtime_error`).

- **Multiple `catch` Blocks:**  
  - **First Catch Block:**  
    - Catches exceptions of type `int`.  
    - Prints the error code if an integer is thrown.
  - **Second Catch Block:**  
    - Catches exceptions of type `std::runtime_error`.  
    - Uses the `what()` method to display an error message.
  - **Catch-All Block:**  
    - `catch(...)` catches any exception not handled by the previous blocks.

```

### Q9 – Short Note

---

### (a) Copy Constructor

- **Definition:**  
  A copy constructor is a special constructor used to create a new object as a copy of an existing object. Its typical signature is:  
  ```cpp
  ClassName(const ClassName& other);
  ```

- **When It Is Invoked:**  
  - **Passing by Value:** When an object is passed to a function by value, a copy constructor is used to create a copy of that object.
  - **Returning from Functions:** When an object is returned by value, a temporary copy may be constructed.
  - **Explicit Copying:** When you explicitly create a copy of an object.

- **Importance of Proper Implementation:**  
  - **Shallow vs. Deep Copy:**  
    The default copy constructor performs a shallow copy (member-wise copy). This is fine for classes that do not manage resources. However, if your class allocates dynamic memory or holds other resources (like file handles), a shallow copy can lead to both objects pointing to the same resource. This may cause issues such as double deletion or resource leaks.  
  - **Rule of Three:**  
    If a class requires a custom copy constructor, it often also needs a custom copy assignment operator and destructor. This set of three is known as the "Rule of Three" and helps ensure that resources are managed correctly.

---

### (b) Pure Virtual Function

- **Definition:**  
  A pure virtual function is a virtual function declared in a base class that has no definition in that class. It is defined by assigning `= 0` in the declaration.  
  ```cpp
  class Base {
  public:
      virtual void display() = 0; // Pure virtual function
  };
  ```

- **Purpose:**  
  - **Forcing Derived Classes to Implement:**  
    Any class that derives from a base class with a pure virtual function must provide its own implementation of that function, or it too becomes abstract.
  - **Creating Abstract Classes:**  
    A class with at least one pure virtual function becomes abstract, meaning it cannot be instantiated. This is useful for defining interfaces or contracts for derived classes.
  - **Polymorphism:**  
    Pure virtual functions enable polymorphism. You can use pointers or references to the base class to refer to objects of derived classes that implement the pure virtual function, ensuring that the correct overridden function is called at runtime.

---

### (c) Object Pointer

- **Definition:**  
  An object pointer is a pointer variable that stores the memory address of an object. It is typically declared as:  
  ```cpp
  MyClass* ptr;
  ```

- **Usage and Importance:**  
  - **Dynamic Memory Allocation:**  
    Object pointers are often used with the `new` operator to allocate objects on the heap. For example:  
    ```cpp
    MyClass* ptr = new MyClass();
    ```
  - **Polymorphism:**  
    Base class pointers can point to objects of derived classes. This allows dynamic binding where virtual functions are resolved at runtime.  
    ```cpp
    Base* basePtr = new Derived();
    basePtr->display(); // Calls Derived::display() if display() is virtual
    ```
  - **Resource Management:**  
    When using dynamic allocation, object pointers require careful handling (e.g., using `delete` to deallocate memory) to avoid memory leaks. Modern C++ favors smart pointers (like `std::unique_ptr` or `std::shared_ptr`) to manage object lifetimes automatically.

---

### (d) Stack Unwinding

- **Definition:**  
  Stack unwinding is the process that occurs during exception handling when an exception is thrown. It involves the destruction of all local (automatic) objects in the reverse order of their construction as the program exits the current scope.

- **Purpose and Mechanism:**  
  - **Resource Cleanup:**  
    As the stack unwinds, the destructors for local objects are automatically called. This ensures that resources (such as memory, file handles, locks, etc.) are properly released, even if an exception occurs.
  - **RAII (Resource Acquisition Is Initialization):**  
    The RAII idiom relies on stack unwinding to guarantee that resource cleanup happens automatically when an object goes out of scope. For example:
    ```cpp
    class Resource {
    public:
        Resource() { cout << "Resource acquired" << endl; }
        ~Resource() { cout << "Resource released" << endl; }
    };

    void function() {
        Resource res;       // Resource is acquired
        throw runtime_error("Error occurred");
        // When the exception is thrown, res's destructor is called, releasing the resource.
    }
    ```
  - **Exception Safety:**  
    By ensuring that all objects are cleaned up during stack unwinding, C++ helps prevent resource leaks and maintains program stability when exceptions are thrown. It’s important that destructors themselves do not throw exceptions, as that can lead to termination of the program.

---


``

---
