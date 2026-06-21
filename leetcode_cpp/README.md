# LeetCode C++ Solutions (130 Problems)

Every problem is a **complete, standalone, compilable `.cpp` file** — not just a bare
function. Each file includes:
- The problem statement as a comment
- A `class Solution` (or relevant design class) with the algorithm
- A `main()` function with sample test cases and printed output, so you can
  compile and run each file directly to see it work

All 130 files were compiled with `g++ -std=c++17` and run to confirm correct output
against known expected results.

## How to compile and run any solution

```bash
g++ -std=c++17 -O2 -o solution Array/01_two_sum.cpp
./solution
```

## Folder structure (organized by topic, matching your list)

| Folder | Count | Problems |
|---|---|---|
| `Array/` | 18 | #1–18 |
| `DP/` | 16 | #19–34 |
| `Graph/` | 11 | #35–45 |
| `Hashing/` | 4 | #46–49 |
| `Interval/` | 6 | #50–55 |
| `LinkedList/` | 10 | #56–65 |
| `Matrix/` | 7 | #66–72 |
| `Design/` | 5 | #73–77 |
| `Sorting/` | 5 | #78–82 |
| `String/` | 15 | #83–97 |
| `Stack/` | 5 | #98–102 |
| `Tree/` | 17 | #103–119 |
| `Heap/` | 6 | #120–125 |
| `BitManipulation/` | 5 | #126–130 |

**Total: 130 problems**

## Notes

- Files are numbered and named to match your original list (e.g.
  `01_two_sum.cpp`, `46_roman_to_integer.cpp`).
- Where the original LeetCode problem requires a custom class/data structure
  (e.g. linked list, binary tree, Trie), the struct/class is defined in the
  same file so it compiles standalone.
- "Premium" problems (Alien Dictionary, Graph Valid Tree, Meeting Rooms I/II,
  Number of Connected Components, Encode/Decode Strings) are implemented
  using the standard, widely-known problem statement since the official
  LeetCode page isn't publicly accessible.
