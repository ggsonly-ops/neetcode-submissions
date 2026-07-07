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
    int findDia(TreeNode* root,int &ans){
        if(!root) return 0;

        int lh = findDia(root->left,ans);
        int rh = findDia(root->right,ans);
        ans=max(ans,lh+rh);

        return 1 + max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        findDia(root,ans);
        return ans;
    }
};
