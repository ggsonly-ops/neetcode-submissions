class Solution {
private:
    // Fixed: Changed semicolon to comma after int idx
    void helper(int n, int k, int idx, vector<int> &curr, vector<vector<int>> &ans) {
        // Fixed: Changed hardcoded 2 to k
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        
        // Fixed: Changed loop limit from k to n
        for (int i = idx; i <= n; i++) {
            curr.push_back(i);
            // Fixed: Changed i to i + 1 to prevent picking duplicates
            helper(n, k, i + 1, curr, ans);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(n, k, 1, curr, ans);
        return ans;
    }
};
