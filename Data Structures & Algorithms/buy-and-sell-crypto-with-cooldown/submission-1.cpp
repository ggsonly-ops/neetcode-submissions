class Solution {
public:
    //buy=0 means cant Buy //buy=1 means can buy
    int helper(vector<int>& prices,int idx,int canBuy,vector<vector<int>> &dp){
        if(idx>=prices.size()) return 0;
        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
        

        if(canBuy==1){
            dp[idx][canBuy]=max(helper(prices,idx+1,1,dp),helper(prices,idx+1,0,dp)-prices[idx]);
        }
        else{
            dp[idx][canBuy]=max(helper(prices,idx+1,0,dp),helper(prices,idx+2,1,dp)+prices[idx]);
        }

        return dp[idx][canBuy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));

        return helper(prices,0,1,dp);
    }
};
