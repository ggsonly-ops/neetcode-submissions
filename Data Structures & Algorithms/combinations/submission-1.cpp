class Solution {
private:
    void helper(int n, int k, int idx, vector<int> &curr, vector<vector<int>> &ans) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        
        if (n - idx + 1 < k - curr.size()) return;

        
        for (int i = idx; i <= n; i++) {
            curr.push_back(i);
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
