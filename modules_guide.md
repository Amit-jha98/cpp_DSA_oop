# C++ DSA and OOP Repository

## Table of Contents
1. [1D Arrays](#module-1-1d-arrays)
2. [2D Arrays](#module-2-2d-arrays)
3. [Functions](#module-3-functions)
4. [Binary Search](#module-4-binary-search)
5. [Recursion](#module-5-recursion)
6. [Stacks](#module-6-stacks)
7. [Queues](#module-7-queues)
8. [Linked Lists](#module-8-linked-lists)
9. [Hashing](#module-9-hashing)
10. [Heaps](#module-10-heaps)
11. [Trees](#module-11-trees)
12. [Graphs](#module-12-graphs)
13. [Sorting](#module-13-sorting)

## Module 1: 1D Arrays

### Definition
A 1D array is a collection of elements of the same data type stored in contiguous memory locations. It acts as a list where elements are accessed via an index.

### Declaration and Initialization
```cpp
int arr[5];               // Declaration of an array of size 5
arr[0] = 10;             // Assigning a value to the first element
int arr[5] = {1, 2, 3, 4, 5}; // Declaration and initialization
```

### Characteristics
- Static size: The size must be declared at compile time
- Homogeneous data: All elements must be of the same type
- Contiguous memory: Each element occupies consecutive memory addresses

### Operations on Arrays

#### 1. Traversal
```cpp
for (int i = 0; i < 5; i++) {
    cout << arr[i];
}
```

#### 2. Insertion
- Adding a new element to a specific position
- Complexity: O(n), as shifting may be required

#### 3. Deletion
- Removing an element from a specific position
- Complexity: O(n), due to the shifting of elements

#### 4. Searching
- Linear Search: Sequentially checks elements (O(n))
- Binary Search: Applicable only to sorted arrays (O(logn))

#### 5. Sorting
- Examples: Bubble Sort, Selection Sort, Quick Sort, etc.

### Advantages
- Direct indexing for quick access
- Simple implementation

### Disadvantages
- Fixed size makes it less flexible
- Expensive insertion and deletion

### Use Cases
- Simple data structures like marks in a class
- Storing fixed-size data like temperatures over a week

---

## Module 2: 2D Arrays

### Definition
A 2D array is a grid-like structure used to represent rows and columns (e.g., a matrix).

### Declaration and Initialization
```cpp
int arr[3][3];           // Declaration of a 3x3 array
arr[0][0] = 1;          // Assigning value to the first element
int arr[2][3] = {{1, 2, 3}, {4, 5, 6}}; // Initialization
```

### Operations

#### Traversal
```cpp
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cout << arr[i][j];
    }
}
```

#### Matrix Operations
- Addition: Adding corresponding elements
- Multiplication: Using nested loops
- Transposition: Swapping rows with columns

### Applications
- Representing grids, tables, and matrices
- Storing images (pixel values)
- Graph adjacency matrices in algorithms

---

## Module 3: Functions

### Definition
A function is a reusable block of code that performs a specific task.

### Key Components
1. Declaration: Function prototype
2. Definition: Actual code for the function
3. Invocation: Calling the function in the main program

### Advantages
- Reduces code duplication
- Improves readability and debugging

### Types

#### User-Defined Functions
```cpp
int add(int a, int b) {
    return a + b;
}
```

#### Recursive Functions
- A function that calls itself
- Example: Factorial computation

### Applications
- Modular programming
- Implementing algorithms like recursion

---

## Module 4: Binary Search

### Definition
Binary search divides the array into halves to find the target element.

### Algorithm
1. Find the middle element of the array
2. If the middle element equals the target, return its index
3. If the target is smaller, search in the left half
4. Otherwise, search in the right half

### Time Complexity
- Best case: O(1)
- Average/Worst case: O(logn)

### Applications
- Efficient searching in large datasets
- Algorithms for sorted data

---

## Module 5: Recursion

### Definition
Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem.

### Key Concepts
1. **Base Case**
   - Condition where recursion stops
   - Prevents infinite recursion
   - Example: factorial(0) = 1

2. **Recursive Case**
   - Problem broken into smaller instances
   - Function calls itself
   - Example: factorial(n) = n * factorial(n-1)

### Code Example
```cpp
int factorial(int n) {
    // Base case
    if (n == 0 || n == 1) return 1;
    
    // Recursive case
    return n * factorial(n-1);
}
```

### Advantages and Disadvantages
#### Advantages
- Simplifies complex problems
- Natural for tree/graph problems
- Clean, readable code

#### Disadvantages
- Memory overhead
- Stack overflow risk
- Performance issues with naive implementations

### Applications
1. Mathematical Computations
2. Divide and Conquer Algorithms
3. Tree/Graph Traversals
4. Dynamic Programming
5. Backtracking Problems

---

## Module 6: Stacks

### Definition
A stack is a LIFO (Last In, First Out) data structure.

### Operations
1. **Push**: Add element to top
2. **Pop**: Remove top element
3. **Peek/Top**: View top element
4. **IsEmpty**: Check if stack empty
5. **Size**: Get element count

### Implementation Examples
```cpp
class Stack {
private:
    vector<int> data;
    
public:
    void push(int value) {
        data.push_back(value);
    }
    
    int pop() {
        if (!isEmpty()) {
            int value = data.back();
            data.pop_back();
            return value;
        }
        return -1;  // Stack empty
    }
    
    bool isEmpty() {
        return data.empty();
    }
};
```

### Applications
1. Expression Evaluation
2. Undo/Redo Operations
3. Function Call Management
4. Browser History
5. Symbol Balancing

---

## Module 7: Queues

### Definition
A queue is a FIFO (First In, First Out) data structure.

### Types
1. **Simple Queue**
   - Basic FIFO implementation
2. **Circular Queue**
   - Memory efficient
   - Rear wraps to front
3. **Priority Queue**
   - Elements ordered by priority
4. **Deque**
   - Double-ended queue

### Implementation Example
```cpp
class Queue {
private:
    vector<int> data;
    
public:
    void enqueue(int value) {
        data.push_back(value);
    }
    
    int dequeue() {
        if (!isEmpty()) {
            int value = data.front();
            data.erase(data.begin());
            return value;
        }
        return -1;  // Queue empty
    }
    
    bool isEmpty() {
        return data.empty();
    }
};
```

### Applications
1. CPU Scheduling
2. Disk Scheduling
3. Data Streaming
4. Print Queue Management
5. BFS Algorithm Implementation

### Advantages and Disadvantages
#### Advantages
- Perfect for FIFO operations
- Wide application scope
- Simple implementation

#### Disadvantages
- Limited access patterns
- Fixed size in array implementation
- Potential memory waste

---

## Module 8: Linked Lists

### Definition
A linear data structure where elements (nodes) are connected using pointers. Each node contains:
- Data: The actual value
- Pointer(s): Reference to other node(s)

### Types
1. **Singly Linked List (SLL)**
   ```cpp
   struct Node {
       int data;
       Node* next;
   };
   ```

2. **Doubly Linked List (DLL)**
   ```cpp
   struct Node {
       int data;
       Node* prev;
       Node* next;
   };
   ```

3. **Circular Linked List**
   - Last node points back to first
   - Can be singly or doubly linked

### Key Operations
1. **Insertion**: O(1) or O(n)
2. **Deletion**: O(1) or O(n)
3. **Traversal**: O(n)
4. **Search**: O(n)

### Applications
- Dynamic memory allocation
- Stack/Queue implementation
- File systems
- Sparse matrix storage

## Module 9: Hashing

### Definition
Technique to map data to specific locations in a hash table.

### Components
1. **Hash Function**
   ```cpp
   int hash(string key) {
       int sum = 0;
       for(char c : key) 
           sum += c;
       return sum % TABLE_SIZE;
   }
   ```

2. **Collision Resolution**
   - Chaining (linked lists)
   - Open Addressing
     - Linear Probing
     - Quadratic Probing

### Applications
- Dictionary implementations
- Database indexing
- Caching systems
- Cryptography

## Module 10: Heaps

### Definition
Specialized tree structure satisfying heap property.

### Types
1. **Max Heap**
   - Parent > Children
2. **Min Heap**
   - Parent < Children

### Operations
```cpp
void insert(int value);
int extractMax();  // for max heap
void heapify(int index);
```

### Applications
- Priority queues
- Heap sort
- Graph algorithms

## Module 11: Trees

### Types
1. **Binary Tree**
   ```cpp
   struct TreeNode {
       int data;
       TreeNode* left;
       TreeNode* right;
   };
   ```

2. **Binary Search Tree (BST)**
   - Left subtree < Node < Right subtree

3. **AVL Tree**
   - Self-balancing BST
   - Balance factor: {-1, 0, 1}

4. **B-Tree**
   - Multiple children
   - Used in databases

### Applications
- File systems
- Expression evaluation
- Database indexing
- Syntax trees

## Module 12: Graphs

### Representations
1. **Adjacency Matrix**
   ```cpp
   vector<vector<int>> graph(V, vector<int>(V, 0));
   ```

2. **Adjacency List**
   ```cpp
   vector<vector<int>> graph(V);
   ```

### Traversals
1. **DFS (Depth-First Search)**
   ```cpp
   void dfs(int vertex, vector<bool>& visited);
   ```

2. **BFS (Breadth-First Search)**
   ```cpp
   void bfs(int start);
   ```

### Applications
- Social networks
- Route planning
- Network flow
- Task scheduling

## Module 13: Sorting

### Algorithms

1. **Bubble Sort**
   - Time: O(n²)
   - Space: O(1)
   ```cpp
   void bubbleSort(vector<int>& arr);
   ```

2. **Merge Sort**
   - Time: O(n log n)
   - Space: O(n)
   ```cpp
   void mergeSort(vector<int>& arr);
   ```

3. **Quick Sort**
   - Time: O(n log n) average
   - Space: O(log n)
   ```cpp
   void quickSort(vector<int>& arr);
   ```

### Comparison Table

| Algorithm      | Time (Avg) | Time (Worst) | Space  | Stable |
|---------------|------------|--------------|--------|--------|
| Bubble Sort   | O(n²)      | O(n²)       | O(1)   | Yes    |
| Selection Sort| O(n²)      | O(n²)       | O(1)   | No     |
| Insertion Sort| O(n²)      | O(n²)       | O(1)   | Yes    |
| Merge Sort    | O(n log n) | O(n log n)  | O(n)   | Yes    |
| Quick Sort    | O(n log n) | O(n²)       | O(log n)| No    |
| Heap Sort     | O(n log n) | O(n log n)  | O(1)   | No     |

### Applications
1. Database sorting
2. File organization
3. Priority management
4. Statistical analysis

---
