class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m = {};
        vector<vector<string>> result;

        for (int i = 0; i < strs.size(); i++) {
            vector<int> freq(26, 0);
            for (int c : strs[i]) {
                freq[c % 26]++;
            }
            if (!m.count(freq)) {
                m[freq] = {strs[i]};
            }
            else {
                m[freq].push_back(strs[i]);
            }
        }

        for (auto& e : m) {
            result.push_back(e.second);
        }

        return result;
    }
};
