class Solution {
public:
    bool contains(unordered_map<char, int>& chars2, unordered_map<char, int>& chars1) {
        for (auto& [k, v] : chars1) {
            if (v > chars2[k]) return false;
        }

        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> chars1;
        unordered_map<char, int> chars2;
        pair<int, int> sub = {0, 0};
        int minL = INT_MAX;

        for (char c : t) {
            chars1[c]++;
        }

        int l = 0, r = 0;
        while (r < s.length()) {
            chars2[s[r]]++;

            while (contains(chars2, chars1)) {
                if (r - l + 1 < minL) {
                    minL = r - l + 1;
                    sub  = {l, minL};
                }
                chars2[s[l]]--;
                l++;
            }
            r++;
        }

        return s.substr(sub.first, sub.second);
    }
};
