class Node{
    public:
        int val;
        Node* next;
};

int findLen(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}