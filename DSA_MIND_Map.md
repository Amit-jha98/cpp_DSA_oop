# Data Structures and Algorithms Mind Map

Welcome to the comprehensive guide on Data Structures and Algorithms (DSA). This document serves as a mind map to help you navigate through various fundamental concepts and implementations in C++. Whether you are a beginner or looking to brush up on your DSA knowledge, this guide provides detailed explanations, code examples, and practical applications for each topic. Dive in to enhance your understanding and improve your problem-solving skills.

---

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

### 1. Fundamental Concepts

#### Definition
- Sequential collection of similar elements
- Stored in contiguous memory locations
- Fixed size (in C++)
- Zero-based indexing

#### Memory Representation
```
 Index:     0    1    2    3    4
Memory:   [10] [20] [30] [40] [50]
Address:  1000 1004 1008 1012 1016  (assuming int = 4 bytes)
```

### 2. Array Operations

#### 2.1 Declaration
```cpp
// Different ways to declare
int arr[5];                    // Uninitialized array
int arr[5] = {1, 2, 3, 4, 5}; // Fully initialized
int arr[] = {1, 2, 3};        // Size inferred
int arr[5] = {1, 2};          // Partial initialization (others = 0)
```

#### 2.2 Basic Operations
1. **Insertion**
   ```cpp
   // At specific index
   void insert(int arr[], int size, int index, int value) {
       if (index >= size) return;
       // Shift elements right
       for(int i = size-1; i > index; i--) {
           arr[i] = arr[i-1];
       }
       arr[index] = value;
   }
   ```

2. **Deletion**
   ```cpp
   // From specific index
   void delete(int arr[], int& size, int index) {
       if (index >= size) return;
       // Shift elements left
       for(int i = index; i < size-1; i++) {
           arr[i] = arr[i+1];
       }
       size--;
   }
   ```

3. **Traversal**
   ```cpp
   // Forward traversal
   for(int i = 0; i < size; i++) {
       cout << arr[i] << " ";
   }

   // Reverse traversal
   for(int i = size-1; i >= 0; i--) {
       cout << arr[i] << " ";
   }
   ```

### 3. Searching Algorithms

#### 3.1 Linear Search
```cpp
int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) return i;
    }
    return -1;
}
```
- Time Complexity: O(n)
- Use when: Array is unsorted

#### 3.2 Binary Search
```cpp
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size-1;
    while(left <= right) {
        int mid = left + (right-left)/2;
        if(arr[mid] == key) return mid;
        if(arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```
- Time Complexity: O(log n)
- Prerequisite: Array must be sorted

### 4. Common Array Operations

#### 4.1 Array Rotation
```cpp
// Left rotate by one position
void leftRotate(int arr[], int size) {
    int temp = arr[0];
    for(int i = 0; i < size-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[size-1] = temp;
}
```

#### 4.2 Array Reversal
```cpp
void reverse(int arr[], int size) {
    int start = 0, end = size-1;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
```

### 5. Time Complexity Analysis

| Operation          | Time Complexity | Space Complexity |
|-------------------|-----------------|------------------|
| Access            | O(1)           | O(1)            |
| Insertion (start) | O(n)           | O(1)            |
| Insertion (end)   | O(1)           | O(1)            |
| Deletion (start)  | O(n)           | O(1)            |
| Deletion (end)    | O(1)           | O(1)            |
| Linear Search     | O(n)           | O(1)            |
| Binary Search     | O(log n)       | O(1)            |

### 6. Common Problems and Solutions

#### 6.1 Find Maximum/Minimum
```cpp
int findMax(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}
```

#### 6.2 Check if Array is Sorted
```cpp
bool isSorted(int arr[], int size) {
    for(int i = 0; i < size-1; i++) {
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}
```

### 7. Advanced Concepts

#### 7.1 Kadane's Algorithm (Maximum Subarray Sum)
```cpp
int maxSubArraySum(int arr[], int size) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    
    for(int i = 1; i < size; i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}
```

#### 7.2 Prefix Sum Array
```cpp
void buildPrefixSum(int arr[], int prefixSum[], int size) {
    prefixSum[0] = arr[0];
    for(int i = 1; i < size; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
}
```

### 8. Best Practices

1. **Boundary Checking**
   - Always validate array indices
   - Check for array size before operations

2. **Memory Management**
   - Be careful with array size declarations
   - Consider using vectors for dynamic sizing

3. **Performance Optimization**
   - Use appropriate search method based on data
   - Consider space-time tradeoffs

### 9. Common Applications

1. **Data Storage**
   - Storing marks of students
   - Temperature readings
   - Sensor data

2. **Algorithm Implementation**
   - Sorting algorithms
   - Searching algorithms
   - Dynamic Programming

3. **Memory Management**
   - Buffer implementation
   - Stack implementation
   - Queue implementation

---

## Module 2: 2D Arrays  

### 1. Fundamental Concepts

#### Definition
- A 2D array is an array of arrays
- Represents data in rows and columns (matrix form)
- Memory is allocated contiguously
- Accessed using two indices [row][column]

#### Memory Layout
```
Memory Representation (3x3 matrix):
[1][2][3]    Row 0: 1000 1004 1008
[4][5][6] -> Row 1: 1012 1016 1020
[7][8][9]    Row 2: 1024 1028 1032
```

### 2. Array Operations

#### 2.1 Declaration and Initialization
```cpp
// Method 1: Direct declaration
int arr[3][4];  // 3 rows, 4 columns

// Method 2: Complete initialization
int arr[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Method 3: Partial initialization
int arr[3][3] = {{1}, {2}, {3}};  // Rest elements are 0
```

#### 2.2 Basic Operations

1. **Matrix Traversal**
```cpp
// Row-major traversal
void rowMajorTraversal(int arr[][3], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Column-major traversal
void colMajorTraversal(int arr[][3], int rows) {
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < rows; i++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
```

2. **Matrix Operations**
```cpp
// Matrix Addition
void matrixAdd(int A[][3], int B[][3], int C[][3], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Matrix Multiplication
void matrixMultiply(int A[][3], int B[][3], int C[][3], int rows1, int cols2) {
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            C[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
```

### 3. Advanced Operations

#### 3.1 Matrix Transformations
```cpp
// Matrix Transpose
void transpose(int arr[][3], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = i; j < 3; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

// Rotate Matrix 90 degrees clockwise
void rotateMatrix(int arr[][3], int n) {
    // Step 1: Transpose
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
    // Step 2: Reverse each row
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n/2; j++) {
            swap(arr[i][j], arr[i][n-1-j]);
        }
    }
}
```

### 4. Time Complexity Analysis

| Operation               | Time Complexity | Space Complexity |
|------------------------|-----------------|------------------|
| Access Element         | O(1)           | O(1)            |
| Row Traversal         | O(n)           | O(1)            |
| Matrix Addition       | O(n*m)         | O(1)            |
| Matrix Multiplication | O(n³)          | O(1)            |
| Matrix Transpose      | O(n²)          | O(1)            |
| Matrix Rotation       | O(n²)          | O(1)            |

### 5. Common Problems and Solutions

#### 5.1 Spiral Matrix Traversal
```cpp
void spiralTraversal(int arr[][4], int rows, int cols) {
    int top = 0, bottom = rows-1;
    int left = 0, right = cols-1;
    
    while(top <= bottom && left <= right) {
        // Print top row
        for(int j = left; j <= right; j++)
            cout << arr[top][j] << " ";
        top++;
        
        // Print right column
        for(int i = top; i <= bottom; i++)
            cout << arr[i][right] << " ";
        right--;
        
        if(top <= bottom) {
            // Print bottom row
            for(int j = right; j >= left; j--)
                cout << arr[bottom][j] << " ";
            bottom--;
        }
        
        if(left <= right) {
            // Print left column
            for(int i = bottom; i >= top; i--)
                cout << arr[i][left] << " ";
            left++;
        }
    }
}
```

#### 5.2 Search in Sorted Matrix
```cpp
bool searchMatrix(int arr[][4], int rows, int cols, int target) {
    int i = 0, j = cols-1;  // Start from top-right
    
    while(i < rows && j >= 0) {
        if(arr[i][j] == target)
            return true;
        else if(arr[i][j] > target)
            j--;    // Move left
        else
            i++;    // Move down
    }
    return false;
}
```

### 6. Memory Management and Best Practices

1. **Dynamic Allocation**
```cpp
// Allocating 2D array dynamically
int** createMatrix(int rows, int cols) {
    int** arr = new int*[rows];
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    return arr;
}

// Deallocating 2D array
void deleteMatrix(int** arr, int rows) {
    for(int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
```

2. **Best Practices**
   - Always check array bounds
   - Use row-major traversal when possible
   - Consider cache locality
   - Use vector<vector<int>> for dynamic sizing

### 7. Applications

1. **Image Processing**
   - Pixel manipulation
   - Image filters
   - Pattern recognition

2. **Game Development**
   - Game boards
   - Tile maps
   - Collision detection

3. **Scientific Computing**
   - Matrix operations
   - Linear equations
   - Graph representation

4. **Data Analysis**
   - Tables and spreadsheets
   - Statistical computations
   - Data visualization

### 8. Common Pitfalls and Solutions

1. **Boundary Issues**
   - Always validate indices
   - Handle edge cases
   - Check for matrix dimensions

2. **Performance Considerations**
   - Cache-friendly access patterns
   - Memory-efficient algorithms
   - Optimal traversal methods

3. **Common Mistakes**
   - Row/column confusion
   - Index out of bounds
   - Memory leaks in dynamic allocation

---

## Module 3: Functions  

### 1. Core Concepts

#### Definition
A function is a self-contained block of code that performs a specific task. Functions provide:
- Code reusability
- Modularity
- Abstraction
- Better organization

#### Components
```cpp
// Function Declaration (Prototype)
return_type function_name(parameter_list);

// Function Definition
return_type function_name(parameter_list) {
    // Function body
    return value;  // if return_type isn't void
}

// Function Call
result = function_name(arguments);
```

### 2. Function Types

#### 2.1 Based on Return Type
```cpp
// Void Functions
void printMessage() {
    cout << "Hello World";
}

// Value-returning Functions
int add(int a, int b) {
    return a + b;
}

// Reference-returning Functions
int& getElement(vector<int>& arr, int index) {
    return arr[index];
}
```

#### 2.2 Based on Parameters
```cpp
// No Parameters
void sayHello() {
    cout << "Hello!";
}

// Value Parameters
int square(int x) {
    return x * x;
}

// Reference Parameters
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Const Parameters
double calculateArea(const double radius) {
    return 3.14159 * radius * radius;
}
```

### 3. Advanced Function Concepts

#### 3.1 Function Overloading
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
};
```

#### 3.2 Default Arguments
```cpp
void printDetails(string name, int age = 20, string city = "Unknown") {
    cout << name << ", " << age << ", " << city;
}

// Can be called as:
printDetails("John");               // Uses default age and city
printDetails("John", 25);          // Uses default city
printDetails("John", 25, "NYC");   // Uses no defaults
```

#### 3.3 Inline Functions
```cpp
inline int max(int a, int b) {
    return (a > b) ? a : b;
}
```

### 4. Parameter Passing Mechanisms

#### 4.1 Pass by Value
```cpp
void modifyValue(int x) {
    x = x + 1;  // Original value unchanged
}
```

#### 4.2 Pass by Reference
```cpp
void modifyValue(int& x) {
    x = x + 1;  // Original value modified
}
```

#### 4.3 Pass by Pointer
```cpp
void modifyValue(int* x) {
    *x = *x + 1;  // Original value modified
}
```

### 5. Function Call Stack

#### Memory Organization
```
Stack Frame for Function Call:
+------------------+
| Return Address   |
| Parameters      |
| Local Variables |
| Saved Registers |
+------------------+
```

#### Example
```cpp
int factorial(int n) {
    // Stack frame created
    if (n <= 1) return 1;
    return n * factorial(n - 1);
    // Stack frame destroyed
}
```

### 6. Advanced Features

#### 6.1 Lambda Functions
```cpp
auto multiply = [](int x, int y) -> int {
    return x * y;
};

// Usage
int result = multiply(5, 3);  // Returns 15
```

#### 6.2 Function Pointers
```cpp
int (*operation)(int, int);  // Function pointer declaration

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

// Usage
operation = add;
int result1 = operation(5, 3);  // Returns 8
operation = subtract;
int result2 = operation(5, 3);  // Returns 2
```

### 7. Best Practices

1. **Function Design**
   - Single Responsibility Principle
   - Clear and meaningful names
   - Consistent parameter ordering
   - Appropriate return types

2. **Parameter Guidelines**
   - Use const when parameter shouldn't be modified
   - Pass large objects by reference
   - Use references instead of pointers when possible
   - Consider default arguments carefully

3. **Error Handling**
   - Use exceptions for error conditions
   - Validate input parameters
   - Handle edge cases
   - Provide meaningful error messages

### 8. Common Applications

1. **Mathematical Operations**
```cpp
double power(double base, int exponent) {
    double result = 1.0;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
```

2. **Data Processing**
```cpp
vector<int> filterEven(const vector<int>& numbers) {
    vector<int> result;
    for(int num : numbers) {
        if(num % 2 == 0) {
            result.push_back(num);
        }
    }
    return result;
}
```

3. **Utility Functions**
```cpp
string formatDate(int day, int month, int year) {
    return to_string(day) + "/" + 
           to_string(month) + "/" + 
           to_string(year);
}
```

### 9. Performance Considerations

1. **Function Call Overhead**
   - Stack operations
   - Parameter copying
   - Register saving/restoring

2. **Optimization Techniques**
   - Inline functions for small, frequently used code
   - Pass by reference for large objects
   - Return value optimization (RVO)

### 10. Common Pitfalls

1. **Parameter Issues**
   - Forgetting to pass by reference for large objects
   - Not checking pointer validity
   - Incorrect parameter order

2. **Return Value Problems**
   - Returning references to local variables
   - Forgetting to return a value
   - Returning inappropriate types

3. **Scope Issues**
   - Variable shadowing
   - Accessing out-of-scope variables
   - Memory leaks in dynamic allocation

---

## Module 4: Binary Search

### Definition
Binary Search is a highly efficient searching algorithm that works on sorted arrays by repeatedly dividing the search space in half.

### Key Concepts

1. **Prerequisites**
   - Array must be sorted
   - Random access to elements (array or similar data structure)

2. **Working Principle**
   - Compare target with middle element
   - If target is smaller, search left half
   - If target is larger, search right half
   - Repeat until found or search space is empty

### Implementation Approaches

1. **Iterative Implementation**
```cpp
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevents overflow
        
        if (arr[mid] == target) 
            return mid;       // Found target
        
        if (arr[mid] < target)
            left = mid + 1;   // Search right half
        else
            right = mid - 1;  // Search left half
    }
    return -1;  // Target not found
}
```

2. **Recursive Implementation**
```cpp
int binarySearchRecursive(vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) return mid;
    
    if (arr[mid] < target)
        return binarySearchRecursive(arr, target, mid + 1, right);
    else
        return binarySearchRecursive(arr, target, left, mid - 1);
}
```

### Complexity Analysis

1. **Time Complexity**
   - Best Case: O(1) - Target is middle element
   - Average Case: O(log n)
   - Worst Case: O(log n)

2. **Space Complexity**
   - Iterative: O(1)
   - Recursive: O(log n) due to call stack

### Common Variations

1. **Finding First Occurrence**
```cpp
int findFirstOccurrence(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // Continue searching left
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return result;
}
```

2. **Finding Last Occurrence**
```cpp
int findLastOccurrence(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;  // Continue searching right
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return result;
}
```

### Real-world Applications

1. **Database Searching**
   - Finding records in sorted databases
   - Index searching in B-trees

2. **System Applications**
   - Finding processes by ID
   - Memory management
   - File system searching

3. **Problem-Solving Scenarios**
   - Finding insertion position
   - Range queries
   - Peak finding

### Common Pitfalls

1. **Implementation Issues**
   - Incorrect middle calculation (potential overflow)
   - Wrong comparison operators
   - Improper handling of boundaries

2. **Usage Mistakes**
   - Using on unsorted array
   - Not handling duplicates properly
   - Incorrect array indices

### Practice Problems

1. **Basic Problems**
   - Find element in sorted array
   - Count occurrences of number
   - Find insertion position

2. **Advanced Problems**
   - Search in rotated sorted array
   - Find peak element
   - Search in 2D sorted matrix

### Best Practices

1. **Code Implementation**
   - Use `mid = left + (right - left) / 2` to prevent overflow
   - Clear boundary conditions
   - Proper handling of duplicates

2. **Performance Optimization**
   - Choose iterative over recursive for better space complexity
   - Handle small arrays with linear search
   - Consider binary search variations based on requirements

---

## Module 5: Recursion  

### 1. Core Concepts

#### Definition
Recursion is a problem-solving technique where a function calls itself with a smaller instance of the same problem until it reaches a base case.

#### Key Components
1. **Base Case**
   - Terminating condition
   - Simplest form of the problem
   - Directly solvable without recursion

2. **Recursive Case**
   - Problem broken into smaller subproblems
   - Each subproblem similar to original
   - Progress toward base case

### 2. Types of Recursion

#### 2.1 Direct Recursion
```cpp
void directRecursion(int n) {
    if(n == 0) return;  // Base case
    cout << n << " ";
    directRecursion(n-1);  // Direct recursive call
}
```

#### 2.2 Indirect Recursion
```cpp
void functionA(int n) {
    if(n <= 0) return;
    cout << n << " ";
    functionB(n-1);  // Call to another function
}

void functionB(int n) {
    if(n <= 0) return;
    cout << n << " ";
    functionA(n-1);  // Call back to first function
}
```

#### 2.3 Tail Recursion
```cpp
int factorial(int n, int acc = 1) {
    if(n == 0) return acc;  // Base case
    return factorial(n-1, n * acc);  // Tail recursive call
}
```

#### 2.4 Non-Tail Recursion
```cpp
int factorial(int n) {
    if(n == 0) return 1;
    return n * factorial(n-1);  // Additional computation after recursive call
}
```

### 3. Memory Management in Recursion

#### 3.1 Stack Frame Structure
```
Call Stack for factorial(3):
+-------------------+
| factorial(0)      |
+-------------------+
| factorial(1)      |
+-------------------+
| factorial(2)      |
+-------------------+
| factorial(3)      |
+-------------------+
```

#### 3.2 Memory Optimization
```cpp
// Tail recursion (compiler can optimize)
int sum(int n, int acc = 0) {
    if(n == 0) return acc;
    return sum(n-1, acc + n);
}

// Converting recursion to iteration
int sum(int n) {
    int result = 0;
    while(n > 0) {
        result += n;
        n--;
    }
    return result;
}
```

### 4. Common Recursive Patterns

#### 4.1 Divide and Conquer
```cpp
// Binary Search
int binarySearch(vector<int>& arr, int target, int left, int right) {
    if(left > right) return -1;
    
    int mid = left + (right - left)/2;
    if(arr[mid] == target) return mid;
    
    if(arr[mid] > target)
        return binarySearch(arr, target, left, mid-1);
    return binarySearch(arr, target, mid+1, right);
}
```

#### 4.2 Backtracking
```cpp
void generatePermutations(string& str, int l, int r) {
    if(l == r) {
        cout << str << endl;
        return;
    }
    
    for(int i = l; i <= r; i++) {
        swap(str[l], str[i]);
        generatePermutations(str, l+1, r);
        swap(str[l], str[i]);  // backtrack
    }
}
```

### 5. Advanced Applications

#### 5.1 Tree Traversal
```cpp
struct TreeNode {
    int data;
    TreeNode *left, *right;
};

void inorderTraversal(TreeNode* root) {
    if(!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
```

#### 5.2 Dynamic Programming with Recursion
```cpp
// Fibonacci with memoization
int fib(int n, vector<int>& memo) {
    if(n <= 1) return n;
    if(memo[n] != -1) return memo[n];
    
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}
```

### 6. Common Problems and Solutions

#### 6.1 Tower of Hanoi
```cpp
void towerOfHanoi(int n, char from, char aux, char to) {
    if(n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    towerOfHanoi(n-1, from, to, aux);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n-1, aux, from, to);
}
```

#### 6.2 Subset Generation
```cpp
void generateSubsets(vector<int>& nums, vector<int>& subset, int index) {
    if(index == nums.size()) {
        printSubset(subset);
        return;
    }
    
    // Don't include current element
    generateSubsets(nums, subset, index + 1);
    
    // Include current element
    subset.push_back(nums[index]);
    generateSubsets(nums, subset, index + 1);
    subset.pop_back();
}
```

### 7. Performance Considerations

#### 7.1 Time Complexity Analysis
- Linear Recursion: O(n)
- Binary Recursion: O(2^n)
- Divide and Conquer: O(log n) to O(n log n)

#### 7.2 Space Complexity
- Stack Space: O(n) for linear recursion
- Additional Space: Depends on problem requirements

### 8. Best Practices

1. **Design Guidelines**
   - Always include base case
   - Ensure progress toward base case
   - Minimize redundant calculations
   - Consider stack limitations

2. **Optimization Techniques**
   - Use tail recursion when possible
   - Implement memoization for overlapping subproblems
   - Consider iterative alternatives
   - Use helper functions for additional parameters

3. **Error Prevention**
   - Handle edge cases
   - Validate input parameters
   - Set proper base conditions
   - Prevent infinite recursion

### 9. Common Pitfalls

1. **Stack Overflow**
   - Too many recursive calls
   - No proper base case
   - Infinite recursion

2. **Performance Issues**
   - Redundant calculations
   - Excessive memory usage
   - Poor choice of base case

3. **Logic Errors**
   - Incorrect base case
   - Wrong recursive step
   - Missing return statements

### 10. Practical Examples

#### 10.1 String Processing
```cpp
bool isPalindrome(string s, int start, int end) {
    if(start >= end) return true;
    if(s[start] != s[end]) return false;
    return isPalindrome(s, start + 1, end - 1);
}
```

#### 10.2 Mathematical Operations
```cpp
int power(int base, int exp) {
    if(exp == 0) return 1;
    if(exp % 2 == 0)
        return power(base * base, exp/2);
    return base * power(base, exp-1);
}
```

---

## Module 6: Stacks  

### 1. Fundamental Concepts

#### Definition
A stack is a linear data structure that follows the Last In First Out (LIFO) principle. Like a stack of plates, elements can only be added or removed from the top.

#### Core Properties
1. **LIFO Principle**
   - Last element inserted is the first one to be removed
   - Access to elements is restricted to the top
   - Maintains insertion order when elements are removed

2. **Stack Pointer**
   - Keeps track of the top element
   - Used for all operations
   - Essential for managing stack state

### 2. Stack Operations

#### 2.1 Basic Operations
```cpp
template<typename T>
class Stack {
private:
    vector<T> elements;

public:
    // Push operation - O(1)
    void push(T value) {
        elements.push_back(value);
    }
    
    // Pop operation - O(1)
    T pop() {
        if(isEmpty()) throw runtime_error("Stack underflow");
        T top = elements.back();
        elements.pop_back();
        return top;
    }
    
    // Peek operation - O(1)
    T top() {
        if(isEmpty()) throw runtime_error("Stack empty");
        return elements.back();
    }
    
    // Check if empty - O(1)
    bool isEmpty() {
        return elements.empty();
    }
    
    // Get size - O(1)
    size_t size() {
        return elements.size();
    }
};
```

#### 2.2 Advanced Operations
```cpp
template<typename T>
class AdvancedStack : public Stack<T> {
public:
    // Clear stack
    void clear() {
        while(!this->isEmpty()) {
            this->pop();
        }
    }
    
    // Get minimum element (for stack of comparable elements)
    T getMin() {
        if(this->isEmpty()) throw runtime_error("Stack empty");
        T min = this->top();
        Stack<T> temp;
        
        while(!this->isEmpty()) {
            T current = this->pop();
            if(current < min) min = current;
            temp.push(current);
        }
        
        // Restore stack
        while(!temp.isEmpty()) {
            this->push(temp.pop());
        }
        return min;
    }
};
```

### 3. Implementation Approaches

#### 3.1 Array-based Implementation
```cpp
template<typename T, size_t SIZE>
class ArrayStack {
private:
    T arr[SIZE];
    int top;

public:
    ArrayStack() : top(-1) {}
    
    void push(T value) {
        if(top >= SIZE-1) throw runtime_error("Stack overflow");
        arr[++top] = value;
    }
    
    T pop() {
        if(top < 0) throw runtime_error("Stack underflow");
        return arr[top--];
    }
};
```

#### 3.2 Linked List Implementation
```cpp
template<typename T>
class LinkedStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    
    Node* topNode;
    size_t stackSize;

public:
    LinkedStack() : topNode(nullptr), stackSize(0) {}
    
    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        stackSize++;
    }
    
    T pop() {
        if(!topNode) throw runtime_error("Stack underflow");
        T value = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        stackSize--;
        return value;
    }
};
```

### 4. Advanced Applications

#### 4.1 Expression Evaluation
```cpp
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int evaluatePostfix(string expr) {
    Stack<int> stack;
    
    for(char c : expr) {
        if(isdigit(c)) {
            stack.push(c - '0');
        }
        else if(isOperator(c)) {
            int b = stack.pop();
            int a = stack.pop();
            
            switch(c) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }
    return stack.pop();
}
```

#### 4.2 Parentheses Matching
```cpp
bool areParenthesesBalanced(string expr) {
    Stack<char> stack;
    
    for(char c : expr) {
        if(c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if(c == ')' || c == '}' || c == ']') {
            if(stack.isEmpty()) return false;
            
            char top = stack.pop();
            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}
```

### 5. Memory Management

#### 5.1 Stack Memory Organization
```
Stack Growth:
+------------------+
| Newest Element   | <- Top
+------------------+
| ...             |
+------------------+
| Oldest Element  |
+------------------+
```

#### 5.2 Dynamic Resizing (Vector-based)
```cpp
template<typename T>
class DynamicStack {
private:
    vector<T> elements;
    size_t capacity;

public:
    DynamicStack(size_t initialCapacity = 10) 
        : capacity(initialCapacity) {
        elements.reserve(capacity);
    }
    
    void push(T value) {
        if(elements.size() == capacity) {
            capacity *= 2;
            elements.reserve(capacity);
        }
        elements.push_back(value);
    }
};
```

### 6. Common Applications

1. **Function Call Management**
   - Return addresses
   - Local variables
   - Parameters
   - Program counter

2. **Expression Parsing**
   - Infix to postfix conversion
   - Expression evaluation
   - Syntax checking

3. **Backtracking Algorithms**
   - Maze solving
   - N-Queens problem
   - Game trees

4. **Browser History**
   - Forward/backward navigation
   - State management
   - Undo/redo operations

### 7. Performance Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Push      | O(1)           | O(1)            |
| Pop       | O(1)           | O(1)            |
| Top       | O(1)           | O(1)            |
| IsEmpty   | O(1)           | O(1)            |
| Search    | O(n)           | O(1)            |

### 8. Best Practices

1. **Error Handling**
   - Check for stack overflow
   - Handle underflow conditions
   - Validate input parameters

2. **Memory Management**
   - Implement proper cleanup
   - Consider dynamic sizing
   - Handle resource allocation

3. **Design Considerations**
   - Choose appropriate implementation
   - Consider thread safety
   - Implement iterator if needed

### 9. Common Pitfalls

1. **Stack Overflow**
   - Fixed-size implementation
   - Recursive calls
   - Infinite loops

2. **Memory Leaks**
   - Improper cleanup in linked implementation
   - Not handling exceptions
   - Resource management issues

3. **Logic Errors**
   - Incorrect pop/push order
   - Not checking empty state
   - Improper boundary checking

### 10. Practice Problems

1. **Basic Problems**
   - Implement stack using queues
   - Sort a stack
   - Reverse a string using stack

2. **Advanced Problems**
   - Implement min stack with O(1) operations
   - Evaluate complex expressions
   - Implement stack with middle operations

---

## Module 7: Queues  

### 1. Fundamental Concepts

#### Definition
A queue is a linear data structure that follows the First In First Out (FIFO) principle. Like a line at a ticket counter, the first person to join is the first to be served.

#### Core Properties
1. **FIFO Principle**
   - First element inserted is first to be removed
   - Elements are added at rear (enqueue)
   - Elements are removed from front (dequeue)

2. **Queue Pointers**
   - Front pointer: Points to first element
   - Rear pointer: Points to last element
   - Both essential for managing queue operations

### 2. Types of Queues

#### 2.1 Simple Queue (Linear Queue)
```cpp
template<typename T>
class SimpleQueue {
private:
    vector<T> elements;

public:
    void enqueue(T value) {
        elements.push_back(value);
    }
    
    T dequeue() {
        if(isEmpty()) throw runtime_error("Queue underflow");
        T front = elements.front();
        elements.erase(elements.begin());
        return front;
    }
    
    bool isEmpty() { return elements.empty(); }
    size_t size() { return elements.size(); }
};
```

#### 2.2 Circular Queue
```cpp
template<typename T, size_t SIZE>
class CircularQueue {
private:
    T arr[SIZE];
    int front, rear;
    int count;

public:
    CircularQueue() : front(0), rear(-1), count(0) {}
    
    void enqueue(T value) {
        if(isFull()) throw runtime_error("Queue overflow");
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
    }
    
    T dequeue() {
        if(isEmpty()) throw runtime_error("Queue underflow");
        T value = arr[front];
        front = (front + 1) % SIZE;
        count--;
        return value;
    }
    
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == SIZE; }
};
```

#### 2.3 Priority Queue
```cpp
template<typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node(T d, int p) : data(d), priority(p) {}
    };
    vector<Node> elements;

public:
    void enqueue(T value, int priority) {
        elements.emplace_back(value, priority);
        // Maintain heap property
        heapifyUp(elements.size() - 1);
    }
    
    T dequeue() {
        if(isEmpty()) throw runtime_error("Queue empty");
        T value = elements[0].data;
        elements[0] = elements.back();
        elements.pop_back();
        if(!isEmpty()) heapifyDown(0);
        return value;
    }
    
private:
    void heapifyUp(int index);
    void heapifyDown(int index);
};
```

#### 2.4 Double-ended Queue (Deque)
```cpp
template<typename T>
class Deque {
private:
    struct Node {
        T data;
        Node *prev, *next;
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };
    Node *front, *rear;
    size_t count;

public:
    void pushFront(T value);
    void pushBack(T value);
    T popFront();
    T popBack();
    bool isEmpty() { return count == 0; }
};
```

### 3. Implementation Approaches

#### 3.1 Array Implementation
```cpp
template<typename T, size_t SIZE>
class ArrayQueue {
private:
    T arr[SIZE];
    int front, rear;

public:
    ArrayQueue() : front(-1), rear(-1) {}
    
    void enqueue(T value) {
        if(rear == SIZE-1) throw runtime_error("Queue full");
        if(front == -1) front = 0;
        arr[++rear] = value;
    }
    
    T dequeue() {
        if(front == -1) throw runtime_error("Queue empty");
        T value = arr[front];
        if(front == rear) front = rear = -1;
        else front++;
        return value;
    }
};
```

#### 3.2 Linked List Implementation
```cpp
template<typename T>
class LinkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    
    Node *front, *rear;
    
public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}
    
    void enqueue(T value) {
        Node* newNode = new Node(value);
        if(rear) rear->next = newNode;
        rear = newNode;
        if(!front) front = newNode;
    }
    
    T dequeue() {
        if(!front) throw runtime_error("Queue empty");
        T value = front->data;
        Node* temp = front;
        front = front->next;
        if(!front) rear = nullptr;
        delete temp;
        return value;
    }
};
```

### 4. Advanced Applications

#### 4.1 BFS Implementation
```cpp
void BFS(Graph& graph, int start) {
    vector<bool> visited(graph.V, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        
        for(int adj : graph.adj[vertex]) {
            if(!visited[adj]) {
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
}
```

#### 4.2 Process Scheduling
```cpp
class ProcessScheduler {
private:
    queue<Process> readyQueue;
    
public:
    void addProcess(Process p) {
        readyQueue.push(p);
    }
    
    void executeNextProcess() {
        if(!readyQueue.empty()) {
            Process p = readyQueue.front();
            readyQueue.pop();
            p.execute();
        }
    }
};
```

### 5. Memory Management

#### 5.1 Queue Memory Organization
```
Linear Queue:
Front -> [1][2][3][4][5] <- Rear

Circular Queue:
     [1][2][3]
    /         \
   [8]        [4]
    \         /
     [7][6][5]
```

#### 5.2 Dynamic Memory Management
```cpp
template<typename T>
class DynamicQueue {
private:
    vector<T> elements;
    size_t capacity;
    
public:
    void enqueue(T value) {
        if(elements.size() == capacity) {
            capacity *= 2;
            // Vector automatically handles resizing
        }
        elements.push_back(value);
    }
};
```

### 6. Performance Analysis

| Operation    | Array Queue | Circular Queue | Linked Queue |
|-------------|-------------|----------------|--------------|
| Enqueue     | O(1)        | O(1)           | O(1)         |
| Dequeue     | O(n)        | O(1)           | O(1)         |
| Front/Rear  | O(1)        | O(1)           | O(1)         |
| Space       | O(n)        | O(n)           | O(n)         |

### 7. Common Applications

1. **Operating Systems**
   - Process scheduling
   - Print spooling
   - Interrupt handling
   - Buffer management

2. **Network Management**
   - Packet routing
   - Message queues
   - Traffic management
   - Request handling

3. **Real-time Systems**
   - Task scheduling
   - Event handling
   - Data streaming
   - Sensor data processing

### 8. Best Practices

1. **Error Handling**
   ```cpp
   void enqueue(T value) {
       try {
           // Attempt enqueue
           if(isFull()) throw QueueFullException();
           // Process enqueue
       } catch(const QueueFullException& e) {
           // Handle exception
       }
   }
   ```

2. **Resource Management**
   - Proper memory deallocation
   - Exception-safe code
   - Thread-safe implementations

3. **Design Considerations**
   - Choose appropriate queue type
   - Consider memory constraints
   - Implement necessary operations only

### 9. Common Pitfalls

1. **Array Queue Issues**
   - Fixed size limitations
   - Memory wastage
   - Inefficient dequeue operation

2. **Circular Queue Problems**
   - Complex index management
   - Full/empty condition confusion
   - Wraparound handling

3. **Implementation Mistakes**
   - Incorrect pointer updates
   - Memory leaks
   - Boundary condition errors

### 10. Practice Problems

1. **Basic Problems**
   - Implement queue using stacks
   - Reverse a queue
   - Sort a queue

2. **Advanced Problems**
   - Implement k queues in a single array
   - Design a queue with get-minimum operation
   - Implement a circular tour problem

---

## Module 8: Linked Lists  

### 1. Core Concepts

#### Definition
A linked list is a dynamic data structure where elements (nodes) are stored in non-contiguous memory locations and connected through references (pointers).

#### Structure of a Node
```cpp
template<typename T>
struct Node {
    T data;              // Data element
    Node* next;         // Reference to next node
    
    Node(T value) : data(value), next(nullptr) {}
};
```

### 2. Types of Linked Lists

#### 2.1 Singly Linked List (SLL)
```cpp
template<typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    size_t size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}
    
    void insertFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    // ... other operations
};
```

#### 2.2 Doubly Linked List (DLL)
```cpp
template<typename T>
struct DLLNode {
    T data;
    DLLNode* prev;
    DLLNode* next;
    
    DLLNode(T value) : data(value), prev(nullptr), next(nullptr) {}
};
```

#### 2.3 Circular Linked List
```cpp
template<typename T>
class CircularLinkedList {
private:
    Node<T>* tail;  // Points to last node
    
public:
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        if(!tail) {
            tail = newNode;
            tail->next = tail;  // Points to itself
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
};
```

### 3. Basic Operations

#### 3.1 Insertion Operations
```cpp
// Insert at beginning - O(1)
void insertFront(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end - O(n) or O(1) with tail pointer
void insertEnd(T value) {
    Node<T>* newNode = new Node<T>(value);
    if(!head) {
        head = newNode;
        return;
    }
    Node<T>* current = head;
    while(current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// Insert at position
void insertAt(T value, int position) {
    if(position < 0) return;
    if(position == 0) {
        insertFront(value);
        return;
    }
    
    Node<T>* newNode = new Node<T>(value);
    Node<T>* current = head;
    for(int i = 0; i < position-1 && current; i++) {
        current = current->next;
    }
    if(!current) return;
    
    newNode->next = current->next;
    current->next = newNode;
}
```

#### 3.2 Deletion Operations
```cpp
// Delete from front - O(1)
void deleteFront() {
    if(!head) return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end - O(n)
void deleteEnd() {
    if(!head) return;
    if(!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    
    Node<T>* current = head;
    while(current->next->next) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}
```

### 4. Advanced Operations

#### 4.1 Reverse a Linked List
```cpp
// Iterative approach
void reverse() {
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;
    
    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Recursive approach
Node<T>* reverseRecursive(Node<T>* node) {
    if(!node || !node->next) return node;
    
    Node<T>* rest = reverseRecursive(node->next);
    node->next->next = node;
    node->next = nullptr;
    return rest;
}
```

#### 4.2 Detect and Remove Cycle
```cpp
bool detectAndRemoveCycle() {
    if(!head) return false;
    
    Node<T>* slow = head;
    Node<T>* fast = head;
    
    // Detect cycle using Floyd's algorithm
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            // Remove cycle
            slow = head;
            while(slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = nullptr;
            return true;
        }
    }
    return false;
}
```

### 5. Memory Management

#### 5.1 Proper Cleanup
```cpp
// Destructor implementation
~LinkedList() {
    Node<T>* current = head;
    while(current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}
```

#### 5.2 Copy Operations
```cpp
// Deep copy constructor
LinkedList(const LinkedList& other) {
    if(!other.head) {
        head = nullptr;
        return;
    }
    
    head = new Node<T>(other.head->data);
    Node<T>* current = head;
    Node<T>* otherCurrent = other.head->next;
    
    while(otherCurrent) {
        current->next = new Node<T>(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}
```

### 6. Common Applications

1. **Implementation of Other Data Structures**
   - Stack implementation
   - Queue implementation
   - Hash table with chaining

2. **Memory Management**
   - Free list implementation
   - Memory allocation systems
   - Garbage collection

3. **System Applications**
   - File systems
   - Task scheduling
   - Polynomial manipulation

### 7. Performance Analysis

| Operation           | Singly Linked | Doubly Linked | Circular    |
|--------------------|---------------|---------------|-------------|
| Insert Front       | O(1)          | O(1)          | O(1)        |
| Insert End         | O(n)/O(1)*    | O(1)          | O(1)        |
| Delete Front       | O(1)          | O(1)          | O(1)        |
| Delete End         | O(n)          | O(1)          | O(1)        |
| Search            | O(n)          | O(n)          | O(n)        |
| Space per Node    | O(1)          | O(1)          | O(1)        |

*O(1) with tail pointer

### 8. Common Problems and Solutions

#### 8.1 Find Middle Element
```cpp
Node<T>* findMiddle() {
    if(!head) return nullptr;
    
    Node<T>* slow = head;
    Node<T>* fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

#### 8.2 Merge Two Sorted Lists
```cpp
Node<T>* mergeSorted(Node<T>* l1, Node<T>* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    
    Node<T>* result;
    if(l1->data <= l2->data) {
        result = l1;
        result->next = mergeSorted(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeSorted(l1, l2->next);
    }
    return result;
}
```

### 9. Best Practices

1. **Memory Management**
   - Always free memory in destructor
   - Handle null pointers
   - Avoid memory leaks
   - Implement deep copy

2. **Error Handling**
   - Check for empty list
   - Validate positions
   - Handle edge cases
   - Proper boundary checking

3. **Design Considerations**
   - Choose appropriate list type
   - Consider using sentinel nodes
   - Implement iterator pattern
   - Use templates for genericity

### 10. Common Pitfalls

1. **Memory Related**
   - Memory leaks
   - Dangling pointers
   - Double deletion
   - Not handling null pointers

2. **Logic Errors**
   - Incorrect pointer updates
   - Lost node references
   - Infinite loops
   - Improper cycle handling

3. **Implementation Issues**
   - Not maintaining size
   - Incorrect boundary conditions
   - Poor error handling
   - Inefficient algorithms

---

## Module 9: Hashing  

### 1. Fundamental Concepts

#### Definition
Hashing is a technique that maps data of arbitrary size to fixed-size values using a hash function, enabling efficient data storage and retrieval.

#### Key Components
1. **Hash Function**: Transforms input data into a fixed-size hash value
2. **Hash Table**: Data structure that stores key-value pairs
3. **Collision Resolution**: Techniques to handle when different keys produce same hash value

### 2. Hash Functions

#### 2.1 Properties of Good Hash Functions
1. Deterministic: Same input always produces same output
2. Uniform Distribution: Spreads values evenly across table
3. Efficiency: Quick to compute
4. Minimal Collisions: Different inputs rarely produce same output

#### 2.2 Common Hash Functions
```cpp
// Division Method
int hashDivision(int key, int tableSize) {
    return key % tableSize;
}

// Multiplication Method
int hashMultiplication(int key, int tableSize) {
    const double A = 0.618033988749895;  // (√5 - 1)/2
    double product = key * A;
    double fractionalPart = product - floor(product);
    return floor(tableSize * fractionalPart);
}

// String Hashing
int hashString(string key, int tableSize) {
    int hash = 0;
    for(char c : key) {
        hash = (hash * 31 + c) % tableSize;  // 31 is a prime number
    }
    return hash;
}
```

### 3. Hash Table Implementation

#### 3.1 Basic Hash Table
```cpp
template<typename K, typename V>
class HashTable {
private:
    static const int DEFAULT_SIZE = 16;
    vector<list<pair<K,V>>> table;
    int size;
    
public:
    HashTable(int s = DEFAULT_SIZE) : size(s) {
        table.resize(size);
    }
    
    int hashFunction(K key) {
        hash<K> hasher;
        return hasher(key) % size;
    }
    
    void insert(K key, V value) {
        int index = hashFunction(key);
        // Check if key exists and update
        for(auto& item : table[index]) {
            if(item.first == key) {
                item.second = value;
                return;
            }
        }
        // Insert new key-value pair
        table[index].push_back({key, value});
    }
    
    V* get(K key) {
        int index = hashFunction(key);
        for(auto& item : table[index]) {
            if(item.first == key) {
                return &item.second;
            }
        }
        return nullptr;
    }
};
```

### 4. Collision Resolution Techniques

#### 4.1 Chaining (Separate Chaining)
```cpp
template<typename K, typename V>
class ChainedHashTable {
private:
    vector<list<pair<K,V>>> table;
    
    // Collision handled by storing in linked list
    void handleCollision(int index, K key, V value) {
        table[index].push_back({key, value});
    }
};
```

#### 4.2 Open Addressing
```cpp
template<typename K, typename V>
class OpenAddressHashTable {
private:
    vector<pair<K,V>> table;
    vector<bool> occupied;
    
    // Linear Probing
    int findSlot(K key) {
        int index = hashFunction(key);
        int i = 0;
        while(occupied[index] && table[index].first != key) {
            i++;
            index = (hashFunction(key) + i) % table.size();  // Linear probing
        }
        return index;
    }
    
    // Quadratic Probing
    int findSlotQuadratic(K key) {
        int index = hashFunction(key);
        int i = 0;
        while(occupied[index] && table[index].first != key) {
            i++;
            index = (hashFunction(key) + i*i) % table.size();
        }
        return index;
    }
};
```

### 5. Load Factor and Rehashing

#### 5.1 Load Factor Management
```cpp
template<typename K, typename V>
class DynamicHashTable {
private:
    static const double LOAD_FACTOR_THRESHOLD = 0.75;
    int elements;
    
    double getLoadFactor() {
        return static_cast<double>(elements) / table.size();
    }
    
    void rehash() {
        vector<list<pair<K,V>>> oldTable = table;
        table.clear();
        table.resize(2 * oldTable.size());
        elements = 0;
        
        // Reinsert all elements
        for(const auto& bucket : oldTable) {
            for(const auto& item : bucket) {
                insert(item.first, item.second);
            }
        }
    }
    
public:
    void insert(K key, V value) {
        if(getLoadFactor() >= LOAD_FACTOR_THRESHOLD) {
            rehash();
        }
        // Normal insert operation
        int index = hashFunction(key);
        table[index].push_back({key, value});
        elements++;
    }
};
```

### 6. Advanced Applications

#### 6.1 Bloom Filter Implementation
```cpp
class BloomFilter {
private:
    vector<bool> bitArray;
    vector<function<int(string)>> hashFunctions;
    
public:
    BloomFilter(int size, int numHashes) {
        bitArray.resize(size, false);
        // Initialize hash functions
        for(int i = 0; i < numHashes; i++) {
            hashFunctions.push_back([i, size](string s) {
                hash<string> hasher;
                return (hasher(s) + i) % size;
            });
        }
    }
    
    void insert(string item) {
        for(auto& hashFunc : hashFunctions) {
            bitArray[hashFunc(item)] = true;
        }
    }
    
    bool mightContain(string item) {
        for(auto& hashFunc : hashFunctions) {
            if(!bitArray[hashFunc(item)]) return false;
        }
        return true;
    }
};
```

#### 6.2 Consistent Hashing
```cpp
class ConsistentHashing {
private:
    map<int, string> ring;  // Hash ring
    int numReplicas;
    
public:
    void addNode(string nodeId) {
        for(int i = 0; i < numReplicas; i++) {
            int hash = hashFunction(nodeId + to_string(i));
            ring[hash] = nodeId;
        }
    }
    
    string getNode(string key) {
        if(ring.empty()) return "";
        int hash = hashFunction(key);
        auto it = ring.lower_bound(hash);
        if(it == ring.end()) it = ring.begin();
        return it->second;
    }
};
```

### 7. Performance Analysis

| Operation | Average Case | Worst Case (Chain) | Worst Case (Open) |
|-----------|-------------|-------------------|------------------|
| Insert    | O(1)        | O(n)             | O(n)            |
| Delete    | O(1)        | O(n)             | O(n)            |
| Search    | O(1)        | O(n)             | O(n)            |
| Space     | O(n)        | O(n)             | O(n)            |

### 8. Common Applications

1. **Database Indexing**
   - Quick record lookup
   - Efficient join operations
   - Index organization

2. **Caching Systems**
   - Memory cache
   - Web cache
   - Distributed caching

3. **Symbol Tables**
   - Compiler symbol tables
   - Language interpreters
   - Runtime environments

4. **Cryptography**
   - Message digests
   - Digital signatures
   - Password storage

### 9. Best Practices

1. **Hash Function Design**
   - Use prime numbers for table size
   - Ensure uniform distribution
   - Consider input characteristics
   - Handle special cases

2. **Collision Handling**
   - Choose appropriate method
   - Monitor load factor
   - Implement efficient resizing
   - Handle edge cases

3. **Performance Optimization**
   - Keep load factor balanced
   - Use efficient collision resolution
   - Implement proper cleanup
   - Consider thread safety

### 10. Common Pitfalls

1. **Design Issues**
   - Poor hash function choice
   - Inadequate table size
   - Inefficient collision handling
   - Improper load factor management

2. **Implementation Problems**
   - Memory leaks
   - Infinite loops in probing
   - Incorrect collision resolution
   - Poor distribution

3. **Usage Mistakes**
   - Not handling duplicates
   - Incorrect key comparisons
   - Missing error handling
   - Improper cleanup

---

## Module 10: Heaps  

### 1. Fundamental Concepts

#### Definition
A heap is a specialized tree-based data structure that satisfies the heap property. It's a complete binary tree where each node's value maintains a specific ordering with respect to its children.

#### Types of Heaps
1. **Max Heap**: Parent nodes are greater than or equal to their children
2. **Min Heap**: Parent nodes are less than or equal to their children

### 2. Implementation

#### 2.1 Basic Heap Structure
```cpp
template<typename T>
class Heap {
protected:
    vector<T> items;
    
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }
};
```

#### 2.2 Max Heap Implementation
```cpp
template<typename T>
class MaxHeap : public Heap<T> {
public:
    void insert(T value) {
        this->items.push_back(value);
        heapifyUp(this->items.size() - 1);
    }
    
    T extractMax() {
        if(this->items.empty()) throw runtime_error("Heap empty");
        
        T root = this->items[0];
        this->items[0] = this->items.back();
        this->items.pop_back();
        
        if(!this->items.empty())
            heapifyDown(0);
            
        return root;
    }

private:
    void heapifyUp(int index);
    void heapifyDown(int index);
};
```

### 3. Advanced Operations

#### 3.1 Priority Queue Implementation
```cpp
template<typename T, typename Compare = less<T>>
class PriorityQueue {
private:
    vector<T> heap;
    Compare comp;
    
    void bubbleUp(int index) {
        while(index > 0) {
            int parent = (index - 1) / 2;
            if(comp(heap[parent], heap[index])) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else break;
        }
    }
};
```

#### 3.2 Heap Sort
```cpp
void heapSort(vector<int>& arr) {
    // Build max heap
    for(int i = arr.size()/2 - 1; i >= 0; i--)
        heapify(arr, arr.size(), i);
        
    // Extract elements from heap
    for(int i = arr.size()-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```

### 4. Applications

1. **Priority Queues**
   - Task scheduling
   - Event-driven simulation
   - Dijkstra's algorithm

2. **Memory Management**
   - Memory allocators
   - Garbage collection

3. **Data Streaming**
   - K-th largest element
   - Median maintenance
   - Top-K elements

### 5. Performance Analysis

| Operation    | Time Complexity |
|-------------|----------------|
| Insert      | O(log n)      |
| Extract     | O(log n)      |
| Peek        | O(1)          |
| Build Heap  | O(n)          |
| Heapify     | O(log n)      |

## Module 11: Trees  

### 1. Tree Types and Implementations

#### 1.1 Binary Tree
```cpp
template<typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode *left, *right;
    
    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
protected:
    BinaryTreeNode<T>* root;
    
public:
    void insert(T value);
    void remove(T value);
    bool search(T value);
    
    // Traversals
    void inorder();
    void preorder();
    void postorder();
    void levelOrder();
};
```

#### 1.2 AVL Tree
```cpp
template<typename T>
struct AVLNode {
    T data;
    AVLNode *left, *right;
    int height;
    
    AVLNode(T value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

template<typename T>
class AVLTree {
private:
    AVLNode<T>* root;
    
    int getHeight(AVLNode<T>* node) {
        return node ? node->height : 0;
    }
    
    int getBalance(AVLNode<T>* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    
    AVLNode<T>* rightRotate(AVLNode<T>* y);
    AVLNode<T>* leftRotate(AVLNode<T>* x);
};
```

### 2. Tree Traversal Techniques

#### 2.1 Depth-First Traversals
```cpp
// Inorder Traversal
void inorderTraversal(TreeNode* root) {
    if(!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal
void preorderTraversal(TreeNode* root) {
    if(!root) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal
void postorderTraversal(TreeNode* root) {
    if(!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
```

#### 2.2 Breadth-First Traversal
```cpp
void levelOrderTraversal(TreeNode* root) {
    if(!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->data << " ";
        
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}
```

### 3. Advanced Tree Operations

#### 3.1 Tree Balancing
```cpp
AVLNode* balance(AVLNode* node) {
    // Update height
    updateHeight(node);
    
    // Get balance factor
    int balance = getBalance(node);
    
    // Left Heavy
    if(balance > 1) {
        if(getBalance(node->left) < 0)
            node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right Heavy
    if(balance < -1) {
        if(getBalance(node->right) > 0)
            node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}
```

## Module 12: Graphs  

### 1. Graph Representations

#### 1.1 Adjacency Matrix
```cpp
class GraphMatrix {
private:
    vector<vector<int>> matrix;
    int vertices;
    
public:
    GraphMatrix(int v) : vertices(v) {
        matrix.resize(v, vector<int>(v, 0));
    }
    
    void addEdge(int from, int to, int weight = 1) {
        matrix[from][to] = weight;
        // For undirected graph:
        // matrix[to][from] = weight;
    }
};
```

#### 1.2 Adjacency List
```cpp
class GraphList {
private:
    vector<vector<pair<int, int>>> adjList;  // {vertex, weight}
    int vertices;
    
public:
    GraphList(int v) : vertices(v) {
        adjList.resize(v);
    }
    
    void addEdge(int from, int to, int weight = 1) {
        adjList[from].push_back({to, weight});
        // For undirected graph:
        // adjList[to].push_back({from, weight});
    }
};
```

### 2. Graph Traversal Algorithms

#### 2.1 Depth-First Search (DFS)
```cpp
class Graph {
private:
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";
        
        for(const auto& adj : adjList[vertex]) {
            if(!visited[adj.first])
                DFSUtil(adj.first, visited);
        }
    }
    
public:
    void DFS(int startVertex) {
        vector<bool> visited(vertices, false);
        DFSUtil(startVertex, visited);
    }
};
```

#### 2.2 Breadth-First Search (BFS)
```cpp
void BFS(int startVertex) {
    vector<bool> visited(vertices, false);
    queue<int> q;
    
    visited[startVertex] = true;
    q.push(startVertex);
    
    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";
        
        for(const auto& adj : adjList[vertex]) {
            if(!visited[adj.first]) {
                visited[adj.first] = true;
                q.push(adj.first);
            }
        }
    }
}
```

### 3. Shortest Path Algorithms

#### 3.1 Dijkstra's Algorithm
```cpp
vector<int> dijkstra(int start) {
    vector<int> dist(vertices, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, 
                  greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for(const auto& adj : adjList[u]) {
            int v = adj.first;
            int weight = adj.second;
            
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

#### 3.2 Floyd-Warshall Algorithm
```cpp
void floydWarshall() {
    vector<vector<int>> dist = matrix;  // Copy adjacency matrix
    
    for(int k = 0; k < vertices; k++)
        for(int i = 0; i < vertices; i++)
            for(int j = 0; i < vertices; j++)
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], 
                                   dist[i][k] + dist[k][j]);
}
```

### 4. Applications

1. **Social Networks**
   - Friend recommendations
   - Community detection
   - Influence analysis

2. **Transportation**
   - Route planning
   - Traffic analysis
   - Network optimization

3. **Computer Networks**
   - Routing protocols
   - Network flow
   - Resource allocation

### 5. Performance Analysis

| Algorithm          | Time Complexity | Space Complexity |
|-------------------|----------------|------------------|
| DFS              | O(V + E)      | O(V)            |
| BFS              | O(V + E)      | O(V)            |
| Dijkstra         | O(E log V)    | O(V)            |
| Floyd-Warshall   | O(V³)         | O(V²)           |
| Prim's MST       | O(E log V)    | O(V)            |
| Kruskal's MST    | O(E log E)    | O(V)            |

---

## Module 13: Sorting

Sorting is the process of arranging elements in a particular order, usually in ascending or descending order. It is a fundamental operation in computer science used for optimizing search processes, organizing data, and improving efficiency in various algorithms. There are multiple sorting algorithms, each with different time complexities, space requirements, and stability characteristics.

### Sorting Algorithm Properties

1. **Time Complexity**: Measures the performance of an algorithm based on input size (n).
2. **Space Complexity**: The amount of additional memory required by the algorithm.
3. **Stability**: A sorting algorithm is stable if it maintains the relative order of records with equal keys.
4. **Comparison-Based vs Non-Comparison-Based**: Some algorithms sort by comparing elements, while others use techniques like counting or bucketing.

---

### Sorting Algorithms

#### 1. **Bubble Sort**
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Stable**: Yes
- **Description**: A simple comparison-based algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if necessary. The process repeats until the list is sorted.

```cpp
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

#### 2. **Selection Sort**
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Stable**: No
- **Description**: Finds the minimum element from the unsorted part and swaps it with the first element of the unsorted part. Repeats for all elements.

```cpp
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}
```

#### 3. **Insertion Sort**
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Stable**: Yes
- **Description**: Iterates through the list, taking one element at a time and inserting it into its correct position in the sorted part.

```cpp
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

#### 4. **Merge Sort**
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)
- **Stable**: Yes
- **Description**: A divide-and-conquer algorithm that splits the array into two halves, sorts each half recursively, and merges them.

```cpp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

#### 5. **Quick Sort**
- **Time Complexity**: O(n log n) (average case), O(n²) (worst case)
- **Space Complexity**: O(log n)
- **Stable**: No
- **Description**: Selects a pivot element, partitions the array around the pivot, and sorts recursively.

```cpp
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

---




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

### Conclusion
Different sorting algorithms are suited for different scenarios. For small datasets, simple algorithms like **Insertion Sort** or **Bubble Sort** might be sufficient. For large datasets, **Merge Sort** and **Quick Sort** are preferred due to their better time complexity. Choosing the right sorting algorithm depends on factors like stability, memory constraints, and whether the data is nearly sorted or not.

---
