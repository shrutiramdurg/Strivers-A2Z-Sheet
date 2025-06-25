class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min heap to store the current head of each list
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Push the head of each non-empty list into the heap
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        // Dummy node to help build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // While the heap is not empty, pop the smallest node and add it to the result
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};