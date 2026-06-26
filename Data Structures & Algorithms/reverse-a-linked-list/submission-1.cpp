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

        ListNode dummy = ListNode(0);
        ListNode* tail = &dummy;

        while (!s.empty()) {
            tail->next = new ListNode(s.top());
            tail = tail->next;
            s.pop();
        }

        return dummy.next;
    }
};
