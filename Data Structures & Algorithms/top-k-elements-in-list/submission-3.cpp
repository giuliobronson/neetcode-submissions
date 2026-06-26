class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m = {};
        vector<pair<int, int>> freq;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        for (auto& e : m) {
            freq.push_back(e);
        }

        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        for (auto it = freq.begin(); it != freq.begin() + k; it++) {
            result.push_back(it->first);
        }

        return result;
    }
};
