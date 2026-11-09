class Solution {
public:
    int peakValleyDifference(vector<int>& A) {
        int n = A.size() , res = 0;
        for(int i = 1 ; i < n - 1; i++){
            if(A[i] > A[i - 1] && A[i] > A[i + 1])
            res += A[i];

            if(A[i] < A[i - 1] && A[i] < A[i + 1])
            res -= A[i];
        }

        return res;
    }
};