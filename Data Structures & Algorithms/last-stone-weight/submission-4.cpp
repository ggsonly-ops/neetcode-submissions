class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        // priority_queue<int, vector<int>> pq;

        // for (int i = 0; i < stones.size(); i++) {
        //     pq.push(stones[i]);
        // }

        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();

            if (stone1 - stone2 != 0) pq.push(stone1 - stone2);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
