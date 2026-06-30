class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool edge = true;

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;

        if (board[i][j] == 'X' || visited[i][j]) return;

        visited[i][j] = true;

        board[i][j] = edge ? 'O' : 'X';

        for (auto& dir : dirs) {
            dfs(board, visited, i + dir.first, j + dir.second);
        }
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            dfs(board, visited, i, 0);
            dfs(board, visited, i, board[0].size() - 1);
        }

        for (int j = 0; j < board[0].size(); j++) {
            dfs(board, visited, 0, j);
            dfs(board, visited, board.size() - 1, j);
        }

        edge = false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'X' || visited[i][j]) continue;
                board[i][j] = 'X';
            }
        }
    }
};
