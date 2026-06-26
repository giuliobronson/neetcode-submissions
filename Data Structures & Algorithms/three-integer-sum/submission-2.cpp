class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        
        for (int k = 0; k < nums.size(); k++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            
            int target = -nums[k], i = k + 1, j = nums.size() - 1;

            while (i < j) {
                if (nums[i] + nums[j] > target) {
                    j--;
                }
                else if (nums[i] + nums[j] < target){
                    i++;
                }
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (i < j && nums[i] == nums[i + 1]) i++;
                    while (i < j && nums[j] == nums[j - 1]) j--;
                    i++; j--;
                }
            }
        }

        return result;
    }
};
