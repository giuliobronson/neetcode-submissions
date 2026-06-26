class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (int i = 0; i < strs.size(); i++) {
            int len = strs[i].length();
            result += to_string(len) + "#" + strs[i];
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string len = "";

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                len += s[i];
            }
            else {
                string buffer = "";
                int m = stoi(len);
                while(m--) buffer += s[++i];
                result.push_back(buffer);
                len = "";
            }
        }

        return result;
    }
};
