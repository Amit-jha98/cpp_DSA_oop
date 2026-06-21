// 120. High Five
// Given scores of students, return the average of the top five scores
// for each student, ordered by student id.
// Theory / Approach:
// Keep each student's top five scores in a min-heap. When more than five scores
// are present, remove the smallest.
//
// Why this works:
// A size-five min-heap always retains the five largest scores seen for that
// student, making the final average direct.
//
// Time Complexity: O(n log 5)
// Space Complexity: O(number of students)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> minHeaps; // id -> min-heap of top 5
        for (auto& item : items) {
            int id = item[0], score = item[1];
            auto& heap = minHeaps[id];
            heap.push(score);
            if ((int)heap.size() > 5) heap.pop();
        }
        vector<vector<int>> res;
        for (auto& [id, heap] : minHeaps) {
            int sum = 0, count = heap.size();
            while (!heap.empty()) { sum += heap.top(); heap.pop(); }
            res.push_back({id, sum / count});
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> items = {
        {1,91},{1,92},{2,93},{2,97},{1,60},{2,77},{1,65},
        {1,87},{1,100},{2,100},{2,76}
    };
    auto res = sol.highFive(items);
    for (auto& r : res) cout << "id=" << r[0] << " avg=" << r[1] << endl;
    return 0;
}
