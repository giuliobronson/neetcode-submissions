class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m = {};
        vector<vector<string>> result;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            if (!m.count(strs[i])) {
                m[strs[i]] = {s};
            }
            else {
                m[strs[i]].push_back(s);
            }
        }

        for (auto& e : m) {
            result.push_back(e.second);
        }

        return result;
    }
};
