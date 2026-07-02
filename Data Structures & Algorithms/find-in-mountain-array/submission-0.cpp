/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    unordered_map<int, int> cache;

    int get(int index, MountainArray &mountainArr) {
        if (cache.find(index) == cache.end()) {
            cache[index] = mountainArr.get(index);
        }
        return cache[index];
    }

    int binarySearch(int l, int r, bool ascending, int target, MountainArray &mountainArr) {
        while (l <= r) {
            int m = (l + r) >> 1;
            int val = get(m, mountainArr);
            if (val == target) {
                return m;
            }
            if (ascending == (val < target)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();

        // Find Peak
        int l = 1, r = length - 2, peak = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            int left = get(m - 1, mountainArr);
            int mid = get(m, mountainArr);
            int right = get(m + 1, mountainArr);
            if (left < mid && mid < right) {
                l = m + 1;
            } else if (left > mid && mid > right) {
                r = m - 1;
            } else {
                peak = m;
                break;
            }
        }

        // Search left portion
        int res = binarySearch(0, peak, true, target, mountainArr);
        if (res != -1) {
            return res;
        }

        // Search right portion
        return binarySearch(peak, length - 1, false, target, mountainArr);
    }
};