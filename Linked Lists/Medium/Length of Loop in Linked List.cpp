class Node{
    public:
        int val;
        Node* next;
};


int findLength(Node* slow, Node* fast){
    int count = 1;
    fast = fast->next;
    while(slow != fast){
        count++;
        fast = fast->next;
    }
    return count;
}

int findLengthLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findLength(slow, fast);
        }
    }
}