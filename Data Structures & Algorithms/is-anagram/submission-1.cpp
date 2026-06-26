class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map = {};
        unordered_map<char, int> t_map = {};

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
            char letter = p.first;

            if (s_map[letter] != t_map[letter]) {
                return false;
            }
        }

        return true;
    }
};
