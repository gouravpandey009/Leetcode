#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

vector<int> getPrimeFactors(int x) {

    vector<int> factors;

    for (int p = 2; p * p <= x; p++) {

        if (x % p == 0) {

            factors.push_back(p);

            while (x % p == 0) {
                x /= p;
            }
        }
    }

    if (x > 1) factors.push_back(x);

    return factors;
}

int minJumps(vector<int>& nums) {

    int n = nums.size();

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {

        vector<int> factors = getPrimeFactors(nums[i]);

        for (int f : factors) {
            mp[f].push_back(i);
        }
    }

    queue<int> q;
    vector<int> vis(n, 0);

    q.push(0);
    vis[0] = 1;

    int steps = 0;

    while (!q.empty()) {

        int sz = q.size();

        while (sz--) {

            int idx = q.front();
            q.pop();

            if (idx == n - 1) return steps;

            if (idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = 1;
                q.push(idx - 1);
            }

            if (idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = 1;
                q.push(idx + 1);
            }

            if (isPrime(nums[idx])) {

                int p = nums[idx];

                for (int nextIdx : mp[p]) {

                    if (!vis[nextIdx]) {
                        vis[nextIdx] = 1;
                        q.push(nextIdx);
                    }
                }

                mp[p].clear();
            }
        }

        steps++;
    }

    return -1;
}

int main() {

    vector<int> nums = {2, 3, 4, 7, 9};

    cout << minJumps(nums);

    return 0;
}