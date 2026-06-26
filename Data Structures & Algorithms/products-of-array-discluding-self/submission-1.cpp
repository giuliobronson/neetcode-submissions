class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0, idx = -1; 
        vector<int> output(nums.size(), 0);
        vector<int> prefix(nums.size(), 1);

        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            if (!nums[i]) {
                idx = i;
                zeros++; 
                n = 1;
            }
            prefix[i] = prefix[i - 1] * n;
        }


        if(!zeros) {
            for (int i = 0; i < nums.size(); i++) {
                output[i] = prefix[nums.size() - 1] / nums[i];
            }
        }
        else if (zeros == 1) {
            output[idx] = prefix[nums.size() - 1];
        }

        return output;
    }
};
