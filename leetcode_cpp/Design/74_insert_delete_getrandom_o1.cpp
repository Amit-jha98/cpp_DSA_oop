// 74. Insert Delete GetRandom O(1)
// Design a data structure supporting insert, remove, and getRandom,
// each in average O(1) time.
// Theory / Approach:
// Store values in a vector and keep a hash map from value to vector index.
// Remove by swapping the target with the last element, then pop.
//
// Why this works:
// The vector gives O(1) random access for getRandom, and the map gives O(1)
// lookup for insert/delete positions.
//
// Time Complexity: O(1) average per operation
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() { srand(time(nullptr)); }

    bool insert(int val) {
        if (idx.count(val)) return false;
        idx[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!idx.count(val)) return false;
        int i = idx[val];
        int last = nums.back();
        nums[i] = last;
        idx[last] = i;
        nums.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int,int> idx; // value -> index in nums
};

int main() {
    RandomizedSet rs;
    cout << boolalpha;
    cout << "insert(1) -> " << rs.insert(1) << endl;
    cout << "remove(2) -> " << rs.remove(2) << endl;
    cout << "insert(2) -> " << rs.insert(2) << endl;
    cout << "getRandom() -> " << rs.getRandom() << endl;
    cout << "remove(1) -> " << rs.remove(1) << endl;
    cout << "insert(2) -> " << rs.insert(2) << endl; // already present
    cout << "getRandom() -> " << rs.getRandom() << endl;
    return 0;
}
