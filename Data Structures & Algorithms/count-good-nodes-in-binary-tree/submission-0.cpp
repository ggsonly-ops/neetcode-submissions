/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

private:

    void dfs(TreeNode* root,int &goodNodes,int pathMax){
        
        if(!root) return;

        if(root->val >= pathMax) goodNodes++;

        dfs(root->left,goodNodes,max(pathMax,root->val));
        dfs(root->right,goodNodes,max(pathMax,root->val));

    }
public:
    int goodNodes(TreeNode* root) {
        
        int goodNodes=0;
        dfs(root,goodNodes,INT_MIN);
        return goodNodes;
    }
};
