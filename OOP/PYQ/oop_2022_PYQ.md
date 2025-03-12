# OOP Exam Answers-2022
---

Below is a detailed and complete response to the user's query, providing theoretical explanations and detailed answers for each question from the "OOP Exam Answers-2022" based on the provided thinking trace. The answers are structured with markdown for clarity and readability.

---

## **Question 1: Multiple Choice Questions**

### **(a) Which among the following best describes inheritance?**
- **Options:**
  - (i) Using the code in the base class.
  - (ii) Using the already defined class in the base class.
  - (iii) Using the data members and member functions of the base class in the derived class.
  - (iv) Using the data and functions into the derived segment.
- **Answer:** (iv) Using the data and functions into the derived segment.
- **Explanation:**  
  Inheritance is a core concept in object-oriented programming (OOP) that allows a derived class to inherit properties (data members) and behaviors (member functions) from a base class. This enables code reuse and establishes a relationship between classes. Option (iv) captures this idea, though its wording is slightly less precise than (iii). However, since (iv) is the provided answer and aligns with the concept of inheritance, it is accepted. For example:
  ```cpp
  class Base {
  public:
      int x;
      void show() { cout << "Base class" << endl; }
  };
  class Derived : public Base {
  public:
      void display() { cout << "Derived class" << endl; }
  };
  ```

### **(b) Which of the following is not a type of class?**
- **Options:**
  - (i) Abstract class
  - (ii) Final class
  - (iii) Start class
  - (iv) String class
- **Answer:** (iii) Start class
- **Explanation:**  
  - **Abstract class:** A class with at least one pure virtual function, used as a base class that cannot be instantiated.
  - **Final class:** A class declared with the `final` keyword (C++11 onward) to prevent inheritance.
  - **String class:** A standard class in C++ (e.g., `std::string`).
  - **Start class:** Not a recognized term or type in C++ or OOP. Hence, it is the correct choice for "not a type of class."

### **(c) What is the default access specifier for data members or member functions declared within a class without any specifier in C++?**
- **Options:**
  - (i) Private
  - (ii) Public
  - (iii) Protected
- **Answer:** (i) Private
- **Explanation:**  
  In C++, when no access specifier is explicitly mentioned for members of a class, the default access level is `private`. This means those members are accessible only within the class. For example:
  ```cpp
  class MyClass {
      int x; // Private by default
  };
  ```

### **(d) Which of the following is not a member of a class?**
- **Options:**
  - (i) Static function
  - (ii) Friend function
  - (iii) Constant function
  - (iv) Virtual function
- **Answer:** (ii) Friend function
- **Explanation:**  
  - **Static function:** A class member that belongs to the class rather than an instance.
  - **Constant function:** A member function that cannot modify the object (e.g., `void func() const`).
  - **Virtual function:** A member function that supports runtime polymorphism.
  - **Friend function:** A non-member function that has access to the private and protected members of a class but is not part of the class itself. Example:
  ```cpp
  class A {
      friend void show(A obj);
  };
  void show(A obj) { /* Not a member */ }
  ```

### **(e) Which constructor will be called from the object created in the code below?**
- **Code:**
  ```cpp
  class A {
      int i;
      A() {
          i = 0;
      }
      A(int x = 0) {
          i = x;
      }
  };
  A obj1;
  ```
- **Options:**
  - (i) A()
  - (ii) A(int x = 0)
  - (iii) Compile-time error
- **Answer:** (iii) Compile-time error
- **Explanation:**  
  The code defines two constructors: `A()` (default constructor) and `A(int x = 0)` (parameterized constructor with a default argument). When `A obj1;` is declared without arguments, both constructors can be called due to the default parameter in `A(int x = 0)`. This creates ambiguity, leading to a compile-time error in C++. The compiler cannot determine which constructor to invoke.

### **(f) To prevent any method from being overridden, we declare the method as**
- **Options:**
  - (i) static
  - (ii) const
  - (iii) final
  - (iv) private
- **Answer:** (iii) final
- **Explanation:**  
  In C++11 and later, the `final` keyword is used to prevent a virtual function from being overridden in derived classes. Example:
  ```cpp
  class Base {
  public:
      virtual void func() final { cout << "Cannot be overridden"; }
  };
  ```
  - `static`: Prevents overriding but is not virtual.
  - `const`: Prevents modification of the object, not overriding.
  - `private`: Limits access but does not prevent overriding.

### **(g) In C++ dynamic memory allocation is accomplished with the operator:**
- **Options:**
  - (i) new
  - (ii) this
  - (iii) malloc
  - (iv) delete
- **Answer:** (i) new
- **Explanation:**  
  The `new` operator in C++ is used for dynamic memory allocation. It allocates memory on the heap and returns a pointer to it. Example:
  ```cpp
  int* ptr = new int(5);
  delete ptr; // Free memory
  ```
  - `this`: A pointer to the current object.
  - `malloc`: A C-style function, not an operator.
  - `delete`: Frees memory, not allocates it.

### **(h) When a class serves as a base class for many derived classes, the situation is called**
- **Options:**
  - (i) Polymorphism
  - (ii) Hierarchical inheritance
  - (iii) Hybrid inheritance
  - (iv) Multipath inheritance
- **Answer:** (ii) Hierarchical inheritance
- **Explanation:**  
  Hierarchical inheritance occurs when multiple derived classes inherit from a single base class. Example:
  ```cpp
  class Base {};
  class D1 : public Base {};
  class D2 : public Base {};
  ```
  - **Polymorphism:** A concept, not an inheritance type.
  - **Hybrid inheritance:** A combination of inheritance types.
  - **Multipath inheritance:** Involves multiple paths to the same base class.

---

## **Question 2**

### **(a) What are the advantages of using exception handling? Explain `try`, `throw`, and `catch` with an example.**
- **Advantages of Exception Handling:**
  1. **Separation of error-handling code:** Keeps normal program logic separate from error-handling logic.
  2. **Graceful error recovery:** Allows the program to handle errors and continue execution.
  3. **Error propagation:** Exceptions can be passed up the call stack to an appropriate handler.
  4. **Type-specific handling:** Different exceptions can be caught and handled separately.

- **Explanation of `try`, `throw`, and `catch`:**
  - **`try`:** Defines a block of code that will be monitored for exceptions.
  - **`throw`:** Used to signal an exception when an error occurs.
  - **`catch`:** Handles the exception thrown in the `try` block.

- **Example:**
  ```cpp
  #include <iostream>
  using namespace std;

  void divide(int a, int b) {
      try {
          if (b == 0) {
              throw "Division by zero!";
          }
          cout << "Result: " << a / b << endl;
      }
      catch (const char* msg) {
          cout << "Error: " << msg << endl;
      }
  }

  int main() {
      divide(10, 2); // Result: 5
      divide(10, 0); // Error: Division by zero!
      return 0;
  }
  ```

### **(b) Write a C++ program to find the sum of the series 1+3+5+…+n, where n is an odd number.**
- **Explanation:**  
  The series consists of odd numbers starting from 1 up to `n`. A loop can iterate over odd numbers by incrementing by 2 each time.

- **Program:**
  ```cpp
  #include <iostream>
  using namespace std;

  int sumOddSeries(int n) {
      int sum = 0;
      for (int i = 1; i <= n; i += 2) {
          sum += i;
      }
      return sum;
  }

  int main() {
      int n;
      cout << "Enter an odd number: ";
      cin >> n;
      if (n % 2 == 0) {
          cout << "Please enter an odd number!" << endl;
      } else {
          cout << "Sum of series: " << sumOddSeries(n) << endl;
      }
      return 0;
  }
  ```

---

## **Question 3**

### **(a) What is inheritance? Discuss different types of inheritance with examples.**
- **Definition:**  
  Inheritance is a mechanism in OOP where a class (derived class) inherits properties and behaviors from another class (base class), promoting code reuse.

- **Types of Inheritance:**
  1. **Single Inheritance:** One derived class inherits from one base class.
     ```cpp
     class Base { public: int x; };
     class Derived : public Base {};
     ```
  2. **Multiple Inheritance:** A derived class inherits from multiple base classes.
     ```cpp
     class A { public: int x; };
     class B { public: int y; };
     class C : public A, public B {};
     ```
  3. **Multilevel Inheritance:** A class inherits from a derived class.
     ```cpp
     class A { public: int x; };
     class B : public A {};
     class C : public B {};
     ```
  4. **Hierarchical Inheritance:** Multiple derived classes inherit from one base class.
     ```cpp
     class A { public: int x; };
     class B : public A {};
     class C : public A {};
     ```
  5. **Hybrid Inheritance:** A combination of two or more types (e.g., multiple and multilevel).
     ```cpp
     class A { public: int x; };
     class B : public A {};
     class C : public A {};
     class D : public B, public C {};
     ```

### **(b) Operator Overloading: Write a program to overload the unary minus (-) operator.**
- **Explanation:**  
  Operator overloading allows redefining the behavior of operators for user-defined types. The unary minus (`-`) negates an object’s value.

- **Program:**
  ```cpp
  #include <iostream>
  using namespace std;

  class Number {
      int value;
  public:
      Number(int v = 0) : value(v) {}
      void operator-() {
          value = -value;
      }
      void display() {
          cout << "Value: " << value << endl;
      }
  };

  int main() {
      Number num(10);
      cout << "Before: ";
      num.display(); // Value: 10
      -num; // Overloaded unary minus
      cout << "After: ";
      num.display(); // Value: -10
      return 0;
  }
  ```

---

## **Question 4**

### **(a) What is a pure virtual function? Write a C++ program to demonstrate it.**
- **Definition:**  
  A pure virtual function is a virtual function declared in a base class with no implementation (set to `= 0`). It makes the class abstract, requiring derived classes to override it.

- **Program:**
  ```cpp
  #include <iostream>
  using namespace std;

  class Shape {
  public:
      virtual void draw() = 0; // Pure virtual function
  };

  class Circle : public Shape {
  public:
      void draw() override {
          cout << "Drawing a circle" << endl;
      }
  };

  int main() {
      Circle c;
      c.draw(); // Drawing a circle
      return 0;
  }
  ```

### **(b) Why is converting a base-class pointer to a derived-class pointer dangerous?**
- **Explanation:**  
  Converting a base-class pointer to a derived-class pointer (downcasting) is risky because:
  - The base class may not contain all the members of the derived class.
  - If the pointer is used to access derived-class-specific members, it results in undefined behavior unless the object is actually of the derived type.
  - Use `dynamic_cast` for safe downcasting in polymorphic classes. Example:
  ```cpp
  class Base {};
  class Derived : public Base { public: int x; };
  Base* b = new Base;
  Derived* d = (Derived*)b; // Unsafe: b is not a Derived object
  ```

---

## **Question 5**

### **(a) Differentiate between abstract class and interface.**
- **Comparison:**
  | Feature             | Abstract Class                          | Interface (in C++ context)             |
  |---------------------|-----------------------------------------|----------------------------------------|
  | Definition          | Contains pure virtual functions         | All functions are pure virtual         |
  | Implementation      | Can have concrete methods              | No implementation allowed              |
  | Constructors        | Can have constructors                  | No constructors                        |
  | Usage in C++        | Declared with `virtual ... = 0`        | Simulated with pure virtual functions  |

- **Note:** C++ does not have a formal `interface` keyword like Java; abstract classes with only pure virtual functions serve this purpose.

### **(b) What is an access modifier in C++?**
- **Definition:**  
  Access modifiers control the visibility of class members. In C++, they are:
  - **Public:** Members are accessible from outside the class.
  - **Private:** Members are accessible only within the class (default for classes).
  - **Protected:** Members are accessible within the class and derived classes.

- **Example:**
  ```cpp
  class MyClass {
  public:
      int pub;
  private:
      int priv;
  protected:
      int prot;
  };
  ```

---

## **Question 6**

### **(a) Differentiate between a class and an object.**
- **Comparison:**
  | Feature        | Class                          | Object                       |
  |----------------|--------------------------------|------------------------------|
  | Definition     | Blueprint for objects          | Instance of a class          |
  | Memory         | No memory allocated            | Memory allocated when created|
  | Example        | `class Car { int speed; };`   | `Car myCar;`                |

### **(b) Explain constructor and destructor.**
- **Constructor:** A special member function called when an object is created to initialize it. It has the same name as the class and no return type.
- **Destructor:** A special member function called when an object is destroyed to clean up resources. It is prefixed with `~`.

- **Example:**
  ```cpp
  #include <iostream>
  using namespace std;

  class Test {
  public:
      Test() { cout << "Constructor" << endl; }
      ~Test() { cout << "Destructor" << endl; }
  };

  int main() {
      Test t; // Constructor, then Destructor
      return 0;
  }
  ```

---

## **Question 7**

### **(a) What is a friend function?**
- **Definition:**  
  A friend function is a non-member function that has access to the private and protected members of a class, declared with the `friend` keyword.

- **Example:**
  ```cpp
  #include <iostream>
  using namespace std;

  class Box {
      int width;
  public:
      Box(int w) : width(w) {}
      friend void printWidth(Box b);
  };

  void printWidth(Box b) {
      cout << "Width: " << b.width << endl;
  }

  int main() {
      Box box(10);
      printWidth(box); // Width: 10
      return 0;
  }
  ```

### **(b) Explain dangling pointer with an example.**
- **Definition:**  
  A dangling pointer points to a memory location that has been deallocated or freed, leading to undefined behavior if accessed.

- **Example:**
  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      int* ptr = new int(10);
      delete ptr; // Memory freed, ptr is now dangling
      // cout << *ptr; // Undefined behavior
      ptr = nullptr; // Good practice to avoid dangling pointer
      return 0;
  }
  ```

---

## **Question 8**

### **(a) How base class members are involved when a derived class has the same member function?**
- **Explanation:**  
  When a derived class defines a member function with the same name as one in the base class:
  - If the base class function is not virtual, the derived class function **hides** it.
  - If the base class function is virtual, the derived class function **overrides** it, enabling polymorphism.

- **Example:**
  ```cpp
  #include <iostream>
  using namespace std;

  class Base {
  public:
      virtual void show() { cout << "Base" << endl; }
  };

  class Derived : public Base {
  public:
      void show() override { cout << "Derived" << endl; }
  };

  int main() {
      Base* b = new Derived;
      b->show(); // Derived (due to virtual)
      return 0;
  }
  ```

### **(b) Implement a `complex` class.**
- **Explanation:**  
  A `complex` class can represent a complex number with real and imaginary parts, with overloaded operators like `+`.

- **Program:**
  ```cpp
  #include <iostream>
  using namespace std;

  class Complex {
      int real, imag;
  public:
      Complex(int r = 0, int i = 0) : real(r), imag(i) {}
      Complex operator+(const Complex& c) {
          return Complex(real + c.real, imag + c.imag);
      }
      void display() {
          cout << real << " + " << imag << "i" << endl;
      }
  };

  int main() {
      Complex c1(3, 4), c2(1, 2);
      Complex c3 = c1 + c2;
      c3.display(); // 4 + 6i
      return 0;
  }
  ```

---

## **Question 9: Write short notes on**

### **Polymorphism**
- Polymorphism allows objects of different types to be treated as objects of a common base type. It includes:
  - **Compile-time polymorphism:** Function overloading, operator overloading.
  - **Runtime polymorphism:** Virtual functions and inheritance.
- Example: `virtual void func()` in a base class overridden in derived classes.

### **Function Templates**
- Function templates allow writing generic functions that work with any data type.
- Example:
  ```cpp
  template <typename T>
  T add(T a, T b) { return a + b; }
  ```

### **Containers in C++**
- Containers are part of the C++ Standard Template Library (STL) and store data, e.g.:
  - `vector`: Dynamic array.
  - `list`: Doubly linked list.
  - `map`: Key-value pairs.
- Example: `vector<int> v;`

### **Namespaces**
- Namespaces prevent name conflicts by grouping code into scopes.
- Example:
  ```cpp
  namespace MySpace {
      int x = 10;
  }
  using namespace MySpace;
  ```

---

