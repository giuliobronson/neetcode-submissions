class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int i = 0, j = 0, maxL = 0;

        while (j < s.length()) {
            if (i < j && chars.count(s[j])) {
                while (s[i] != s[j]) {
                    chars.erase(s[i++]);
                };
                i++;
            } 
            else {
                maxL = max(maxL, j - i + 1);
            }
            chars.insert(s[j++]);
        }

        return maxL;
    }
};
