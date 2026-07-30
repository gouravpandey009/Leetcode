class Solution {
public:

    // Returns winner using 0-based indexing
    int josephus(int n, int k) {

        // Base case:
        // Only one player remains.
        if (n == 1)
            return 0;

        // Solve smaller problem and
        // convert answer to current circle.
        return (josephus(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {

        // Convert 0-based answer
        // into 1-based player number.
        return josephus(n, k) + 1;
    }
};