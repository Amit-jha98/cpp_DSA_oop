// 78. Merge Sorted Array
// Merge nums2 into nums1 as one sorted array, in place. nums1 has length
// m+n, with the last n elements set to 0 and ignored.
// Theory / Approach:
// Merge from the back of nums1 using pointers at the ends of the initialized
// portion of nums1 and nums2.
//
// Why this works:
// Filling from the back avoids overwriting unused nums1 values. The largest
// remaining value always belongs at the current write position.
//
// Time Complexity: O(m + n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    sol.merge(nums1, 3, nums2, 3);
    cout << "Merged: [";
    for (int i = 0; i < (int)nums1.size(); ++i) cout << nums1[i] << (i+1<(int)nums1.size()?",":"");
    cout << "]\n";
    return 0;
}
