class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lprefix(nums.size(), 1);
        vector<int> rprefix(nums.size(), 1);
        vector<int> output(nums.size());

        lprefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            lprefix[i] = lprefix[i - 1] * nums[i];
        }

        rprefix[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            rprefix[i] = rprefix[i + 1] * nums[i];
        }

        output[0] = rprefix[1];
        output[nums.size() - 1] = lprefix[nums.size() - 2];
        for (int i = 1; i < nums.size() - 1; i++) {
            output[i] = lprefix[i - 1] * rprefix[i + 1];
        }
         
        return output;
    }
};
