class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3, 0);

        for (int n : nums) {
            colors[n]++;
        }

        int i = 0, j = 0;
        while (i < nums.size()) {
            while (i < nums.size() && j < colors.size() && colors[j]) {
                nums[i++] = j;
                colors[j]--;
            }
            j++;
        }
    }
};