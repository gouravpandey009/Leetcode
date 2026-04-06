#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_set<long long> st;

    for (auto &obs : obstacles) {
        long long key = (long long)obs[0] * 1000000 + obs[1];
        st.insert(key);
    }

    int x = 0, y = 0;
    int dir = 0;

    vector<pair<int,int>> d = {
        {0,1}, {1,0}, {0,-1}, {-1,0}
    };

    int maxDist = 0;

    for (int cmd : commands) {
        if (cmd == -1) {
            dir = (dir + 1) % 4;
        } 
        else if (cmd == -2) {
            dir = (dir + 3) % 4;
        } 
        else {
            for (int i = 0; i < cmd; i++) {
                int nx = x + d[dir].first;
                int ny = y + d[dir].second;

                long long key = (long long)nx * 1000000 + ny;

                if (st.count(key)) break;

                x = nx;
                y = ny;

                maxDist = max(maxDist, x*x + y*y);
            }
        }
    }

    return maxDist;
}

int main() {
    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};

    cout << "Max Distance Squared: " << robotSim(commands, obstacles) << endl;

    return 0;
}