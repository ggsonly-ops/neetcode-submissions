class Solution {
public:
    int maxProfit(vector<int>& price) {
        int profit=0;

        for(int i=1;i< price.size();i++){
            if(price[i]-price[i-1]>0) profit+=price[i]-price[i-1];
        }

        return profit;
    }
};