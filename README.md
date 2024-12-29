# C++ Programming: DSA and OOPs Repository

Welcome to the **C++ DSA and OOPs** repository! This project is a comprehensive collection of theoretical concepts, code snippets, and implementations covering **Data Structures and Algorithms (DSA)**, **Object-Oriented Programming (OOP)**, and other important aspects of **C++ programming**. This repository is meticulously designed to help learners and developers master the art of problem-solving and programming in C++.

---

## About the Author

Hello! My name is **Amit Kumar Jha**, and I am currently a student at **GEC Madhubani College**. I am passionate about programming, problem-solving, and software development. My aim is to make learning C++, DSA, and OOPs more accessible and engaging for everyone.  
Feel free to reach out to me for any questions, feedback, or collaboration opportunities.  

📧 Email: [Sumitkr95078@gmail.com](mailto:Sumitkr95078@gmail.com) 

📄
 LinkedIn: [Amit Kumar Jha](https://www.linkedin.com/in/amit-jha-5897102b1)


---

## Table of Contents

1. [Introduction to C++](#introduction-to-c++)
2. [Data Structures](#data-structures)
3. [Algorithms](#algorithms)
4. [Object-Oriented Programming (OOP)](#object-oriented-programming-oop)
5. [Advanced C++ Concepts](#advanced-c++-concepts)
6. [How to Use This Repository](#how-to-use-this-repository)
7. [Contributing](#contributing)
8. [License](#license)

---

## Introduction to C++

C++ is one of the most powerful programming languages, providing flexibility for both **low-level memory manipulation** and **high-level object-oriented design**.  

### Why Learn C++?
1. **System Programming**: Ideal for creating operating systems, compilers, and game engines.
2. **Efficiency**: Offers fine-grained control over hardware resources.
3. **Standard Template Library (STL)**: Provides ready-to-use data structures and algorithms.
4. **Wide Industry Use**: Used in domains like finance, gaming, and robotics.

### Key Concepts Covered:
- **Syntax and Structure**: Basics of writing, compiling, and running a C++ program.
- **Data Types and Variables**: Integer, float, char, string, etc.
- **Control Flow**: If-else, loops, switch-case.
- **Functions**: Defining and calling functions, recursion, inline functions.

## Detailed C++ Concepts

### Memory Management
1. **Stack Memory**
   - Automatic allocation/deallocation
   - Fixed size, faster access
   - Used for local variables

2. **Heap Memory**
   - Dynamic allocation using `new/delete`
   - Manual memory management
   - Used for runtime-sized data structures

3. **References vs Pointers**
   - References: Aliases to existing variables
   - Pointers: Store memory addresses
   - Smart pointers: `unique_ptr`, `shared_ptr`, `weak_ptr`

### Advanced Features
1. **Exception Handling**
   ```cpp
   try {
       // risky code
   } catch (exception& e) {
       // handle error
   }
   ```

2. **Templates**
   - Function templates
   - Class templates
   - Variadic templates
   - SFINAE (Substitution Failure Is Not An Error)

3. **STL Containers Deep Dive**
   - **Sequence Containers**
     - `vector`: Dynamic array
     - `deque`: Double-ended queue
     - `list`: Doubly-linked list
   - **Associative Containers**
     - `set/multiset`: Sorted unique/non-unique elements
     - `map/multimap`: Key-value pairs
   - **Unordered Containers**
     - `unordered_set/map`: Hash-based containers

---

## Data Structures

Data structures form the backbone of efficient programming. They help store and organize data for quick access and modification.

### Detailed Theory:
1. **Arrays**
   - Sequential memory allocation.
   - Fixed size, with elements stored contiguously.
   - Common operations include traversal, insertion, deletion, and searching.
   - Applications: Used in problems like matrix manipulation and prefix sums.

2. **Linked List**
   - A linear data structure where elements (nodes) are linked using pointers.
   - Types:
     - **Singly Linked List**: Each node contains data and a pointer to the next node.
     - **Doubly Linked List**: Nodes contain pointers to both the previous and next nodes.
     - **Circular Linked List**: Last node points to the first node, forming a circle.
   - Advantages: Dynamic memory allocation and efficient insertion/deletion.

3. **Stacks**
   - LIFO (Last In, First Out) structure.
   - Operations: `push`, `pop`, `peek`.
   - Applications: Undo functionality in text editors, parsing expressions, backtracking algorithms.

4. **Queues**
   - FIFO (First In, First Out) structure.
   - Types:
     - **Simple Queue**: Basic enqueue and dequeue.
     - **Circular Queue**: Overcomes the limitation of unused space in arrays.
     - **Priority Queue**: Elements are dequeued based on priority.

5. **Trees**
   - Hierarchical structure with nodes connected by edges.
   - Types:
     - **Binary Trees**: Each node has at most two children.
     - **Binary Search Trees (BST)**: Left child < root < right child.
     - **AVL Trees**: Self-balancing BST.
     - **Heaps**: Specialized tree-based data structure for priority queues.
   - Applications: Database indexing, Huffman coding.

6. **Graphs**
   - Represent relationships between entities using nodes (vertices) and edges.
   - Representations:
     - **Adjacency Matrix**
     - **Adjacency List**
   - Key algorithms: BFS, DFS, Dijkstra, and Floyd-Warshall.

7. **Hashing**
   - Efficient data retrieval using hash functions.
   - Resolving collisions:
     - **Chaining**: Use linked lists.
     - **Open Addressing**: Probing techniques (linear, quadratic).

8. **Dynamic Programming (DP)**
   - Optimizes recursive solutions by storing intermediate results.
   - Examples:
     - Longest Common Subsequence (LCS)
     - Knapsack Problem

---

## Algorithms

Algorithms are well-defined steps to solve computational problems. Mastering them is crucial for competitive programming and real-world applications.

### Detailed Theory:
1. **Sorting Algorithms**
   - Divide datasets into sorted order.
   - Common techniques:
     - **Bubble Sort**: Repeatedly swap adjacent elements.
     - **Merge Sort**: Divide and conquer approach.
     - **Quick Sort**: Partitioning around a pivot element.
   - Applications: Organizing data, optimizing search operations.

2. **Searching Algorithms**
   - Locate elements in data structures.
   - Techniques:
     - **Linear Search**: Check each element sequentially.
     - **Binary Search**: Works on sorted data; O(log n) time complexity.

3. **Greedy Algorithms**
   - Make locally optimal choices.
   - Examples: Activity Selection, Huffman Coding.

4. **Backtracking**
   - Explore all possibilities by trial-and-error.
   - Examples: Solving N-Queens, Sudoku.

## Advanced Algorithms

### Graph Algorithms
1. **Minimum Spanning Tree**
   - Kruskal's Algorithm
   - Prim's Algorithm
   - Applications in network design

2. **Shortest Path**
   - Dijkstra's Algorithm
   - Bellman-Ford Algorithm
   - Floyd-Warshall Algorithm

3. **Network Flow**
   - Ford-Fulkerson Algorithm
   - Maximum Flow Problem
   - Bipartite Matching

### String Algorithms
1. **Pattern Matching**
   - KMP Algorithm
   - Rabin-Karp Algorithm
   - Boyer-Moore Algorithm

2. **String Processing**
   - Trie Data Structure
   - Suffix Arrays
   - Aho-Corasick Algorithm

---

## Object-Oriented Programming (OOP)

OOP enables modular and reusable code by organizing data and behavior into objects.

### Detailed Theory:
1. **Encapsulation**
   - Combine data and methods in a class.
   - Benefits: Data hiding and modularity.

2. **Abstraction**
   - Focus on essential details, hiding complexity.
   - Achieved via abstract classes and interfaces.

3. **Inheritance**
   - Reuse code from base classes in derived classes.
   - Types:
     - Single, Multiple, Multilevel, Hierarchical, Hybrid.

4. **Polymorphism**
   - Ability of methods to perform different actions based on the object.
   - Achieved through method overloading (compile-time) and overriding (runtime).

5. **Advanced Topics**
   - **Virtual Functions**: Support runtime polymorphism.
   - **Templates**: Write generic and reusable code.
   - **Operator Overloading**: Customize the behavior of operators for user-defined types.

## Advanced OOP Concepts

### Design Patterns
1. **Creational Patterns**
   - Singleton
   - Factory Method
   - Abstract Factory
   - Builder Pattern

2. **Structural Patterns**
   - Adapter
   - Bridge
   - Composite
   - Decorator

3. **Behavioral Patterns**
   - Observer
   - Strategy
   - Command
   - State

### SOLID Principles
1. **Single Responsibility Principle**
   - A class should have only one reason to change

2. **Open/Closed Principle**
   - Open for extension, closed for modification

3. **Liskov Substitution Principle**
   - Derived classes must be substitutable for base classes

4. **Interface Segregation**
   - Many specific interfaces better than one general

5. **Dependency Inversion**
   - Depend on abstractions, not concretions

### Memory Management in OOP
1. **Rule of Three**
   - Destructor
   - Copy constructor
   - Copy assignment operator

2. **Rule of Five (Modern C++)**
   - Move constructor
   - Move assignment operator
   - Plus Rule of Three

3. **RAII Pattern**
   - Resource Acquisition Is Initialization
   - Automatic resource management

---

## Advanced C++ Concepts

Master advanced features to unlock the true potential of C++.

### Topics Covered in Detail:
1. **Smart Pointers**
   - Automate memory management with unique, shared, and weak pointers.
2. **File Handling**
   - Stream-based reading and writing to files.
3. **Multithreading**
   - Create concurrent programs with threading libraries.
4. **Move Semantics**
   - Efficient object transfer using r-value references and move constructors.
5. **STL (Standard Template Library)**
   - Containers: Vector, List, Map, Set.
   - Algorithms: Binary search, Sort, Reverse.

---

## How to Use This Repository

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Amit-jha98/cpp_DSA_oops.git
   cd cpp_DSA_oops
   ```
2. **Navigate Through Folders**: Each folder represents a specific topic with organized code examples.
3. **Read Theory**: Start with theoretical explanations provided in markdown files within each folder.
4. **Run Code**: Compile and run code examples to understand implementations practically.

---

## Contributing

Contributions are welcome! If you have suggestions, find issues, or want to add more topics, feel free to open a pull request.

---

## License

This repository is licensed under the MIT License. You are free to use, modify, and distribute the code and content with proper attribution.

