class KthLargest {
public:
    priority_queue<int> pq;
    int k;

    KthLargest(int k, vector<int>& nums) : k(k) {
        this->pq = priority_queue<int>(nums.begin(), nums.end());
    }
    
    int add(int val) {
        pq.push(val);
        
        priority_queue<int> temp(pq); 

        int i = 0, value = temp.top();
        while (!temp.empty() && i < k) {
            value = temp.top(); temp.pop();
            i++;
        }

        return value;
    }
};
