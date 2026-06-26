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
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next, *reversed = nullptr; slow->next = nullptr;
        while (curr) {
            ListNode* tmp = curr;
            curr = curr->next;
            tmp->next = reversed;
            reversed = tmp;
        }

        ListNode dummy = ListNode();
        ListNode* merged = &dummy;
        while (reversed && head) {
            merged->next = head;
            head = head->next;
            merged = merged->next;
            merged->next = reversed;
            reversed = reversed->next;
            merged = merged->next;
        }

        merged->next = head ? head : reversed;
    }
};
