#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    TreeNode* current=root;
    while(current){
        if(p->val<current->val && q->val<current->val){
            current=current->left;
        }
        else if(p->val>current->val && q->val>current->val){
            current=current->right;
        }
        else{
            return current;
        }
    }
    return nullptr; // Should not reach here for valid inputs
}