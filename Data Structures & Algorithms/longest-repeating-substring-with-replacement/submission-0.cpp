class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> chars;
        int l = 0, r = 0, maxL = 0, freq = 0;

        while (r < s.length()) {
            freq = max(freq, ++chars[s[r]]);

            int len = r - l + 1;
            int repl = len - freq;

            if (repl <= k) {
                maxL = max(maxL, len);
            }
            else {
                chars[s[l]]--;
                l++;
            }
            r++;
        }

        return maxL;
    }
};
