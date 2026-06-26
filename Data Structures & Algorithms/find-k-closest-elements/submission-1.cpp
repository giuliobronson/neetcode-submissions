class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](auto a, auto b){ 
            int diff = abs(a - x) - abs(b - x);
            return diff == 0 ? a < b : diff < 0;
        });

        vector<int> res(arr.begin(), arr.begin() + k);
        
        sort(res.begin(), res.end());

        return res;
    }
};