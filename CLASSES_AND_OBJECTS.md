# Classes and Objects in C++: Complete Guide

## 1. Theory

### What is a Class?
A class is a user-defined data type that serves as a blueprint for creating objects. It encapsulates:
- Data members (attributes)
- Member functions (methods)
- Access specifiers (public, private, protected)
- Constructors and destructors
- Friend functions and classes

### What is an Object?
An object is an instance of a class that:
- Represents a real-world entity
- Has state (data members)
- Has behavior (member functions)
- Occupies memory space

### Class Components

#### 1. Data Members
- Instance variables that store object state
- Can be primitive types or other objects
- Access controlled through access specifiers

#### 2. Member Functions
- Define object behavior
- Can access and modify data members
- Types: Constructor, Destructor, Getter, Setter, Utility functions

#### 3. Access Specifiers
- **private**: Only accessible within class (default)
- **protected**: Accessible in derived classes
- **public**: Accessible everywhere

## 2. Practical Implementation

### Basic Class Structure
```cpp
class Student {
private:
    // Data members
    string name;
    int rollNumber;
    double gpa;
    
    // Private utility function
    bool isValidGPA(double g) {
        return g >= 0.0 && g <= 4.0;
    }

public:
    // Constructors
    Student() : rollNumber(0), gpa(0.0) {}  // Default constructor
    
    Student(string n, int r, double g) {     // Parameterized constructor
        name = n;
        rollNumber = r;
        setGPA(g);  // Using setter for validation
    }
    
    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        gpa = other.gpa;
    }
    
    // Getter methods
    string getName() const { return name; }
    int getRollNumber() const { return rollNumber; }
    double getGPA() const { return gpa; }
    
    // Setter methods with validation
    void setGPA(double g) {
        if (isValidGPA(g)) {
            gpa = g;
        } else {
            throw invalid_argument("Invalid GPA value");
        }
    }
    
    // Utility methods
    void displayInfo() const {
        cout << "Name: " << name << endl
             << "Roll Number: " << rollNumber << endl
             << "GPA: " << gpa << endl;
    }
    
    // Destructor
    ~Student() {
        // Cleanup code if needed
    }
};
```

### Advanced Class Features

#### 1. Static Members
```cpp
class University {
private:
    static int totalStudents;  // Shared among all 
    string name;

public:
    University(string n) : name(n) {
        totalStudents++;
    }
    
    static int getTotalStudents() {
        return totalStudents;
    }
    
    ~University() {
        totalStudents--;
    }
};

// Initialize static member
int University::totalStudents = 0;
```

#### 2. Const Members and Methods
```cpp
class Circle {
private:
    const double PI = 3.14159;  // Constant data member
    double radius;

public:
    Circle(double r) : radius(r) {}
    
    // Const method - cannot modify object state
    double getArea() const {
        return PI * radius * radius;
    }
};
```

#### 3. Friend Functions and Classes
```cpp
class Complex {
private:
    double real, imag;
    
    // Friend function declaration
    friend Complex add(const Complex& a, const Complex& b);
    
    // Friend class declaration
    friend class ComplexCalculator;

public:
    Complex(double r, double i) : real(r), imag(i) {}
};

// Friend function definition
Complex add(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}
```

## 3. Object Lifecycle

### Creation and Initialization
```cpp
// Stack allocation
Student s1;                           // Default constructor
Student s2("Alice", 101, 3.8);       // Parameterized constructor
Student s3 = s2;                     // Copy constructor

// Heap allocation
Student* s4 = new Student();         // Dynamic allocation
Student* s5 = new Student(s2);       // Dynamic copy
```

### Usage and Manipulation
```cpp
// Object usage
s2.setGPA(3.9);
cout << s2.getName() << " has GPA: " << s2.getGPA() << endl;

// Array of objects
Student classroom[3] = {
    Student("Alice", 101, 3.8),
    Student("Bob", 102, 3.9),
    Student("Charlie", 103, 3.7)
};
```

### Destruction
```cpp
// Stack objects destroyed automatically
{
    Student temp("Temp", 999, 4.0);
    // temp destroyed when scope ends
}

// Heap objects must be manually destroyed
delete s4;
delete s5;
```

## 4. Best Practices

1. **Initialization**
   - Use initialization lists in constructors
   - Initialize all data members
   - Consider making immutable members const

2. **Encapsulation**
   - Keep data members private
   - Provide public interface through methods
   - Use getters/setters with validation

3. **Resource Management**
   - Implement destructor for cleanup
   - Follow Rule of Three/Five
   - Use smart pointers for dynamic memory

4. **Method Design**
   - Make methods const when they don't modify object state
   - Use reference parameters for efficiency
   - Consider returning const references for getters

## 5. Common Pitfalls

1. **Memory Leaks**
```cpp
// Wrong
class ResourceHolder {
    int* data;
public:
    ResourceHolder() { data = new int[100]; }
    // Missing destructor!
};

// Right
class ResourceHolder {
    int* data;
public:
    ResourceHolder() { data = new int[100]; }
    ~ResourceHolder() { delete[] data; }
};
```

2. **Object Slicing**
```cpp
class Base { /* ... */ };
class Derived : public Base { /* ... */ };

// Wrong
Base b = Derived();  // Slices off Derived parts

// Right
Base* b = new Derived();  // Use pointers/references
```

### Additional Resources
1. [C++ Classes and Objects](https://en.cppreference.com/w/cpp/language/classes)
2. [Object-Oriented Programming](https://isocpp.org/wiki/faq/object-oriented-programming)
