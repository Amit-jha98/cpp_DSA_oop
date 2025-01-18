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

## Detailed Explanations and Examples

### 1. Classes and Objects

**Theory:**
A class is a user-defined data type that serves as a blueprint for creating objects. It encapsulates data and behavior related to an entity.

**Example:**
```cpp
class Student {
private:
    string name;
    int age;
    double gpa;

public:
    // Constructor
    Student(string n, int a, double g) : name(n), age(a), gpa(g) {}
    
    // Methods
    void study() {
        cout << name << " is studying" << endl;
    }
    
    double getGPA() const {
        return gpa;
    }
};

// Creating objects
Student alice("Alice", 20, 3.8);
alice.study();  // Output: Alice is studying
```

### 2. Encapsulation

**Theory:**
Encapsulation is the bundling of data and methods that operate on that data within a single unit (class), hiding internal details using access specifiers.

**Example:**
```cpp
class BankAccount {
private:
    double balance;
    string accountNumber;
    
    bool isValidAmount(double amount) {
        return amount > 0;
    }

public:
    bool deposit(double amount) {
        if (!isValidAmount(amount)) return false;
        balance += amount;
        return true;
    }
    
    double getBalance() const {
        return balance;
    }
};
```

### 3. Inheritance

**Theory:**
Inheritance allows a class to inherit attributes and methods from another class, promoting code reuse and establishing relationships between classes.

**Example:**
```cpp
class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string b, int y) : brand(b), year(y) {}
    virtual void displayInfo() {
        cout << year << " " << brand;
    }
};

class Car : public Vehicle {
private:
    int doors;

public:
    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {}
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << ", " << doors << " doors" << endl;
    }
};
```

### 4. Polymorphism

**Theory:**
Polymorphism allows objects of different classes to be treated as objects of a common base class, enabling dynamic behavior at runtime.

#### 4.1 Compile-time Polymorphism
```cpp
class Calculator {
public:
    // Function overloading
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    string add(string a, string b) { return a + b; }
};
```

#### 4.2 Runtime Polymorphism
```cpp
class Shape {
public:
    virtual double area() = 0;  // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.14159 * radius * radius;
    }
};
```

### 5. Abstraction

**Theory:**
Abstraction means hiding complex implementation details and showing only necessary features of an object.

**Example:**
```cpp
class DatabaseConnection {
private:
    string connectionString;
    bool isConnected;
    
    void validateConnection() {
        // Complex validation logic
    }

public:
    bool connect() {
        validateConnection();
        // Simplified interface for users
        return isConnected;
    }
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
