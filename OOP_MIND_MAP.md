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
- [Core Concepts](#1-core-concepts)
  - [Classes and Objects](#1-classes-and-objects)
  - [Encapsulation](#2-encapsulation)
  - [Inheritance](#3-inheritance)
  - [Polymorphism](#4-polymorphism)
  - [Abstraction](#5-abstraction)
- [Advanced Concepts](#2-advanced-concepts)
  - [Design Patterns](#7-design-patterns)
  - [SOLID Principles](#8-best-practices)
  - [Memory Management](#9-memory-management)
- [Implementation Features](#3-implementation-features)
  - [Templates](#61-templates)
  - [Friend Functions](#62-friend-functions)
- [Best Practices](#4-best-practices)
- [Testing & Debugging](#5-testing--debugging)
- [Practice Examples](#10-practice-examples)
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

## Detailed Concept Explanations

### Classes and Objects Explained

A class is a blueprint for creating objects. Think of it like a cookie cutter - the class is the template, and objects are the cookies you make from it.

#### Key Components:
1. **Data Members (Attributes)**
   - Variables that store object state
   - Example: A `Car` class might have `color`, `model`, and `speed`
   - Usually private to maintain encapsulation

2. **Member Functions (Methods)**
   - Functions that define object behavior
   - Example: `startEngine()`, `accelerate()`, `brake()`
   - Can be public, private, or protected

3. **Access Specifiers**
   ```cpp
   class Example {
   private:     // Only accessible within the class
       int privateVar;
   
   protected:   // Accessible in derived classes
       int protectedVar;
   
   public:      // Accessible everywhere
       int publicVar;
   };
   ```

### Encapsulation Explained

Encapsulation is like a protective wrapper that:
- Keeps data and methods together
- Hides internal details
- Protects data integrity

#### Implementation Strategy:
1. Make data members private
2. Provide public methods for access
3. Add validation in setter methods
4. Use const for read-only methods

## Detailed Encapsulation Guide

### What is Encapsulation?
Encapsulation is like a protective capsule that:
1. Wraps data and methods together in a single unit (class)
2. Protects data from unauthorized access
3. Controls how data is accessed and modified
4. Implements information hiding

### Why Use Encapsulation?
1. **Data Protection**
   - Prevents direct manipulation of data
   - Ensures data integrity
   - Validates data before changes

2. **Flexibility**
   - Change internal implementation without affecting other code
   - Maintain backward compatibility
   - Version control friendly

3. **Maintainability**
   - Easier debugging
   - Better code organization
   - Reduced complexity

### Implementation Examples

#### 1. Basic Encapsulation
```cpp
class Employee {
private:
    string name;
    double salary;
    int id;

    bool isValidSalary(double amount) {
        return amount >= 0 && amount <= 1000000;
    }

public:
    // Constructor with validation
    Employee(string n, double s, int i) {
        name = n;
        id = i;
        if (isValidSalary(s)) {
            salary = s;
        } else {
            throw invalid_argument("Invalid salary amount");
        }
    }

    // Getter methods (read-only access)
    string getName() const { return name; }
    int getId() const { return id; }
    double getSalary() const { return salary; }

    // Setter method with validation
    bool setSalary(double newSalary) {
        if (isValidSalary(newSalary)) {
            salary = newSalary;
            return true;
        }
        return false;
    }
};
```

#### 2. Advanced Encapsulation Patterns

##### 2.1 Nested Class Encapsulation
```cpp
class BankSystem {
private:
    class Account {
    private:
        string accountNumber;
        double balance;
        
    public:
        Account(string num, double bal) : 
            accountNumber(num), balance(bal) {}
        
        bool withdraw(double amount) {
            if (amount <= balance) {
                balance -= amount;
                return true;
            }
            return false;
        }
    };
    
    vector<Account> accounts;
    
public:
    void createAccount(string num, double initialBalance) {
        accounts.emplace_back(num, initialBalance);
    }
    
    bool processWithdrawal(int accountIndex, double amount) {
        if (accountIndex < accounts.size()) {
            return accounts[accountIndex].withdraw(amount);
        }
        return false;
    }
};
```

##### 2.2 Data Validation Layer
```cpp
class UserProfile {
private:
    string email;
    string password;
    vector<string> loginHistory;

    bool isValidEmail(const string& email) {
        // Email validation logic
        return email.find('@') != string::npos;
    }

    bool isStrongPassword(const string& pwd) {
        return pwd.length() >= 8 && 
               pwd.find_first_of("0123456789") != string::npos &&
               pwd.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos;
    }

    void logLogin() {
        loginHistory.push_back("Login at: " + getCurrentTime());
    }

public:
    bool setEmail(const string& newEmail) {
        if (isValidEmail(newEmail)) {
            email = newEmail;
            return true;
        }
        return false;
    }

    bool setPassword(const string& newPassword) {
        if (isStrongPassword(newPassword)) {
            password = newPassword;
            return true;
        }
        return false;
    }

    bool login(const string& attemptedPassword) {
        if (attemptedPassword == password) {
            logLogin();
            return true;
        }
        return false;
    }
};
```

### Best Practices for Encapsulation

1. **Access Level Guidelines**
```cpp
class Product {
private:
    // Internal implementation details
    double price;
    int stock;
    
protected:
    // Shared with derived classes
    void updateInventory(int quantity);
    
public:
    // Public interface
    bool purchase(int quantity);
    double getPrice() const;
};
```

2. **Immutable Objects**
```cpp
class Configuration {
private:
    const string API_KEY;
    const int MAX_RETRIES;
    
public:
    Configuration(string key, int retries) : 
        API_KEY(key), MAX_RETRIES(retries) {}
        
    string getApiKey() const { return API_KEY; }
    int getMaxRetries() const { return MAX_RETRIES; }
};
```

3. **Interface Segregation**
```cpp
class Database {
private:
    // Connection details
    string connectionString;
    bool isConnected;

public:
    // Minimal public interface
    bool connect();
    bool disconnect();
    bool executeQuery(const string& query);
    
    // No direct access to connection details
};
```

### Common Encapsulation Patterns

#### 1. PIMPL (Pointer to Implementation)
```cpp
// Header file
class Engine {
private:
    class Impl;
    unique_ptr<Impl> pimpl;

public:
    Engine();
    void start();
    void stop();
    ~Engine();
};

// Implementation file
class Engine::Impl {
private:
    bool isRunning;
    int temperature;
    
public:
    void start() { /* implementation */ }
    void stop() { /* implementation */ }
};
```

#### 2. Facade Pattern
```cpp
class ComputerSystem {
private:
    class CPU {
        void freeze() {}
        void execute() {}
    };
    
    class Memory {
        void load() {}
        void free() {}
    };
    
    CPU cpu;
    Memory memory;
    
public:
    // Simple interface hiding complex subsystems
    void start() {
        cpu.freeze();
        memory.load();
        cpu.execute();
    }
};
```

### Inheritance Explained

Inheritance creates a parent-child relationship between classes, allowing code reuse.

#### Types of Inheritance:
1. **Single Inheritance**
   ```cpp
   class Animal { }; 
   class Dog : public Animal { };  // Dog inherits from Animal
   ```

2. **Multiple Inheritance**
   ```cpp
   class Camera { };
   class Phone { };
   class Smartphone : public Camera, public Phone { };
   ```

3. **Multilevel Inheritance**
   ```cpp
   class Vehicle { };
   class Car : public Vehicle { };
   class ElectricCar : public Car { };
   ```

### Polymorphism Explained

Polymorphism allows objects to take multiple forms.

#### Two Types:

1. **Compile-time (Static)**
   - Function overloading
   - Operator overloading
   - Resolved at compile time
   ```cpp
   class Calculator {
   public:
       int add(int a, int b) { return a + b; }
       double add(double a, double b) { return a + b; }
   };
   ```

2. **Runtime (Dynamic)**
   - Virtual functions
   - Function overriding
   - Resolved at runtime
   ```cpp
   class Shape {
   public:
       virtual double area() = 0;  // Pure virtual function
   };
   ```

### Abstraction Explained

Abstraction focuses on essential features while hiding complexity.

#### Implementation Methods:

1. **Abstract Classes**
   - Contains at least one pure virtual function
   - Cannot be instantiated
   - Serves as interface
   ```cpp
   class Database {
   public:
       virtual void connect() = 0;
       virtual void disconnect() = 0;
   };
   ```

2. **Interfaces**
   - Pure abstract classes
   - All methods are pure virtual
   ```cpp
   class Printable {
   public:
       virtual void print() = 0;
       virtual ~Printable() = default;
   };
   ```

### Design Patterns Explained

Design patterns are reusable solutions to common problems.

#### Common Patterns:

1. **Singleton Pattern**
   - Ensures only one instance exists
   - Global point of access
   ```cpp
   class Singleton {
       static Singleton* instance;
       Singleton() {}
   public:
       static Singleton* getInstance();
   };
   ```

2. **Factory Pattern**
   - Creates objects without specifying exact class
   - Subclasses decide which class to instantiate
   ```cpp
   class Factory {
   public:
       static Product* createProduct(string type);
   };
   ```

### Memory Management Explained

Proper memory management is crucial in C++ OOP.

#### Key Concepts:

1. **Smart Pointers**
   ```cpp
   unique_ptr<Class> ptr(new Class());  // Automatically deleted
   shared_ptr<Class> shared(new Class());  // Reference counted
   ```

2. **RAII (Resource Acquisition Is Initialization)**
   ```cpp
   class ResourceManager {
       Resource* res;
   public:
       ResourceManager() : res(new Resource()) {}
       ~ResourceManager() { delete res; }
   };
   ```

## Comprehensive OOP Concepts Guide

### 1. Classes and Objects

#### 1.1 Class Structure
```cpp
class Employee {
private:
    // Data members (attributes)
    string name;
    int id;
    double salary;

protected:
    // Protected members accessible to derived classes
    string department;

public:
    // Constructors
    Employee() : id(0), salary(0) {}  // Default constructor
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {}  // Parameterized

    // Member functions (methods)
    void displayInfo() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }

    // Getter/Setter methods
    double getSalary() const { return salary; }
    void setSalary(double s) { salary = s; }

    // Destructor
    ~Employee() {
        // Cleanup code
    }
};
```

#### 1.2 Object Creation and Usage
```cpp
// Stack allocation
Employee emp1("John", 101, 50000);

// Heap allocation
Employee* emp2 = new Employee("Jane", 102, 60000);

// Object usage
emp1.displayInfo();
emp2->displayInfo();

// Don't forget to delete heap objects
delete emp2;
```

### 2. Encapsulation Deep Dive

#### 2.1 Access Modifiers
```cpp
class BankAccount {
private:
    double balance;  // Only accessible within class
    string accountNumber;
    
    bool validateTransaction(double amount) {
        return (amount > 0 && balance >= amount);
    }

protected:
    void updateBalance(double amount) {
        balance += amount;
    }

public:
    bool withdraw(double amount) {
        if (validateTransaction(amount)) {
            updateBalance(-amount);
            return true;
        }
        return false;
    }
};
```

#### 2.2 Data Hiding Implementation
```cpp
class Student {
private:
    int scores[5];
    double calculateAverage() const {
        double sum = 0;
        for(int i = 0; i < 5; i++) sum += scores[i];
        return sum/5;
    }

public:
    void setScore(int index, int value) {
        if(index >= 0 && index < 5 && value >= 0 && value <= 100) {
            scores[index] = value;
        }
    }

    char getGrade() const {
        double avg = calculateAverage();
        if(avg >= 90) return 'A';
        if(avg >= 80) return 'B';
        return 'C';
    }
};
```

### 3. Inheritance Advanced Concepts

#### 3.1 Types of Inheritance
```cpp
// Single Inheritance
class Animal {
protected:
    string name;
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "Woof!" << endl; }
};

// Multiple Inheritance
class Camera {
public:
    virtual void takePhoto() = 0;
};

class Phone {
public:
    virtual void makeCall() = 0;
};

class Smartphone : public Camera, public Phone {
public:
    void takePhoto() override { cout << "Click!" << endl; }
    void makeCall() override { cout << "Dialing..." << endl; }
};

// Multilevel Inheritance
class Vehicle {
protected:
    string brand;
public:
    virtual void start() = 0;
};

class Car : public Vehicle {
protected:
    int doors;
public:
    void start() override { cout << "Car starting" << endl; }
};

class ElectricCar : public Car {
private:
    int batteryLevel;
public:
    void start() override { 
        if(batteryLevel > 0) cout << "Silent start" << endl; 
    }
};
```

### 4. Advanced Polymorphism

#### 4.1 Virtual Functions and Late Binding
```cpp
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    double perimeter() const override { return 2 * (width + height); }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
    double perimeter() const override { return 2 * 3.14159 * radius; }
};
```

#### 4.2 Template Metaprogramming
```cpp
template<typename T, typename U>
class Pair {
private:
    T first;
    U second;
public:
    Pair(T f, U s) : first(f), second(s) {}
    
    template<typename V>
    bool compareFirst(const V& value) {
        return first == value;
    }
    
    // Perfect forwarding example
    template<typename... Args>
    void processValues(Args&&... args) {
        // Process multiple arguments
    }
};
```

### 5. Design Patterns Implementation

#### 5.1 Observer Pattern
```cpp
class Observer {
public:
    virtual void update(const string& message) = 0;
};

class Subject {
private:
    vector<Observer*> observers;
public:
    void attach(Observer* obs) { observers.push_back(obs); }
    void notify(const string& message) {
        for(auto obs : observers) obs->update(message);
    }
};
```

#### 5.2 Factory Method Pattern
```cpp
class Logger {
public:
    virtual void log(const string& message) = 0;
    virtual ~Logger() = default;
};

class FileLogger : public Logger {
public:
    void log(const string& message) override {
        // Log to file
    }
};

class ConsoleLogger : public Logger {
public:
    void log(const string& message) override {
        cout << message << endl;
    }
};

class LoggerFactory {
public:
    static unique_ptr<Logger> createLogger(const string& type) {
        if(type == "file") return make_unique<FileLogger>();
        return make_unique<ConsoleLogger>();
    }
};
```

### 6. SOLID Principles with Examples

```cpp
// Single Responsibility Principle
class UserAuthentication {
public:
    bool authenticate(string username, string password);
};

class UserRepository {
public:
    void saveUser(User user);
};

// Open/Closed Principle
class PaymentProcessor {
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCardPayment : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        // Process credit card payment
    }
};

// Liskov Substitution Principle
class Bird {
public:
    virtual void move() = 0;
};

class FlyingBird : public Bird {
public:
    void move() override { fly(); }
protected:
    virtual void fly() = 0;
};

// Interface Segregation
class Printer {
public:
    virtual void print() = 0;
};

class Scanner {
public:
    virtual void scan() = 0;
};

class ModernPrinter : public Printer, public Scanner {
    // Implements both interfaces
};
```

### 6. Advanced OOP Concepts

#### 6.1 Templates
```cpp
template<typename T>
class SmartArray {
private:
    T* data;
    size_t size;

public:
    SmartArray(size_t s) : size(s) {
        data = new T[size];
    }
    
    T& operator[](size_t index) {
        return data[index];
    }
    
    ~SmartArray() {
        delete[] data;
    }
};
```

#### 6.2 Friend Functions
```cpp
class Complex {
private:
    double real, imag;
    friend Complex operator+(const Complex& a, const Complex& b);

public:
    Complex(double r, double i) : real(r), imag(i) {}
};

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}
```

### 7. Design Patterns

#### 7.1 Singleton Pattern
```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};
```

#### 7.2 Factory Pattern
```cpp
class Animal {
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "Woof!" << endl; }
};

class Cat : public Animal {
public:
    void makeSound() override { cout << "Meow!" << endl; }
};

class AnimalFactory {
public:
    static Animal* createAnimal(string type) {
        if (type == "dog") return new Dog();
        if (type == "cat") return new Cat();
        return nullptr;
    }
};
```

### 8. Best Practices

1. **SOLID Principles Implementation:**
```cpp
// Single Responsibility Principle
class Logger {
public:
    void logError(string message) {
        // Only responsible for logging
    }
};

class Calculator {
public:
    // Only responsible for calculations
    double calculate() {
        // calculation logic
    }
};
```

2. **Exception Handling:**
```cpp
class DivisionByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "Division by zero attempted";
    }
};

double divide(double a, double b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}
```

### 9. Memory Management

```cpp
// Smart Pointers
void smartPointerExample() {
    unique_ptr<int> uniq(new int(42));  // Automatically deleted
    shared_ptr<string> shared(new string("Hello"));  // Reference counted
    weak_ptr<string> weak = shared;  // No ownership
}

// RAII Example
class ResourceManager {
private:
    int* resource;

public:
    ResourceManager() : resource(new int[100]) {}
    ~ResourceManager() { delete[] resource; }
};
```

### 10. Practice Examples

1. Bank Account System
2. Shape Hierarchy
3. Employee Management System
4. Library Management System
5. Vehicle Rental System

For each of these systems, implement:
- Proper class hierarchy
- Encapsulation of data
- Appropriate use of inheritance
- Polymorphic behavior
- Exception handling
- Memory management

### Additional Resources
1. C++ Reference: [https://en.cppreference.com/](https://en.cppreference.com/)
2. Design Patterns: [https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns)
3. SOLID Principles: [https://www.digitalocean.com/community/tutorials/solid-principles-explained-in-plain-english](https://www.digitalocean.com/community/tutorials/solid-principles-explained-in-plain-english)

## Detailed Inheritance Guide

### What is Inheritance?
Inheritance is a mechanism that allows a class (derived/child) to inherit properties and methods from another class (base/parent). It enables:
- Code reuse
- Establishing relationships between classes
- Runtime polymorphism
- Extension of existing classes

### Types of Inheritance

#### 1. Single Inheritance
```cpp
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}
    virtual void makeSound() = 0;
};

class Dog : public Animal {
private:
    string breed;
public:
    Dog(string n, string b) : Animal(n), breed(b) {}
    void makeSound() override { cout << "Woof!" << endl; }
};
```

#### 2. Multiple Inheritance
```cpp
class Printer {
public:
    virtual void print() = 0;
};

class Scanner {
public:
    virtual void scan() = 0;
};

class AllInOnePrinter : public Printer, public Scanner {
public:
    void print() override { cout << "Printing..." << endl; }
    void scan() override { cout << "Scanning..." << endl; }
};
```

#### 3. Multilevel Inheritance
```cpp
class Vehicle {
protected:
    string brand;
public:
    Vehicle(string b) : brand(b) {}
    virtual void start() = 0;
};

class Car : public Vehicle {
protected:
    int seats;
public:
    Car(string b, int s) : Vehicle(b), seats(s) {}
    void start() override { cout << "Car starting" << endl; }
};

class ElectricCar : public Car {
private:
    int batteryCapacity;
public:
    ElectricCar(string b, int s, int bc) 
        : Car(b, s), batteryCapacity(bc) {}
    void start() override { 
        cout << "Electric car starting silently" << endl; 
    }
    void chargeBattery() { /* charging logic */ }
};
```

### Access Specifiers in Inheritance

```cpp
class Base {
private:
    int privateVar;    // Only accessible within Base
protected:
    int protectedVar;  // Accessible in Base and derived classes
public:
    int publicVar;     // Accessible everywhere
};

class Derived : public Base {
    void someFunction() {
        // protectedVar and publicVar are accessible
        // privateVar is not accessible
    }
};
```

### Virtual Functions and Abstract Classes

#### 1. Pure Virtual Functions
```cpp
class Shape {
public:
    virtual double area() = 0;      // Pure virtual function
    virtual double perimeter() = 0;  // Pure virtual function
    virtual ~Shape() = default;      // Virtual destructor
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() override { return width * height; }
    double perimeter() override { return 2 * (width + height); }
};
```

#### 2. Virtual Destructors
```cpp
class Base {
public:
    virtual ~Base() { 
        cout << "Base destructor" << endl; 
    }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() : data(new int[100]) {}
    ~Derived() override { 
        delete[] data;
        cout << "Derived destructor" << endl;
    }
};
```

### Advanced Inheritance Concepts

#### 1. Diamond Problem Solution
```cpp
class A {
protected:
    int value;
public:
    A(int v) : value(v) {}
};

class B : virtual public A {
public:
    B(int v) : A(v) {}
};

class C : virtual public A {
public:
    C(int v) : A(v) {}
};

class D : public B, public C {
public:
    D(int v) : A(v), B(v), C(v) {}  // Only one copy of A
};
```

#### 2. Protected Inheritance
```cpp
class Base {
public:
    void publicFunction() {}
protected:
    void protectedFunction() {}
};

class Derived : protected Base {
    // publicFunction becomes protected
    // protectedFunction remains protected
    void someFunction() {
        publicFunction();      // Accessible
        protectedFunction();   // Accessible
    }
};
```

### Best Practices for Inheritance

1. **Use Virtual Destructors**
```cpp
class Base {
public:
    virtual ~Base() = default;  // Always make base destructor virtual
};
```

2. **Override Keyword**
```cpp
class Derived : public Base {
public:
    void function() override {  // Catches errors if Base::function doesn't exist
        // Implementation
    }
};
```

3. **Composition vs Inheritance**
```cpp
// Prefer composition when "has-a" relationship
class Car {
private:
    Engine engine;      // Composition
    Transmission trans; // Composition
public:
    void start() {
        engine.start();
        trans.engage();
    }
};
```

### Common Inheritance Patterns

#### 1. Template Method Pattern
```cpp
class DataMiner {
public:
    void mine() {  // Template method
        openFile();
        extractData();
        parseData();
        analyzeData();
        closeFile();
    }
protected:
    virtual void extractData() = 0;
    virtual void analyzeData() = 0;
    // Common implementations
    void openFile() { /* common implementation */ }
    void parseData() { /* common implementation */ }
    void closeFile() { /* common implementation */ }
};

class PDFDataMiner : public DataMiner {
protected:
    void extractData() override { /* PDF-specific logic */ }
    void analyzeData() override { /* PDF-specific logic */ }
};
```

#### 2. Strategy Pattern with Inheritance
```cpp
class SortStrategy {
public:
    virtual void sort(vector<int>& data) = 0;
};

class QuickSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        // QuickSort implementation
    }
};

class MergeSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        // MergeSort implementation
    }
};
```

### Common Pitfalls and Solutions

1. **Object Slicing**
```cpp
// Avoid this:
Base b = derived;  // Slices off derived class members

// Instead use pointers or references:
Base* b = &derived;
Base& ref = derived;
```

2. **Multiple Inheritance Complexity**
```cpp
// Use interfaces (pure abstract classes) for multiple inheritance
class Interface1 {
public:
    virtual void method1() = 0;
};

class Interface2 {
public:
    virtual void method2() = 0;
};

class Implementation : public Interface1, public Interface2 {
    // Clean implementation of multiple interfaces
};
```

## Detailed Polymorphism Guide

### What is Polymorphism?
Polymorphism means "many forms" and occurs when we have many classes that are related to each other by inheritance. It allows us to:
- Perform a single action in different ways
- Process objects differently based on their data type
- Execute different functions using the same function name

### Types of Polymorphism

#### 1. Compile-time (Static) Polymorphism

##### 1.1 Function Overloading
```cpp
class Calculator {
public:
    // Overloaded functions
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    string add(string a, string b) {
        return a + b;
    }
    
    // Variable number of arguments
    template<typename... Args>
    double addMultiple(Args... args) {
        return (args + ...);
    }
};
```

##### 1.2 Operator Overloading
```cpp
class Vector {
private:
    double x, y;

public:
    Vector(double x = 0, double y = 0) : x(x), y(y) {}
    
    // Operator overloading
    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y);
    }
    
    Vector operator*(double scalar) const {
        return Vector(x * scalar, y * scalar);
    }
    
    // Friend operator overloading
    friend Vector operator*(double scalar, const Vector& v) {
        return v * scalar;
    }
};
```

#### 2. Runtime (Dynamic) Polymorphism

##### 2.1 Virtual Functions
```cpp
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual double perimeter() const = 0;
    virtual void scale(double factor) = 0;
    virtual ~Shape() = default;  // Virtual destructor
    
    // Non-virtual function
    void printInfo() const {
        cout << "Area: " << area() << endl
             << "Perimeter: " << perimeter() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
    
    void scale(double factor) override {
        radius *= factor;
    }
};
```

##### 2.2 Virtual Inheritance
```cpp
class Device {
protected:
    string id;
public:
    virtual void powerOn() = 0;
};

class Portable {
protected:
    int batteryLevel;
public:
    virtual void checkBattery() = 0;
};

// Virtual inheritance to solve diamond problem
class Laptop : virtual public Device, virtual public Portable {
public:
    void powerOn() override {
        if (batteryLevel > 0) {
            cout << "Laptop powered on" << endl;
        }
    }
    
    void checkBattery() override {
        cout << "Battery at " << batteryLevel << "%" << endl;
    }
};
```

### Advanced Polymorphic Concepts

#### 1. Abstract Classes and Interfaces
```cpp
// Abstract class (has at least one pure virtual function)
class DataSource {
public:
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual bool isConnected() const = 0;
    
    // Concrete method using abstract methods
    void processData() {
        if (!isConnected()) {
            connect();
        }
        // Process data
        disconnect();
    }
};

// Interface (only pure virtual functions)
class Printable {
public:
    virtual void print() const = 0;
    virtual string getFormattedOutput() const = 0;
    virtual ~Printable() = default;
};
```

#### 2. Virtual Function Tables (VTables)
```cpp
class Base {
public:
    virtual void function1() { cout << "Base::function1" << endl; }
    virtual void function2() { cout << "Base::function2" << endl; }
};

class Derived : public Base {
public:
    void function1() override { cout << "Derived::function1" << endl; }
    // function2 uses Base implementation
};

// Usage demonstrating vtable mechanism
Base* ptr = new Derived();
ptr->function1();  // Calls Derived::function1
ptr->function2();  // Calls Base::function2
```

### Best Practices for Polymorphism

#### 1. Virtual Destructors
```cpp
class Resource {
public:
    virtual ~Resource() = default;  // Always make base destructors virtual
};

class DerivedResource : public Resource {
private:
    int* data;
public:
    DerivedResource() : data(new int[100]) {}
    ~DerivedResource() override { delete[] data; }
};
```

#### 2. Override Keyword
```cpp
class Interface {
public:
    virtual void method() = 0;
};

class Implementation : public Interface {
public:
    // Override keyword catches errors if base method signature changes
    void method() override {
        // Implementation
    }
};
```

#### 3. Final Keyword
```cpp
class Base {
public:
    virtual void method() final {  // Cannot be overridden
        // Implementation
    }
};

class Final final {  // Cannot be inherited from
public:
    void method() { }
};
```

### Common Polymorphic Patterns

#### 1. Strategy Pattern
```cpp
class SortStrategy {
public:
    virtual void sort(vector<int>& data) = 0;
};

class QuickSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        // QuickSort implementation
    }
};

class MergeSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        // MergeSort implementation
    }
};

class Sorter {
private:
    unique_ptr<SortStrategy> strategy;
public:
    void setStrategy(unique_ptr<SortStrategy> s) {
        strategy = move(s);
    }
    
    void performSort(vector<int>& data) {
        strategy->sort(data);
    }
};
```

#### 2. Observer Pattern
```cpp
class Observer {
public:
    virtual void update(const string& message) = 0;
};

class Subject {
private:
    vector<Observer*> observers;
public:
    void attach(Observer* obs) {
        observers.push_back(obs);
    }
    
    void notify(const string& message) {
        for(auto obs : observers) {
            obs->update(message);
        }
    }
};
```

### Common Pitfalls and Solutions

1. **Object Slicing**
```cpp
// Wrong:
Derived d;
Base b = d;  // Slices off derived part

// Right:
Base& ref = d;  // Use references
Base* ptr = &d; // Or pointers
```

2. **Virtual Function Performance**
```cpp
// Consider performance impact of virtual functions
class PerformanceCritical {
public:
    void normalFunction() { }     // Direct call
    virtual void virtualFunction() { }  // Indirect call through vtable
};
```

// ...rest of existing content...
