class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> counting = {};

        for (int i = 0; i < nums.size(); i++) {
            if (!counting.count(nums[i])) {
                counting[nums[i]] = 1;
            }
            else {
                counting[nums[i]]++;
            }
        }

        for (auto& p : counting) {
            if (p.second > 1) {
                return true;
            }
        }
        return false;
    }
};