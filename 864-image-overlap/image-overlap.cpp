class Solution {
public:

    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B , int rowOff , int colOff){

        int n  = A.size();

        int count = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                //find indices of B from A

                int B_i = i + rowOff;
                int B_j = j + colOff;


                if(B_i < 0 || B_i >= n || B_j < 0 || B_j  >= n)
                continue;


                if(A[i][j] == 1  && B[B_i][B_j] == 1)
                count++;

            }
        }

        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n =A.size();
        //n * n matrix
        //row = n
        //col = n

        int maxOverlap = 0;

        for(int rowOff = - n + 1; rowOff < n ; rowOff++){
            for(int colOff = -n + 1 ; colOff < n; colOff++){
                int count = countOverlaps(A , B , rowOff , colOff);

                maxOverlap = max(maxOverlap , count);
            }
        }

        return maxOverlap;
    }
};