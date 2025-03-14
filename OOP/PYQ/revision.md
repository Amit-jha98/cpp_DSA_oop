**Object-Oriented Programming (OOP) in C++ - Exam Notes**

### **1. Introduction to OOP**

- Object-Oriented Programming (OOP) is a programming paradigm based on the concept of objects and classes.
- Key features: **Encapsulation, Inheritance, Polymorphism, and Abstraction.**
- Benefits:
  - Code reusability
  - Modularity
  - Scalability
  - Security

### **2. Classes and Objects**

- **Class:** A blueprint for creating objects (user-defined data type).
- **Object:** An instance of a class that contains attributes and methods.

#### **Example:**

```cpp
#include<iostream>
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
    car1.display();
    return 0;
}
```

### **3. Encapsulation**

- Bundling data and methods together to restrict direct access to data members.
- Achieved using access specifiers: **private, protected, public.**

#### **Example:**

```cpp
class Student {
private:
    int rollNo;
public:
    void setRollNo(int r) { rollNo = r; }
    int getRollNo() { return rollNo; }
};
```

### **4. Inheritance**

- Allows a class to inherit properties from another class.
- Types of inheritance:
  - **Single** (one parent, one child)
  - **Multiple** (multiple parents)
  - **Multilevel** (grandparent → parent → child)
  - **Hierarchical** (one parent, multiple children)
  - **Hybrid** (combination)

#### **Example:**

```cpp
class Animal {
public:
    void eat() { cout << "Eating..."; }
};
class Dog : public Animal {
public:
    void bark() { cout << "Barking..."; }
};
```

### **5. Polymorphism**

- **Compile-time (Function Overloading & Operator Overloading)**
- **Runtime (Function Overriding - achieved using virtual functions)**

#### **Example: Function Overloading**

```cpp
class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};
```

#### **Example: Function Overriding**

```cpp
class Base {
public:
    virtual void show() { cout << "Base class"; }
};
class Derived : public Base {
public:
    void show() override { cout << "Derived class"; }
};
```

### **6. Abstraction**

- Hiding implementation details and showing only essential features.
- Achieved using **Abstract Classes** and **Interfaces** (pure virtual functions).

#### **Example:**

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};
class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle"; }
};
```

### **7. Constructors and Destructors**

- **Constructor:** Initializes an object when created.
- **Destructor:** Cleans up resources when an object goes out of scope.

#### **Example:**

```cpp
class Demo {
public:
    Demo() { cout << "Constructor called"; }
    ~Demo() { cout << "Destructor called"; }
};
```

### **8. Friend Function & Operator Overloading**

- A **friend function** can access private members of a class.
- **Operator overloading** allows custom behavior for operators.

#### **Example: Friend Function**

```cpp
class Box {
private:
    int width;
public:
    Box(int w) : width(w) {}
    friend void showWidth(Box b);
};
void showWidth(Box b) {
    cout << "Width: " << b.width;
}
```

#### **Example: Operator Overloading**

```cpp
class Complex {
public:
    int real, imag;
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};
```

### **9. File Handling in C++**

- **ofstream** (write), **ifstream** (read), **fstream** (both).

#### **Example:**

```cpp
#include<fstream>
int main() {
    ofstream file("test.txt");
    file << "Hello, World!";
    file.close();
}
```

### **10. Exception Handling**

- Used to handle runtime errors.
- Keywords: **try, catch, throw**

#### **Example:**

```cpp
try {
    throw 10;
} catch (int e) {
    cout << "Exception: " << e;
}
```

---

