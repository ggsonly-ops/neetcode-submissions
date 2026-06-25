class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];

        for(int i=0;i< strs.size();i++){

            int j=0;
            while (j<min(ans.length(),strs[i].length())){
                if(ans[j]!=strs[i][j]) break;
                j++;
            }
            ans=ans.substr(0,j);
        }
        return ans;
    }
};