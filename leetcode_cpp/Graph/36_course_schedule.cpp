// 36. Course Schedule
// Given numCourses and prerequisites, determine if it's possible to finish
// all courses (i.e., the prerequisite graph has no cycle).
// Theory / Approach:
// Model courses as a directed graph and use topological sorting. Courses with
// indegree 0 can be taken first; removing them may unlock more courses.
//
// Why this works:
// If all courses can be removed, there is no cycle. Any remaining course must
// belong to a dependency cycle, making completion impossible.
//
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (indeg[i] == 0) q.push(i);
        int visited = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ++visited;
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }
        return visited == numCourses;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> prereq = {{1,0}};
    cout << boolalpha;
    cout << "numCourses=2, prerequisites=[[1,0]] -> " << sol.canFinish(2, prereq) << endl;
    vector<vector<int>> prereq2 = {{1,0},{0,1}};
    cout << "numCourses=2, prerequisites=[[1,0],[0,1]] -> " << sol.canFinish(2, prereq2) << endl;
    return 0;
}
