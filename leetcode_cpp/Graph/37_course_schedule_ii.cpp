// 37. Course Schedule II
// Return a valid ordering of courses to finish all courses, or empty
// array if impossible.
// Theory / Approach:
// Build the prerequisite graph and run Kahn's topological sort. Append courses
// as their indegree becomes 0.
//
// Why this works:
// A topological order always places prerequisites before dependent courses. If a
// cycle exists, no full ordering can include every course.
//
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (indeg[i] == 0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }
        if ((int)order.size() != numCourses) return {};
        return order;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> prereq = {{1,0},{2,0},{3,1},{3,2}};
    auto order = sol.findOrder(4, prereq);
    cout << "numCourses=4, prerequisites=[[1,0],[2,0],[3,1],[3,2]]\nOrder: [";
    for (int i = 0; i < (int)order.size(); ++i) cout << order[i] << (i+1<(int)order.size()?",":"");
    cout << "]\n";
    return 0;
}
