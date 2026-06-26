class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int r = 1, l = 0, maxP = 0;

        while (r < prices.size()) {
            if (prices[r] > prices[l]) {
                maxP = max(prices[r] - prices[l], maxP);
            }
            else {
                l = r;
            }
            r++;
        }

        return maxP;
    }
};
