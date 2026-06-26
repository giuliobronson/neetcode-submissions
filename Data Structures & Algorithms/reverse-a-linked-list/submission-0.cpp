/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> s;

        ListNode* curr = head;
        while (curr != nullptr) {
            s.push(curr->val);
            curr = curr->next;
        }

        ListNode* prev = nullptr, *rhead = nullptr;
        while (!s.empty()) {
            if (prev != nullptr) {
                ListNode* curr = new ListNode(s.top());
                prev->next = curr;
                prev = curr;
            }
            else {
                rhead = new ListNode(s.top());
                prev = rhead;
            }
            s.pop();
        }

        return rhead;
    }
};
