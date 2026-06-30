class Solution {
public:
    bool findCycle(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& path, int u) {
        if (path[u]) return true;

        if (visited[u]) return false;

        visited[u] = true; path[u] = true;

        for (int v : adj[u]) {
            if(findCycle(adj, visited, path, v)) {
                return true;
            }
        }

        path[u] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false), path(numCourses, false);
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        for (int u = 0; u < numCourses; u++) {
            if (visited[u]) continue;
            if (findCycle(adj, visited, path, u)) return false;
        }

        return true;
    }
};
