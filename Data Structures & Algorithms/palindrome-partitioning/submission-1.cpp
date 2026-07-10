class Solution {
private:
    bool checkPalindrome(int l, int r, string& s, vector<vector<int>>& dp) {
        if (l >= r) return true;
        if (dp[l][r] != -1) return dp[l][r];
        if (s[l] != s[r]) return dp[l][r] = false;
        return dp[l][r] = checkPalindrome(l + 1, r - 1, s, dp);
    }

    void partitionPalindromes(int idx, string& s, vector<string>& curr,
                               vector<vector<string>>& result, vector<vector<int>>& dp) {
        if (idx == s.size()) {
            result.push_back(curr);
            return;
        }

        for (int j = idx; j < s.size(); j++) {
            if (checkPalindrome(idx, j, s, dp)) {
                curr.push_back(s.substr(idx, j - idx + 1));
                partitionPalindromes(j + 1, s, curr, result, dp);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        vector<string> curr;
        partitionPalindromes(0, s, curr, result, dp);
        return result;
    }
};