#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBits(int x) {

        int cnt = 0;
        while(x) {
            cnt += x & 1;
            x >>= 1;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int ca = countBits(a);
            int cb = countBits(b);
            if(ca == cb) return a < b;
            return ca < cb;
        });

        return arr;
    }
};

int main() {
    Solution sol;
 
    vector<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    
    cout << "Original array: ";
    for(int x : data) cout << x << " ";
    cout << endl;


    vector<int> result = sol.sortByBits(data);

    cout << "Sorted by bits: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
