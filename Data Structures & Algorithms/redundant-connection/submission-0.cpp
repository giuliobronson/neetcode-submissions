class Solution {
public:

    bool findCycle(vector<vector<int>>& adj, vector<bool>& visited, int u, int p) {
        if (visited[u]) return true;
        
        visited[u] = true; 

        for (int v : adj[u]) {
            if (v == p) continue;
            if (findCycle(adj, visited, v, u)) {
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<bool> visited(edges.size() + 1, false);

            if (findCycle(adj, visited, u, -1)) {
                return {u, v};
            }
        }

        return {};
    }
};
