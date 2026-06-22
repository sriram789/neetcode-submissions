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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *mergedList = nullptr;
        for (int index = 0 ; index < lists.size() ; index++) {
            mergedList = mergeTwoLists(mergedList, lists[index]);
        }

        return mergedList;
    }

    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {

        if (!first && !second) return nullptr;
        if (!first) return second;
        if (!second) return first;

        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;

        while (first && second) {
            if (first->val <= second->val) {
                dummy->next = first;
                first = first->next;
            } else {
                dummy->next = second;
                second = second->next;
            }

            dummy = dummy->next;
        }

        if (first) {
            dummy->next = first;
        } else {
            dummy->next = second;
        }

        return head->next;
    }
};
