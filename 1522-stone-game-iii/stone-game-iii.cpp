class Solution {
public:
    string stoneGameIII(const vector<int>& A , int r = 0) {
        for(int n = A.size() , i = n - 1 , a = 0 , b = 0 , c = 0 ; i >= 0 ; --i){
            r = max({(i + 2 < n ? A[i] + A[i + 1] + A[i + 2] - a : INT_MIN) , (i + 1 < n? A[i] + A[i + 1] - b : INT_MIN) , A[i] - c});
            a = b;
            b = c;
            c = r;
        }

        return !r ? "Tie" : r > 0 ? "Alice" : "Bob";
    }
};