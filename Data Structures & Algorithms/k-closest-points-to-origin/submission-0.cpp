class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](auto& p1, auto& p2) {
            return p1[0] * p1[0] + p1[1] * p1[1] > p2[0] * p2[0] + p2[1] * p2[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(points.begin(), points.end());
        vector<vector<int>> res;

        while (k--) {
            res.push_back(pq.top()); pq.pop();
        }

        return res;
    }
};
