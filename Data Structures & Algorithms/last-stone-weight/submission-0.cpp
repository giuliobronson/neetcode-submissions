class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(!pq.empty()) {
            int x = pq.top(); pq.pop();

            if (pq.empty()) return x;

            int y = pq.top(); pq.pop();

            if (x == y) continue;
            
            pq.push(abs(y - x));
        }

        return 0;
    }
};
