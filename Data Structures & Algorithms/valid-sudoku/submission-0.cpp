class Solution {
public:
    bool isValidVector(vector<char>& v) {
        unordered_set<char> s = {};

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == '.') continue;
            if(s.count(v[i])) {
                return false;
            }
            s.insert(v[i]);
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // check de rows
        for (int i = 0; i < 9; i++) {
            if (!isValidVector(board[i])) {
                return false;
            }
        }

        // check the columns
        for (int i = 0; i < 9; i++) {
            vector<char> column;
            for (int j = 0; j < 9; j++) {
                column.push_back(board[j][i]);
            }
            if (!isValidVector(column)) {
                return false;
            }
        }

        // check the sub-boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<char> box;
                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                        box.push_back(board[i + a][j + b]);
                    }
                }
                if (!isValidVector(box)) {
                    return false;
                }
            }
        }

        return true;
    }
};
