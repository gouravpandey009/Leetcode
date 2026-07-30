class Solution {
public:
    int findTheWinner(int n, int k) {

        // Queue stores all players
        queue<int> players;

        // Initially every player is alive
        for (int player = 1; player <= n; player++) {
            players.push(player);
        }

        // Continue until only one player survives
        while (players.size() > 1) {

            // Rotate the first (k-1) players
            // by moving them from front to back.
            for (int count = 1; count < k; count++) {

                players.push(players.front());
                players.pop();
            }

            // The kth player is eliminated.
            players.pop();
        }

        // Last remaining player is the winner.
        return players.front();
    }
};