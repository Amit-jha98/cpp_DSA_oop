Below is a comprehensive set of notes that covers Big O notation and dives into each major data structure and algorithm topic. These notes provide definitions, explanations, and details on time and space complexities, which are commonly expressed using Big O notation.

---
---

### **1. Big O Notation: Purpose & Fundamentals**  
**Purpose**: Quantifies how an algorithm's **runtime** or **memory usage** scales as the input size (*n*) grows, focusing on the **worst-case scenario**.  

#### **Key Concepts**  
1. **Worst-Case Analysis**:  
   - Evaluates the maximum time/space required (e.g., searching for an item that doesn’t exist in a list).  
   - Ensures performance guarantees even in the most demanding scenarios.  
2. **Input Size (*n*)**: Represents the number of elements or operations (e.g., array length, graph nodes).  
3. **Asymptotic Behavior**: Describes growth rates as *n* approaches infinity (ignoring constants and lower-order terms).  

#### **Why It Matters**  
- **Scalability**: Helps predict how algorithms perform with large datasets (e.g., *O(n²)* becomes impractical for *n > 10,000*).  
- **Resource Optimization**: Guides trade-offs between speed (time complexity) and memory (space complexity).  

---

### **2. Common Time Complexities**  

#### **O(1) – Constant Time**  
- **Definition**: Time is independent of input size.  
- **Examples**:  
  - Accessing an array element by index: `arr[5]`.  
  - Inserting a node at the head of a linked list.  
  - Hash table lookups (average case).  
- **Real-World Use**: Cache lookups, arithmetic operations.  

#### **O(log n) – Logarithmic Time**  
- **Definition**: Time grows logarithmically as *n* increases (doubling *n* adds one step).  
- **Examples**:  
  - Binary search (halving the search space each step).  
  - Balanced BST operations (AVL trees, Red-Black trees).  
- **Math Insight**: *log₂(1,000,000) ≈ 20* → Very efficient for large *n*.  
- **Real-World Use**: Database indexing (B-trees), divide-and-conquer algorithms.  

#### **O(n) – Linear Time**  
- **Definition**: Time scales linearly with *n*.  
- **Examples**:  
  - Summing all elements in an array.  
  - Linear search (checking each element once).  
- **Real-World Use**: Iterating through user inputs, file parsing.  

#### **O(n log n) – Linearithmic Time**  
- **Definition**: Slightly slower than linear time, common in efficient sorting algorithms.  
- **Examples**:  
  - Merge Sort, QuickSort (average case), HeapSort.  
  - Fast Fourier Transform (FFT) in signal processing.  
- **Math Insight**: *n log n* grows faster than *n* but slower than *n²*.  

#### **O(n²) – Quadratic Time**  
- **Definition**: Time grows proportionally to *n²*.  
- **Examples**:  
  - Bubble Sort, Selection Sort, Insertion Sort.  
  - Checking all pairs in an array (e.g., nested loops).  
- **Real-World Pitfall**: Becomes impractical for *n > 10,000* (e.g., 10,000² = 100,000,000 operations).  

#### **O(2ⁿ) – Exponential Time**  
- **Definition**: Time doubles with each added element.  
- **Examples**:  
  - Recursive Fibonacci (unoptimized).  
  - Brute-force solutions for the Traveling Salesman Problem.  
- **Real-World Use**: Only feasible for very small *n* (e.g., *n ≤ 25*).  

---

### **3. Space Complexity**  
**Definition**: Measures the memory an algorithm uses relative to *n*.  

#### **Examples**  
1. **O(1)**: Iterative algorithms with fixed variables (e.g., swapping two numbers).  
2. **O(n)**: Storing an array, hash table, or recursion call stack.  
3. **O(n²)**: 2D matrices (e.g., adjacency matrix for a graph).  

#### **Trade-Offs**  
- **Time vs. Space**: Faster algorithms may use more memory (e.g., hash tables vs. linear search).  
- **Recursion**: Deep recursion can cause stack overflow (e.g., *O(n)* space for recursive Fibonacci).  

---

### **4. Formal Definition & Rules**  
Big O is defined mathematically as:  
```
f(n) = O(g(n)) if ∃ constants c > 0 and n₀ ≥ 0 such that 0 ≤ f(n) ≤ c·g(n) ∀ n ≥ n₀.
```  
- **Simplification Rules**:  
  1. Ignore constants: *O(5n)* → *O(n)*.  
  2. Keep the dominant term: *O(n² + n)* → *O(n²)*.  
  3. Drop lower-order terms: *O(n! + n³)* → *O(n!)*.  

---

### **5. How to Calculate Big O**  
1. **Identify Loops**:  
   - Single loop → *O(n)*.  
   - Nested loops → *O(n²)* (e.g., two nested loops).  
2. **Recursion**: Analyze the recursion tree (e.g., Fibonacci: *O(2ⁿ)*).  
3. **Divide-and-Conquer**: Look for patterns like *O(n log n)* (e.g., Merge Sort).  

#### **Example Analysis**  
```python  
def find_duplicates(arr):  
    for i in range(len(arr)):        # O(n)  
        for j in range(i+1, len(arr)):  # O(n)  
            if arr[i] == arr[j]:    # O(1)  
                return True  
    return False  
```  
- **Complexity**: *O(n²)* (nested loops).  

---

### **6. Big O vs. Other Notations**  
| **Notation** | **Description**                  | Example (Algorithm) |  
|--------------|-----------------------------------|---------------------|  
| **Big Ω**    | Best-case complexity              | Ω(1) for linear search (item found first). |  
| **Big Θ**    | Tight bound (both O and Ω)        | Θ(n log n) for Merge Sort. |  

---

### **7. Practical Implications**  
| **Complexity** | Max Feasible *n* (1M ops/sec) | Real-World Example |  
|----------------|-------------------------------|--------------------|  
| **O(1)**       | Any size                      | Hash table lookups. |  
| **O(n)**       | ~1,000,000                   | Processing user data. |  
| **O(n²)**      | ~10,000                      | Small-scale matrix ops. |  
| **O(2ⁿ)**      | ~25                          | Brute-force puzzles. |  

---

### **8. Common Pitfalls**  
1. **Ignoring Hidden Costs**:  
   - Example: Appending to a dynamic array (amortized *O(1)* but involves occasional *O(n)* resizing).  
2. **Over-Optimization**: Prioritize readability unless scaling demands it.  
3. **Misjudging Recursion**: Unoptimized recursion (e.g., Fibonacci) can explode to *O(2ⁿ)*.  

---

### **9. Advanced Topics**  
1. **Amortized Analysis**: Averages time over multiple operations (e.g., dynamic array resizing).  
2. **Space-Time Tradeoff**: Use memoization (extra space) to reduce time (e.g., DP).  

---


# Data Structures

---

### **1. Array Fundamentals in C**

#### **What is an Array?**
- **Definition**: A collection of elements of the same data type stored in contiguous memory locations.
- **Key Characteristics**:
  - Fixed size (static arrays) or resizable (dynamic arrays using pointers)
  - Zero-based indexing
  - Elements accessed via pointer arithmetic

#### **Types of Arrays**
1. **Static Arrays**:
   - Size determined at compile time
   - Memory allocated on the stack
   - Cannot be resized

2. **Dynamic Arrays**:
   - Size determined at runtime
   - Memory allocated on the heap using `malloc`/`calloc`
   - Resizable using `realloc`

---

### **2. Time Complexity**
| Operation               | Static Array | Dynamic Array |
|-------------------------|--------------|---------------|
| Access                  | O(1)         | O(1)          |
| Search                  | O(n)         | O(n)          |
| Insertion at End        | N/A          | O(1) amortized|
| Insertion at Middle     | N/A          | O(n)          |
| Deletion at End         | N/A          | O(1)          |
| Deletion at Middle      | N/A          | O(n)          |

---

### **3. Complete Code Implementation**

#### **Dynamic Array Implementation**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

// Initialize array with initial capacity
void init_array(DynamicArray *arr, size_t initial_capacity) {
    arr->data = (int*)malloc(initial_capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initial_capacity;
}

// Resize array when full (private function)
void resize(DynamicArray *arr) {
    arr->capacity *= 2;
    arr->data = (int*)realloc(arr->data, arr->capacity * sizeof(int));
}

// Append element to end
void append(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        resize(arr);
    }
    arr->data[arr->size++] = value;
}

// Insert element at specific index
void insert_at(DynamicArray *arr, size_t index, int value) {
    if (index > arr->size) {
        printf("Index out of bounds!\n");
        return;
    }

    if (arr->size == arr->capacity) {
        resize(arr);
    }

    memmove(&arr->data[index+1], &arr->data[index], 
            (arr->size - index) * sizeof(int));
    arr->data[index] = value;
    arr->size++;
}

// Delete element at index
void delete_at(DynamicArray *arr, size_t index) {
    if (index >= arr->size) {
        printf("Index out of bounds!\n");
        return;
    }

    memmove(&arr->data[index], &arr->data[index+1], 
            (arr->size - index - 1) * sizeof(int));
    arr->size--;
}

// Search for element (returns index or -1)
int search(const DynamicArray *arr, int target) {
    for (size_t i = 0; i < arr->size; i++) {
        if (arr->data[i] == target) {
            return (int)i;
        }
    }
    return -1;
}

// Free allocated memory
void free_array(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = arr->capacity = 0;
}

// Print array contents
void print_array(const DynamicArray *arr) {
    printf("[");
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    DynamicArray arr;
    init_array(&arr, 2);

    // Basic operations
    append(&arr, 10);
    append(&arr, 20);
    append(&arr, 30);  // Triggers resize
    insert_at(&arr, 1, 15);
    delete_at(&arr, 2);

    printf("Array contents: ");
    print_array(&arr);  // Output: [10, 15, 30]

    // Search demonstration
    int index = search(&arr, 15);
    if (index != -1) {
        printf("Found at index: %d\n", index);  // Output: Found at index: 1
    }

    free_array(&arr);
    return 0;
}
```

---

### **4. Common Array Algorithms**

#### **Reverse Array (In-Place)**
```c
void reverse_array(int *arr, size_t size) {
    for (size_t i = 0; i < size/2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
```

#### **Kadane's Algorithm (Maximum Subarray Sum)**
```c
int max_subarray_sum(const int *arr, size_t size) {
    if (size == 0) return 0;
    
    int max_current = arr[0];
    int max_global = arr[0];
    
    for (size_t i = 1; i < size; i++) {
        max_current = (arr[i] > max_current + arr[i]) ? arr[i] : max_current + arr[i];
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    return max_global;
}
```

#### **Rotate Array (Block Swap Algorithm)**
```c
void rotate_array(int *arr, size_t size, size_t rotations) {
    rotations %= size;
    int temp;
    
    for (size_t i = 0; i < rotations; i++) {
        temp = arr[0];
        for (size_t j = 0; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }
}
```

---

### **5. Memory Management Best Practices**
1. Always check `malloc`/`realloc` return values
2. Use `memmove` instead of `memcpy` for overlapping regions
3. Set pointers to `NULL` after freeing
4. Initialize all memory after allocation
5. Use `size_t` for sizes and indices

---

### **6. When to Use Arrays**
- **Use Static Arrays**:
  - Known fixed-size data
  - Stack memory constraints
  - Short-lived variables

- **Use Dynamic Arrays**:
  - Unknown or changing data sizes
  - Large datasets
  - Long-lived data structures

---

### **7. Key Advantages/Disadvantages**
| **Advantages**          | **Disadvantages**         |
|-------------------------|---------------------------|
| Fast random access      | Insert/Delete cost        |
| Memory efficiency       | Fixed size (static)       |
| Cache locality          | Resizing overhead (dynamic)|
| Simple implementation   | Wasted space (pre-allocation)|

---


### 2. Hash Tables
- **Description:**  
  Uses a hash function to map keys to indices in an array; supports fast lookup.
- **Operations & Complexity:**  
  - **Insertion, Deletion, Search:** Average-case O(1)  
  - **Worst-case:** O(n) – in case of many collisions (depending on the collision resolution technique)

### 3. Singly Linked Lists
- **Description:**  
  A sequence of nodes where each node contains data and a pointer to the next node.
- **Operations & Complexity:**  
  - **Insertion/Deletion at Head:** O(1)  
  - **Insertion/Deletion at Tail (if no tail pointer):** O(n)  
  - **Search:** O(n) – Must traverse nodes sequentially

### 4. Doubly Linked Lists
- **Description:**  
  Similar to singly linked lists but each node has pointers to both the next and previous nodes.
- **Operations & Complexity:**  
  - **Insertion/Deletion:** O(1) if the node is known  
  - **Search:** O(n) – Sequential traversal, but easier to delete a node if already found

### 5. Queues
- **Description:**  
  A First-In-First-Out (FIFO) data structure.
- **Implementations:**  
  - Often implemented using arrays or linked lists.
- **Operations & Complexity:**  
  - **Enqueue (insert):** O(1)  
  - **Dequeue (remove):** O(1)  
  - **Peek:** O(1)

### 6. Stacks
- **Description:**  
  A Last-In-First-Out (LIFO) data structure.
- **Operations & Complexity:**  
  - **Push (insert):** O(1)  
  - **Pop (remove):** O(1)  
  - **Peek:** O(1)

### 7. Trees

#### a. Binary Search Trees (BST)
- **Description:**  
  A tree where each node has at most two children, with left child values less than the node and right child values greater.
- **Complexity:**  
  - **Average-case:** O(log n) for search, insertion, and deletion  
  - **Worst-case:** O(n) – when the tree becomes skewed (like a linked list)

#### b. AVL Trees
- **Description:**  
  A self-balancing BST where the heights of two child subtrees differ by at most one.
- **Complexity:**  
  - **Search, Insertion, Deletion:** O(log n) – rebalancing guarantees logarithmic height

#### c. Red Black Trees
- **Description:**  
  A self-balancing BST with an extra color attribute for each node (red or black) that enforces balance.
- **Complexity:**  
  - **Search, Insertion, Deletion:** O(log n) – balance maintained through rotations and color changes

#### d. Binary Heaps
- **Description:**  
  A complete binary tree used primarily for priority queues. Can be a min-heap or max-heap.
- **Complexity:**  
  - **Insertion:** O(log n)  
  - **Deletion (Extract min/max):** O(log n)  
  - **Peek (min/max):** O(1)

### 8. Tries
- **Description:**  
  A tree-like data structure used to store associative arrays where keys are usually strings.
- **Operations & Complexity:**  
  - **Insertion & Search:** O(m), where m is the length of the key  
  - **Space Complexity:** Can be high due to many pointers, especially if the alphabet is large

### 9. Graphs
- **Description:**  
  Consists of nodes (vertices) connected by edges; can be directed or undirected.
- **Representations:**  
  - **Adjacency List:** O(V + E) space; efficient for sparse graphs  
  - **Adjacency Matrix:** O(V²) space; fast edge lookup, less space-efficient for sparse graphs
- **Operations & Complexity:**  
  - **Traversal (BFS/DFS):** O(V + E)  
  - **Shortest path (e.g., Dijkstra’s):** Varies; typically O((V+E) log V) with min-heaps

---

# Algorithms

### 1. Recursion
- **Concept:**  
  A function that calls itself with a subset of the original problem.
- **Key Points:**  
  - Base Case: Prevents infinite recursion  
  - Recursive Case: Breaks the problem into smaller instances  
- **Complexity Analysis:**  
  Often involves solving recurrence relations (e.g., T(n) = T(n/2) + O(1) leads to O(log n))  
- **Common Examples:**  
  Factorial, Fibonacci sequence, tree traversals

### 2. Sorting Algorithms
- **Overview:**  
  Methods for arranging data in a particular order.
- **Common Algorithms & Their Complexities:**  
  - **Bubble Sort:** O(n²) average/worst-case  
  - **Selection Sort:** O(n²)  
  - **Insertion Sort:** O(n²) worst-case; O(n) best-case (nearly sorted)  
  - **Merge Sort:** O(n log n) worst-case; stable sort  
  - **Quick Sort:** Average-case O(n log n); worst-case O(n²) (often mitigated by randomized pivot selection)  
  - **Heap Sort:** O(n log n) worst-case; in-place sorting

### 3. Searching Algorithms
- **Linear Search:**  
  - **Description:** Check each element sequentially.  
  - **Complexity:** O(n)
- **Binary Search:**  
  - **Description:** Works on sorted arrays by repeatedly dividing the search interval in half.  
  - **Complexity:** O(log n)  
  - **Requirement:** Array must be sorted.

### 4. Tree Traversal Techniques
- **Inorder Traversal:**  
  - **Order:** Left subtree → Node → Right subtree  
  - **Use-case:** Produces sorted order for BSTs.
- **Preorder Traversal:**  
  - **Order:** Node → Left subtree → Right subtree  
  - **Use-case:** Copying the tree structure.
- **Postorder Traversal:**  
  - **Order:** Left subtree → Right subtree → Node  
  - **Use-case:** Deleting the tree.
- **Complexity:** Each traversal visits every node once → O(n)

### 5. Breadth First Search (BFS)
- **Description:**  
  Traverses the graph level by level, using a queue to track the next node to visit.
- **Applications:**  
  - Shortest path in unweighted graphs  
  - Level-order traversal in trees
- **Complexity:** O(V + E), where V is the number of vertices and E is the number of edges

### 6. Depth First Search (DFS)
- **Description:**  
  Traverses as far as possible along each branch before backtracking, often implemented using recursion or a stack.
- **Applications:**  
  - Topological sorting  
  - Detecting cycles in graphs  
  - Solving puzzles like mazes
- **Complexity:** O(V + E)

### 7. Dynamic Programming (DP)
- **Concept:**  
  A method to solve problems by breaking them down into overlapping subproblems and solving each subproblem just once (often using a table to store solutions).
- **Key Features:**  
  - **Overlapping Subproblems:** Problems that recur with the same inputs  
  - **Optimal Substructure:** The optimal solution can be constructed from optimal solutions of its subproblems
- **Approaches:**  
  - **Memoization (Top-Down):** Caching results of recursive calls  
  - **Tabulation (Bottom-Up):** Iteratively filling in a table based on smaller subproblems
- **Examples:**  
  - Fibonacci sequence  
  - Knapsack problem  
  - Longest Common Subsequence (LCS)
- **Complexity:**  
  Varies by problem; many DP solutions run in polynomial time (e.g., O(n²) or O(n·m))

---

# Summary

- **Big O Notation** gives a high-level understanding of how an algorithm scales.
- **Data Structures** such as arrays, linked lists, hash tables, trees, and graphs are chosen based on the required operations and their efficiency.
- **Algorithms** for sorting, searching, and traversing, as well as techniques like recursion and dynamic programming, are analyzed by how they reduce or combine subproblems, with their complexities expressed using Big O notation.
- Understanding the time and space complexities associated with each data structure and algorithm helps in selecting the best tool for solving a problem efficiently.

