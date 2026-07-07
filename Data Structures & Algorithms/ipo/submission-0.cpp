class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects; // {capital, profit}
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end()); // sort by capital ascending

        priority_queue<int> maxProfitHeap; // max-heap of profits, currently affordable
        int idx = 0;

        for (int i = 0; i < k; i++) {
            // Unlock every project whose capital requirement is now met
            while (idx < n && projects[idx].first <= w) {
                maxProfitHeap.push(projects[idx].second);
                idx++;
            }

            if (maxProfitHeap.empty()) break; // no affordable project left

            w += maxProfitHeap.top(); // take the best available profit
            maxProfitHeap.pop();
        }

        return w;
    }
};