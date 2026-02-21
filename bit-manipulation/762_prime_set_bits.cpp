#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = 
            {2,3,5,7,11,13,17,19,23,29,31};

        int ans = 0;

        for(int i = left; i <= right; i++) {
            int x = i;
            int cnt = 0;

            while(x) {
                cnt += x & 1;
                x >>= 1;
            }

            if(primes.count(cnt)) ans++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int left = 6, right = 10;
    int result = sol.countPrimeSetBits(left, right);
    cout << "Range: [" << left << ", " << right << "]" << endl;
    cout << "Count of numbers with prime set bits: " << result << endl;

    return 0;
}

