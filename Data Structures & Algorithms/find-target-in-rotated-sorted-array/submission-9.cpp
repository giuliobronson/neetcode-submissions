class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1; 
        
        while (l < r) {
            int m = (l + r) / 2;

            if (nums[m] > nums[r]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        return r;
    }

    int search(vector<int>& nums, int target) {
        int i = findMin(nums);

        auto it1 = lower_bound(nums.begin(), nums.begin() + i, target);
        auto it2 = lower_bound(nums.begin() + i, nums.end(), target);

        if (it1 != nums.end() && *it1 == target) {
            return it1 - nums.begin();
        }
        else if (it2 != nums.end() && *it2 == target) {
            return it2 - nums.begin();
        }

        return -1;
    }
};
