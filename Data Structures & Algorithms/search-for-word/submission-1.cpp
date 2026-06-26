class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j, int p) {
        if (p >= word.length()) return true;

        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0) return false;

        if (visited[i][j]) return false;

        if (word[p] == board[i][j]) {
            visited[i][j] = true;

            if (backtrack(board, word, visited, i + 1, j, p + 1) ||
                backtrack(board, word, visited, i - 1, j, p + 1) ||
                backtrack(board, word, visited, i, j + 1, p + 1) ||
                backtrack(board, word, visited, i, j - 1, p + 1)) {
                return true;
            }

            visited[i][j] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, visited, i, j, 0)) return true;
            }
        }

        return false;
    }
};
