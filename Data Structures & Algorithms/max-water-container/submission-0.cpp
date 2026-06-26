class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights.size(); j++) {
                result = max(min(heights[i], heights[j]) * (j - i), result);
            }
        }

        return result;
    }
};
