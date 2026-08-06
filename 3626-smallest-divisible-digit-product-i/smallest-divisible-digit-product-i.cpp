class Solution {
public:
    int smallestNumber(int n, int t) {

        while (true) {

            int x = n;
            int prod = 1;

            // Compute product of digits.
            while (x) {
                prod *= x % 10;
                x /= 10;
            }

            if (prod % t == 0)
                return n;

            n++;
        }

        return -1;
    }
};