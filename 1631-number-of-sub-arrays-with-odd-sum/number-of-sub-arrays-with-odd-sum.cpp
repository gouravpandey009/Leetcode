class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd_prefixes = 0;
        int current_parity = 0;
        for(int x : arr){
            current_parity ^= (x & 1);
            odd_prefixes += current_parity;
        }

        long long even_prefixes = (arr.size() + 1) - odd_prefixes;
        return (odd_prefixes * even_prefixes) % 1'000'000'007;
    }
};