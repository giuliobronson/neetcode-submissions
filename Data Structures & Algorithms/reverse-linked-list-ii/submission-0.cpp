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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy = ListNode(0, head);
        ListNode* before = &dummy, *after = nullptr, *curr = head, *prev = nullptr, *begin = nullptr;
        int index = 1;

        while (curr) {
            if (left > index)  before = curr;
            if (left  == index) begin = curr;
            if (right == index) after = curr->next;

            if (left <= index && right >= index) {
                ListNode* temp = curr;
                curr = curr->next;
                temp->next = prev;
                prev = temp;
                index++;
                continue;
            }

            curr = curr->next; index++;
        }

        before->next = prev;
        begin->next = after;

        return dummy.next;
    }
};