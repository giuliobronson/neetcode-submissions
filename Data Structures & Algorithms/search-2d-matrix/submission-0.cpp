class Solution {
public:
    vector<int> flatteningMatrix(vector<vector<int>>& matrix) {
        vector<int> result;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                result.push_back(matrix[i][j]);
            }
        }

        return result;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> result = flatteningMatrix(matrix);

        return binary_search(result.begin(), result.end(), target);
    }
};
