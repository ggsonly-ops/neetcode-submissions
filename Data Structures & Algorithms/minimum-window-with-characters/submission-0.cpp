class Solution {
public:
    string minWindow(string s, string t) {
        
        int minLen=INT_MAX;
        int sIdx=-1;
        int l=0;
        int r=0;
        int n=s.size();
        int m=t.size();
        int hash[256]={0};
        int count=0;

        for(auto c:t) hash[c]++;


        while(r < n){
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;

            while(count==m){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    sIdx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) count--;
                l++;
            }
            r++;
        }

        return sIdx == -1 ? "" : s.substr(sIdx,minLen);
    }
};
