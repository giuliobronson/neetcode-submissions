class Solution {
public:
    bool neighborWords(string& s, string& t) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) count++;
        }

        return count == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj(wordList.size());
        unordered_set<string> visited;
        queue<pair<string, int>> q;

        wordList.push_back(beginWord);

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i; j < wordList.size(); j++) {
                if (neighborWords(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [u, d] = q.front(); q.pop();

            if (u == endWord) return d;

            if (visited.count(u)) continue;

            visited.insert(u);

            for (auto& v : adj[u]) {
                q.push({v, d + 1});
            }
        }

        return 0;
    }
};
