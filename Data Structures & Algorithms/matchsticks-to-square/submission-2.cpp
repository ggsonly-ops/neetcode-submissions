class Solution {

private:
    bool helper(vector<int>& matchsticks,int idx,int target,vector<int> &sides){

        if(idx == matchsticks.size()) {
            return true;
        }

        for(int side=0;side<4;side++){
            if(sides[side] + matchsticks[idx] <= target) {
                sides[side] = sides[side] + matchsticks[idx];
                if(helper(matchsticks,idx+1,target,sides)) return true;
                sides[side] = sides[side] - matchsticks[idx];
            }
        }
        return false;

    }
public:
    bool makesquare(vector<int>& matchsticks) {
        
        int sum=0;
        for(int m:matchsticks) sum+=m;

        if(sum % 4 != 0) return false;
        int target = sum/4;
        vector<int> sides(4,0);

        return helper(matchsticks,0,target,sides);
    }
};