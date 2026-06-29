class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> hash(256,0);

        int n=s.size();
        int l=0;
        int r=0;
        int maxLen=0;

        while(r < n){
            
            while(hash[s[r]]>0){
                hash[s[l]]--;
                l++;
            }
            
            hash[s[r]]++;
            maxLen=max(maxLen,(r-l)+1);
            r++;
        }

        return maxLen;
    }
};
