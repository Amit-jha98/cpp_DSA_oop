
# **Object-Oriented Programming (OOP) in C++ - Exam Notes**

## **1. Introduction to OOP**
Object-Oriented Programming (OOP) is a programming paradigm that organizes code around **objects** and **classes**, rather than focusing solely on functions and procedures. It models real-world entities and their interactions, making code more intuitive, reusable, and easier to maintain.

- **Key Features**:
  - **Encapsulation**: Combines data (attributes) and methods (functions) into a single unit called a class, restricting direct access to data to ensure its integrity.
  - **Inheritance**: Enables a class to inherit properties and behaviors from another class, fostering code reuse and establishing hierarchical relationships.
  - **Polymorphism**: Allows a single interface to represent different underlying forms or data types, enhancing flexibility and extensibility.
  - **Abstraction**: Hides complex implementation details and exposes only the essential features, simplifying interaction with objects.

- **Benefits**:
  - **Code Reusability**: Inheritance and polymorphism reduce redundancy by allowing existing code to be reused or adapted.
  - **Modularity**: Code is divided into self-contained units (classes), making it easier to develop, test, and debug.
  - **Scalability**: New features can be added with minimal changes to existing code, supporting large-scale projects.
  - **Security**: Encapsulation protects sensitive data from unauthorized access or modification.

- **Additional Theory**:
  - OOP emerged as a response to the limitations of procedural programming, which often led to tightly coupled and hard-to-maintain code in complex systems. By treating data and behavior as inseparable, OOP mirrors how humans naturally conceptualize the world (e.g., a "car" has attributes like "color" and behaviors like "drive").
  - The paradigm is rooted in the idea of **message passing**, where objects communicate by invoking each other’s methods, simulating real-world interactions.
  - OOP aligns with the **open-closed principle**, meaning classes should be open for extension (e.g., through inheritance) but closed for modification, enhancing stability in software design.
  - Historically, OOP gained prominence with languages like Smalltalk and was later adopted by C++ (via Bjarne Stroustrup’s extensions to C), blending procedural efficiency with object-oriented flexibility.

---

## **2. Classes and Objects**
- **Class**: A user-defined data type that acts as a blueprint for creating objects. It defines attributes (data members) and methods (member functions) that describe the properties and behaviors of objects.
- **Object**: A specific instance of a class that holds actual values for the attributes defined in the class. Each object has its own identity, state, and behavior.

- **Additional Theory**:
  - Classes represent an abstraction of a concept, while objects are the tangible realizations of that concept. For instance, "Student" is a class defining general properties (e.g., name, roll number), while "John Doe" is an object with specific values (e.g., name = "John Doe", roll number = 101).
  - The concept of classes is inspired by type theory in programming languages, allowing developers to create custom types tailored to their needs.
  - Objects are stored in memory, with their data members occupying space based on their types (e.g., `int`, `string`), and methods shared across all instances to optimize memory usage.
  - The lifecycle of an object involves **creation** (via constructors), **usage** (via method calls), and **destruction** (via destructors), aligning with resource management principles in C++.
  - Classes enable **data abstraction**, where the internal structure is hidden, and objects provide a public interface for interaction, a foundational aspect of OOP.

- **Example**:
```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;
    void display() {
        cout << "Brand: " << brand << " Year: " << year << endl;
    }
};

int main() {
    Car car1;
    car1.brand = "Toyota";
    car1.year = 2022;
    car1.display();  // Outputs: Brand: Toyota Year: 2022
    return 0;
}
```

---

## **3. Encapsulation**
Encapsulation bundles data and the methods that operate on it into a single unit (class) and restricts direct access to some components using access specifiers: **public**, **private**, and **protected**.

- **Additional Theory**:
  - Encapsulation is often described as the "information hiding" principle, ensuring that an object’s internal state can only be modified through controlled interfaces (e.g., getters and setters).
  - It aligns with the **principle of least privilege**, where only the necessary parts of an object are exposed, reducing the risk of unintended side effects in large systems.
  - In C++, encapsulation leverages access specifiers to enforce boundaries: `private` members are inaccessible outside the class, `protected` members extend access to derived classes, and `public` members are freely accessible.
  - The concept draws from modular design, where each class acts as a "black box" with a defined interface, enhancing maintainability and testability.
  - Encapsulation also supports **data validation**, as setter methods can enforce constraints (e.g., ensuring a roll number is positive), preventing invalid states.

- **Example**:
```cpp
#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
public:
    void setRollNo(int r) {
        if (r > 0) rollNo = r;
        else cout << "Invalid roll number" << endl;
    }
    int getRollNo() {
        return rollNo;
    }
};

int main() {
    Student s1;
    s1.setRollNo(101);
    cout << "Roll No: " << s1.getRollNo() << endl;  // Outputs: Roll No: 101
    return 0;
}
```

---

## **4. Inheritance**
Inheritance allows a new class (derived/child class) to inherit properties and behaviors from an existing class (base/parent class), promoting code reuse and hierarchical relationships.

- **Types**:
  1. **Single Inheritance**: One base class.
  2. **Multiple Inheritance**: Multiple base classes.
  3. **Multilevel Inheritance**: A chain of inheritance.
  4. **Hierarchical Inheritance**: Multiple classes from one base.
  5. **Hybrid Inheritance**: Combination of inheritance types.

- **Additional Theory**:
  - Inheritance models the **"is-a" relationship** (e.g., a "Dog" is an "Animal"), distinguishing it from composition, which models a "has-a" relationship (e.g., a "Car" has an "Engine").
  - It supports the **Liskov Substitution Principle**, where a derived class object should be substitutable for a base class object without altering program correctness.
  - In C++, inheritance can be public, private, or protected, affecting how base class members are accessed in the derived class (e.g., `public` inheritance preserves the base class’s public interface).
  - Multiple inheritance introduces complexity, such as the **diamond problem**, where a class inherits from two classes that share a common base, potentially causing ambiguity. C++ resolves this using virtual inheritance.
  - Inheritance facilitates **incremental development**, where base classes provide core functionality, and derived classes extend or specialize it, a key strategy in software evolution.

- **Example (Single Inheritance)**:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

int main() {
    Dog d;
    d.eat();   // Inherited method
    d.bark();  // Defined in Dog
    return 0;
}
```

---

## **5. Polymorphism**
Polymorphism allows a single interface to represent different underlying forms, enabling flexibility and extensibility.

- **Types**:
  - **Compile-time**: Function overloading and operator overloading (resolved at compile time).
  - **Runtime**: Function overriding with virtual functions (resolved at runtime).

- **Additional Theory**:
  - The term "polymorphism" comes from Greek, meaning "many forms," reflecting its ability to adapt behavior based on context.
  - Compile-time polymorphism relies on **static binding**, where the compiler determines the function to call based on parameter types or operator arguments, optimizing performance.
  - Runtime polymorphism uses **dynamic binding**, enabled by virtual functions and the **vtable** (virtual table), a lookup table created by the compiler to resolve function calls at runtime.
  - Polymorphism supports the **open-closed principle**, allowing new functionality (e.g., new derived classes) without modifying existing code.
  - It is a cornerstone of **design patterns** like Strategy and Factory, where interchangeable behaviors or object creation are managed through a common interface.

- **Example (Function Overloading)**:
```cpp
#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};

int main() {
    Math m;
    cout << m.add(5, 10) << endl;      // Outputs: 15
    cout << m.add(5.5, 10.5) << endl;  // Outputs: 16
    return 0;
}
```

- **Example (Function Overriding)**:
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class" << endl;
    }
};

int main() {
    Base* b = new Derived();
    b->show();  // Outputs: Derived class
    delete b;
    return 0;
}
```

---

## **6. Abstraction**
Abstraction hides complex implementation details and exposes only the essential features of an object, reducing complexity.

- **Additional Theory**:
  - Abstraction separates **what** an object does from **how** it does it, aligning with the principle of **separation of concerns**.
  - In C++, abstraction is implemented through abstract classes (with pure virtual functions) and interfaces, which define a contract that derived classes must follow.
  - It supports **top-down design**, where high-level interfaces are defined first, and implementations are deferred to later stages, aiding in system architecture.
  - Abstraction reduces cognitive load by allowing developers to work with simplified models, a critical factor in managing large codebases.
  - It is distinct from encapsulation: abstraction focuses on the external interface, while encapsulation protects internal data.

- **Example**:
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Shape* s = new Circle();
    s->draw();  // Outputs: Drawing Circle
    delete s;
    return 0;
}
```

---

## **7. Constructors and Destructors**
- **Constructor**: Automatically called when an object is created to initialize its data members.
- **Destructor**: Automatically called when an object is destroyed to clean up resources.

- **Types of Constructors**:
  1. **Default**: No parameters, default values.
  2. **Parameterized**: Specific values via parameters.
  3. **Copy**: Copies an existing object.

- **Additional Theory**:
  - Constructors ensure objects are in a valid state upon creation, adhering to the **invariant principle** (an object’s state must always be consistent).
  - Destructors are critical in C++ due to manual memory management, preventing resource leaks (e.g., unclosed files or unreleased memory).
  - The order of constructor/destructor calls in inheritance follows a **bottom-up/top-down** pattern: base class constructors run first, followed by derived, while destructors reverse this order.
  - Constructors can use **initializer lists** to efficiently initialize members before the constructor body executes, optimizing performance.
  - The absence of a user-defined destructor triggers a compiler-generated default destructor, but this may not suffice for dynamic resources, necessitating explicit cleanup.

- **Example**:
```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    int value;
    Demo() {
        value = 0;
        cout << "Default Constructor" << endl;
    }
    Demo(int v) {
        value = v;
        cout << "Parameterized Constructor" << endl;
    }
    ~Demo() {
        cout << "Destructor" << endl;
    }
};

int main() {
    Demo d1;
    Demo d2(10);
    return 0;  // Destructors called in reverse order
}
```

---

## **8. Friend Functions and Operator Overloading**
- **Friend Function**: A non-member function with access to a class’s private/protected members.
- **Operator Overloading**: Redefines operators for user-defined types.

- **Additional Theory**:
  - Friend functions break encapsulation intentionally, useful for utility functions needing access to multiple classes (e.g., comparing two objects).
  - They are declared with the `friend` keyword, signaling a trusted relationship, but overuse can undermine data hiding.
  - Operator overloading enhances code readability by allowing natural syntax (e.g., `obj1 + obj2`) for custom types, aligning with C++’s philosophy of flexibility.
  - Overloaded operators are implemented as functions (e.g., `operator+`), with rules governing arity (unary vs. binary) and precedence preserved by the compiler.
  - Certain operators (e.g., `sizeof`, `::`) cannot be overloaded, ensuring core language semantics remain intact.

- **Example (Friend Function)**:
```cpp
#include <iostream>
using namespace std;

class Box {
private:
    int width;
public:
    Box(int w) : width(w) {}
    friend void showWidth(Box b);
};

void showWidth(Box b) {
    cout << "Width: " << b.width << endl;
}

int main() {
    Box b(10);
    showWidth(b);  // Outputs: Width: 10
    return 0;
}
```

- **Example (Operator Overloading)**:
```cpp
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }
};

int main() {
    Complex c1(3, 4), c2(5, 6);
    Complex c3 = c1 + c2;
    cout << c3.real << " + " << c3.imag << "i" << endl;  // Outputs: 8 + 10i
    return 0;
}
```

---

## **9. File Handling in C++**
File handling uses stream classes (`ofstream`, `ifstream`, `fstream`) to read from and write to files.

- **Additional Theory**:
  - File handling extends C++’s stream-based I/O model (e.g., `cin`, `cout`) to persistent storage, treating files as sequences of bytes.
  - Streams abstract the underlying file system, providing a uniform interface across platforms, a hallmark of C++’s portability.
  - File modes (e.g., `ios::app`, `ios::binary`) control behavior, such as appending vs. overwriting or handling binary vs. text data.
  - The **fail-safe principle** is critical: checking `is_open()` prevents operations on unopened files, ensuring robust error handling.
  - File handling ties into resource management, with explicit `close()` calls necessary to free system resources, contrasting with automatic cleanup in languages with garbage collection.

- **Example**:
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outfile("test.txt");
    if (outfile.is_open()) {
        outfile << "Hello, World!" << endl;
        outfile.close();
    }
    ifstream infile("test.txt");
    if (infile.is_open()) {
        string line;
        getline(infile, line);
        cout << line << endl;  // Outputs: Hello, World!
        infile.close();
    }
    return 0;
}
```

---

## **10. Exception Handling**
Exception handling manages runtime errors using `try`, `throw`, and `catch`.

- **Additional Theory**:
  - Exceptions separate error-handling code from normal logic, improving readability and maintainability, a practice rooted in structured programming.
  - The `throw` mechanism allows custom error objects (e.g., integers, strings, or classes), supporting flexible error reporting.
  - C++ uses **stack unwinding** when an exception is thrown, destroying local objects in reverse order until a `catch` block is found, ensuring proper cleanup.
  - The **exception hierarchy** (e.g., `std::exception`) enables generic handling, with derived classes like `std::runtime_error` for specific cases.
  - Exception handling incurs overhead, so it’s reserved for exceptional conditions (e.g., file not found), not routine control flow, per C++ design philosophy.

- **Example**:
```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int age = 15;
        if (age < 18) throw age;
    } catch (int e) {
        cout << "Exception: Age " << e << " is less than 18" << endl;
    }
    return 0;
}
```

---

## **11. Templates**
Templates enable generic programming by allowing functions and classes to work with any data type.

- **Additional Theory**:
  - Templates are a form of **metaprogramming**, where code generates code at compile time, enhancing performance by avoiding runtime type checks.
  - They embody the **DRY principle** (Don’t Repeat Yourself), eliminating duplicate code for different types (e.g., separate `add` functions for `int` and `double`).
  - Template instantiation creates type-specific versions of the code, stored in the binary, balancing flexibility with efficiency.
  - C++ supports **template specialization**, where specific types (e.g., `char*`) get custom implementations, refining generic behavior.
  - Templates underpin the Standard Template Library (STL), demonstrating their power in reusable, type-safe containers and algorithms.

- **Example (Function Template)**:
```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(5, 10) << endl;      // Outputs: 15
    cout << add(5.5, 10.5) << endl;  // Outputs: 16
    return 0;
}
```

---

## **12. Virtual Functions and Pure Virtual Functions**
- **Virtual Functions**: Enable runtime polymorphism by allowing overriding in derived classes.
- **Pure Virtual Functions**: Define an interface with `= 0`, making a class abstract.

- **Additional Theory**:
  - Virtual functions rely on the **vptr** (virtual pointer) and **vtable**, dynamically linking calls to the correct implementation, a trade-off for runtime flexibility over compile-time speed.
  - Pure virtual functions enforce a **contract**, ensuring derived classes implement required behavior, akin to interfaces in other languages (e.g., Java).
  - Abstract classes cannot be instantiated, serving as skeletons for concrete classes, a key abstraction mechanism.
  - The `override` keyword (C++11) prevents accidental errors by ensuring a function matches a virtual base declaration, enhancing code safety.
  - Virtual destructors are crucial in inheritance to ensure proper cleanup of derived objects via base pointers, avoiding resource leaks.

- **Example**:
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void func() = 0;
};

class Derived : public Base {
public:
    void func() override {
        cout << "Implemented in Derived" << endl;
    }
};

int main() {
    Base* b = new Derived();
    b->func();  // Outputs: Implemented in Derived
    delete b;
    return 0;
}
```

---

## **13. Static Members**
- **Static Data Members**: Shared across all objects of a class.
- **Static Member Functions**: Callable without an object, accessing only static members.

- **Additional Theory**:
  - Static members exist at the class level, not per object, residing in the program’s static memory segment, initialized before `main()` executes.
  - They are ideal for **class-wide state** (e.g., object counters) or constants, reducing memory overhead compared to per-instance storage.
  - Static functions lack a `this` pointer, restricting them to static data, aligning with their class-level scope.
  - The concept parallels global variables/functions but scopes them to a class, avoiding namespace pollution.
  - Static members support **singleton patterns**, where a single instance of a class is managed globally, a common design strategy.

- **Example**:
```cpp
#include <iostream>
using namespace std;

class Counter {
public:
    static int count;
    Counter() { count++; }
    static void showCount() {
        cout << "Count: " << count << endl;
    }
};

int Counter::count = 0;

int main() {
    Counter c1, c2;
    Counter::showCount();  // Outputs: Count: 2
    return 0;
}
```

---

## **14. Namespaces**
Namespaces group related code under a unique name to avoid naming conflicts.

- **Additional Theory**:
  - Namespaces address the **namespace collision problem**, prevalent in large projects or when integrating third-party libraries with overlapping names.
  - They emulate a hierarchical structure, similar to file systems (e.g., `namespace A::B`), improving code organization.
  - The `using` directive trades convenience for potential ambiguity, requiring careful use to maintain clarity.
  - Namespaces align with C++’s **modularity goals**, encapsulating code units logically, much like classes encapsulate data and behavior.
  - The global namespace (`::`) serves as the root, with `std` being the most prominent example, housing the standard library.

- **Example**:
```cpp
#include <iostream>
using namespace std;

namespace MyNamespace {
    int value = 1000;
    void display() {
        cout << "Value: " << value << endl;
    }
}

int main() {
    MyNamespace::display();  // Outputs: Value: 1000
    return 0;
}
```

---

## **15. Dynamic Memory Allocation**
Dynamic memory allocation uses `new` and `delete` to manage memory at runtime.

- **Additional Theory**:
  - Dynamic allocation occurs on the **heap**, contrasting with stack-based automatic variables, offering flexibility for variable lifetimes and sizes.
  - It reflects C++’s **manual memory management** philosophy, giving developers control but requiring diligence to avoid leaks or dangling pointers.
  - The `new` operator invokes constructors for objects, integrating memory allocation with initialization, a unique C++ feature over C’s `malloc`.
  - Memory fragmentation can occur with frequent allocations/deallocations, impacting performance in long-running programs.
  - Modern C++ encourages **smart pointers** (e.g., `unique_ptr`, `shared_ptr`) over raw `new`/`delete` to automate deallocation, reducing errors.

- **Example**:
```cpp
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int;
    *ptr = 10000;
    cout << *ptr << endl;  // Outputs: 10000
    delete ptr;
    return 0;
}
```

---
