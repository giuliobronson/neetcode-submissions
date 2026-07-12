class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int a = 0, pa = a; a < nums.size(); pa = a) {
            for (int d = nums.size() - 1, pd = d; d > a; pd = d) {
                long sum = (long) target - nums[a] - nums[d];
                int b = a + 1, c = d - 1;

                while (b < c) {
                    if (nums[b] + nums[c] == sum) {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                    }

                    int i = b, j = c;
                    while (b < c && nums[i] == nums[b] && nums[b] + nums[c] == sum) {
                        b++;
                        c--;
                    }
                    while (b < c && nums[i] == nums[b] && nums[b] + nums[c] < sum) b++;
                    while (b < c && nums[j] == nums[c] && nums[b] + nums[c] > sum) c--;
                }

                while (d >= 0 && nums[d] == nums[pd]) d--;
            }

            while (a < nums.size() && nums[a] == nums[pa]) a++;
        }

        return res;
    }
};