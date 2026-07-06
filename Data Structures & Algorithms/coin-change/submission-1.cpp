class Solution {
public:
    int minCount = -1;

    int change(vector<int>& coins, int amount, int count, int i) {
        if (amount < 0 || i >= coins.size()) return -1;
        if (amount == 0 && (count < minCount || minCount == -1)) {
            minCount = count;
            return minCount;
        }

        int take = change(coins, amount - coins[i], count + 1, i);
        int dont = change(coins, amount, count, i + 1);

        if (take > 0 && dont > 0) {
            return min(take, dont);
        }
        else if (take > 0) {
            return take;
        }
        return dont;
    }

    int coinChange(vector<int>& coins, int amount) {
        return change(coins, amount, 0, 0);
    }
};
