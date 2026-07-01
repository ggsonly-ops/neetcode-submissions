class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int maxArea=0;
        stack<pair<int,int>> st; //idx ele

        for(int i=0;i< heights.size(); i++){
            int start=i;
            int h=heights[i];
            while(!st.empty() && h < st.top().second){
                auto[idx,height] = st.top();
                st.pop();
                maxArea=max(maxArea,(i-idx)*height);
                start=idx;
            }
            st.push({start,h});
        }

        while(!st.empty()){
            auto[idx,height] = st.top();
            st.pop();
            maxArea=max(maxArea,((int)heights.size()-idx)*height);
        }

        return maxArea;
    }
};
