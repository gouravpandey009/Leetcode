#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        for(auto &row : grid)
            for(auto &val : row)
                total += val;

        long long prefix = 0;

        unordered_map<int, int> bottomFreq;

        for(auto &row : grid)
            for(auto &val : row)
                bottomFreq[val]++;

        unordered_map<int, int> topFreq;

        for(int i = 0; i < m - 1; i++) {

            for(int j = 0; j < n; j++) {
                int val = grid[i][j];
                prefix += val;

                topFreq[val]++;
                bottomFreq[val]--;
                if(bottomFreq[val] == 0)
                    bottomFreq.erase(val);
            }

            long long bottom = total - prefix;

            if(prefix == bottom) return true;

            long long diff = abs(prefix - bottom);

            if(prefix > bottom) {
                if(topFreq.count(diff)) return true;
            } else {
                if(bottomFreq.count(diff)) return true;
            }
        }

        prefix = 0;

        unordered_map<int, int> rightFreq;

        for(auto &row : grid)
            for(auto &val : row)
                rightFreq[val]++;

        unordered_map<int, int> leftFreq;

        for(int j = 0; j < n - 1; j++) {

            for(int i = 0; i < m; i++) {
                int val = grid[i][j];
                prefix += val;

                leftFreq[val]++;
                rightFreq[val]--;
                if(rightFreq[val] == 0)
                    rightFreq.erase(val);
            }

            long long right = total - prefix;

            if(prefix == right) return true;

            long long diff = abs(prefix - right);

            if(prefix > right) {
                if(leftFreq.count(diff)) return true;
            } else {
                if(rightFreq.count(diff)) return true;
            }
        }

        return false;
    }
};

int main() {

    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid:\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    Solution sol;

    cout << (sol.canPartitionGrid(grid) ? "True" : "False") << endl;

    return 0;
}