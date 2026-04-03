#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:

    // Count number of walls in range [L, R]
    int countWalls(vector<int>& walls, int L, int R) {
        return upper_bound(walls.begin(), walls.end(), R) -
               lower_bound(walls.begin(), walls.end(), L);
    }

    int maxWalls(vector<int>& robots, vector<int>& dist, vector<int>& walls) {

        int n = robots.size();

        // Sort walls
        sort(walls.begin(), walls.end());

        // Pair robots with distance
        vector<pair<int,int>> r;
        for(int i = 0; i < n; i++) {
            r.push_back({robots[i], dist[i]});
        }

        // Sort robots by position
        sort(r.begin(), r.end());

        // dp[i][0] -> current robot shoots LEFT
        // dp[i][1] -> current robot shoots RIGHT
        vector<vector<int>> dp(n, vector<int>(2, 0));

        // First robot
        int pos = r[0].first;
        int d = r[0].second;

        dp[0][0] = countWalls(walls, pos - d, pos - 1);      // LEFT
        dp[0][1] = countWalls(walls, pos + 1, pos + d);      // RIGHT

        // Process remaining robots
        for(int i = 1; i < n; i++) {

            int currPos = r[i].first;
            int currD = r[i].second;
            int prevPos = r[i-1].first;

            // LEFT range (cannot cross previous robot)
            int L = max(currPos - currD, prevPos + 1);
            int R = currPos - 1;
            int wL = countWalls(walls, L, R);

            // RIGHT range (cannot cross next robot)
            int nextPos = (i == n - 1 ? INT_MAX : r[i+1].first);
            int RL = currPos + 1;
            int RR = min(currPos + currD, nextPos - 1);
            int wR = countWalls(walls, RL, RR);

            // DP transitions
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + wL;
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + wR;
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};

int main() {

    int n;
    cout << "Enter number of robots: ";
    cin >> n;

    vector<int> robots(n), dist(n);

    cout << "Enter robot positions:\n";
    for(int i = 0; i < n; i++) cin >> robots[i];

    cout << "Enter distances:\n";
    for(int i = 0; i < n; i++) cin >> dist[i];

    int m;
    cout << "Enter number of walls: ";
    cin >> m;

    vector<int> walls(m);

    cout << "Enter wall positions:\n";
    for(int i = 0; i < m; i++) cin >> walls[i];

    Solution sol;

    int result = sol.maxWalls(robots, dist, walls);

    cout << "\nMaximum walls destroyed: " << result << endl;

    return 0;
}