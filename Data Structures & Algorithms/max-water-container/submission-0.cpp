class Solution {
public:
    int maxArea(vector<int>& h) {
        
        int n=h.size();
        int l=0;
        int r=n-1;
        int ans=min(h[l],h[r])*(r-l);
        while(l<r){
            if(h[l]<h[r]){
                l++;
            }else{
                r--;
            }
            ans=max(ans,min(h[l],h[r])*(r-l));
        }

        return ans;
    }
};
