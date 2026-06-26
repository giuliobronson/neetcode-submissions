class Solution {
public:

    string encode(vector<string>& strs) {
        string sep = "%%";
        string result = "";

        for (int i = 0; i < strs.size(); i++) {
            result += strs[i] + sep;
        }

        return result;
    }

    vector<string> decode(string s) {
        string sep = "%%";
        vector<string> result;

        for (int i = 0, j = 1; j < s.length(); j++) {
            string window = {s[j - 1], s[j]};

            if (window == sep) {
                if (i >= j - 1) {
                    result.push_back("");
                }
                else {
                    result.push_back(s.substr(i, j - i - 1));
                }
                i = j + 1;
                j++;
            }
        }

        return result;
    }
};
