class Solution {

private:
    void helper(string &s,int idx,vector<string> &curr, vector<string> &ans, vector<string>& wordDict){

        if(idx == s.size()){

            string sentence = curr[0];
            for (int i = 1; i < curr.size(); i++) sentence += " " + curr[i];
            ans.push_back(sentence);
            return;

        }

        for(auto w : wordDict){
            int len=w.size();
            if(idx + len <= s.size() && s.substr(idx,len)==w){
                curr.push_back(w);
                helper(s,idx+len,curr,ans,wordDict);
                curr.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        vector<string> curr;
        helper(s, 0, curr, ans, wordDict);
        return ans;
    }
};