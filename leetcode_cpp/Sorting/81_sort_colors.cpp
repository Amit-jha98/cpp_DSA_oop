// 81. Sort Colors
// Sort an array of 0s, 1s, and 2s in place (Dutch National Flag problem).
// Theory / Approach:
// Use the Dutch National Flag algorithm with three regions: 0s on the left, 2s
// on the right, and unknown values in the middle.
//
// Why this works:
// Each swap places a 0 or 2 into its final region, while 1s naturally remain in
// the middle.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = (int)nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                ++low; ++mid;
            } else if (nums[mid] == 1) {
                ++mid;
            } else {
                swap(nums[mid], nums[high]);
                --high;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    cout << "Sorted: [";
    for (int i = 0; i < (int)nums.size(); ++i) cout << nums[i] << (i+1<(int)nums.size()?",":"");
    cout << "]\n";
    return 0;
}
