// The API is already defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int left = 1;
        int right = n;

        // Continue until only one candidate remains
        while (left < right) {

            // Overflow-safe middle calculation
            int mid = left + (right - left) / 2;

            // If current version is bad,
            // the first bad version can be:
            // - mid itself
            // - somewhere before mid
            if (isBadVersion(mid)) {

                right = mid;
            }

            // Current version is good,
            // so the answer must lie strictly to the right.
            else {

                left = mid + 1;
            }
        }

        // left == right
        // Both point to the first bad version.
        return left;
    }
};