class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;

        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        while (pq.size() > 2) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();

            if (stone1 - stone2 != 0) pq.push(stone1 - stone2);
        }

        if (pq.size() == 2) {
            int secondLast = pq.top();
            pq.pop();
            int last = pq.top();
            pq.pop();

            if (secondLast == last)
                return 0;
            else
                return secondLast - last;
        }
        else {
            return pq.top();
        }
    }
};
