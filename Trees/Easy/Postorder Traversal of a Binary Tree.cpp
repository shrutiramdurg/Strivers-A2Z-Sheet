#include <iostream>
#include <vector>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


void postorder(Node* root, vector<int>& arr){

    if(root==NULL){
        return;
    }

    postorder(root->left, arr);
 
    postorder(root->right, arr);

    arr.push_back(root->data);
}


vector<int> postOrder(Node* root){

    vector<int> arr;

    postorder(root, arr);

    return arr;
}
