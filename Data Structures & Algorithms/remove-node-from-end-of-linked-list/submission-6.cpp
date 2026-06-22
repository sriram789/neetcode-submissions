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
        ListNode *dummy = new ListNode(INT_MAX, head);
        ListNode *fast = head;
        ListNode *slow = dummy;

        while (n--) fast = fast->next;

        while (fast) { fast = fast->next; slow = slow->next; }

        ListNode* temp = slow->next;
        slow->next = temp->next;

        return dummy->next;
    }
};
