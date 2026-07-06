class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> maxHeap;
        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});

        string result;

        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();

            int len = result.size();
            // Check if placing 'ch' would create a 3-in-a-row
            if (len >= 2 && result[len-1] == ch && result[len-2] == ch) {
                // Can't use this char right now — try the next-best candidate
                if (maxHeap.empty()) break; // no alternative available, must stop

                auto [count2, ch2] = maxHeap.top();
                maxHeap.pop();

                result += ch2;
                count2--;
                if (count2 > 0) maxHeap.push({count2, ch2});

                // Push the original blocked char back, unused this round
                maxHeap.push({count, ch});
            } else {
                result += ch;
                count--;
                if (count > 0) maxHeap.push({count, ch});
            }
        }

        return result;
    }
};