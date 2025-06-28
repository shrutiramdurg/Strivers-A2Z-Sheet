#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

struct TreeNode {

    int val;

    TreeNode* left;

    TreeNode* right;


    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    int findCeil(TreeNode* root, int key){

        int ceil = -1; 
        

        while(root){

            if(root->val == key){
                ceil = root->val;
                return ceil;
            } 
 
            if(key > root->val){
                root = root->right;
            }
            else{ 
              
                ceil = root->val;
                root = root->left;
            }
        }

        return ceil;
    }
};