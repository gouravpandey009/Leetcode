#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

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

            // 1. Check adjacent left neighbor
            if (index - 1 >= 0 && !visited[index - 1]) {
                visited[index - 1] = true;
                q.push({index - 1, steps + 1});
            }

            // 2. Check adjacent right neighbor
            if (index + 1 < n && !visited[index + 1]) {
                visited[index + 1] = true;
                q.push({index + 1, steps + 1});
            }

            // 3. Check identical value neighbors
            if (mp.count(arr[index])) {
                for (int nextIndex : mp[arr[index]]) {
                    if (!visited[nextIndex]) {
                        visited[nextIndex] = true;
                        q.push({nextIndex, steps + 1});
                    }
                }
                // Clear map entry immediately to avoid redundant lookups
                mp.erase(arr[index]);
            }
        }

        return -1;
    }
};

int main() {
    Solution obj; // Fixed: Instantiated the object
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    cout << obj.minJumps(arr) << endl;

    return 0;
}
