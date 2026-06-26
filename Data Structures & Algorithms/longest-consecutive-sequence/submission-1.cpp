class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> successor = {};
        vector<int> beginner;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            successor.insert(nums[i] + 1);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!successor.count(nums[i])) {
                beginner.push_back(nums[i]);
            }
        }

        for (int i = 0; i < beginner.size(); i++) {
            int len = 0;
            int init = beginner[i];
            while (successor.count(++init)) {
                len++;
            }
            result = max(len, result);
        }

        return result;
    }
};
