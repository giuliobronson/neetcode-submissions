class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        deque<int> dq;
        
        int r = it - arr.begin(), l = r - 1, n = arr.size();
        while (l >=0 && r < n && r - l <= k) {
            if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                dq.push_front(arr[l]);
                l--;
            }
            else {
                dq.push_back(arr[r]);
                r++;
            }
        }

        while (l >=0 && r - l <= k) {
            dq.push_front(arr[l]);
            l--;
        }

        while (r < n && r - l <= k) {
            dq.push_back(arr[r]);
            r++;
        }

        vector<int> res(dq.begin(), dq.end());
        return res;
    }
};