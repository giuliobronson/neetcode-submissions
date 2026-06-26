class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> chars1(26, 0);
        vector<int> chars2(26, 0);
        int l = 0, r = 0;

        for (char c : s1) {
            chars1[c - 'a']++;
        }

        while (r < s2.length()) {
            chars2[s2[r] - 'a']++;

            if (r - l + 1 > (int) s1.length()) {
                chars2[s2[l] - 'a']--;
                l++;
            }
            if (chars1 == chars2) return true;
            r++;
        }

        return false;
    }
};
