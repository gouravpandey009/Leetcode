#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        
        int length = (1 << n) - 1; 
        int mid = length / 2 + 1;
        
        if(k == mid) return '1';
        else if(k < mid) return findKthBit(n - 1, k);
        else {
            int newK = length - k + 1;
            char bit = findKthBit(n - 1, newK);
            return bit == '0' ? '1' : '0';
        }
    }
};

int main() {
    Solution sol;
    int n, k;

    cout << "Enter value for n: ";
    cin >> n;
    
    cout << "Enter value for k: ";
    cin >> k;

    cout << "Result: " << sol.findKthBit(n, k) << endl;
    
    return 0;
}
