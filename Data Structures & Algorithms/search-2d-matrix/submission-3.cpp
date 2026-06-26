class Solution {
public:
    pair<int, int> getCoordinates(int t, int n) {
        int i = t % n;
        int j = t / n;

        return {i, j};
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = n * m - 1; 

        while (l <= r) {
            int t = (l + r) / 2;
            auto [i, j] = getCoordinates(t, n);

            cout << t << '\n';
            cout << i << " " << j << '\n';

            if (matrix[j][i] > target) {
                r = t - 1;
            }
            else if (matrix[j][i] < target) {
                l = t + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
