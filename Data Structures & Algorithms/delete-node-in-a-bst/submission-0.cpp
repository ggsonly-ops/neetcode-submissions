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
    // Helper function to find the maximum node in the left subtree (Inorder Predecessor)
    TreeNode* findMax(TreeNode* node) {
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case
        if (root == nullptr) {
            return nullptr;
        }

        // 1. Search for the node to delete
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        // 2. Target node found
        else {
            // Case 1 & 2: Node has 0 or 1 child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has 2 children
            // Find the inorder predecessor (max value in left subtree)
            TreeNode* predecessor = findMax(root->left);

            // Copy its value over to the current root
            root->val = predecessor->val;

            // Delete the predecessor node from the left subtree
            root->left = deleteNode(root->left, predecessor->val);
        }
        return root;
    }
};
