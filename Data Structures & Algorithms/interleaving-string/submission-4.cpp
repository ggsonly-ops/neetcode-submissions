class Solution {
   public:
    bool helper(int i, int j, int k, string& s1, string& s2, string& s3,vector<vector<int>> &dp) {
        if (k == s3.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool case1 = false;
        bool case2 = false;

        if (i < s1.size() && s1[i] == s3[k]) case1 = helper(i + 1, j, k + 1, s1, s2, s3,dp);
        if (j < s2.size() && s2[j] == s3[k]) case2 = helper(i, j + 1, k + 1, s1, s2, s3,dp);

        return dp[i][j]=(case1 || case2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(0, 0, 0, s1, s2, s3,dp);
    }
};
