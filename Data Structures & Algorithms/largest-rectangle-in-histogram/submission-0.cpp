class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;

        for (int i = 0; i < heights.size(); i++) {
            int l = i, r = i;
            while (l >= 0 && heights[i] <= heights[l]) l--;
            while (r < heights.size() && heights[i] <= heights[r]) r++;
            area = max(area, heights[i] * (r - l - 1));
        }

        return area;
    }
};
