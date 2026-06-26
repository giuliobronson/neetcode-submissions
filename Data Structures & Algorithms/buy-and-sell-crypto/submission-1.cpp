class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> highest(prices.size());
        int max_diff = 0;
        
        highest[prices.size() - 1] = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            highest[i] = max(highest[i + 1], prices[i]);
        }

        for (int i = 0; i < prices.size(); i++) {
            max_diff = max(highest[i] - prices[i], max_diff);
        }

        return max_diff;
    }
};
