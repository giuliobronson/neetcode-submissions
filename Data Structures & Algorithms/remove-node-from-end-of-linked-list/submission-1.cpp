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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0, head);
        ListNode* slow = &dummy, *fast = head;
        int i = 0;
        while (fast) {
            fast = fast->next;
            if (i >= n) {
                slow = slow->next;
            }
            i++;
        }

        ListNode* removed = slow->next;
        if (removed) {
            slow->next = removed->next;
            removed->next = nullptr;
            delete removed;
        } 
        return dummy.next;
    }
};
