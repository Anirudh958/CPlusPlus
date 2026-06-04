#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
    public:
        vector<vector<int>> pathSum(TreeNode* root,int targetSum){
            vector<vector<int>> result;
            vector<int> path;
            dfs(root,targetSum,0,path,result);
            return result;
        }
        void dfs(TreeNode* root,int target,int current,vector<int>& path,vector<vector<int>>& result){
            if(root==nullptr) return;
            path.push_back(root->val);
            current+=root->val;
            if(root->left==nullptr && root->right==nullptr){
                if(current==target){
                result.push_back(path);
                }
            }
            else{
                dfs(root->left,target,current,path,result);
                dfs(root->right,target,current,path,result);
            }
            path.pop_back();
        }
};