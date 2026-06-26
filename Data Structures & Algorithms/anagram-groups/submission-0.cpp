class Solution {
public:
    bool isAnagram(string& s, string& t) {
        unordered_map<char, int> s_map, t_map;

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (!s_map.count(s[i])) {
                s_map[s[i]] = 1;
            }
            else {
                s_map[s[i]]++;
            }
        } 

        for (int i = 0; i < t.length(); i++) {
            if (!t_map.count(t[i])) {
                t_map[t[i]] = 1;
            }
            else {
                t_map[t[i]]++;
            }
        } 

        for (auto& p : s_map) {
            if (p.second != t_map[p.first]) {
                return false;
            }
        }

        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        for (auto& s : strs) {
            bool found = false;

            for (auto& group : result) {
                if (isAnagram(*group.begin(), s)) {
                    group.push_back(s);
                    found = true;
                    break;
                }
            }

            if (!found) {
                result.push_back({s});
            }
        }

        return result;
    }
};
