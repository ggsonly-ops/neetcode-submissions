class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // find the NGE

        int n = temperatures.size();
        stack<pair<int, int>> st;  // {ele, idx}
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                auto [ele, idx] = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};
