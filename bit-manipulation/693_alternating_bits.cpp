#include <iostream>

class Solution {
public:
    /**
     * Bitwise approach:
     * n ^ (n >> 1) creates a number with all 1s if n has alternating bits.
     * (x & (x + 1)) == 0 checks if x is a number consisting of all 1s.
     */
    bool hasAlternatingBits(int n) {
        long x = n ^ (n >> 1); 
        return (x & (x + 1)) == 0;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    int testCases[] = {5, 7, 10, 11};
    
    for (int n : testCases) {
        std::cout << "Input: " << n << " -> Result: " 
                  << (sol.hasAlternatingBits(n) ? "true" : "false") 
                  << std::endl;
    }
    
    return 0;
}
