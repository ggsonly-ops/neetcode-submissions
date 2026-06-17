class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {

        //dp[i] = whether the first i chars of the str can be segmented or not
    
        int n = s.size();
        vector<bool> dp(n + 1, false);

        int maxLen = 0;
        for (auto w : wordDict) {
            maxLen = max(maxLen, (int)w.size());
        }

        dp[0] = true;  // empty prefix is trivially "segmentable"

        for (int i = 1; i <= n; i++) {
            // i represents "first i characters", so the word we're
            // trying to place ends at index i-1 in s (0-indexed)
            for (int start = i - maxLen; start < i; start++) {
                if (start < 0) continue;
                if (dp[start] &&
                    find(wordDict.begin(), wordDict.end(), s.substr(start, i - start)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};