#### Algorithm For Sem Exam

---
=============================
---

| **Category**            | **Subcategory**               | **Key Topics**                                                                                                                                          |
|-------------------------|-------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Data Structures**     | **Linear DS**                 | Array, Singly/Doubly/Circular Linked List, Stack, Queue, Deque, Priority Queue                                                                          |
|                         | **Trees**                     | Binary Tree, Binary Search Tree, AVL Tree, Heap (Min/Max), Segment Tree, Trie                                                                           |
|                         | **Graphs**                    | Directed/Undirected, Weighted/Unweighted, Representations (Adjacency List / Matrix), Edge List                                                          |
| **Algorithms**          | **Sorting**                   | Bubble, Selection, Insertion, Merge, Quick, Heap, Counting, Radix, Bucket                                                                               |
|                         | **Searching**                 | Linear Search, Binary Search, Ternary Search                                                                                                            |
|                         | **Recursion & Backtracking**  | Recursion fundamentals, Call stack, Backtracking templates (Permutations, Combinations, N-Queens, Sudoku)                                                  |
|                         | **Divide & Conquer**          | Merge Sort, Quick Sort, Binary Search, Strassen’s Matrix Multiplication                                                                                 |
|                         | **Dynamic Programming**       | Memoization vs Tabulation, Knapsack, Longest Increasing Subsequence (LIS), Longest Common Subsequence (LCS), Matrix Chain Multiplication                  |
|                         | **Greedy Algorithms**         | Activity Selection, Fractional Knapsack, Huffman Coding, Job Sequencing                                                                                 |
|                         | **Graph Algorithms**          | BFS, DFS, Dijkstra, Bellman–Ford, Floyd–Warshall, Kruskal, Prim, Topological Sort                                                                         |
| **Complexity Analysis** | —                             | Time Complexity (O, Ω, Θ), Space Complexity, Amortized Analysis                                                                                         |
| **Problem Patterns**    | —                             | Sliding Window, Two Pointers, Fast & Slow Pointers, Divide & Conquer, Greedy, DP, Backtracking                                                           |
| **Common Problems**     | —                             | Array Manipulations (two-sum, subarray sums), Linked List Ops (reverse, detect cycle), Tree Traversals (in/pre/post), Shortest Path in Graph, <br>Subset/Permutation Generation |


---
=============================

#### 1. .....stack.....

=============================
---

### 1. Stack Operations (Array Implementation)

Assume a fixed‐size array `S[0…MAX-1]` and an integer `top` initialized to `–1`.

#### 1.1 Initialize  
1. `top ← –1`

#### 1.2 isEmpty  
```
FUNCTION isEmpty():
    RETURN (top == –1)
```

#### 1.3 isFull  
```
FUNCTION isFull():
    RETURN (top == MAX-1)
```

#### 1.4 Push  
```
FUNCTION push(x):
    IF isFull() THEN
        ERROR “Stack Overflow”
    ELSE
        top ← top + 1
        S[top] ← x
```

#### 1.5 Pop  
```
FUNCTION pop():
    IF isEmpty() THEN
        ERROR “Stack Underflow”
    ELSE
        x ← S[top]
        top ← top – 1
        RETURN x
```

#### 1.6 Peek (Top Element)  
```
FUNCTION peek():
    IF isEmpty() THEN
        ERROR “Stack is empty”
    ELSE
        RETURN S[top]
```

#### 1.7 Display  
```
FUNCTION display():
    IF isEmpty() THEN
        PRINT “Stack is empty”
    ELSE
        FOR i FROM top DOWNTO 0 DO
            PRINT S[i]
```

---

### 2. Stack via Singly Linked List

Each node has `data` and `next`. Keep a pointer `top` initially `NULL`.

#### 2.1 Push  
```
FUNCTION push(x):
    CREATE node newNode
    newNode.data ← x
    newNode.next ← top
    top ← newNode
```

#### 2.2 Pop  
```
FUNCTION pop():
    IF top == NULL THEN
        ERROR “Underflow”
    ELSE
        x ← top.data
        temp ← top
        top ← top.next
        DELETE temp
        RETURN x
```

#### 2.3 Peek  
```
FUNCTION peek():
    IF top == NULL THEN
        ERROR “Empty”
    ELSE
        RETURN top.data
```

#### 2.4 isEmpty  
```
FUNCTION isEmpty():
    RETURN (top == NULL)
```

---

### 3. Application: Parenthesis Matching

Check if every ‘(’, ‘{’, ‘[’ has a corresponding closing.

```
FUNCTION isBalanced(expr):
    CREATE empty stack
    FOR each ch IN expr DO
        IF ch IN { '(', '{', '[' } THEN
            push(ch)
        ELSE IF ch IN { ')', '}', ']' } THEN
            IF isEmpty() THEN RETURN FALSE
            topChar ← pop()
            IF NOT matches(topChar, ch) THEN RETURN FALSE
    END FOR
    RETURN isEmpty()

FUNCTION matches(open, close):
    RETURN (open=='(' AND close==')')
        OR (open=='{' AND close=='}')
        OR (open=='[' AND close==']')
```

---

### 4. Infix → Postfix Conversion (Shunting‐Yard)

```
FUNCTION infixToPostfix(expr):
    CREATE empty stack (for operators)
    CREATE empty list output
    FOR each token IN expr DO
        IF token is operand THEN
            APPEND token to output
        ELSE IF token == '(' THEN
            push(token)
        ELSE IF token == ')' THEN
            WHILE peek() != '(' DO
                APPEND pop() to output
            pop()      // remove '('
        ELSE    // token is operator
            WHILE NOT isEmpty() AND precedence(peek()) ≥ precedence(token) DO
                APPEND pop() to output
            push(token)
    END FOR
    WHILE NOT isEmpty() DO
        APPEND pop() to output
    RETURN concatenate(output)
```

- **precedence(op)** returns an integer (e.g. `+`/`-`→1, `*`/`/`→2, `^`→3).  
- For right-associative (`^`), use `>` instead of `≥` in the comparison.

---

### 5. Postfix Expression Evaluation

```
FUNCTION evalPostfix(expr):
    CREATE empty stack (for values)
    FOR each token IN expr DO
        IF token is operand THEN
            push(numericValue(token))
        ELSE    // operator
            val2 ← pop()
            val1 ← pop()
            result ← applyOperator(val1, val2, token)
            push(result)
    END FOR
    RETURN pop()
```

---

#### Example: Minimum Element Tracking

Maintain two stacks: `S` for data, `MinS` for current minima.

```
FUNCTION push(x):
    IF isEmpty_MinS() OR x ≤ peek_MinS() THEN
        push_MinS(x)
    push_S(x)

FUNCTION pop():
    x ← pop_S()
    IF x == peek_MinS() THEN
        pop_MinS()
    RETURN x

FUNCTION getMin():
    RETURN peek_MinS()
```

---

#### More Examples....

---

## 1. Core Stack Operations  
*(Array or Linked-List implementation – you already have these down: push, pop, peek, isEmpty, isFull.)*

---

## 2. Parenthesis / Delimiter Matching  
**Use:** Validate expressions like `({[()]})`  
```
FUNCTION isBalanced(expr):
    CREATE empty stack
    FOR each ch IN expr:
        IF ch IN { '(', '{', '[' }:
            push(ch)
        ELSE IF ch IN { ')', '}', ']' }:
            IF isEmpty(): RETURN FALSE
            open ← pop()
            IF NOT match(open, ch): RETURN FALSE
    RETURN isEmpty()

FUNCTION match(o, c):
    RETURN (o=='(' AND c==')')
        OR (o=='{' AND c=='}')
        OR (o=='[' AND c==']')
```

---

## 3. Infix ⇄ Postfix / Prefix Conversion  
### 3.1 Infix → Postfix (Shunting-Yard)
```
FUNCTION infixToPostfix(tokens):
    CREATE empty stack OP
    CREATE empty list OUT
    FOR each t IN tokens:
        IF t is operand:
            APPEND t to OUT
        ELSE IF t == '(':
            push(OP, t)
        ELSE IF t == ')':
            WHILE peek(OP) != '(':
                APPEND pop(OP) to OUT
            pop(OP)      // discard '('
        ELSE:  // t is operator
            WHILE NOT isEmpty(OP) AND prec(peek(OP)) ≥ prec(t):
                APPEND pop(OP) to OUT
            push(OP, t)
    WHILE NOT isEmpty(OP):
        APPEND pop(OP) to OUT
    RETURN OUT as string
```
- For right-associative (e.g. `^`) use `>` instead of `≥`.

### 3.2 Infix → Prefix  
1. Reverse the infix string (swap `(`↔`)`).  
2. Apply infix→postfix.  
3. Reverse the resulting postfix to get prefix.

---

## 4. Postfix / Prefix Evaluation  
### 4.1 Evaluate Postfix
```
FUNCTION evalPostfix(tokens):
    CREATE empty stack VAL
    FOR each t IN tokens:
        IF t is operand:
            push(VAL, valueOf(t))
        ELSE:
            b ← pop(VAL)
            a ← pop(VAL)
            push(VAL, apply(a, b, t))
    RETURN pop(VAL)
```

### 4.2 Evaluate Prefix  
Same as postfix but traverse tokens right→left, and swap operand order when applying.

---

## 5. Next Greater Element (to right)  
**Use:** For each element in array, find the next greater on its right in O(n).  
```
FUNCTION nextGreater(arr):
    n ← length(arr)
    CREATE result[n], INIT with –1
    CREATE empty stack S
    FOR i FROM 0 TO n–1:
        WHILE NOT isEmpty(S) AND arr[i] > arr[peek(S)]:
            idx ← pop(S)
            result[idx] ← arr[i]
        push(S, i)
    // remaining in S have no greater; result already –1
    RETURN result
```

---

## 6. Stock Span Problem  
**Use:** For array of daily prices, span[i] = #consecutive days before i with price ≤ price[i].  
```
FUNCTION stockSpan(price):
    n ← length(price)
    span ← array[n]
    CREATE empty stack S  // stores indices
    FOR i FROM 0 TO n–1:
        WHILE NOT isEmpty(S) AND price[S.top] ≤ price[i]:
            pop(S)
        IF isEmpty(S):
            span[i] ← i + 1
        ELSE:
            span[i] ← i – S.top
        push(S, i)
    RETURN span
```

---

## 7. Min-Stack (O(1) getMin)  
**Maintain two stacks:** `dataS` for all values, `minS` for current minima.  
```
FUNCTION push(x):
    push(dataS, x)
    IF isEmpty(minS) OR x ≤ peek(minS):
        push(minS, x)

FUNCTION pop():
    x ← pop(dataS)
    IF x == peek(minS):
        pop(minS)
    RETURN x

FUNCTION getMin():
    RETURN peek(minS)
```

---

## 8. Reverse a Stack (Recursion)  
```
FUNCTION insertAtBottom(S, x):
    IF isEmpty(S):
        push(S, x)
    ELSE:
        temp ← pop(S)
        insertAtBottom(S, x)
        push(S, temp)

FUNCTION reverseStack(S):
    IF NOT isEmpty(S):
        temp ← pop(S)
        reverseStack(S)
        insertAtBottom(S, temp)
```

---

## 9. Sort a Stack (using one auxiliary stack)  
```
FUNCTION sortedInsert(S, x):
    IF isEmpty(S) OR x > peek(S):
        push(S, x)
    ELSE:
        temp ← pop(S)
        sortedInsert(S, x)
        push(S, temp)

FUNCTION sortStack(S):
    IF NOT isEmpty(S):
        temp ← pop(S)
        sortStack(S)
        sortedInsert(S, temp)
```

---

## 10. Largest Rectangle in Histogram  
**Use a stack of indices to track bars in increasing height.**  
```
FUNCTION maxHistogramArea(heights):
    n ← length(heights)
    CREATE empty stack S
    maxArea ← 0
    FOR i FROM 0 TO n:
        currH ← (i==n ? 0 : heights[i])
        WHILE NOT isEmpty(S) AND currH < heights[peek(S)]:
            h ← heights[pop(S)]
            w ← isEmpty(S) ? i : i – peek(S) – 1
            maxArea ← max(maxArea, h * w)
        push(S, i)
    RETURN maxArea
```

---

#### 2. .....Queue......

---

## 1. Core Queue Operations  
*(Array‐ or Linked-List-based)*

### 1.1 Array Implementation (Fixed-Size)  
Assume array `Q[0…MAX-1]`, `front = –1`, `rear = –1`.

```  
FUNCTION isEmpty():
    RETURN (front == –1)

FUNCTION isFull():
    RETURN (rear == MAX-1)

FUNCTION enqueue(x):
    IF isFull(): ERROR “Overflow”
    IF isEmpty(): front ← 0
    rear ← rear + 1
    Q[rear] ← x

FUNCTION dequeue():
    IF isEmpty(): ERROR “Underflow”
    x ← Q[front]
    IF front == rear:
        front ← rear ← –1
    ELSE:
        front ← front + 1
    RETURN x

FUNCTION peek():
    IF isEmpty(): ERROR “Empty”
    RETURN Q[front]
```

### 1.2 Singly-Linked List Implementation  
Maintain `front` and `rear` pointers, initially both `NULL`.

```  
FUNCTION enqueue(x):
    newNode ← Node(x)
    IF rear == NULL:
        front ← rear ← newNode
    ELSE:
        rear.next ← newNode
        rear ← newNode

FUNCTION dequeue():
    IF front == NULL: ERROR “Underflow”
    x ← front.data
    front ← front.next
    IF front == NULL: rear ← NULL
    RETURN x

FUNCTION isEmpty():
    RETURN (front == NULL)

FUNCTION peek():
    IF isEmpty(): ERROR “Empty”
    RETURN front.data
```

---

## 2. Circular Queue (Array)  
Reuses freed slots in a ring.

```  
FUNCTION isFull():
    RETURN ((rear + 1) mod MAX) == front

FUNCTION isEmpty():
    RETURN (front == –1)

FUNCTION enqueue(x):
    IF isFull(): ERROR “Overflow”
    IF isEmpty(): front ← 0
    rear ← (rear + 1) mod MAX
    Q[rear] ← x

FUNCTION dequeue():
    IF isEmpty(): ERROR “Underflow”
    x ← Q[front]
    IF front == rear:
        front ← rear ← –1
    ELSE:
        front ← (front + 1) mod MAX
    RETURN x
```

---

## 3. Deque (Double-Ended Queue)  
Supports insertion/removal at both ends in O(1).

```  
FUNCTION insertFront(x):
    IF isFull(): ERROR
    front ← (front – 1 + MAX) mod MAX
    Q[front] ← x
    IF rear == –1: rear ← front

FUNCTION insertRear(x):
    IF isFull(): ERROR
    rear ← (rear + 1) mod MAX
    Q[rear] ← x
    IF front == –1: front ← rear

FUNCTION deleteFront():
    IF isEmpty(): ERROR
    x ← Q[front]
    IF front == rear: front ← rear ← –1
    ELSE: front ← (front + 1) mod MAX
    RETURN x

FUNCTION deleteRear():
    IF isEmpty(): ERROR
    x ← Q[rear]
    IF front == rear: front ← rear ← –1
    ELSE: rear ← (rear – 1 + MAX) mod MAX
    RETURN x
```

---

## 4. Implement Queue Using Two Stacks  
— Amortized O(1) enqueue, O(1) / amortized O(1) dequeue

```
STACK inSt, outSt

FUNCTION enqueue(x):
    push(inSt, x)

FUNCTION dequeue():
    IF isEmpty(inSt) AND isEmpty(outSt): ERROR “Empty”
    IF isEmpty(outSt):
        WHILE NOT isEmpty(inSt):
            push(outSt, pop(inSt))
    RETURN pop(outSt)

FUNCTION peek():
    IF isEmpty(outSt):
        WHILE NOT isEmpty(inSt):
            push(outSt, pop(inSt))
    RETURN top(outSt)
```

---

## 5. Breadth-First Search (BFS) on a Graph/Tree  
```
FUNCTION BFS(start):
    CREATE empty queue Q
    MARK start as visited
    enqueue(Q, start)
    WHILE NOT isEmpty(Q):
        u ← dequeue(Q)
        PROCESS(u)
        FOR each v IN neighbors(u):
            IF v not visited:
                MARK v visited
                enqueue(Q, v)
```

---

## 6. Level-Order Traversal of Binary Tree  
```
FUNCTION levelOrder(root):
    IF root == NULL: RETURN
    enqueue(Q, root)
    WHILE NOT isEmpty(Q):
        node ← dequeue(Q)
        VISIT(node)
        IF node.left ≠ NULL: enqueue(Q, node.left)
        IF node.right ≠ NULL: enqueue(Q, node.right)
```

---

## 7. Sliding Window Maximum (Deque-Based)  
Find max in every window of size `k` over array `A[0…n-1]`.

```
FUNCTION slidingMax(A, k):
    CREATE empty deque D  // will store indices
    result ← empty list

    FOR i FROM 0 TO n–1:
        // Remove indices out of this window
        WHILE NOT empty(D) AND D.front < i – k + 1:
            D.pop_front()

        // Remove smaller elements in k-window
        WHILE NOT empty(D) AND A[D.back] ≤ A[i]:
            D.pop_back()

        D.push_back(i)

        IF i ≥ k – 1:
            APPEND A[D.front] to result

    RETURN result
```

---

## 8. Josephus Problem (Circular Queue Simulation)  
Eliminate every `k`-th person in a circle of `n`.

```
FUNCTION josephus(n, k):
    CREATE queue Q
    FOR i FROM 1 TO n:
        enqueue(Q, i)

    WHILE size(Q) > 1:
        FOR i FROM 1 TO k – 1:
            enqueue(Q, dequeue(Q))
        dequeue(Q)  // remove k-th

    RETURN dequeue(Q)
```

---

## 9. Generate Binary Numbers 1…N Using a Queue  
```
FUNCTION generateBinary(n):
    CREATE empty queue Q
    enqueue(Q, "1")
    FOR i FROM 1 TO n:
        s ← dequeue(Q)
        PRINT s
        enqueue(Q, s + "0")
        enqueue(Q, s + "1")
```

---

## 10. Interleave First and Second Half of a Queue  
```
FUNCTION interleave(Q):
    n ← size(Q)
    IF n % 2 ≠ 0: ERROR “Even size required”

    // Step 1: push first half into stack
    CREATE empty stack S
    FOR i FROM 1 TO n/2:
        push(S, dequeue(Q))

    // Step 2: enqueue stack contents back
    WHILE NOT empty(S):
        enqueue(Q, pop(S))

    // Step 3: move first half to back
    FOR i FROM 1 TO n/2:
        enqueue(Q, dequeue(Q))

    // Step 4: again push first half into stack
    FOR i FROM 1 TO n/2:
        push(S, dequeue(Q))

    // Step 5: interleave
    WHILE NOT empty(S):
        enqueue(Q, pop(S))
        enqueue(Q, dequeue(Q))
```

---

#### 3.......Linked List......


## 1. Core Definitions & Traversal

``` 
STRUCT Node:
    data
    next

FUNCTION traverse(head):
    curr ← head
    WHILE curr ≠ NULL:
        PRINT curr.data
        curr ← curr.next
```

---

## 2. Insertion

### 2.1 At Front  
```
FUNCTION insertFront(head, x):
    newNode ← Node(x)
    newNode.next ← head
    head ← newNode
    RETURN head
```

### 2.2 At End  
```
FUNCTION insertEnd(head, x):
    newNode ← Node(x)
    IF head == NULL: 
        RETURN newNode
    curr ← head
    WHILE curr.next ≠ NULL:
        curr ← curr.next
    curr.next ← newNode
    RETURN head
```

### 2.3 After a Given Node  
```
FUNCTION insertAfter(prevNode, x):
    IF prevNode == NULL: ERROR
    newNode ← Node(x)
    newNode.next ← prevNode.next
    prevNode.next ← newNode
```

### 2.4 At Position (1-indexed)  
```
FUNCTION insertAtPos(head, pos, x):
    IF pos == 1: RETURN insertFront(head, x)
    curr ← head
    FOR i FROM 1 TO pos–2:
        IF curr == NULL: ERROR
        curr ← curr.next
    insertAfter(curr, x)
    RETURN head
```

---

## 3. Deletion

### 3.1 By Key  
```
FUNCTION deleteByKey(head, key):
    IF head == NULL: RETURN NULL
    IF head.data == key:
        temp ← head
        head ← head.next
        DELETE temp
        RETURN head
    curr ← head
    WHILE curr.next ≠ NULL AND curr.next.data ≠ key:
        curr ← curr.next
    IF curr.next == NULL: RETURN head  // not found
    temp ← curr.next
    curr.next ← temp.next
    DELETE temp
    RETURN head
```

### 3.2 By Position (1-indexed)  
```
FUNCTION deleteAtPos(head, pos):
    IF head == NULL: RETURN NULL
    IF pos == 1:
        temp ← head
        head ← head.next
        DELETE temp
        RETURN head
    curr ← head
    FOR i FROM 1 TO pos–2:
        IF curr == NULL: ERROR
        curr ← curr.next
    IF curr.next == NULL: ERROR
    temp ← curr.next
    curr.next ← temp.next
    DELETE temp
    RETURN head
```

---

## 4. Search

```
FUNCTION search(head, key):
    curr ← head
    WHILE curr ≠ NULL:
        IF curr.data == key: RETURN TRUE
        curr ← curr.next
    RETURN FALSE
```

---

## 5. Reverse a Linked List

### 5.1 Iterative  
```
FUNCTION reverseIter(head):
    prev ← NULL
    curr ← head
    WHILE curr ≠ NULL:
        nextNode ← curr.next
        curr.next ← prev
        prev ← curr
        curr ← nextNode
    RETURN prev   // new head
```

### 5.2 Recursive  
```
FUNCTION reverseRec(curr, prev = NULL):
    IF curr == NULL: RETURN prev
    nextNode ← curr.next
    curr.next ← prev
    RETURN reverseRec(nextNode, curr)
```

---

## 6. Detect & Remove Loop (Floyd’s Algorithm)

```
FUNCTION detectLoop(head):
    slow, fast ← head, head
    WHILE fast ≠ NULL AND fast.next ≠ NULL:
        slow ← slow.next
        fast ← fast.next.next
        IF slow == fast: RETURN TRUE
    RETURN FALSE

FUNCTION removeLoop(head):
    // First detect meeting point
    slow, fast ← head, head
    LOOP UNTIL fast == NULL OR fast.next == NULL OR slow == fast:
        slow ← slow.next
        fast ← fast.next.next
    IF fast == NULL OR fast.next == NULL: RETURN head  // no loop
    // Find loop start
    slow ← head
    WHILE slow.next ≠ fast.next:
        slow ← slow.next
        fast ← fast.next
    // Break loop
    fast.next ← NULL
    RETURN head
```

---

## 7. Two-Pointer Techniques

### 7.1 Find Middle Node  
```
FUNCTION findMiddle(head):
    slow, fast ← head, head
    WHILE fast ≠ NULL AND fast.next ≠ NULL:
        slow ← slow.next
        fast ← fast.next.next
    RETURN slow   // middle (for even-size lists, the ⌈n/2⌉th)
```

### 7.2 Nth Node from End  
```
FUNCTION nthFromEnd(head, n):
    first, second ← head, head
    FOR i FROM 1 TO n:
        IF first == NULL: ERROR
        first ← first.next
    WHILE first ≠ NULL:
        first ← first.next
        second ← second.next
    RETURN second.data
```

---

## 8. Merge Two Sorted Lists

```
FUNCTION mergeSorted(a, b):
    dummy ← Node(–)
    tail ← dummy
    WHILE a ≠ NULL AND b ≠ NULL:
        IF a.data ≤ b.data:
            tail.next ← a
            a ← a.next
        ELSE:
            tail.next ← b
            b ← b.next
        tail ← tail.next
    tail.next ← (a == NULL ? b : a)
    RETURN dummy.next
```

---

## 9. Remove Duplicates

### 9.1 From Sorted List  
```
FUNCTION removeDupSorted(head):
    curr ← head
    WHILE curr ≠ NULL AND curr.next ≠ NULL:
        IF curr.data == curr.next.data:
            temp ← curr.next
            curr.next ← temp.next
            DELETE temp
        ELSE:
            curr ← curr.next
    RETURN head
```

### 9.2 From Unsorted List (Hash Set)  
```
FUNCTION removeDupUnsorted(head):
    seen ← empty set
    prev ← NULL
    curr ← head
    WHILE curr ≠ NULL:
        IF curr.data IN seen:
            prev.next ← curr.next
            DELETE curr
            curr ← prev.next
        ELSE:
            ADD curr.data TO seen
            prev ← curr
            curr ← curr.next
    RETURN head
```

---

## 10. Palindrome Check

```
FUNCTION isPalindrome(head):
    // 1. Find middle
    mid ← findMiddle(head)
    // 2. Reverse second half
    second ← reverseIter(mid.next)
    // 3. Compare halves
    p1, p2 ← head, second
    WHILE p2 ≠ NULL:
        IF p1.data ≠ p2.data: RETURN FALSE
        p1 ← p1.next
        p2 ← p2.next
    // (optional) restore list: mid.next ← reverseIter(second)
    RETURN TRUE
```

---

## 11. Reverse in Groups of k

```
FUNCTION reverseK(head, k):
    curr, prev, nextNode ← head, NULL, NULL
    count ← 0
    WHILE curr ≠ NULL AND count < k:
        nextNode ← curr.next
        curr.next ← prev
        prev ← curr
        curr ← nextNode
        count ← count + 1
    IF nextNode ≠ NULL:
        head.next ← reverseK(nextNode, k)
    RETURN prev   // new head of this segment
```

---

## 12. Rotate List by k

```
FUNCTION rotateRight(head, k):
    IF head == NULL OR k == 0: RETURN head
    // 1. Compute length & make it circular
    tail, n ← head, 1
    WHILE tail.next ≠ NULL:
        tail ← tail.next
        n ← n + 1
    tail.next ← head
    // 2. Find new tail: move (n – k % n – 1) steps
    steps ← n – (k mod n) – 1
    newTail ← head
    FOR i FROM 1 TO steps:
        newTail ← newTail.next
    newHead ← newTail.next
    newTail.next ← NULL
    RETURN newHead
```

---

## 13. Circular & Doubly‐Linked Lists

### 13.1 Circular Singly (Insert/Delete)  
- **Insert Sorted**: walk until `curr.data ≤ x ≤ curr.next.data` (or wrap), splice in.
- **Delete Node**: find node, adjust predecessor’s `next`; handle single-node case.

### 13.2 Doubly-Linked List  
```  
STRUCT DNode:
    data
    prev, next

FUNCTION insertAfter(node, x):
    newNode ← DNode(x)
    newNode.next ← node.next
    newNode.prev ← node
    IF node.next ≠ NULL: node.next.prev ← newNode
    node.next ← newNode

FUNCTION deleteNode(head, node):
    IF head == NULL OR node == NULL: RETURN head
    IF head == node: head ← node.next
    IF node.next ≠ NULL: node.next.prev ← node.prev
    IF node.prev ≠ NULL: node.prev.next ← node.next
    DELETE node
    RETURN head
```

---
### 4. .....Sortig Searching....
---

## I. Sorting Algorithms

### 1. Bubble Sort  
Repeatedly “bubble” the largest remaining element to the end.  
```
FUNCTION bubbleSort(A, n):
    FOR i FROM 1 TO n–1:
        FOR j FROM 0 TO n–i–1:
            IF A[j] > A[j+1]:
                SWAP A[j], A[j+1]
```

### 2. Selection Sort  
Select the minimum from the unsorted portion and swap into place.  
```
FUNCTION selectionSort(A, n):
    FOR i FROM 0 TO n–2:
        minIdx ← i
        FOR j FROM i+1 TO n–1:
            IF A[j] < A[minIdx]:
                minIdx ← j
        SWAP A[i], A[minIdx]
```

### 3. Insertion Sort  
Build a sorted prefix one element at a time.  
```
FUNCTION insertionSort(A, n):
    FOR i FROM 1 TO n–1:
        key ← A[i]
        j ← i–1
        WHILE j ≥ 0 AND A[j] > key:
            A[j+1] ← A[j]
            j ← j–1
        A[j+1] ← key
```

### 4. Merge Sort (Divide & Conquer)  
Recursively split, sort halves, then merge.  
```
FUNCTION mergeSort(A, l, r):
    IF l < r:
        m ← ⌊(l + r)/2⌋
        mergeSort(A, l, m)
        mergeSort(A, m+1, r)
        merge(A, l, m, r)

FUNCTION merge(A, l, m, r):
    // Copy A[l..m] into L[0..n1-1], A[m+1..r] into R[0..n2-1], then:
    i, j, k ← 0, 0, l
    WHILE i < n1 AND j < n2:
        IF L[i] ≤ R[j]:
            A[k++] ← L[i++]
        ELSE:
            A[k++] ← R[j++]
    COPY remaining elements of L or R into A
```

### 5. Quick Sort (Divide & Conquer)  
Partition around a pivot, then sort partitions.  
```
FUNCTION quickSort(A, low, high):
    IF low < high:
        p ← partition(A, low, high)
        quickSort(A, low, p–1)
        quickSort(A, p+1, high)

FUNCTION partition(A, low, high):
    pivot ← A[high]
    i ← low–1
    FOR j FROM low TO high–1:
        IF A[j] ≤ pivot:
            i ← i+1
            SWAP A[i], A[j]
    SWAP A[i+1], A[high]
    RETURN i+1
```

### 6. Heap Sort  
Build a max-heap, then repeatedly extract max to end.  
```
FUNCTION heapSort(A, n):
    // Build max-heap
    FOR i FROM ⌊n/2⌋–1 DOWNTO 0:
        heapify(A, n, i)
    // Extract elements
    FOR i FROM n–1 DOWNTO 1:
        SWAP A[0], A[i]        // move max to end
        heapify(A, i, 0)       // restore heap on A[0..i-1]

FUNCTION heapify(A, heapSize, root):
    largest ← root
    left ← 2*root + 1
    right ← 2*root + 2
    IF left < heapSize AND A[left] > A[largest]:
        largest ← left
    IF right < heapSize AND A[right] > A[largest]:
        largest ← right
    IF largest ≠ root:
        SWAP A[root], A[largest]
        heapify(A, heapSize, largest)
```

### 7. Counting Sort  
For non-negative integers in a known range [0…k].  
```
FUNCTION countingSort(A, n, k):
    MAKE count[0..k] initialized to 0
    FOR i FROM 0 TO n–1:
        count[A[i]] ← count[A[i]] + 1
    FOR i FROM 1 TO k:
        count[i] ← count[i] + count[i–1]
    MAKE output[0..n–1]
    FOR i FROM n–1 DOWNTO 0:
        output[count[A[i]]–1] ← A[i]
        count[A[i]] ← count[A[i]] – 1
    COPY output back into A
```

### 8. Radix Sort (LSD)  
Sort numbers by each digit, using counting sort as a subroutine.  
```
FUNCTION radixSort(A, n):
    maxVal ← maximum element in A
    exp ← 1
    WHILE maxVal/exp > 0:
        countingSortByDigit(A, n, exp)
        exp ← exp * 10

FUNCTION countingSortByDigit(A, n, exp):
    // Like countingSort but key = (A[i] / exp) mod 10
```

### 9. Bucket Sort  
Distribute into buckets, sort each (e.g. insertion sort), then concatenate.  
```
FUNCTION bucketSort(A, n):
    CREATE buckets[0..n–1] as empty lists
    FOR i FROM 0 TO n–1:
        idx ← ⌊n * A[i]⌋     // for A[i] in [0,1)
        buckets[idx].append(A[i])
    FOR each bucket in buckets:
        insertionSort(bucket, size(bucket))
    CONCATENATE all buckets back into A
```

### 10. Shell Sort  
Generalized insertion sort with diminishing gaps.  
```
FUNCTION shellSort(A, n):
    gaps ← sequence of intervals, e.g. ⌊n/2⌋, ⌊n/4⌋, …, 1
    FOR each gap IN gaps:
        FOR i FROM gap TO n–1:
            temp ← A[i]
            j ← i
            WHILE j ≥ gap AND A[j–gap] > temp:
                A[j] ← A[j–gap]
                j ← j–gap
            A[j] ← temp
```

---

## II. Searching Algorithms

### 1. Linear Search  
Scan until you find the key.  
```
FUNCTION linearSearch(A, n, key):
    FOR i FROM 0 TO n–1:
        IF A[i] == key:
            RETURN i      // found at index i
    RETURN –1             // not found
```

### 2. Binary Search (Iterative)  
On sorted array: repeatedly halve the search interval.  
```
FUNCTION binarySearch(A, n, key):
    low ← 0; high ← n–1
    WHILE low ≤ high:
        mid ← ⌊(low + high)/2⌋
        IF A[mid] == key:
            RETURN mid
        ELSE IF A[mid] < key:
            low ← mid + 1
        ELSE:
            high ← mid - 1
    RETURN –1
```

### 3. Binary Search (Recursive)  
```
FUNCTION binSearchRec(A, low, high, key):
    IF low > high: RETURN –1
    mid ← ⌊(low + high)/2⌋
    IF A[mid] == key: RETURN mid
    IF A[mid] < key:
        RETURN binSearchRec(A, mid+1, high, key)
    ELSE:
        RETURN binSearchRec(A, low, mid-1, key)
```

### 4. Interpolation Search  
Good for uniformly distributed sorted arrays.  
```
FUNCTION interpolationSearch(A, n, key):
    low ← 0; high ← n–1
    WHILE low ≤ high AND key ≥ A[low] AND key ≤ A[high]:
        pos ← low + ⌊((high - low) * (key - A[low])) / (A[high] - A[low])⌋
        IF A[pos] == key:
            RETURN pos
        ELSE IF A[pos] < key:
            low ← pos + 1
        ELSE:
            high ← pos - 1
    RETURN –1
```

### 5. Ternary Search  
Divide into three parts (for unimodal functions). Rarely used on arrays.  
```
FUNCTION ternarySearch(A, low, high, key):
    IF low > high: RETURN –1
    third1 ← low + ⌊(high - low)/3⌋
    third2 ← high - ⌊(high - low)/3⌋
    IF A[third1] == key: RETURN third1
    IF A[third2] == key: RETURN third2
    IF key < A[third1]:
        RETURN ternarySearch(A, low, third1-1, key)
    ELSE IF key > A[third2]:
        RETURN ternarySearch(A, third2+1, high, key)
    ELSE:
        RETURN ternarySearch(A, third1+1, third2-1, key)
```
---
## II. Hashing Algorithms
---

## 1. Hash Table Setup

```  
// Table of size M, array HT[0…M–1]
FUNCTION initHashTable(M):
    FOR i FROM 0 TO M–1:
        HT[i] ← NULL      // for chaining: head pointer or empty list
        // for open addressing: mark slot EMPTY
    size ← 0
```

### 1.1 Common Hash Functions

```  
// Division method
FUNCTION hashDiv(key):
    RETURN key mod M

// Multiplication method
FUNCTION hashMult(key):
    A ← constant (0 < A < 1)
    x ← floor(M * frac(key * A))   // frac(y) = y – floor(y)
    RETURN x
```

---

## 2. Collision Resolution by Chaining

### 2.1 Insert
```
FUNCTION chainInsert(key):
    idx ← hashDiv(key)
    // prepend to list at HT[idx]
    newNode ← Node(key)
    newNode.next ← HT[idx]
    HT[idx] ← newNode
    size ← size + 1
```

### 2.2 Search
```
FUNCTION chainSearch(key):
    idx ← hashDiv(key)
    curr ← HT[idx]
    WHILE curr ≠ NULL:
        IF curr.key == key:
            RETURN TRUE
        curr ← curr.next
    RETURN FALSE
```

### 2.3 Delete
```
FUNCTION chainDelete(key):
    idx ← hashDiv(key)
    prev ← NULL
    curr ← HT[idx]
    WHILE curr ≠ NULL AND curr.key ≠ key:
        prev ← curr
        curr ← curr.next
    IF curr == NULL:
        RETURN FALSE    // not found
    IF prev == NULL:
        HT[idx] ← curr.next
    ELSE:
        prev.next ← curr.next
    DELETE curr
    size ← size – 1
    RETURN TRUE
```

---

## 3. Open Addressing

Slots HT[0…M–1] hold either a key, or EMPTY, or DELETED marker.  

### 3.1 Linear Probing

```  
FUNCTION linProbeHash(key, i):
    RETURN (hashDiv(key) + i) mod M

FUNCTION lpInsert(key):
    FOR i FROM 0 TO M–1:
        idx ← linProbeHash(key, i)
        IF HT[idx] is EMPTY or DELETED:
            HT[idx] ← key
            size ← size + 1
            RETURN TRUE
    ERROR “Table Full”

FUNCTION lpSearch(key):
    FOR i FROM 0 TO M–1:
        idx ← linProbeHash(key, i)
        IF HT[idx] is EMPTY:
            RETURN FALSE     // not present
        IF HT[idx] == key:
            RETURN TRUE
    RETURN FALSE

FUNCTION lpDelete(key):
    FOR i FROM 0 TO M–1:
        idx ← linProbeHash(key, i)
        IF HT[idx] is EMPTY:
            RETURN FALSE
        IF HT[idx] == key:
            HT[idx] ← DELETED
            size ← size – 1
            RETURN TRUE
    RETURN FALSE
```

### 3.2 Quadratic Probing

```  
FUNCTION quadHash(key, i):
    RETURN (hashDiv(key) + c1*i + c2*i*i) mod M
// same insert/search/delete loops as above, using quadHash
```

### 3.3 Double Hashing

```  
FUNCTION dblHash1(key):    // primary
    RETURN key mod M

FUNCTION dblHash2(key):    // secondary, must be ≠0
    RETURN R – (key mod R)  // R < M, often prime

FUNCTION dhHash(key, i):
    RETURN (dblHash1(key) + i * dblHash2(key)) mod M
// same insert/search/delete loops, using dhHash(key,i)
```

---

## 4. Load Factor & Rehashing

```  
LOAD_FACTOR ← size / M

FUNCTION rehash():
    oldHT ← HT
    oldM ← M
    M ← nextPrime(2 * oldM)
    initHashTable(M)
    FOR each slot in oldHT:
        IF slot holds a valid key:
            INSERT key into new HT (using chosen scheme)
```

- **When to rehash?**  
  - Chaining: when LOAD_FACTOR > α_max  
  - Open addressing: when LOAD_FACTOR > β_max  

---

## 5. Universal Hashing (Theory)

Choose hash function at random from a family H to guarantee expected O(1) per op.  

```  
// Example: h_{a,b}(key) = ((a*key + b) mod p) mod M
// a ∈ [1…p–1], b ∈ [0…p–1], p prime > universe size
```

---
---

### 5. .......Tree.....

---

## 1. Binary Tree Basics

Assume  
```  
STRUCT Node:  
    data  
    left, right  
```  

### 1.1 Tree Traversals  
```  
FUNCTION preorder(node):              // Root, Left, Right
    IF node == NULL: RETURN
    PROCESS(node.data)
    preorder(node.left)
    preorder(node.right)

FUNCTION inorder(node):               // Left, Root, Right
    IF node == NULL: RETURN
    inorder(node.left)
    PROCESS(node.data)
    inorder(node.right)

FUNCTION postorder(node):             // Left, Right, Root
    IF node == NULL: RETURN
    postorder(node.left)
    postorder(node.right)
    PROCESS(node.data)

FUNCTION levelOrder(root):            // BFS
    IF root == NULL: RETURN
    CREATE empty queue Q
    enqueue(Q, root)
    WHILE NOT isEmpty(Q):
        node ← dequeue(Q)
        PROCESS(node.data)
        IF node.left ≠ NULL: enqueue(Q, node.left)
        IF node.right ≠ NULL: enqueue(Q, node.right)
```

### 1.2 Height, Node Count, Leaf Count  
```  
FUNCTION height(node):
    IF node == NULL: RETURN 0
    RETURN 1 + max(height(node.left), height(node.right))

FUNCTION countNodes(node):
    IF node == NULL: RETURN 0
    RETURN 1 + countNodes(node.left) + countNodes(node.right)

FUNCTION countLeaves(node):
    IF node == NULL: RETURN 0
    IF node.left == NULL AND node.right == NULL: RETURN 1
    RETURN countLeaves(node.left) + countLeaves(node.right)
```

### 1.3 Mirror, Find LCA  
```  
FUNCTION mirror(node):
    IF node == NULL: RETURN
    SWAP(node.left, node.right)
    mirror(node.left)
    mirror(node.right)

FUNCTION findLCA(root, p, q):
    IF root == NULL OR root.data == p OR root.data == q:
        RETURN root
    leftLCA  ← findLCA(root.left, p, q)
    rightLCA ← findLCA(root.right, p, q)
    IF leftLCA ≠ NULL AND rightLCA ≠ NULL: RETURN root
    RETURN (leftLCA ≠ NULL ? leftLCA : rightLCA)
```

---

## 2. Binary Search Tree (BST)

### 2.1 Search  
```  
FUNCTION bstSearch(node, key):
    IF node == NULL: RETURN FALSE
    IF key == node.data: RETURN TRUE
    ELSE IF key < node.data: RETURN bstSearch(node.left, key)
    ELSE: RETURN bstSearch(node.right, key)
```

### 2.2 Insert  
```  
FUNCTION bstInsert(root, key):
    IF root == NULL:
        RETURN new Node(key)
    IF key < root.data:
        root.left  ← bstInsert(root.left, key)
    ELSE IF key > root.data:
        root.right ← bstInsert(root.right, key)
    // duplicates ignored
    RETURN root
```

### 2.3 Delete  
```  
FUNCTION bstDelete(root, key):
    IF root == NULL: RETURN NULL
    IF key < root.data:
        root.left  ← bstDelete(root.left, key)
    ELSE IF key > root.data:
        root.right ← bstDelete(root.right, key)
    ELSE:
        // node found
        IF root.left == NULL:
            RETURN root.right
        ELSE IF root.right == NULL:
            RETURN root.left
        // two children: replace with inorder successor
        succ ← minNode(root.right)
        root.data ← succ.data
        root.right ← bstDelete(root.right, succ.data)
    RETURN root

FUNCTION minNode(node):
    WHILE node.left ≠ NULL:
        node ← node.left
    RETURN node
```

---

## 3. AVL Tree (Self-Balancing BST)

Each node stores `height`.

```  
FUNCTION getHeight(n):  
    RETURN (n==NULL ? 0 : n.height)

FUNCTION getBalance(n):  
    RETURN getHeight(n.left) – getHeight(n.right)

// Right Rotation (for Left-Left case)
FUNCTION rotateRight(y):
    x ← y.left
    T2 ← x.right
    x.right ← y
    y.left  ← T2
    y.height ← 1 + max(getHeight(y.left), getHeight(y.right))
    x.height ← 1 + max(getHeight(x.left), getHeight(x.right))
    RETURN x

// Left Rotation (for Right-Right case)
FUNCTION rotateLeft(x):
    y ← x.right
    T2 ← y.left
    y.left  ← x
    x.right ← T2
    x.height ← 1 + max(getHeight(x.left), getHeight(x.right))
    y.height ← 1 + max(getHeight(y.left), getHeight(y.right))
    RETURN y

FUNCTION avlInsert(node, key):
    // 1. Standard BST insert
    IF node == NULL:
        RETURN new Node(key)
    IF key < node.data:
        node.left  ← avlInsert(node.left, key)
    ELSE IF key > node.data:
        node.right ← avlInsert(node.right, key)
    ELSE:
        RETURN node   // duplicates

    // 2. Update height & balance
    node.height ← 1 + max(getHeight(node.left), getHeight(node.right))
    balance ← getBalance(node)

    // 3. Rebalance
    // Left-Left
    IF balance > 1 AND key < node.left.data:
        RETURN rotateRight(node)
    // Right-Right
    IF balance < –1 AND key > node.right.data:
        RETURN rotateLeft(node)
    // Left-Right
    IF balance > 1 AND key > node.left.data:
        node.left ← rotateLeft(node.left)
        RETURN rotateRight(node)
    // Right-Left
    IF balance < –1 AND key < node.right.data:
        node.right ← rotateRight(node.right)
        RETURN rotateLeft(node)

    RETURN node
```

*(Deletion in AVL is similar: BST delete + rebalance on the way up.)*

---

## 4. Binary Heap (Min- or Max-Heap)

Stored in array `H[0…n–1]`, parent/child indices:  
```
parent(i) = (i–1)//2  
left(i)   = 2*i + 1  
right(i)  = 2*i + 2
```

### 4.1 Heapify (Down)  
```  
FUNCTION heapify(H, n, i):
    largest ← i
    l ← left(i);  r ← right(i)
    IF l < n AND H[l] > H[largest]:
        largest ← l
    IF r < n AND H[r] > H[largest]:
        largest ← r
    IF largest ≠ i:
        SWAP H[i], H[largest]
        heapify(H, n, largest)
```

### 4.2 Build-Heap  
```  
FUNCTION buildMaxHeap(H, n):
    FOR i FROM ⌊n/2⌋–1 DOWNTO 0:
        heapify(H, n, i)
```

### 4.3 Insert (Up-heap)  
```  
FUNCTION heapInsert(H, key):
    n ← size(H)
    H[n] ← key
    i ← n
    WHILE i > 0 AND H[parent(i)] < H[i]:
        SWAP H[parent(i)], H[i]
        i ← parent(i)
```

### 4.4 Extract-Max  
```  
FUNCTION extractMax(H):
    IF size(H) == 0: ERROR
    maxVal ← H[0]
    H[0] ← H[last]
    REMOVE last element
    heapify(H, size(H), 0)
    RETURN maxVal
```

---

## 5. Trie (Prefix Tree)

Each node has `children[alphabetSize]`, `isEndOfWord`.

```  
STRUCT TrieNode:
    children[0…25]    // or map
    isEndOfWord = FALSE

FUNCTION trieInsert(root, key):
    node ← root
    FOR each ch IN key:
        idx ← ch – 'a'
        IF node.children[idx] == NULL:
            node.children[idx] ← new TrieNode()
        node ← node.children[idx]
    node.isEndOfWord ← TRUE

FUNCTION trieSearch(root, key):
    node ← root
    FOR ch IN key:
        idx ← ch – 'a'
        IF node.children[idx] == NULL: RETURN FALSE
        node ← node.children[idx]
    RETURN node.isEndOfWord

FUNCTION trieDelete(node, key, depth = 0):
    IF node == NULL: RETURN NULL
    IF depth == length(key):
        IF node.isEndOfWord: node.isEndOfWord ← FALSE
        IF all children of node are NULL:
            DELETE node
            node ← NULL
        RETURN node
    idx ← key[depth] – 'a'
    node.children[idx] ← trieDelete(node.children[idx], key, depth+1)
    IF node.isEndOfWord == FALSE AND all children NULL:
        DELETE node
        node ← NULL
    RETURN node
```

---


### 6. .....Graph.....
---

## 1. Graph Representations

1. **Adjacency Matrix**  
   - **Space:** O(V²)  
   - `G[u][v] = 1` if edge u→v exists, else 0.

2. **Adjacency List**  
   - **Space:** O(V + E)  
   - `adj[u]` is a list of all neighbors of u.

---

## 2. Traversal

### 2.1 Breadth-First Search (BFS)  
**Use:** Shortest paths in unweighted graphs, level order.  
```
FUNCTION BFS(start):
    FOR each v: visited[v] ← FALSE
    CREATE empty queue Q
    visited[start] ← TRUE
    enqueue(Q, start)
    WHILE NOT isEmpty(Q):
        u ← dequeue(Q)
        PROCESS(u)
        FOR each v IN adj[u]:
            IF NOT visited[v]:
                visited[v] ← TRUE
                enqueue(Q, v)
```

### 2.2 Depth-First Search (DFS)  
**Use:** Connectivity, cycle detection, ordering.  
```
FUNCTION DFS(u):
    visited[u] ← TRUE
    PROCESS(u)
    FOR each v IN adj[u]:
        IF NOT visited[v]:
            DFS(v)

FUNCTION DFS_Full():
    FOR each v: visited[v] ← FALSE
    FOR each v:
        IF NOT visited[v]:
            DFS(v)
```

---

## 3. Cycle Detection

### 3.1 In Undirected Graph  
```
FUNCTION hasCycleUndir(u, parent):
    visited[u] ← TRUE
    FOR v IN adj[u]:
        IF NOT visited[v]:
            IF hasCycleUndir(v, u): RETURN TRUE
        ELSE IF v ≠ parent:
            RETURN TRUE
    RETURN FALSE

FUNCTION detectCycleUndir():
    FOR each v: visited[v] ← FALSE
    FOR each v:
        IF NOT visited[v] AND hasCycleUndir(v, –1):
            RETURN TRUE
    RETURN FALSE
```

### 3.2 In Directed Graph (White-Gray-Black)  
```
FUNCTION hasCycleDir(u):
    color[u] ← GRAY
    FOR v IN adj[u]:
        IF color[v] == GRAY: RETURN TRUE
        IF color[v] == WHITE AND hasCycleDir(v): RETURN TRUE
    color[u] ← BLACK
    RETURN FALSE

FUNCTION detectCycleDir():
    FOR each v: color[v] ← WHITE
    FOR each v:
        IF color[v] == WHITE AND hasCycleDir(v):
            RETURN TRUE
    RETURN FALSE
```

---

## 4. Topological Sort (Directed Acyclic Graph)

```
FUNCTION topoDFS(u):
    visited[u] ← TRUE
    FOR v IN adj[u]:
        IF NOT visited[v]:
            topoDFS(v)
    PUSH u ONTO stack

FUNCTION topologicalSort():
    FOR each v: visited[v] ← FALSE
    CREATE empty stack S
    FOR each v:
        IF NOT visited[v]:
            topoDFS(v)
    WHILE NOT isEmpty(S):
        PRINT pop(S)
```

*(Or Kahn’s algorithm using in-degree queue.)*

---

## 5. Connected Components

### 5.1 Undirected Graph  
```
FUNCTION countComponents():
    FOR each v: visited[v] ← FALSE
    count ← 0
    FOR each v:
        IF NOT visited[v]:
            count ← count + 1
            DFS(v)
    RETURN count
```

### 5.2 Strongly Connected Components (Directed)

#### Kosaraju’s Algorithm  
1. Run DFS on original graph, push vertices onto stack in finish order.  
2. Reverse all edges.  
3. Pop from stack and DFS on reversed graph; each DFS tree is one SCC.

```
FUNCTION kosaraju(V):
    // 1. Order by finish time
    FOR v: visited[v] ← FALSE
    FOR v:
        IF NOT visited[v]: dfs1(v)
    // 2. Transpose graph
    build adjT as transpose of adj
    // 3. Assign components
    FOR v: visited[v] ← FALSE
    WHILE stack NOT empty:
        u ← pop(stack)
        IF NOT visited[u]:
            dfs2(u)    // on adjT, mark all reachable as one SCC
            PRINT “-- end of one SCC --”
```

---

## 6. Minimum Spanning Tree (Undirected, Connected)

### 6.1 Kruskal’s Algorithm  
```
SORT edges by weight ascending
MAKE-SET for each vertex
mstWeight ← 0
FOR each edge (u,v,w) in sorted edges:
    IF FIND(u) ≠ FIND(v):
        UNION(u,v)
        ADD w to mstWeight
RETURN mstWeight
```

### 6.2 Prim’s Algorithm (Using Min-Heap)  
```
KEY[v] ← ∞, inMST[v] ← FALSE
KEY[start] ← 0
PUSH (0, start) INTO minHeap
WHILE minHeap NOT empty:
    (k, u) ← extractMin(minHeap)
    IF inMST[u]: CONTINUE
    inMST[u] ← TRUE
    FOR (v, w) IN adj[u]:
        IF NOT inMST[v] AND w < KEY[v]:
            KEY[v] ← w
            parent[v] ← u
            PUSH (KEY[v], v) INTO minHeap
```

---

## 7. Single-Source Shortest Paths

### 7.1 Dijkstra’s Algorithm (Nonnegative Weights)  
```
DIST[v] ← ∞ for all v; DIST[src] ← 0
PUSH (0, src) INTO minHeap
WHILE minHeap NOT empty:
    (d, u) ← extractMin(minHeap)
    IF d > DIST[u]: CONTINUE
    FOR (v, w) IN adj[u]:
        IF DIST[u] + w < DIST[v]:
            DIST[v] ← DIST[u] + w
            PUSH (DIST[v], v) INTO minHeap
```

### 7.2 Bellman-Ford Algorithm (Works with Negative Weights)  
```
DIST[v] ← ∞; DIST[src] ← 0
FOR i FROM 1 TO V–1:
    FOR each edge (u,v,w):
        IF DIST[u] + w < DIST[v]:
            DIST[v] ← DIST[u] + w
// Check for negative cycles
FOR each (u,v,w):
    IF DIST[u] + w < DIST[v]:
        ERROR “Negative cycle detected”
```

---

## 8. All-Pairs Shortest Paths

### Floyd-Warshall Algorithm  
```
LET dist be V×V matrix initialized:
    dist[u][v] ← w(u,v) if edge, else ∞; dist[v][v] ← 0
FOR k FROM 1 TO V:
    FOR i FROM 1 TO V:
        FOR j FROM 1 TO V:
            IF dist[i][k] + dist[k][j] < dist[i][j]:
                dist[i][j] ← dist[i][k] + dist[k][j]
```

---

## 9. Network Flow (Optional / Advanced)

### Edmonds–Karp (Ford–Fulkerson with BFS)  
```
maxFlow ← 0
WHILE there is augmenting path P from s to t in residual graph:
    flow ← min residual capacity along P
    FOR each edge (u,v) in P:
        decrease residual[u][v] by flow
        increase residual[v][u] by flow
    maxFlow ← maxFlow + flow
RETURN maxFlow
```

---

## 10. Additional Topics

- **Bipartite Check** via BFS/DFS coloring (2-colorable iff no odd cycle).  
- **Articulation Points & Bridges** via DFS time-stamps (Tarjan’s algorithms).  
- **Graph Coloring (Greedy Heuristic).**

---

### Thank You...
