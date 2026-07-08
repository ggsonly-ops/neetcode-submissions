class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> levelOrder;
        if (!root) return levelOrder;

        queue<TreeNode*> q;

        q.push(root);
        int currLevel=0;

        while(!q.empty()){
            levelOrder.push_back({}); // create an empty slot for this level first
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                levelOrder[currLevel].push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            currLevel++;
        }
        return levelOrder;
    }
};