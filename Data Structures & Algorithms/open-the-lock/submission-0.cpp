class Solution {
private:
    // Helper function to generate all 8 neighbors/children of a lock combination
    vector<string> getChildren(string lock) {
        vector<string> res;
        for (int i = 0; i < 4; i++) {
            char original_char = lock[i];
            
            // 1. Roll dial forward (+1)
            char forward = (original_char - '0' + 1) % 10 + '0';
            lock[i] = forward;
            res.push_back(lock);
            
            // 2. Roll dial backward (-1)
            char backward = (original_char - '0' - 1 + 10) % 10 + '0';
            lock[i] = backward;
            res.push_back(lock);
            
            // Backtrack to the original character for the next loop iteration
            lock[i] = original_char;
        }
        return res;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        // Transfer deadends to an unordered_set for O(1) tracking
        unordered_set<string> visit(deadends.begin(), deadends.end());
        
        // Edge case: if starting position is a deadend
        if (visit.count("0000")) {
            return -1;
        }
        
        // Queue stores pair: {current_lock_string, current_turns}
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visit.insert("0000"); // Mark starting point as visited
        
        while (!q.empty()) {
            auto [lock, turns] = q.front();
            q.pop();
            
            // If target combination is reached, return the total turns taken
            if (lock == target) {
                return turns;
            }
            
            // Process all neighboring combinations
            for (const string& child : getChildren(lock)) {
                if (visit.find(child) == visit.end()) {
                    visit.insert(child); // Mark as visited immediately before pushing
                    q.push({child, turns + 1});
                }
            }
        }
        
        return -1; // Target is blocked or unreachable
    }
};
