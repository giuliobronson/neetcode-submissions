class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr = 0, n = gas.size();

        int i = 0, j = i, k = 0, l = 0;
        while (k < n && l < n) {
            curr += gas[j];
            if (cost[j] > curr) {
                i = ++i % n; k++;
                j = i; 
                l = 0; curr = 0;
            }
            else {
                curr -= cost[j];
                j = ++j % n; l++;
            }
        }

        if (l == n) return i;
        return -1;
    }
};