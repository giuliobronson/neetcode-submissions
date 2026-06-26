class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;

        path = path + "/";
        for (int l = 0, r = 0; r < path.length(); r++) {
            if (path[r] == '/') {
                string directory = path.substr(l, r - l);
                if (directory == "..") {
                    if (!s.empty()) s.pop();
                }
                else if (!directory.empty() && directory != ".") {
                    s.push(directory);
                }
                l = r + 1;
            }
        }

        string res = "";
        while (!s.empty()) {
            string directory = s.top(); s.pop();
            res =  "/" + directory + res;
        }

        if (res.empty()) return "/";
        return res;
    }
};