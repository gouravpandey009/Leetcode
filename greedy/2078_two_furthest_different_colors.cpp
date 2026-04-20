#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<int>& colors) {
    int n = colors.size();
    int ans = 0;

    for(int j = n - 1; j >= 0; j--) {
        if(colors[j] != colors[0]) {
            ans = max(ans, j);
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        if(colors[i] != colors[n - 1]) {
            ans = max(ans, n - 1 - i);
            break;
        }
    }

    return ans;
}

int main() {
    vector<int> colors = {1,1,1,6,1,1,1};

    cout << maxDistance(colors) << endl;

    return 0;
}