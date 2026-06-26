class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, vector<int>> m = {};
        vector<int> result;

        sort(nums.begin(), nums.end());

        for (int i = 0, j = 0, len = 0; j <= nums.size(); j++, len++) {
            if (j == nums.size() || nums[i] != nums[j]) {
                m[len].push_back(nums[i]);
                i = j;
                len = 0;
            }
        }

        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            result.insert(result.end(), (it->second).begin(), (it->second).end());
            if (result.size() >= k) {
                return result;
            }
        }
    }
};
