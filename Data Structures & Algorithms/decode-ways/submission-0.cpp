class Solution {
   public:
    int numDecodings(string s) {
        // NIKHIL LOHIA

        // dp[i]= number of ways to decode the first i chars of string s

        int n=s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        if (s[0] == '0')
            dp[1] = 0;
        else
            dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int oneDigit = stoi(s.substr(i - 1, 1));
            int twoDigits = stoi(s.substr(i - 2, 2));

            if(oneDigit>=1) dp[i] += dp[i-1];
            if(twoDigits >=10 && twoDigits<=26) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
