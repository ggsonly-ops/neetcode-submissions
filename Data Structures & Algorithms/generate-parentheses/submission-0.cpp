class Solution {

private:
    void generate(int n,int opencount,int closecount,string cur,vector<string> &ans){
        
        if(opencount == n && closecount == n){
            ans.push_back(cur);
            return;
        }

        if(opencount < n) generate(n,opencount+1,closecount,cur + '(',ans);
        if(closecount < opencount) generate(n,opencount,closecount+1,cur + ')',ans);

    }
public:
    vector<string> generateParenthesis(int n) {
        
        string cur="";
        vector<string> ans;
        generate(n,0,0,cur,ans);
        return ans;
    }
};
