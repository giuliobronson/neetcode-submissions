class Solution {
public:
    int minCount = -1;

    void change(vector<int>& coins, int amount, int count, int i) {
        if (amount < 0 || i >= coins.size()) return;
        if (amount == 0 && (count < minCount || minCount == -1)) {
            minCount = count;
            return;
        }

        change(coins, amount - coins[i], count + 1, i);
        change(coins, amount, count, i + 1);
    }

    int coinChange(vector<int>& coins, int amount) {
        change(coins, amount, 0, 0);
        return minCount;
    }
};
