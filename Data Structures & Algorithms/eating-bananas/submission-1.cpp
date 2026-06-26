class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxK = *max_element(piles.begin(), piles.end());

        for (long long k = 1 ; k <= maxK; k++) {
            long long t = 0;

            for (long long i = 0; i < piles.size(); i++) {
                t += (piles[i] + k - 1) / k;
            }

            if (t <= h) {
                return k;
            }
        }

        return 0;
    }
};
