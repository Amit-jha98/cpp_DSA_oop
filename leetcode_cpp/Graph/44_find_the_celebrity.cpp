// 44. Find the Celebrity
// A celebrity is known by everyone but knows no one. Find the celebrity's
// label using only the knows(a, b) API, or -1 if none exists.
// Theory / Approach:
// First find a candidate: if candidate knows i, candidate cannot be celebrity,
// so i becomes the candidate. Then verify the candidate against everyone.
//
// Why this works:
// The elimination pass discards one impossible person per comparison. The final
// candidate is the only possible celebrity and must satisfy both conditions.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

// Simulated "knows" relation for demonstration purposes.
vector<vector<bool>> knowsMatrix;
bool knows(int a, int b) { return knowsMatrix[a][b]; }

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) candidate = i;
        }
        for (int i = 0; i < n; ++i) {
            if (i == candidate) continue;
            if (knows(candidate, i) || !knows(i, candidate)) return -1;
        }
        return candidate;
    }
};

int main() {
    // Person 1 is the celebrity: persons 0, 2, 3 all know 1, and 1 knows no one.
    int n = 4;
    knowsMatrix = {
        {false, true,  false, false},
        {false, false, false, false},
        {true,  true,  false, true},
        {false, true,  false, false}
    };
    Solution sol;
    cout << "Celebrity: " << sol.findCelebrity(n) << " (expected 1)" << endl;
    return 0;
}
