class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int> lane(target, 0);
        stack<int> st;
        int fleet = position.size();

        for (int i = 0; i < speed.size(); i++) {
            lane[position[i]] = speed[i];
        }

        for (int i = 0; i < lane.size(); i++) {
            if (!lane[i]) {
                continue;
            }
            while (!st.empty() && lane[st.top()] > lane[i]) {
                if ((target - st.top()) * lane[i] <= (target - i) * lane[st.top()]) {
                    fleet--;
                }
                else {
                    break;
                }
                st.pop();
            }
            st.push(i);
        }

        return fleet;
    }
};