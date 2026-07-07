class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false; // ran out of tree, no match found anywhere

        // Check if the subtree rooted HERE matches subRoot exactly
        if (isSameTree(root, subRoot)) return true;

        // Otherwise, try the same check at every other node in root
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};