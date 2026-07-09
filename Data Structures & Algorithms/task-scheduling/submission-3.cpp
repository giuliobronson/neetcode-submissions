class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        
        for (char task : tasks) freq[task]++;
        for (auto [k, v] : freq) pq.push(v); 

        int time = 0;
        do {
            if (!pq.empty()) {
                auto f = pq.top(); pq.pop();
                if (--f) q.push({f, time + n});  
            }

            auto [f, t] = q.front(); 

            if (time == t) {
                pq.push(f); q.pop();
            }

            time++;
        } while (!q.empty() || !pq.empty());

        return time;
    }
};
