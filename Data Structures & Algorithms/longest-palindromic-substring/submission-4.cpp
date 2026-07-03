class Solution {
public:
    string longestPalindrome(string s) {
        pair<int, int> res = {0, 1};

        for (int i = 0; i < s.length(); i++) {
            int l = i, r = i;
            while (r < s.length() - 1 && s[r] == s[r + 1]) {
                r++;
                res = r - l + 1 > res.second ? make_pair(l, r - l + 1) : res; 
                i = (l + r) / 2;
            }
            while (l >= 1 && r <= s.length() - 1 && s[l - 1] == s[r + 1]) {
                res = r - l + 3 > res.second ? make_pair(l - 1, r - l + 3) : res;
                l--; r++;
            }
        }

        return s.substr(res.first, res.second);
    }
};
