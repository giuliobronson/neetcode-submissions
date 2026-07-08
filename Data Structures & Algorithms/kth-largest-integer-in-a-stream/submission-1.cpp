class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) add(num);
    }
    
    int add(int val) {
        pq.push(val); k--;

        if (k < 0) {
            pq.pop();
            k++;
        }

        return pq.top();
    }
};
