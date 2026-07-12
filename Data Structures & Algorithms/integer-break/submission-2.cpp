class Solution {
public:
    int maxProd(int n) {
        if (n <= 1) return 1;
        if (n == 2 || n == 3) return n;
        return max(2 * maxProd(n - 2), 3 * maxProd(n - 3));
    }

    int integerBreak(int n) {
        if (n == 2 || n == 3) return n - 1;
        return maxProd(n);
    }
};