class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> res, indegree(numCourses, 0);
        stack<int> s;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1], v = prerequisites[i][0];
            adj[u].push_back(v); indegree[v]++;
        } 

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) s.push(i);
        }

        while (!s.empty()) {
            int u = s.top(); s.pop();
            
            res.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) s.push(v);
            }

            numCourses--;
        }

        cout << numCourses << '\n';

        if (!numCourses) return res;
        return {};
    }
};