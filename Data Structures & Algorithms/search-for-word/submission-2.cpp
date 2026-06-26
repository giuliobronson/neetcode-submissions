class Solution {
public:
    set<pair<int, int>> visited;

    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int p) {
        if (p >= word.length()) return true;

        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0) return false;

        if (visited.count({i, j})) return false;

        if (word[p] == board[i][j]) {
            visited.insert({i, j});

            if (backtrack(board, word, i + 1, j, p + 1) ||
                backtrack(board, word, i - 1, j, p + 1) ||
                backtrack(board, word, i, j + 1, p + 1) ||
                backtrack(board, word, i, j - 1, p + 1)) {
                return true;
            }

            visited.erase({i, j});
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};
