#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1) {
            return 0;
        }

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;

        vector<bool> visited(n, false);

        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {

            auto [index, steps] = q.front();
            q.pop();

            if (index == n - 1) {
                return steps;
            }

            vector<int> neighbors;

            neighbors.push_back(index - 1);
            neighbors.push_back(index + 1);

            for (int nextIndex : mp[arr[index]]) {
                neighbors.push_back(nextIndex);
            }

            for (int next : neighbors) {

                if (next >= 0 && next < n && !visited[next]) {

                    visited[next] = true;

                    q.push({next, steps + 1});
                }
            }

            mp[arr[index]].clear();
        }

        return -1;
    }
};

int main() {
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    cout << obj.minJumps(arr);

    return 0;
}