### - 2023 Special Exam Question Answers  

---

### **Q.1 Answer Sheet (with all options + correct one)**

---

**(a)** Which is known as generic class?

* (i) Abstract class
* (ii) Final class
* (iii) **Template class** ✅
* (iv) Efficient code

**Correct:** (iii) Template class

---

**(b)** When the compiler cannot differentiate between two overloaded constructors, they are called:

* (i) overloaded
* (ii) destructed
* (iii) **ambiguous** ✅
* (iv) overriding

**Correct:** (iii) ambiguous

---

**(c)** In C++, dynamic memory allocation is accomplished with the operator:

* (i) **new** ✅
* (ii) this
* (iii) malloc
* (iv) delete

**Correct:** (i) new

---

**(d)** What is default access specifier for data members or functions declared within a class without any specifier in C++?

* (i) **Private** ✅
* (ii) Protected
* (iii) Public
* (iv) Depends on compiler

**Correct:** (i) Private

---

**(e)** Multiple inheritance means:

* (i) one class inheriting from more superclasses
* (ii) **more classes inheriting from one superclass** ✅
* (iii) more classes inheriting from more superclasses
* (iv) None of the above

**Correct:** (ii) more classes inheriting from one superclass
*(Though note — normally “multiple inheritance” means one class inheriting from multiple superclasses — seems like a misstatement in options)*

---

**(f)** To prevent any method from overriding, we declare the method as:

* (i) Static
* (ii) const
* (iii) **final** ✅
* (iv) None of the above

**Correct:** (iii) final

---

**(g)** When a class serves as base class for many derived classes, the situation is called:

* (i) polymorphism
* (ii) **hierarchical inheritance** ✅
* (iii) hybrid inheritance
* (iv) multipath inheritance

**Correct:** (ii) hierarchical inheritance

---

**(h)** Which of the following is not a type of class?

* (i) Abstract class
* (ii) Final class
* (iii) **Start class** ✅
* (iv) String class

**Correct:** (iii) Start class

---

**(i)** Which among the following best describes the inheritance?

* (i) copying code already written
* (ii) using the code already written once
* (iii) using already defined function in programming language
* (iv) **using the data and functions into derived segment** ✅

**Correct:** (iv) using the data and functions into derived segment

---

**(j)** Which of the following statements is correct?

* (i) Base class pointer cannot point to derived class
* (ii) **Derived class pointer cannot point to base class** ✅
* (iii) Pointer to derived class cannot be created
* (iv) Pointer to base class cannot be created

**Correct:** (ii) Derived class pointer cannot point to base class

---

---

## Q.2 Constructors & Destructors

### (a) C++ Program Demonstrating Constructors and Destructors

```cpp
#include <iostream>
using namespace std;

class Resource {
private:
    int* data;
public:
    // Default constructor
    Resource() : data(new int[5]) {
        cout << "Constructor: Allocated array of 5 ints at " << data << endl;
        for (int i = 0; i < 5; ++i) 
            data[i] = i * 10;
    }

    // Parameterized constructor
    Resource(int n) : data(new int[n]) {
        cout << "Constructor: Allocated array of " << n << " ints at " << data << endl;
        for (int i = 0; i < n; ++i)
            data[i] = i * 100;
    }

    // Destructor
    ~Resource() {
        cout << "Destructor: Deallocating memory at " << data << endl;
        delete[] data;
    }

    void print(int n) const {
        cout << "Data: ";
        for (int i = 0; i < n; ++i)
            cout << data[i] << ' ';
        cout << endl;
    }
};

int main() {
    {
        Resource r1;        // calls default constructor
        r1.print(5);

        Resource r2(3);     // calls parameterized constructor
        r2.print(3);
    } // both r1 and r2 go out of scope here → destructors called

    cout << "End of main()\n";
    return 0;
}
```

**Explanation:**

* **Constructor(s)**: Special member functions that initialize new objects.

  * **Default constructor** (no parameters).
  * **Parameterized constructor** (takes an integer).
* **Destructor**: A special member function, named `~ClassName()`, automatically invoked when an object’s lifetime ends (scope exit, `delete`, etc.). Used to clean up resources (e.g., `delete[]`, file handles).

---

### (b) Destructor Syntax and Differences from Constructor

```cpp
class MyClass {
public:
    MyClass();         // Constructor
    ~MyClass();        // Destructor
};
```

| Aspect      | Constructor                          | Destructor                       |
| ----------- | ------------------------------------ | -------------------------------- |
| Name        | Same as class (no `~`)               | Same as class prefixed by `~`    |
| Purpose     | Initialize new objects               | Clean up before deletion         |
| Overloading | Yes (can have multiple constructors) | No (only one destructor allowed) |
| Return type | Implicitly returns the object        | No return (cannot return value)  |
| Invocation  | Called on object creation            | Called on object destruction     |
| Parameters  | Can take parameters                  | Cannot take parameters           |

---

## Q.3 OOP Benefits & I/O Formatting

### (a) Benefits of Object‑Oriented Programming (OOP)

1. **Encapsulation**

   * Bundles data and functions together in classes.
   * Hides internal state (private/protected members) and exposes only necessary interfaces.
2. **Inheritance**

   * Allows creation of new classes (derived) from existing classes (base), promoting code reuse.
   * Example: `class Square : public Shape { … };`
3. **Polymorphism**

   * **Compile‑time (overloading)** and **run‑time (virtual functions)** enable the same interface to work with different underlying types.
   * Example: `virtual void draw();` overridden by `Circle::draw()`.
4. **Abstraction**

   * Focus on essential features; hide implementation details.
   * Improves readability and maintainability.
5. **Modularity & Maintainability**

   * Classes define clear boundaries; easier to locate and fix bugs or extend functionality.
6. **Reusability & Extensibility**

   * Inheritance and templates let you build upon existing components rather than rewrite code.

---

### (b) Formatting of I/O in C++

C++ provides manipulators (in `<iomanip>`) and stream flags to control formatting:

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double x = 1234.56789;

    // 1. Fixed vs scientific
    cout << "Default:      " << x << "\n";
    cout << "fixed set:    " << fixed << x << "\n";
    cout << "scientific:   " << scientific << x << "\n";

    // 2. Set precision
    cout << resetiosflags(ios::floatfield) 
         << setprecision(3)
         << "Precision 3:  " << x << "\n";

    // 3. Field width and fill character
    cout << setw(15) << setfill('.') << left 
         << "Left-aligned" << "|" << "\n";
    cout << setw(15) << setfill('.') << right 
         << "Right-aligned" << "|" << "\n";

    // 4. Show base prefixes, showpoint
    cout << showbase << hex << nouppercase 
         << 255 << "\n";               // shows '0xff'
    cout << showpoint << dec << x << "\n"; // ensures decimal point

    return 0;
}
```

* **`setw(n)`**: Sets field width to `n`.
* **`setfill(c)`**: Uses character `c` to pad unused width.
* **`setprecision(n)`**: For floating‑point, sets number of digits.
* **`fixed` / `scientific`**: Switch between notations.
* **Alignment flags**: `left`, `right`, `internal`.
* **`showbase`**, **`showpoint`**, **`uppercase`**, **`hex`**, **`oct`**, **`dec`** control numeral representation.

---

## Q.4 Static Functions & Dynamic Allocation

### (a) Static Member Functions

* Declared in a class with the keyword `static`.
* **Characteristics:**

  * Belong to the class, not to any specific object.
  * Can be called without instantiating an object: `ClassName::func()`.
  * Cannot access non‑static members (no `this` pointer).
* **Use cases:**

  * Utility functions related to class but not to any one object.
  * Factory methods, counters shared across all instances.

```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    static int count;   // static data member
public:
    Counter() { ++count; }
    ~Counter() { --count; }

    static void printCount() {
        cout << "Active objects: " << count << endl;
    }
};

int Counter::count = 0; // initialize static member

int main() {
    Counter::printCount(); // 0
    Counter a, b;
    Counter::printCount(); // 2
    {
        Counter c;
        Counter::printCount(); // 3
    }
    Counter::printCount(); // 2
}
```

---

### (b) Dynamic Memory Allocation

* C++ operators `new` and `delete` allocate and deallocate memory at runtime.
* **Single object:**

  ```cpp
  T* ptr = new T;    // allocate
  delete ptr;        // deallocate
  ```
* **Array:**

  ```cpp
  T* arr = new T[n];
  delete[] arr;
  ```
* **Key points:**

  * Throw `std::bad_alloc` if allocation fails (unless you use `nothrow`).
  * Always pair each `new` with exactly one `delete` (and `new[]` with `delete[]`) to avoid leaks.
  * Consider RAII: wrap allocations in objects whose destructors free memory automatically (e.g., `std::vector`, `std::unique_ptr`).

---

## Q.5 Inheritance & Operator Overloading

### (a) Hierarchical Inheritance: Square and Cube

**Theory:**

* **Hierarchical inheritance** means one base class and multiple derived classes.
* Here, `Number` is the base; `Square` and `Cube` each derive from it.

```cpp
#include <iostream>
using namespace std;

class Number {
protected:
    int value;
public:
    void input() {
        cout << "Enter a number: ";
        cin >> value;
    }
};

class Square : public Number {
public:
    void display() const {
        cout << "Square of " << value << " = " << (value * value) << endl;
    }
};

class Cube : public Number {
public:
    void display() const {
        cout << "Cube of " << value << " = " << (value * value * value) << endl;
    }
};

int main() {
    Square sq;
    Cube cu;

    sq.input();
    sq.display();

    cu.input();
    cu.display();

    return 0;
}
```

---

### (b) Operator Overloading & Unary Minus

**Theory:**

* Overloading lets you redefine operators for user‑defined types.
* Unary minus (`-obj`) is a member function with no parameters.

```cpp
#include <iostream>
using namespace std;

class Integer {
private:
    int value;
public:
    Integer(int v = 0) : value(v) {}

    // Overload unary minus
    Integer operator-() const {
        return Integer(-value);
    }

    void print() const {
        cout << "Value = " << value << endl;
    }
};

int main() {
    Integer a(42);
    Integer b = -a;  // invokes operator-()
    a.print();       // Value = 42
    b.print();       // Value = -42
    return 0;
}
```

---

## Q.6 Friend Functions & Dangling Pointers

### (a) Friend Function

**Theory:**

* A **friend function** is granted access to private/protected members of a class.
* Declared with the `friend` keyword inside class definition but is not a member.

```cpp
#include <iostream>
using namespace std;

class Box {
private:
    double width;
public:
    Box(double w) : width(w) {}
    // Declare showWidth as friend
    friend void showWidth(const Box& b);
};

// Definition of friend function
void showWidth(const Box& b) {
    cout << "Width of box: " << b.width << endl;
}

int main() {
    Box box(3.14);
    showWidth(box);  
    return 0;
}
```

**Advantages:**

* Access encapsulated data without exposing public getters/setters.
* Simplifies some operator‑overloading implementations (`operator<<`, `operator>>`).

**Guidelines:**

* Use sparingly—overuse breaks encapsulation.
* Prefer member functions when possible.
* Keep friend declarations close to where they are used.

---

### (b) Dangling Pointer

**Theory:**
A **dangling pointer** refers to memory that has been freed/deallocated. Using it leads to undefined behavior.

```cpp
#include <iostream>
using namespace std;

int* createDangling() {
    int temp = 100;
    return &temp;      // BAD: temp goes out of scope
}

int main() {
    int* p = new int(50);
    delete p;          // p now dangling
    // cout << *p;     // Undefined behavior!

    int* q = createDangling();
    // cout << *q;     // Also UB!

    p = nullptr;       // SAFE: reset pointer
    q = nullptr;
    return 0;
}
```

**Avoidance Strategies:**

* Set pointers to `nullptr` after delete.
* Use smart pointers (`std::unique_ptr`, `std::shared_ptr`).
* Avoid returning addresses of local variables.

---

## Q.7 STL List & Containers

### (a) Erase All Elements in a `std::list` Using Iterators

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> L = { 10, 20, 30, 40, 50 };

    // Erase via iterator in a loop
    for (auto it = L.begin(); it != L.end(); /*no increment here*/) {
        it = L.erase(it);  // erase returns iterator to next element
    }

    cout << "List size after erase: " << L.size() << endl;  // 0
    return 0;
}
```

**Key Point:**

* `erase(it)` invalidates only the erased iterator; returns the next valid iterator so you can continue.

---

### (b) Containers: Sequence vs Associative

**Containers** in the C++ Standard Library are data structures for managing collections of elements.

| Category                  | Examples                             | Characteristics                                                                                                  |
| ------------------------- | ------------------------------------ | ---------------------------------------------------------------------------------------------------------------- |
| **Sequence**              | `vector`, `deque`, `list`            | - Elements in strict linear order<br>- `vector` supports random access (O(1))<br>- `list` supports fast splicing |
| **Associative**           | `set`, `map`, `multiset`, `multimap` | - Elements organized by keys<br>- Typically implemented as balanced trees (O(log n) lookup/insert/erase)         |
| **Unordered Associative** | `unordered_set`, `unordered_map`     | - Hash‐based (average O(1) operations), no ordering guarantees                                                   |

---

## Q.8 Templates & Exception Handling

### (a) Linked List with Templates & Insertion

**Theory:**

* Templates allow container classes (e.g., linked lists) to work with any data type.
* A **singly linked list** consists of nodes pointing to the next node.

```cpp
#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& d) : data(d), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}

    // Insert at front
    void insertFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Display all elements
    void display() const {
        Node<T>* ptr = head;
        while (ptr) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL\n";
    }

    // Destructor to free nodes
    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> list;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.display();  // 30 -> 20 -> 10 -> NULL
    return 0;
}
```

---

### (b) Exception Handling with `try`–`catch`–`throw`

```cpp
#include <iostream>
using namespace std;

int safeDivide(int a, int b) {
    if (b == 0) 
        throw runtime_error("Division by zero error");
    return a / b;
}

int main() {
    int x, y;
    cout << "Enter dividend and divisor: ";
    cin >> x >> y;

    try {
        int result = safeDivide(x, y);
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    catch (...) {
        cout << "Caught unexpected exception\n";
    }

    cout << "Program continues...\n";
    return 0;
}
```

* **`throw`**: Signals that an error/exception occurred.
* **`try`**: Block where exceptions might be thrown.
* **`catch`**: Handler(s) for specific exception types.
* Unhandled exceptions propagate upward and terminate the program.

---

## Q.9 Short Notes (choose any two)

### 1. **Wrapper Class**

A **wrapper class** encapsulates a built‑in (primitive) type in a user‑defined class, providing it with object‑like behavior and member functions.

* **Motivation**: Add methods, enforce invariants, integrate with STL algorithms (e.g., you cannot store `int` in a container of pointers without wrapping).

* **Example**:

  ```cpp
  class Integer {
  private:
      int value;
  public:
      Integer(int v = 0) : value(v) {}
      int get() const { return value; }
      void set(int v) { value = v; }
      Integer operator+(const Integer& other) const {
          return Integer(value + other.value);
      }
  };
  ```

* **Use cases**: Logging changes, thread safety, custom memory management.

---

### 2. **Data Abstraction**

**Data abstraction** is the principle of hiding internal implementation details and exposing only essential features through a well‑defined interface.

* **Achieved by**: `private`/`protected` members + `public` member functions.
* **Benefits**:

  * **Simplify** usage: Users call `obj.doSomething()` without knowing how it works inside.
  * **Protect** invariants: Prevent invalid states (e.g., enforce input ranges).
  * **Maintain** code: Implementation can change without affecting clients.
* **Real‑world analogy**: Driving a car—you use the steering wheel and pedals without knowing how the engine works.

---
