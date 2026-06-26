class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> max_diff(prices.size());

        for (int i = 0; i < prices.size(); i++) {
            for (int j = i; j < prices.size(); j++) {
                max_diff[i] = max(prices[j] - prices[i], max_diff[i]);
            }
        }

        return *max_element(max_diff.begin(), max_diff.end());
    }
};
