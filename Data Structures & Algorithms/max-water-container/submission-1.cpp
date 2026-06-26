class Solution {
public:
    int calculateArea(vector<int>& heights, int i, int j) {
        return min(heights[i], heights[j]) * (j - i);
    }

    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int a = calculateArea(heights, i, j);

        while (i < j) {
            heights[i] < heights[j] ? i++ : j--;
            a = max(calculateArea(heights, i, j), a);
        }

        return a;
    }
};
