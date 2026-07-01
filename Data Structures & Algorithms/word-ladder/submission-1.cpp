class Solution {
public:
    bool neighborWords(string& s, string& t) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) count++;
        }

        return count == 1;
    }

    vector<string> neighbors(string& s) {
        vector<string> res;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            for (int j = 0; j < 26; j++) {
                if (c == 'a' + j) continue;
                s[i] = 'a' + j;
                res.push_back(s);
            }
            s[i] = c;
        }

        return res;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [u, d] = q.front(); q.pop();

            if (u == endWord) return d;

            if (visited.count(u)) continue;

            visited.insert(u);

            for (string& v: neighbors(u)) {
                if (words.count(v)) q.push({v, d + 1});
            }
        }

        return 0;
    }
};
