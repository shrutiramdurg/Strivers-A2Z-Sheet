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
    ListNode* reverseLinkedList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseLinkedList(slow->next);

        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        bool ok = true;
        while (p2) {
            if (p1->val != p2->val) { ok = false; break; }
            p1 = p1->next;
            p2 = p2->next;
        }
        reverseLinkedList(secondHalf);   
        return ok;
    }
};

