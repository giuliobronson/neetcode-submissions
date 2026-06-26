class Solution {
public:
    long long eatingTime(long long k, long long h, vector<int>& piles) {
        long long t = 0;

        for (long long i = 0; i < piles.size(); i++) {
            t += (piles[i] + k - 1) / k;
        }

        return t;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxK = *max_element(piles.begin(), piles.end());
        long long l = 1, r = maxK;

        while (l < r) {
            long long m = (l + r) / 2;
            long long t = eatingTime(m, h, piles);
            
            if (t > h) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        return r;
    }
};
