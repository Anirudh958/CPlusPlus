#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
void preorder(TreeNode* root){
    if(root==nullptr) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(TreeNode* root){
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
void breadthFirst(TreeNode* root){
    if(root==nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* current=q.front();
        q.pop();
        cout<<current->val<<" ";
        if(current->left){
            q.push(current->left);
        }
        if(current->right){
            q.push(current->right);
        }
    }
}
int maxDepth(TreeNode* root){
    if(root==nullptr) return 0;
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);
    return max(leftDepth,rightDepth)+1;
}
TreeNode* invertTree(TreeNode* root){
    if(root==nullptr) return nullptr;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
bool isValidBST(TreeNode* root, long long minval=LLONG_MIN, long long maxval=LLONG_MAX){
    if(!root) return true;
    if(root->val<=minval || root->val>=maxval) return false;
    return isValidBST(root->left,minval,root->val)&&isValidBST(root->right,root->val,maxval);
}
int main(){
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(7);
    root->right->right=new TreeNode(9);

    cout<<"Preorder traversal: "<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Inorder traversal: "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Postorder traversal: "<<endl;
    postorder(root);
    cout<<endl;

    cout<<"Breadth-First traversal: "<<endl;
    breadthFirst(root);
    cout<<endl;

    cout<<"Maximum depth: "<<maxDepth(root)<<endl;

    cout<<"Is Valid BST: "<<isValidBST(root)<<endl;

    return 0;
}