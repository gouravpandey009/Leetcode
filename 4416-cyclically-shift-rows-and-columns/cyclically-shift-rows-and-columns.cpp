class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& G, vector<int>& RS, vector<int>& CS) {

        vector<vector<int>> res(n , vector<int>(n));
        for(int r = 0 ; r < n ; r++)
        for(int c = 0 ; c < n ; c++)
        res[r][c] = G[(r + CS[c]) % n][(c + RS[(r + CS[c]) % n]) % n];
        return res;
    }
};