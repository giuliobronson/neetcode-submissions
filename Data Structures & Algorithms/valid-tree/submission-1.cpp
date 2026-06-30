class Solution {
public:


    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int u, int p) {
        if (visited[u]) return false;

        visited[u] = true;

        for (int v : adj[u]) {
            if (v == p) continue;
            if (!dfs(adj, visited, v, u)) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (!dfs(adj, visited, 0, -1)) return false;

        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) return false;
        }

        return true;
    }
};
