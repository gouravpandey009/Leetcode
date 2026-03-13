#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool can(long long mid, int height, vector<int>& workerTimes){

        long long removed = 0;

        for(int t : workerTimes){

            long long x = mid / t;

            long long k = (sqrt(1 + 8*x) - 1) / 2;

            removed += k;

            if(removed >= height)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes){

        long long left = 0;
        long long right = 1e18;

        while(left < right){

            long long mid = (left + right) / 2;

            if(can(mid, mountainHeight, workerTimes))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main(){

    int height, n;

    cout << "Enter mountain height: ";
    cin >> height;

    cout << "Enter number of workers: ";
    cin >> n;

    vector<int> workerTimes(n);

    cout << "Enter worker times: ";
    for(int i = 0; i < n; i++)
        cin >> workerTimes[i];

    Solution sol;

    cout << sol.minNumberOfSeconds(height, workerTimes) << endl;

    return 0;
}