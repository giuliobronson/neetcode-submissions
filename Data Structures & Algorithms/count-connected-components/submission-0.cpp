class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int u) {
        if (visited[u]) return;

        visited[u] = true;

        for (int v : adj[u]) {
            dfs(adj, visited, v);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < visited.size(); i++) {
            if (visited[i]) continue;
            dfs(adj, visited, i);
            count++;
        }

        return count;
    }
};
