# Complete DSA Theory Guide for Beginners

## 1. Basic Concepts

### Time Complexity
- **What is it?** 
  - A measure of how long an algorithm takes to run as input size grows
  - Expressed in Big O notation: O(n), O(1), O(n²), etc.

### Space Complexity
- **What is it?**
  - Amount of memory space needed by an algorithm
  - Includes both auxiliary space and space used by input

## 2. Data Structures in Detail

### Arrays
**Definition:** Collection of elements stored in contiguous memory locations

**Types:**
1. **1D Arrays**
   ```cpp
   int arr[5] = {1, 2, 3, 4, 5};
   ```
   - Access: O(1)
   - Search: O(n)
   - Insertion: O(n)
   - Deletion: O(n)

2. **2D Arrays**
   ```cpp
   int matrix[3][3] = {
       {1, 2, 3},
       {4, 5, 6},
       {7, 8, 9}
   };
   ```

**Common Problems:**
1. Array Rotation
2. Finding Maximum/Minimum
3. Array Sorting
4. Searching Elements

### Linked Lists
**Definition:** Collection of nodes where each node contains data and reference to next node

**Types:**
1. **Singly Linked List**
   ```cpp
   struct Node {
       int data;
       Node* next;
   };
   ```

2. **Doubly Linked List**
   ```cpp
   struct Node {
       int data;
       Node* prev;
       Node* next;
   };
   ```

**Operations:**
- Insertion (Beginning/End/Middle): O(1) or O(n)
- Deletion: O(1) or O(n)
- Search: O(n)

**Use Cases:**
- Implementation of stacks and queues
- Music playlist
- Browser history

### Stacks
**Definition:** LIFO (Last In First Out) data structure

**Operations:**
```cpp
push(x)   // Add element: O(1)
pop()     // Remove top: O(1)
top()     // View top: O(1)
isEmpty() // Check if empty: O(1)
```

**Real-world Applications:**
1. Function call stack
2. Undo operation in editors
3. Browser back button
4. Expression evaluation

### Queues
**Definition:** FIFO (First In First Out) data structure

**Types:**
1. **Simple Queue**
   ```cpp
   enqueue(x) // Add at rear
   dequeue()  // Remove from front
   ```

2. **Circular Queue**
   - Efficient memory usage
   - Uses modulo operator for wraparound

3. **Priority Queue**
   - Elements have priority
   - Higher priority elements dequeued first

**Applications:**
1. Print queue
2. CPU scheduling
3. Breadth-First Search

### Trees
**Definition:** Hierarchical data structure with root and child nodes

**Types:**
1. **Binary Tree**
   ```cpp
   struct Node {
       int data;
       Node* left;
       Node* right;
   };
   ```

2. **Binary Search Tree (BST)**
   - Left subtree < Node < Right subtree
   - Operations:
     - Search: O(log n)
     - Insert: O(log n)
     - Delete: O(log n)

3. **AVL Tree**
   - Self-balancing BST
   - Balance factor: -1, 0, or 1
   - Rotations: Left, Right, Left-Right, Right-Left

4. **Red-Black Tree**
   - Self-balancing BST
   - Every node is either red or black
   - Root and leaves (NIL) are black

### Graphs
**Definition:** Collection of vertices (nodes) and edges

**Representations:**
1. **Adjacency Matrix**
   ```cpp
   int graph[V][V] = {
       {0, 1, 1},
       {1, 0, 0},
       {1, 0, 0}
   };
   ```

2. **Adjacency List**
   ```cpp
   vector<vector<int>> adj(V);
   ```

**Traversal:**
1. **DFS (Depth-First Search)**
   - Uses stack
   - Goes deep before exploring neighbors

2. **BFS (Breadth-First Search)**
   - Uses queue
   - Explores all neighbors before going deep

### Hashing
**Definition:** Technique to map data to fixed size array

**Components:**
1. Hash Function
2. Hash Table
3. Collision Resolution

**Collision Resolution:**
1. **Chaining**
   - Using linked lists
   - Multiple elements at same index

2. **Open Addressing**
   - Linear Probing
   - Quadratic Probing
   - Double Hashing

## 3. Advanced Data Structures

### Trie
**Definition:** Tree for storing strings, efficient for prefix searches

```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
};
```

### Segment Tree
**Definition:** Tree for range queries and updates

**Operations:**
- Range Sum
- Range Minimum
- Range Maximum

### Disjoint Set
**Definition:** Data structure for managing grouped elements

**Operations:**
- Find: Find group representative
- Union: Merge two groups

## 4. Common Algorithms

### Sorting
1. **Bubble Sort**
   - Time: O(n²)
   - Space: O(1)
   - Stable sort

2. **Merge Sort**
   - Time: O(n log n)
   - Space: O(n)
   - Divide and conquer

3. **Quick Sort**
   - Time: O(n log n) average
   - Space: O(log n)
   - Partition-based

### Searching
1. **Linear Search**
   - Time: O(n)
   - For unsorted arrays

2. **Binary Search**
   - Time: O(log n)
   - For sorted arrays
   ```cpp
   while (left <= right) {
       mid = left + (right - left)/2;
       if (arr[mid] == target) return mid;
       if (arr[mid] < target) left = mid + 1;
       else right = mid - 1;
   }
   ```

### Dynamic Programming
**Definition:** Breaking problems into smaller subproblems

**Examples:**
1. Fibonacci Series
2. 0/1 Knapsack
3. Longest Common Subsequence

**Steps:**
1. Define subproblems
2. Write recurrence relation
3. Identify base cases
4. Choose implementation method
   - Top-down (Memoization)
   - Bottom-up (Tabulation)

## 5. Practice Tips
1. Start with basic data structures
2. Implement each structure from scratch
3. Solve related problems
4. Analyze time and space complexity
5. Practice visualization
6. Focus on one concept at a time
7. Revisit concepts regularly

## 6. Resources
1. Online Platforms:
   - LeetCode
   - GeeksforGeeks
   - HackerRank
2. Books:
   - Introduction to Algorithms (CLRS)
   - Data Structures and Algorithms in C++
3. Visualization Tools:
   - VisuAlgo
   - Algorithm Visualizer
