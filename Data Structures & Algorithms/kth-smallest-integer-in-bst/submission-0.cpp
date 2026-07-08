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
public:
    bool inorder(TreeNode* root, int& k, int& result) {
        if (!root) return false;

        if (inorder(root->left, k, result)) return true; // found it in left subtree already

        k--;
        if (k == 0) {
            result = root->val;
            return true; // found it right here, stop
        }

        return inorder(root->right, k, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inorder(root, k, result);
        return result;
    }
};