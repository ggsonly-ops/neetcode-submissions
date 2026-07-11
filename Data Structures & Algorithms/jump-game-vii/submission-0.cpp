class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int maxIdx = 0;
        int n = s.size();
        int nextIdx = INT_MAX; // fixed: sentinel should be "larger than any valid index"
        int i = 0;

        while (i < n) {
            bool foundAny = false; // also need to detect "no valid j found at all -> dead end"
            for (int j = i + minJump; j <= min(n - 1, i + maxJump); j++) { // also fixed bound below
                if (s[j] == '0') {
                    nextIdx = min(nextIdx, j);
                    maxIdx = j;
                    foundAny = true;
                }
                if (maxIdx == n - 1) return true;
            }
            if (!foundAny) return false; // no reachable '0' from here -> stuck, fail
            i = nextIdx;
            nextIdx = INT_MAX; // reset for the next round
        }
        return false;
    }
};