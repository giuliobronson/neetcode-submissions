class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> col, row, d, D;

    bool isValidPosition(int i, int j) {
        if (col.count(j) || row.count(i) || d.count(i + j) || D.count(i - j)) {
            return false;
        }

        return true;
    }

    void insertQueen(int i, int j) {
        col.insert(j); row.insert(i); d.insert(i + j); D.insert(i - j);
    }

    void removeQueen(int i, int j) {
        col.erase(j); row.erase(i); d.erase(i + j); D.erase(i - j);
    }

    void backtrack(vector<string>& board, int i, int j, int n) {
        if (n <= 0) {
            res.push_back(board);
            return;
        }

        if (j >= board[0].size()) {
            i++; j = 0;
        }

        if (i >= board.size()) return;

        if(isValidPosition(i, j)) {
            insertQueen(i, j); board[i][j] = 'Q';
            backtrack(board, i + 1, 0, n - 1);
            removeQueen(i, j); board[i][j] = '.';
        }

        backtrack(board, i, j + 1,  n);
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, 0, n);
        return res;
    }
};
