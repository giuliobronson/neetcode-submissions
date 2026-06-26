class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        int n = heights.size();
        vector<int> lbound(n, -1);
        vector<int> rbound(n,  n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                rbound[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                lbound[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            area = max(area, heights[i] * (rbound[i] - lbound[i] - 1));
        }

        return area;
        
    }
};
