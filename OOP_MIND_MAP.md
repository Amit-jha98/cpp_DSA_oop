# Complete Object-Oriented Programming Guide

## Introduction to Object-Oriented Programming

Object-Oriented Programming (OOP) is a programming paradigm that organizes software design around data, or objects, rather than functions and logic. An object can be defined as a data field that has unique attributes and behavior. OOP focuses on the objects that developers want to manipulate rather than the logic required to manipulate them.

### Key Benefits of OOP:
1. **Modularity**: Encapsulated objects can be maintained separately
2. **Reusability**: Objects can be reused across applications
3. **Maintainability**: Easier to maintain and modify existing code
4. **Data Security**: Implementation details are hidden
5. **Scalability**: New objects can be added with minimal modification

## Table of Contents
- [Introduction to Object-Oriented Programming](#introduction-to-object-oriented-programming)
- [Core Concepts](#1-core-concepts)
    - [Classes and Objects](#classes-and-objects)
    - [Encapsulation](#encapsulation)
    - [Inheritance](#inheritance)
    - [Polymorphism](#polymorphism)
    - [Abstraction](#abstraction)
- [Advanced Concepts](#2-advanced-concepts)
    - [Design Patterns and Singleton](#singleton-pattern)
    - [Advanced Features](#advanced-oop-concepts)
        - [Friend Functions and Classes](#friend-functions-and-classes)
        - [Operator Overloading](#operator-overloading)
        - [Templates](#templates)
    - [Memory Management](#memory-management)
        - [Smart Pointers](#smart-pointers)
- [Best Practices](#best-practices)
- [Code Examples](#code-examples)
- [Additional Resources](#additional-resources)

## 1. Core Concepts
```
OOP
├── Classes
│   ├── Attributes/Properties
│   ├── Methods/Functions
│   ├── Constructors
│   └── Destructors
│
├── Objects
│   ├── Instance Variables
│   └── Instance Methods
│
├── Encapsulation
│   ├── Data Hiding
│   ├── Access Modifiers
│   │   ├── Public
│   │   ├── Private
│   │   └── Protected
│   └── Getters/Setters
│
├── Inheritance
│   ├── Types
│   │   ├── Single
│   │   ├── Multiple
│   │   ├── Multilevel
│   │   └── Hierarchical
│   └── Virtual Functions
│
├── Polymorphism
│   ├── Compile-time (Static)
│   │   ├── Function Overloading
│   │   └── Operator Overloading
│   └── Runtime (Dynamic)
│       └── Function Overriding
│
└── Abstraction
        ├── Abstract Classes
        └── Interfaces
```

## 2. Advanced Concepts
```
Advanced OOP
├── Design Patterns
│   ├── Creational
│   │   ├── Singleton
│   │   ├── Factory
│   │   └── Builder
│   ├── Structural
│   │   ├── Adapter
│   │   ├── Decorator
│   │   └── Facade
│   └── Behavioral
│       ├── Observer
│       ├── Strategy
│       └── Command
│
├── SOLID Principles
│   ├── Single Responsibility
│   ├── Open-Closed
│   ├── Liskov Substitution
│   ├── Interface Segregation
│   └── Dependency Inversion
│
└── Memory Management
        ├── Stack vs Heap
        ├── Smart Pointers
        └── RAII
```

## 3. Implementation Features
```
Implementation
├── Class Members
│   ├── Data Members
│   │   ├── Instance Variables
│   │   └── Static Variables
│   └── Member Functions
│       ├── Instance Methods
│       └── Static Methods
│
├── Special Functions
│   ├── Constructors
│   │   ├── Default
│   │   ├── Parameterized
│   │   └── Copy
│   ├── Destructors
│   └── Assignment Operators
│
├── Friend Functions
│   ├── Friend Classes
│   └── Friend Methods
│
└── Templates
        ├── Function Templates
        └── Class Templates
```

## 4. Best Practices
```
Best Practices
├── Code Organization
│   ├── Header Files
│   └── Source Files
│
├── Naming Conventions
│   ├── Class Names
│   ├── Method Names
│   └── Variable Names
│
├── Error Handling
│   ├── Exceptions
│   └── Error States
│
└── Documentation
        ├── Comments
        └── API Documentation
```

## 5. Testing & Debugging
```
Testing
├── Unit Testing
│   ├── Class Testing
│   └── Method Testing
│
├── Integration Testing
│   └── Object Interactions
│
└── Debugging Techniques
        ├── Object State
        └── Method Flow
```

## Introduction to OOP

Object-Oriented Programming (OOP) is a paradigm that organizes software design around **objects** rather than functions and logic. Objects encapsulate data (attributes) and methods (functions) into a single unit.

### Key Benefits of OOP:
1. **Modularity**: Classes encapsulate data and functionality, making code more modular.
2. **Reusability**: Classes and objects can be reused in multiple applications.
3. **Data Security**: Encapsulation and access modifiers ensure restricted access to sensitive data.
4. **Scalability**: OOP makes it easier to scale and extend codebases.

---

## Core Concepts

---

# Classes and Objects

## **Class**
A **class** is a user-defined data type that serves as a blueprint for creating objects. It encapsulates:
1. **Attributes (Data Members)**: Variables to store data or state.
2. **Methods (Member Functions)**: Functions to define the behavior or actions.

### Characteristics of a Class:
- Classes define the structure and behavior of objects.
- Members of a class can have access specifiers:
  - `private`: Members accessible only within the class.
  - `public`: Members accessible from outside the class.
  - `protected`: Members accessible within the class and derived classes.

---

## **Object**
An **object** is an instance of a class. It represents a specific entity with actual data. Objects allow you to access the attributes and methods defined in the class.

### Key Points:
- Objects store **real data** as per the structure defined by the class.
- Multiple objects can be created from a single class, and each object will have its own copy of the data members.

---

## Syntax and Example

```cpp
#include <iostream>
using namespace std;

// Defining a class
class ClassName {
private:
    // Attributes (Data Members)
    int attribute1;
    double attribute2;

public:
    // Constructor: Initializes attributes when an object is created
    ClassName(int a, double b) : attribute1(a), attribute2(b) {}

    // Method to display the values of attributes
    void display() {
        cout << "Attribute 1: " << attribute1 << ", Attribute 2: " << attribute2 << endl;
    }
};

// Main function
int main() {
    // Creating an object of the class
    ClassName obj(5, 3.14);

    // Accessing a method using the object
    obj.display();

    return 0;
}
```

---

## Explanation

### Class Definition
```cpp
class ClassName {
private:
    int attribute1;  // Integer attribute
    double attribute2; // Double attribute

public:
    // Constructor to initialize attributes
    ClassName(int a, double b) : attribute1(a), attribute2(b) {}

    // Method to display the attributes
    void display() {
        cout << "Attribute 1: " << attribute1 << ", Attribute 2: " << attribute2 << endl;
    }
};
```

1. **Attributes**:
   - `attribute1` and `attribute2` store data for the object.
   - Access specifier `private` ensures attributes can only be accessed within the class.

2. **Constructor**:
   - A special member function with the same name as the class.
   - Initializes the attributes when an object is created.
   - Uses an **initializer list** (`: attribute1(a), attribute2(b)`) to assign values to attributes.

3. **Method**:
   - The `display` method prints the values of `attribute1` and `attribute2`.
   - The `public` access specifier allows this method to be called from outside the class.

---

### Object Creation and Usage
```cpp
// Creating an object of the class
ClassName obj(5, 3.14);

// Calling the display method using the object
obj.display();
```

1. **Object Creation**:
   - The `ClassName obj(5, 3.14);` line creates an object named `obj` and initializes `attribute1` with `5` and `attribute2` with `3.14`.

2. **Method Invocation**:
   - The `obj.display();` line calls the `display` method to output the object's attribute values.

---

## Output
When you run the program, the output will be:
```
Attribute 1: 5, Attribute 2: 3.14
```

---

## Additional Example: Multiple Objects

```cpp
#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    int year;

public:
    // Constructor to initialize attributes
    Car(string b, int y) : brand(b), year(y) {}

    // Method to display car details
    void displayDetails() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    // Creating multiple objects of the Car class
    Car car1("Toyota", 2020);
    Car car2("Ford", 2018);

    // Calling methods using objects
    car1.displayDetails();
    car2.displayDetails();

    return 0;
}
```

### Output:
```
Brand: Toyota, Year: 2020
Brand: Ford, Year: 2018
```

In this example:
- Two objects (`car1` and `car2`) are created from the `Car` class.
- Each object stores its own values for `brand` and `year`.

---


---

---

### Encapsulation

**Encapsulation** is one of the core principles of Object-Oriented Programming (OOP). It refers to the bundling of data (attributes) and methods (functions) that operate on that data into a single unit (a class). Encapsulation is used to hide the internal implementation details of an object and restrict access to its data.

### Key Points:
1. **Data Protection**: Prevents unauthorized access and modification of data by making attributes private.
2. **Access Modifiers**: Controls the visibility of class members:
   - `private`: Accessible only within the class.
   - `protected`: Accessible within the class and derived classes.
   - `public`: Accessible from anywhere.
3. **Controlled Access**: Provides **public getter and setter methods** to allow controlled access to private data.
4. **Improves Maintainability**: Allows internal implementation changes without affecting external code.

---

### Example: Encapsulation in a Bank Account System

#### Code:
```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance; // Encapsulated data: Balance is private

    // Validation helper function
    bool isValidAmount(double amount) {
        return amount > 0;
    }

public:
    // Constructor to initialize the balance
    BankAccount(double initialBalance) {
        if (initialBalance >= 0)
            balance = initialBalance;
        else {
            balance = 0;
            cout << "Invalid initial balance! Setting to 0." << endl;
        }
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        if (isValidAmount(amount)) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (isValidAmount(amount) && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    // Getter method to access the balance
    double getBalance() const {
        return balance;
    }
};

int main() {
    // Creating an object of the BankAccount class
    BankAccount account(1000.0);

    // Performing operations on the account
    account.deposit(500.0);         // Depositing money
    account.withdraw(300.0);       // Withdrawing money
    account.withdraw(1500.0);      // Attempt to overdraw

    // Accessing the balance using the getter
    cout << "Current Balance: " << account.getBalance() << endl;

    return 0;
}
```

---

#### Explanation:
1. **Private Data**:
   - The `balance` variable is declared as `private`. This ensures it cannot be accessed or modified directly from outside the class.
   
2. **Public Methods**:
   - **`deposit(double amount)`**: Adds money to the account. It validates the input using a private helper function `isValidAmount`.
   - **`withdraw(double amount)`**: Subtracts money from the account after checking the validity of the amount and ensuring sufficient balance.
   - **`getBalance()`**: Provides read-only access to the balance.

3. **Validation**:
   - The `isValidAmount()` helper function ensures that only positive amounts are processed. This protects the integrity of the data.

4. **Constructor**:
   - Initializes the `balance` when the object is created. If an invalid initial balance is provided, it sets the balance to `0` and displays an error message.

---

### Output:
```
Deposited: 500
Withdrew: 300
Invalid withdrawal amount or insufficient balance!
Current Balance: 1200
```

---

### Benefits of Encapsulation:
1. **Security**: The `balance` is hidden from external access, ensuring unauthorized changes are prevented.
2. **Validation**: Only valid operations are allowed, improving data consistency.
3. **Flexibility**: The internal logic (like validation rules) can be modified without affecting the external code that uses the class.

---

---

---

# Inheritance

## What is Inheritance?
**Inheritance** is one of the key principles of Object-Oriented Programming (OOP). It allows one class (called the **child class** or **derived class**) to inherit the properties and behaviors (attributes and methods) of another class (called the **parent class** or **base class**). This mechanism promotes **code reuse** and establishes a hierarchical relationship between classes.

---

## Benefits of Inheritance
1. **Code Reusability**: Common functionality defined in the base class can be reused in derived classes.
2. **Hierarchy**: Establishes a clear hierarchy between classes.
3. **Extensibility**: Makes it easy to extend the functionality of an existing class.
4. **Consistency**: Avoids duplication of code, improving maintainability.

---

## Key Concepts in Inheritance
1. **Base Class**:
   - The parent class from which properties and methods are inherited.
2. **Derived Class**:
   - The child class that inherits properties and methods from the base class.
3. **Access Specifiers**:
   - Control how members of the base class are accessible in the derived class:
     - `public`: Accessible to everyone.
     - `protected`: Accessible within the class, its derived classes, and friends.
     - `private`: Accessible only within the class.

---

## Types of Inheritance

### 1. Single Inheritance
A derived class inherits from a single base class.

#### Code Example:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog : public Animal { // Dog inherits from Animal
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();  // Method inherited from Animal
    dog.bark(); // Method specific to Dog
    return 0;
}
```

#### Explanation:
- The `Dog` class is derived from the `Animal` class using the `public` access specifier.
- The `eat()` method of the `Animal` class is reused in the `Dog` class.
- The `Dog` class adds its own functionality through the `bark()` method.

---

### 2. Multilevel Inheritance
A derived class inherits from another derived class, forming a chain of inheritance.

#### Code Example:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Mammal : public Animal {
public:
    void walk() {
        cout << "This mammal walks." << endl;
    }
};

class Dog : public Mammal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();  // Inherited from Animal
    dog.walk(); // Inherited from Mammal
    dog.bark(); // Specific to Dog
    return 0;
}
```

#### Explanation:
- The `Dog` class indirectly inherits the `eat()` method from `Animal` through the `Mammal` class.
- This demonstrates a hierarchy where each class builds upon its parent class.

---

### 3. Multiple Inheritance
A derived class inherits from multiple base classes.

#### Code Example:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Pet {
public:
    void play() {
        cout << "This pet loves to play." << endl;
    }
};

class Dog : public Animal, public Pet {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();  // Inherited from Animal
    dog.play(); // Inherited from Pet
    dog.bark(); // Specific to Dog
    return 0;
}
```

#### Explanation:
- The `Dog` class inherits from both the `Animal` and `Pet` classes.
- It combines functionality from multiple base classes.
- **Note**: Be cautious of the **Diamond Problem** when using multiple inheritance (explained below).

---

### 4. Hierarchical Inheritance
Multiple derived classes inherit from a single base class.

#### Code Example:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "The cat meows." << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    dog.eat();  // Inherited from Animal
    dog.bark(); // Specific to Dog

    cat.eat();  // Inherited from Animal
    cat.meow(); // Specific to Cat

    return 0;
}
```

#### Explanation:
- Both the `Dog` and `Cat` classes inherit the `eat()` method from the `Animal` class.
- Each derived class adds its own specific functionality (`bark()` for Dog, `meow()` for Cat).

---

### The Diamond Problem in Multiple Inheritance
When a class inherits from two classes that share a common base class, ambiguity can arise regarding which version of the base class's method to use.

#### Example of the Problem:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Mammal : public Animal {};

class Bird : public Animal {};

class Bat : public Mammal, public Bird {}; // Multiple inheritance

int main() {
    Bat bat;
    // bat.eat(); // Error: Ambiguity between Mammal::eat and Bird::eat
    return 0;
}
```

#### Solution: Virtual Inheritance
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Mammal : virtual public Animal {};
class Bird : virtual public Animal {};
class Bat : public Mammal, public Bird {};

int main() {
    Bat bat;
    bat.eat(); // Ambiguity resolved using virtual inheritance
    return 0;
}
```

---

## Access Specifiers in Inheritance
The type of inheritance (`public`, `protected`, or `private`) determines the accessibility of base class members in the derived class.

| Base Class Members  | Public Inheritance | Protected Inheritance | Private Inheritance |
|---------------------|--------------------|-----------------------|---------------------|
| `public`            | `public`          | `protected`           | `private`           |
| `protected`         | `protected`       | `protected`           | `private`           |
| `private`           | Inaccessible      | Inaccessible          | Inaccessible        |

---

## Real-Life Example: Vehicle Inheritance Hierarchy
```cpp
#include <iostream>
using namespace std;

class Vehicle {
public:
    void start() {
        cout << "Vehicle started." << endl;
    }
};

class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is driving." << endl;
    }
};

class ElectricCar : public Car {
public:
    void chargeBattery() {
        cout << "Battery is charging." << endl;
    }
};

int main() {
    ElectricCar tesla;
    tesla.start();        // Inherited from Vehicle
    tesla.drive();        // Inherited from Car
    tesla.chargeBattery(); // Specific to ElectricCar

    return 0;
}
```

---

## Summary
1. Inheritance enables the reuse of existing code by creating a hierarchy of classes.
2. Use **public inheritance** for "is-a" relationships.
3. Be cautious of the **Diamond Problem** in multiple inheritance and resolve it using **virtual inheritance**.
4. Inheritance is a key feature for implementing polymorphism and extending functionality.


---

---

# Polymorphism

## What is Polymorphism?
**Polymorphism** is one of the fundamental principles of Object-Oriented Programming (OOP). The term "polymorphism" means "many forms." It allows one interface (function or operator) to represent different behaviors depending on the context.

### Key Characteristics of Polymorphism:
1. **Single Interface, Multiple Implementations**: A single function, method, or operator can behave differently based on the input or the type of object it is applied to.
2. **Improved Code Reusability**: Polymorphism reduces code duplication by using a common interface.
3. **Extensibility**: Polymorphism makes it easier to add new functionality with minimal changes to existing code.

---

## Types of Polymorphism

### 1. Compile-Time Polymorphism (Static Binding)
- Resolved at **compile time**.
- Achieved through:
  - **Function Overloading**: Multiple functions with the same name but different parameter lists.
  - **Operator Overloading**: Custom behavior for operators (e.g., `+`, `*`) when applied to user-defined types.

#### **Example: Function Overloading**
```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    // Overloaded add functions
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    string add(string a, string b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    cout << calc.add(5, 3) << endl;       // Calls int version
    cout << calc.add(2.5, 3.1) << endl;  // Calls double version
    cout << calc.add("Hello, ", "World!") << endl; // Calls string version

    return 0;
}
```

#### Output:
```
8
5.6
Hello, World!
```

---

#### **Example: Operator Overloading**
```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the '+' operator
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Display the complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.5, 2.5), c2(1.5, 3.5);
    Complex c3 = c1 + c2; // Uses overloaded '+' operator

    c3.display();

    return 0;
}
```

#### Output:
```
5 + 6i
```

---

### 2. Runtime Polymorphism (Dynamic Binding)
- Resolved at **runtime**.
- Achieved using:
  - **Virtual Functions**: Allows derived classes to override base class methods.
  - **Function Overriding**: A method in a derived class provides a specific implementation of a method declared in the base class.

#### Key Features of Runtime Polymorphism:
- Base class pointers or references can be used to call methods of derived classes.
- Requires a **virtual** keyword in the base class method.
- Ensures **dynamic binding** through a **vtable** (virtual table).

---

#### **Example: Virtual Functions**
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    // Virtual method
    virtual void draw() {
        cout << "Drawing a generic shape." << endl;
    }

    // Virtual destructor
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override { // Override base class method
        cout << "Drawing a circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override { // Override base class method
        cout << "Drawing a rectangle." << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();    // Pointer to base class
    Shape* shape2 = new Rectangle();

    shape1->draw(); // Calls Circle's draw()
    shape2->draw(); // Calls Rectangle's draw()

    // Clean up
    delete shape1;
    delete shape2;

    return 0;
}
```

#### Output:
```
Drawing a circle.
Drawing a rectangle.
```

#### Explanation:
1. The `draw()` method in the base class `Shape` is declared as `virtual`, allowing derived classes to override it.
2. At runtime, the method corresponding to the actual type of object (`Circle` or `Rectangle`) is invoked, not the type of the pointer (`Shape`).

---

### Real-Life Analogy of Polymorphism

Consider the example of a **media player**:
- The base class `MediaPlayer` provides a method `play()`.
- Derived classes like `AudioPlayer` and `VideoPlayer` override the `play()` method to handle audio and video files differently.

---

## Key Differences Between Compile-Time and Runtime Polymorphism

| Feature                  | Compile-Time Polymorphism                | Runtime Polymorphism            |
|--------------------------|------------------------------------------|----------------------------------|
| **Binding Time**         | Resolved at compile time (static)        | Resolved at runtime (dynamic)   |
| **Methods**              | Achieved through function/operator overloading | Achieved through virtual functions |
| **Performance**          | Faster, as the function to be called is known at compile time | Slightly slower due to runtime overhead |
| **Flexibility**          | Less flexible                           | More flexible                   |

---

## Advanced Runtime Polymorphism Example: Abstract Classes

An **abstract class** is a class that cannot be instantiated directly. It contains at least one **pure virtual function**.

#### Code Example:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() = 0; // Pure virtual function
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks." << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows." << endl;
    }
};

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->sound(); // Calls Dog's sound()
    cat->sound(); // Calls Cat's sound()

    delete dog;
    delete cat;

    return 0;
}
```

#### Output:
```
Dog barks.
Cat meows.
```

---

## Summary of Polymorphism
1. **Polymorphism** allows a single interface to have multiple implementations.
2. **Compile-Time Polymorphism** uses function overloading and operator overloading for static binding.
3. **Runtime Polymorphism** uses virtual functions and function overriding for dynamic binding.
4. Enhances **code flexibility**, **reusability**, and **extensibility**.


#### Example: Virtual Functions
```cpp
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

int main() {
    Shape* shape = new Circle();
    shape->draw(); // Calls Circle's draw()
    delete shape;
    return 0;
}
```

---


---

# Abstraction

## What is Abstraction?

**Abstraction** is an Object-Oriented Programming (OOP) concept that focuses on **hiding implementation details** and exposing only the essential features of an object. It provides a clear interface while keeping the internal workings hidden.

### Key Characteristics:
1. **Simplification**: Users interact with an interface rather than understanding the internal complexity.
2. **Separation of Concerns**: Implementation details are abstracted away from the user.
3. **Implementation Hiding**: Internal workings are kept private and can be modified without affecting external code.

---

## How Abstraction is Achieved in C++
Abstraction can be implemented in two primary ways:
1. **Abstract Classes**: A class that contains at least one pure virtual function. 
2. **Interfaces**: Classes that only contain pure virtual functions, functioning as complete blueprints.

---

## Example: Abstract Classes

```cpp
#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual functions
    virtual double area() = 0;  // Must be overridden in derived classes
    virtual void display() = 0; // Must be overridden in derived classes

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {}

    // Override pure virtual functions
    double area() override {
        return 3.14 * radius * radius;
    }

    void display() override {
        cout << "Circle Area: " << area() << endl;
    }
};

// Main function
int main() {
    Shape* shape = new Circle(5); // Create a Circle object using Shape pointer
    shape->display();             // Call overridden function
    delete shape;                 // Free allocated memory
    return 0;
}
```

---

### Explanation:
1. **Abstract Class**:
   - The `Shape` class is an abstract class because it contains pure virtual functions (`area()` and `display()`).
   - A pure virtual function is declared by assigning `= 0` in the method definition.

2. **Derived Class**:
   - The `Circle` class inherits from `Shape` and provides specific implementations of the `area()` and `display()` functions.
   - Since `Shape` is abstract, objects of `Shape` cannot be created directly.

3. **Dynamic Binding**:
   - A `Shape*` pointer is used to reference the derived `Circle` object, showcasing runtime polymorphism.

4. **Virtual Destructor**:
   - The virtual destructor ensures that the destructor of the derived class is called when the object is deleted.

---

## Example: Multiple Shapes Using Abstraction

```cpp
#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    virtual double area() = 0; // Pure virtual function
    virtual void display() = 0; // Pure virtual function

    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14 * radius * radius;
    }

    void display() override {
        cout << "Circle Area: " << area() << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

    void display() override {
        cout << "Rectangle Area: " << area() << endl;
    }
};

int main() {
    // Array of Shape pointers
    Shape* shapes[2];

    shapes[0] = new Circle(5);         // Create a Circle object
    shapes[1] = new Rectangle(4, 6);  // Create a Rectangle object

    // Display the details of all shapes
    for (int i = 0; i < 2; i++) {
        shapes[i]->display();
        delete shapes[i]; // Free allocated memory
    }

    return 0;
}
```

---

### Output:
```
Circle Area: 78.5
Rectangle Area: 24
```

---

## Real-Life Analogy of Abstraction

Imagine a **TV Remote Control**:
- The **remote control** is the interface: It provides buttons to increase volume, change the channel, etc.
- The **internal mechanism** of the TV is abstracted: You don’t need to know how the signals are processed to change the channel.

---

## Key Features of Abstraction

1. **Pure Virtual Functions**:
   - Declared using `= 0` syntax in a class.
   - Forces derived classes to implement them.
   - Example:
     ```cpp
     virtual void functionName() = 0;
     ```

2. **Abstract Class**:
   - Cannot be instantiated directly.
   - Can have both pure virtual functions and regular member functions.

3. **Separation of Interface and Implementation**:
   - Interface (abstract class or pure virtual functions) defines "what" the object does.
   - Derived classes define "how" it is done.

---

## Interface in C++ (Pure Abstract Class)

An **interface** is a class that contains only pure virtual functions. It is essentially a contract that derived classes must adhere to.

#### Code Example:
```cpp
#include <iostream>
using namespace std;

// Interface
class Printable {
public:
    virtual void print() = 0; // Pure virtual function
    virtual ~Printable() {}
};

// Derived class: Report
class Report : public Printable {
public:
    void print() override {
        cout << "Printing a Report." << endl;
    }
};

// Derived class: Invoice
class Invoice : public Printable {
public:
    void print() override {
        cout << "Printing an Invoice." << endl;
    }
};

int main() {
    Printable* doc1 = new Report();  // Interface pointer to Report
    Printable* doc2 = new Invoice(); // Interface pointer to Invoice

    doc1->print();
    doc2->print();

    delete doc1;
    delete doc2;

    return 0;
}
```

---

### Output:
```
Printing a Report.
Printing an Invoice.
```

---

## Differences Between Abstraction and Encapsulation

| Feature                 | Abstraction                                     | Encapsulation                                  |
|-------------------------|------------------------------------------------|-----------------------------------------------|
| **Definition**          | Hides implementation details.                  | Hides internal data from direct access.       |
| **Focus**               | Focuses on "what" the object does.             | Focuses on "how" the object achieves it.      |
| **Implementation**      | Achieved using abstract classes and interfaces.| Achieved using access specifiers (private/protected). |
| **Real-World Example**  | TV remote (hides internal mechanism).           | Bank account (hides balance data).            |

---

## Summary

1. **Abstraction** hides the internal implementation and exposes only essential details to the user.
2. Achieved using **abstract classes** or **interfaces**.
3. Pure virtual functions act as contracts that derived classes must fulfill.
4. Promotes **flexibility**, **modularity**, and **separation of concerns**.


---

## Advanced OOP Concepts

### Friend Functions and Classes

A **friend function** can access private and protected members of a class.

#### Example
```cpp
class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    friend void printWidth(Box b); // Declare friend function
};

void printWidth(Box b) {
    cout << "Width: " << b.width << endl; // Access private member
}

int main() {
    Box b(10.5);
    printWidth(b);
    return 0;
}
```

---

### Operator Overloading

Operators can be redefined to work with user-defined types.

#### Example
```cpp
class Complex {
private:
    double real, imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Overloading the '+' operator
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.5, 2.5), c2(1.5, 3.5);
    Complex c3 = c1 + c2; // Using overloaded operator
    c3.display();
    return 0;
}
```

---

### Templates

Templates allow writing generic code that works with any data type.

#### Example: Function Template
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(5, 3) << endl;       // Integers
    cout << add(2.5, 3.1) << endl;  // Doubles
    return 0;
}
```

---

## Design Patterns

### Singleton Pattern
Ensures that a class has only one instance and provides a global access point.

#### Example
```cpp
class Singleton {
private:
    static Singleton* instance;

    // Private constructor
    Singleton() {}

public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout << (s1 == s2) << endl; // Output: 1 (same instance)
    return 0;
}
```

---

## Best Practices
1. Use **encapsulation** to protect sensitive data.
2. Follow **naming conventions** for readability.
3. Use **virtual destructors** in base classes.
4. Prefer **composition** over inheritance when possible.

---

## Memory Management

### Smart Pointers
Use smart pointers (`unique_ptr`, `shared_ptr`) to manage dynamic memory automatically.

#### Example
```cpp
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> p1 = make_unique<int>(10); // Automatically deleted
    cout << *p1 << endl;

    shared_ptr<int> p2 = make_shared<int>(20); // Shared ownership
    cout << *p2 << endl;

    return 0;
}
```

---

## Code Examples

- **Bank Account System**
- **Employee Management System**
- **Shape Hierarchy**
- **Library Management System**

---

## Additional Resources

- [C++ Reference](https://en.cppreference.com/)
- [Design Patterns](https://refactoring.guru/design-patterns)

---

You can copy and save this content as a `.md` file. Let me know if you'd like further refinements!