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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        stack<ListNode*> s;

        int count = 0;
        while (curr) {
            s.push(curr);
            curr = curr->next;
            count++;
        }

        curr  = head;
        for (int step = 0; step < count / 2; step++) {
            ListNode* tmp = curr;
            curr = curr->next;
            tmp->next = s.top();
            s.top()->next = curr;
            s.pop();
        }

        curr->next = nullptr;
    }
};
