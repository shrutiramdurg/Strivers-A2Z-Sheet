class Node{
    public:
        int val;
        Node* next;
};

bool checkElem(Node* head, int value){
   Node* temp = head;
   while(temp!=NULL){
        if(temp->val == value){
            return true;
        }
        else{
            temp = temp->next;
        }
   }
   return false; 
}
