class Solution {
public:
    string getAlphanumeric(string& s) {
        string result = "";

        for (char c : s) {
            if (isalnum(c)) {
                result += tolower(c);
            }
        }

        return result;
    }

    bool isPalindrome(string s) {
        s = getAlphanumeric(s);

        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }
};
