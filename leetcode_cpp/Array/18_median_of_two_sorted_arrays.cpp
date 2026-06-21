// 18. Median of Two Sorted Arrays
// Find the median of two sorted arrays in O(log(min(m,n))).
// Theory / Approach:
// Binary search the partition position in the smaller array. The correct
// partition has all left-side values <= all right-side values across both arrays.
//
// Why this works:
// The median depends only on the largest value on the left partition and the
// smallest value on the right partition. Binary search fixes invalid partitions.
//
// Time Complexity: O(log min(m, n))
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int lo = 0, hi = m;
        int half = (m + n + 1) / 2;
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2; // partition in nums1
            int j = half - i;           // partition in nums2

            int leftA = (i == 0) ? INT_MIN : nums1[i-1];
            int rightA = (i == m) ? INT_MAX : nums1[i];
            int leftB = (j == 0) ? INT_MIN : nums2[j-1];
            int rightB = (j == n) ? INT_MAX : nums2[j];

            if (leftA <= rightB && leftB <= rightA) {
                if ((m + n) % 2 == 1) return max(leftA, leftB);
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            } else if (leftA > rightB) {
                hi = i - 1;
            } else {
                lo = i + 1;
            }
        }
        return 0.0; // unreachable for valid input
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    cout << "Input: nums1=[1,3], nums2=[2]\n";
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = {1,2};
    vector<int> nums4 = {3,4};
    cout << "Input: nums1=[1,2], nums2=[3,4]\n";
    cout << "Median: " << sol.findMedianSortedArrays(nums3, nums4) << endl;
    return 0;
}
