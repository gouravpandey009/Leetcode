#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool dfs(vector<int>& arr, int index, vector<bool>& visited) {

        int n = arr.size();

        if (index < 0 || index >= n || visited[index]) {
            return false;
        }

        if (arr[index] == 0) {
            return true;
        }

        visited[index] = true;

        int forward = index + arr[index];
        int backward = index - arr[index];

        return dfs(arr, forward, visited) ||
               dfs(arr, backward, visited);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<bool> visited(arr.size(), false);

        return dfs(arr, start, visited);
    }
};

int main() {

    Solution obj;

    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    int start = 5;

    if (obj.canReach(arr, start)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}