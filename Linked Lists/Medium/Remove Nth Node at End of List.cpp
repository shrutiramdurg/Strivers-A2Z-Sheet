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
        // Dummy node to simplify deleting the head
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // step 1: advance fast by n nodes
        for (int i = 0; i < n; ++i) fast = fast->next;

        // step 2: move both until fast is at last node
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow->next is the node to delete
        ListNode* toDel = slow->next;
        slow->next = toDel->next;
        delete toDel;

        return dummy.next;      // new head
    }
};
