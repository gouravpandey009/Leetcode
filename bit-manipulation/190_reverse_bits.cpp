//LeetCode 190 - Reverse Bits
// Approach: Position based bit swapping
// Time: O(1), Space: O(1)

#include <iostream>
#include <cstdint> // Required for uint32_t
#include <bitset>  // Useful for printing bits

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;          // Shift result left to make room
            res |= (n & 1);     // Add the rightmost bit of n to result
            n >>= 1;            // Shift n right to process next bit
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example test case (Input: 43261596)
    uint32_t input = 43261596; 
    uint32_t output = sol.reverseBits(input);

    cout << "Input:  " << bitset<32>(input) << " (" << input << ")" << endl;
    cout << "Output: " << bitset<32>(output) << " (" << output << ")" << endl;

    return 0;
}

