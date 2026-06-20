class Solution {   
public:
    int helper(int i,int j, vector<int>& piles,vector<vector<int>> &dp){
        int remainingPiles=j-i+1;
        if(remainingPiles==0) return 0;

        if(dp[i][j]!=-1e9) return dp[i][j];
        
        
        if (remainingPiles % 2 == 0) {
            // Alice's Turn: Maximize score
            int pickLeft  = piles[i] + helper(i + 1, j, piles, dp);
            int pickRight = piles[j] + helper(i, j - 1, piles, dp);
            return dp[i][j] = max(pickLeft, pickRight);
        } 
        else {
            // Bob's Turn: Minimize Alice's score advantage
            int pickLeft  = -piles[i] + helper(i + 1, j, piles, dp);
            int pickRight = -piles[j] + helper(i, j - 1, piles, dp);
            return dp[i][j] = min(pickLeft, pickRight); 
        }
        
    }
    bool stoneGame(vector<int>& piles) {
        
        //we would be tracking just the score as 
        // ALICE - BOB 
        // so each time Alice picks we add
        //each time Bob picks we substract
        //so at the end if we have an ans >0 we can 
        // say Alice won

        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1e9));
        int ans=helper(0,n-1,piles,dp);
        if(ans>0) return true;
        return false;
    }
};