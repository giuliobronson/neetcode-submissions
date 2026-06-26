class Solution {
public:
    bool contains(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] < v2[i]) return false;
        }

        return true;
    }

    int idx(char c) {
        return islower(c) ? c - 'a' : c - 'A' + 26;
    }

    string minWindow(string s, string t) {
        vector<int> chars1(52, 0);
        vector<int> chars2(52, 0);
        pair<int, int> sub = {0, 0};
        int minL = INT_MAX;

        for (char c : t) {
            chars1[idx(c)]++;
        }

        int l = 0, r = 0;
        while (r < s.length()) {
            chars2[idx(s[r])]++;

            while (contains(chars2, chars1)) {
                if (r - l + 1 < minL) {
                    minL = r - l + 1;
                    sub  = {l, minL};
                }
                chars2[idx(s[l])]--;
                l++;
            }
            r++;
        }

        return s.substr(sub.first, sub.second);
    }
};
