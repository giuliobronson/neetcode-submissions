class Solution {
public:
    int getWater(int i, int l, int r, vector<int>& height) {
        return min(l, r) - height[i];
    }

    int trap(vector<int>& height) {
        vector<int> preffix(height.size());
        vector<int> suffix(height.size());
        int a = 0;
        
        preffix[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            preffix[i] = max(height[i], preffix[i - 1]);
        }

        suffix[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            suffix[i] = max(height[i], suffix[i + 1]);
        }

        for (int i = 0; i < height.size(); i++) {
            a += getWater(i, preffix[i], suffix[i], height);
        }

        return a;
    }
};
