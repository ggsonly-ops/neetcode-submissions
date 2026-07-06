class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> mp;

        for(char task: tasks){
            mp[task]++;
        }

        priority_queue<int> pq;
        queue<pair<int,int>> q;

        for (auto& pair : mp) {
            pq.push(pair.second);
        }

        int currTime=0;
        while(!pq.empty() || !q.empty()){
            currTime++;


            if(!q.empty() && currTime==q.front().second){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                int remainingFreq=pq.top()-1;
                pq.pop();

                if(remainingFreq > 0){
                    int availaibleTime=currTime + n + 1;
                    q.push({remainingFreq,availaibleTime});
                }
            }
        }

        return currTime;
    }
};
