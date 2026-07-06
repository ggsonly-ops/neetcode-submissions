class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        priority_queue<pair<int,char>> maxHeap; // {frequency, char}
        for (auto& [ch, count] : freq) {
            maxHeap.push({count, ch});
        }

        string result;
        pair<int,char> prev = {0, '#'}; // placeholder "no previous" state

        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();

            result += ch;
            count--;

            // If the previously held-back char is now eligible to be pushed back, do it
            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            // Hold the current char back for one round, so it can't be placed again immediately next
            prev = {count, ch};
        }

        if (result.size() != s.size()) return ""; // couldn't fully place everything

        return result;
    }
};