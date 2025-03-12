Below is the corrected and fully formatted version of the OOP Exam Answers document in Markdown, based on the provided user query and refined using the thinking trace. All questions from both Part I and Part II are answered comprehensively, ensuring clarity and correctness, with explanations and examples where appropriate. The document adheres to the original structure and intent while incorporating necessary corrections and enhancements.

---

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
**Explanation:** In C++ (since C++11), the `final` specifier can be used with virtual functions to prevent them from being overridden in derived classes. While `static` methods are not subject to overriding (as they are bound at compile time), the context of preventing overriding typically applies to virtual functions, making `final` the correct choice. `const` prevents modification of the object’s state but does not affect overriding.

---

### (b) Does constructor overloading include different return types for constructors to be overloaded?
- **(i)** yes, if return types are different, signature becomes different.  
- **(ii)** yes, because return types can differentiate two functions.  
- **(iii)** no, because return types cannot differentiate two functions.  
- **(iv)** no, constructors don’t have any return type.  

**Correct Answer:** **(iv) no, constructors don’t have any return type**  
**Explanation:** In C++, constructors do not have return types, not even `void`. Overloading of constructors is based solely on the number and types of parameters, making (iv) the correct answer.

---

### (c) Which of the following type of class allows only one object of it to be created?
- **(i)** Virtual Class  
- **(ii)** Abstract Class  
- **(iii)** Singleton Class  
- **(iv)** Friend Class  

**Correct Answer:** **(iii) Singleton Class**  
**Explanation:** A Singleton Class is specifically designed to restrict instantiation to a single object, typically using a private constructor and a static method to provide global access to that instance. Other options like Abstract Class (which cannot be instantiated but allows multiple derived objects) do not fit this criterion.

---

### (d) What will happen if the exception is not caught in the program?
- **(i)** Error one  
- **(ii)** Program will execute  
- **(iii)** Block of the code will not execute  
- **(iv)** None of the above  

**Correct Answer:** **(iii) Block of the code will not execute**  
**Explanation:** In C++, if an exception is not caught, it propagates up the call stack. If it remains unhandled, the program terminates abnormally via `std::terminate`, and the code following the point of the exception (in the try block or beyond) will not execute. Option (iii) aligns with this behavior, though termination is the ultimate outcome.

---

### (e) In C++ dynamic memory allocation is accomplished with the operator:
- **(i)** new  
- **(ii)** malloc  
- **(iii)** this  
- **(iv)** allocate  

**Correct Answer:** **(i) new**  
**Explanation:** In C++, the `new` operator is used for dynamic memory allocation on the heap, also invoking constructors for objects. While `malloc` (inherited from C) allocates memory, it does not call constructors, making `new` the standard C++ operator.

---

### (f) Which of the following statement is correct?
- **(i)** base class pointer cannot point to derived class.  
- **(ii)** derived class pointer cannot point to base class.  
- **(iii)** pointer to derived class cannot be created.  
- **(iv)** pointer to base class cannot be created.  

**Correct Answer:** **(ii) derived class pointer cannot point to base class.**  
**Explanation:** In C++, a base class pointer can point to a derived class object (supporting polymorphism), but a derived class pointer cannot point to a base class object without explicit (and potentially unsafe) casting, due to type safety rules.

---

### (g) You should make a function virtual if:
- **(i)** every class that is derived from this class uses all the member functions from this class.  
- **(ii)** every class that is derived from this class needs to redefine this function.  
- **(iii)** that function is an operator.  
- **(iv)** defined only in the derived classes.  

**Correct Answer:** **(ii) every class that is derived from this class needs to redefine this function.**  
**Explanation:** A function is made `virtual` in C++ to allow derived classes to override it, enabling runtime polymorphism. This is appropriate when derived classes need to provide their own implementations, as stated in (ii).

---

### (h) Data members in a structure in C and a class in C++ are by default:
- **(i)** public, protected  
- **(ii)** protected, public  
- **(iii)** private, private  
- **(iv)** public, private  

**Correct Answer:** **(iv) public, private**  
**Explanation:** In C, structure members are `public` by default. In C++, class members are `private` by default (unlike structures in C++, which are also `public` by default). Thus, (iv) correctly pairs the defaults.

---

### (i) Class Dog: public X, public Y is an example of:
- **(i)** multiple inheritance  
- **(ii)** multilevel inheritance  
- **(iii)** linear inheritance  
- **(iv)** none of the above  

**Correct Answer:** **(i) multiple inheritance**  
**Explanation:** The syntax `class Dog: public X, public Y` indicates that `Dog` inherits from both `X` and `Y`, which is an example of multiple inheritance in C++. Multilevel inheritance involves a chain (e.g., A → B → C), not multiple direct bases.

---

### (j) The compiler identifies a virtual function to be pure:
- **(i)** by the presence of the keyword pure.  
- **(ii)** by its location in the program.  
- **(iii)** if it is equated to 0.  
- **(iv)** none of the above  

**Correct Answer:** **(iii) if it is equated to 0.**  
**Explanation:** In C++, a virtual function is declared pure by appending `= 0` to its declaration (e.g., `virtual void func() = 0;`), making the class abstract and requiring derived classes to override it.

---

## Part II – Long Answer Questions

*(Answer any five questions. Each question is worth 7 marks.)*

### Q2(a) – Benefits of Object-Oriented Programming (OOP) over Procedural Programming
**Answer:**  
Object-Oriented Programming (OOP) provides several advantages over Procedural Programming:

1. **Encapsulation:**  
   - Data and methods are bundled into classes, hiding implementation details and exposing only necessary interfaces, enhancing security and modularity.
2. **Inheritance:**  
   - Enables code reuse by allowing classes to inherit properties and behaviors from other classes, reducing redundancy.
3. **Polymorphism:**  
   - Allows methods to behave differently based on the object type, supporting flexibility and extensibility via runtime or compile-time mechanisms.
4. **Modularity:**  
   - Breaks programs into independent objects, simplifying maintenance and debugging compared to the linear flow of procedural code.
5. **Abstraction:**  
   - Focuses on what an object does rather than how, making complex systems easier to design and understand.

Procedural Programming, with its top-down approach, often results in less reusable and harder-to-maintain code, especially for large systems.

---

### Q2(b) – Constructors and Destructors with Example
**Answer:**  
- **Constructors:** Special member functions called automatically when an object is created to initialize its data members.  
- **Destructors:** Special member functions called when an object is destroyed to release resources (e.g., dynamically allocated memory).

**Example:**
```cpp
#include <iostream>
using namespace std;

class Demo {
    int* ptr;
public:
    Demo() {  // Constructor
        ptr = new int(10);
        cout << "Constructor: Allocated memory." << endl;
    }
    ~Demo() {  // Destructor
        delete ptr;
        cout << "Destructor: Freed memory." << endl;
    }
};

int main() {
    Demo obj;  // Constructor called
    return 0;  // Destructor called at scope end
}
```
**Output:**
```
Constructor: Allocated memory.
Destructor: Freed memory.
```

---

### Q3(a) – Access Specifiers in C++
**Answer:**  
C++ defines three access specifiers to control member visibility:
- **Public:** Members are accessible from anywhere in the program.  
- **Private:** Members are accessible only within the class itself.  
- **Protected:** Members are accessible within the class and its derived classes.

**Example:**
```cpp
class Example {
public:
    int publicVar;
private:
    int privateVar;
protected:
    int protectedVar;
};
```
These specifiers enforce encapsulation and inheritance rules in OOP.

---

### Q3(b) – Advantages of Passing by Reference and the zeroSmaller() Function
**Answer:**  
**Advantages of Passing by Reference:**  
- **Efficiency:** Avoids copying large objects, reducing memory and time overhead.  
- **Modification:** Allows functions to alter the original arguments directly.  
- **Flexibility:** Facilitates returning multiple values via parameters.

**zeroSmaller() Example:**
```cpp
#include <iostream>
using namespace std;

void zeroSmaller(int& a, int& b) {
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
**Output:**
```
Before: x = 5, y = 10
After: x = 0, y = 10
```
The function modifies the smaller value to 0 using references.

---

### Q4(a) – Dangers of Converting a Base Class Pointer to a Derived Class Pointer
**Answer:**  
Converting a base class pointer to a derived class pointer (downcasting) is risky because:
- **Type Mismatch:** The base pointer may not point to a derived class object, leading to invalid memory access.
- **Undefined Behavior:** Accessing derived-specific members through an incorrect pointer can cause runtime errors or crashes.
- **Safety:** Without runtime type checking (e.g., `dynamic_cast`), the operation is unsafe.

**Example (Unsafe Downcast):**
```cpp
class Base {};
class Derived : public Base { public: int x = 42; };
Base* b = new Base();
Derived* d = static_cast<Derived*>(b);  // Dangerous!
```

Using `dynamic_cast` with RTTI enabled can mitigate this by returning `nullptr` if the cast is invalid.

---

### Q4(b) – Finding a Substring in a String
**Answer:**  
In C++, the `std::string::find()` method locates a substring within a string, returning its starting position or `string::npos` if not found.

**Example:**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello, World!";
    string substr = "World";
    size_t pos = text.find(substr);
    if (pos != string::npos)
        cout << "Found at position: " << pos << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
```
**Output:**
```
Found at position: 7
```

---

### Q5(a) – Abstract Class vs. Interface
**Answer:**  
- **Abstract Class:**  
  - Contains a mix of implemented and pure virtual functions (`= 0`).  
  - Can have data members.  
  - Supports single inheritance in C++.  
- **Interface (Pure Abstract Class in C++):**  
  - Contains only pure virtual functions, no implementations.  
  - Typically no data members (except static constants).  
  - Supports multiple inheritance.

**Example:**
```cpp
class Abstract {
public:
    virtual void func() = 0;  // Pure virtual
    void concrete() {}
};
class Interface {
public:
    virtual void method1() = 0;
    virtual void method2() = 0;
};
```

---

### Q5(b) – Function Templates, Template Class vs. Class Template
**Answer:**  
- **Function Templates:** Generic functions that work with any type.  
  - Example: `template <typename T> T max(T a, T b) { return a > b ? a : b; }`
- **Class Templates:** Generic classes that work with any type.  
  - Example: 
    ```cpp
    template <typename T>
    class Box {
        T value;
    public:
        Box(T v) : value(v) {}
    };
    ```
- **Note:** "Template Class" and "Class Template" are interchangeable terms in C++, referring to the same concept.

Both enable generic programming for reusable code.

---

### Q6(a) – Different Forms of Inheritance with Examples
**Answer:**  
1. **Single Inheritance:** One base class.  
   - `class B : public A {};`
2. **Multiple Inheritance:** Multiple base classes.  
   - `class C : public A, public B {};`
3. **Multilevel Inheritance:** Chain of inheritance.  
   - `class C : public B {}; class B : public A {};`
4. **Hierarchical Inheritance:** Multiple derived classes from one base.  
   - `class B : public A {}; class C : public A {};`
5. **Hybrid Inheritance:** Combination (e.g., multiple + multilevel).  
   - `class D : public B, public C {};` where `B` and `C` inherit from `A`.

---

### Q6(b) – Friend Function and Overloading the Assignment Operator
**Answer:**  
- **Friend Function:** A non-member function granted access to a class’s private members via the `friend` keyword.  
- **Assignment Operator (`=`):** Typically a member function, not a friend, because it modifies the object’s state using `this` and returns `*this`.

**Example (Member Assignment):**
```cpp
class MyClass {
    int x;
public:
    MyClass& operator=(const MyClass& other) {
        if (this != &other) x = other.x;
        return *this;
    }
};
```
Friend functions are useful for external operations, but `=` is best as a member.

---

### Q7(a) – Overloading vs. Overriding
**Answer:**  
- **Overloading:** Same function name, different parameters, resolved at compile time.  
  - Example: `void print(int); void print(double);`
- **Overriding:** Redefining a virtual function in a derived class, resolved at runtime.  
  - Example:
    ```cpp
    class Base { public: virtual void show() {} };
    class Derived : public Base { public: void show() override {} };
    ```

---

### Q7(b) – Overloading a Template Function
**Answer:**  
Template functions can be overloaded by varying the number or types of parameters.

**Example:**
```cpp
#include <iostream>
using namespace std;

template <typename T> void display(T x) { cout << x << endl; }
template <typename T, typename U> void display(T x, U y) { cout << x << " " << y << endl; }

int main() {
    display(5);         // Single param
    display(5, "test"); // Two params
    return 0;
}
```

---

### Q8(a) – Checking Palindrome Using Function Overloading
**Answer:**  
**Example:**
```cpp
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s) {
    int l = 0, r = s.length() - 1;
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

bool isPalindrome(int n) {
    if (n < 0) return false;
    int orig = n, rev = 0;
    while (n > 0) { rev = rev * 10 + n % 10; n /= 10; }
    return orig == rev;
}

int main() {
    cout << isPalindrome("radar") << endl;  // 1
    cout << isPalindrome(12321) << endl;    // 1
    return 0;
}
```

---

### Q8(b) – Error vs. Exception and Multiple Catch Handlers
**Answer:**  
- **Error:** Severe, often unrecoverable issues (e.g., hardware failure).  
- **Exception:** Recoverable conditions (e.g., invalid input) that can be handled.  
- **Multiple Catch Handlers:** Handle different exception types separately.

**Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        throw string("Error");
    } catch (int e) {
        cout << "Int: " << e << endl;
    } catch (const string& e) {
        cout << "String: " << e << endl;
    }
    return 0;
}
```

---

### Q9 – Short Notes on Four Topics
*(Answer any two of the following. Each is worth 5 marks.)*

#### (a) Copy Constructor
A constructor that initializes an object using another object of the same class. Used for deep copying when managing dynamic resources.

#### (b) Pure Virtual Function
Declared with `= 0` (e.g., `virtual void func() = 0;`), making a class abstract and requiring overrides in derived classes.

#### (c) Object Pointer
A pointer to an object, enabling dynamic access and polymorphism (e.g., `Base* ptr = new Derived();`).

#### (d) Stack Unwinding
The process of destroying local objects in reverse order when an exception propagates, ensuring resource cleanup.

--- 

This completes the corrected and Markdown-formatted OOP Exam Answers document, covering all questions comprehensively.