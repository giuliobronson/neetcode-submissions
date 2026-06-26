class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> deleted;
        priority_queue<int> heap(nums.begin(), nums.begin() + k);
        vector<int> res(1, heap.top());
        int l = 0, r = k;
        
        while (r < nums.size()) {
            heap.push(nums[r]);
            deleted[nums[l]]++;

            while (!heap.empty() && deleted[heap.top()] > 0) {
                deleted[heap.top()]--;
                heap.pop();
            }

            res.push_back(heap.top());
            
            l++; r++;
        }

        return res;
    }
};
