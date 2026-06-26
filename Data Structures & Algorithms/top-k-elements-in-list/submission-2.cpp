class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> freq = {};
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for (auto& [k, v] : freq) {
            bucket[v].push_back(k);
        }

        for (auto it = bucket.rbegin(); it != bucket.rend(); it++) {
            result.insert(result.end(), it->begin(), it->end());
            if (result.size() == k) {
                break;
            }
        }

        return result;
    }
};
