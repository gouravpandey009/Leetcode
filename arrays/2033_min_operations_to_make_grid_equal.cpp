#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> arr;

    for(auto &row : grid) {
        for(int v : row) {
            arr.push_back(v);
        }
    }

    int base = arr[0];

    for(int v : arr) {
        if((v - base) % x != 0) return -1;
    }

    sort(arr.begin(), arr.end());

    int n = arr.size();
    int median = arr[n / 2];

    int ops = 0;

    for(int v : arr) {
        ops += abs(v - median) / x;
    }

    return ops;
}

int main() {
    vector<vector<int>> grid = {
        {2,4},
        {6,8}
    };

    int x = 2;

    cout << minOperations(grid, x) << endl;

    return 0;
}