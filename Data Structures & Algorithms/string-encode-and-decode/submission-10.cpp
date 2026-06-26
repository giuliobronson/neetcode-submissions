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
        string buffer = "";
        vector<string> result;

        for (int i = 0, j = 1; j < s.length(); j++) {
            string window = {s[j - 1], s[j]};
            buffer += s[j - 1];

            if (window == sep) {
                if (i >= j - 1) {
                    result.push_back("");
                }
                else {
                    buffer.pop_back();
                    result.push_back(buffer);
                }
                buffer = "";
                i = j + 1;
                j++;
            }
        }

        return result;
    }
};
