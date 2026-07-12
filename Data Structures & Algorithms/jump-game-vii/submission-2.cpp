class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        queue<int> q;
        q.push(0);
        int n=s.size();
        int farthest=0;

        while(!q.empty()){
            
            int i=q.front();
            q.pop();
            int start=max(minJump + i,farthest+1);
            int end= min(n-1,i + maxJump);

            for (int j=start ; j <= end ; j++){
                if(s[j]=='0') q.push(j);
                if(s[j] == '0' && j==n-1) return true;
            }

            farthest=max(farthest,end);
        }
       
        return false;
    }
};