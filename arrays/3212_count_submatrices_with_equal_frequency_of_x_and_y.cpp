#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numberOfSubmatrices(vector<vector<char>>& grid){

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> px(m, vector<int>(n, 0));
        vector<vector<int>> py(m, vector<int>(n, 0));

        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                px[i][j] = (grid[i][j] == 'X');
                py[i][j] = (grid[i][j] == 'Y');

                if(i>0){
                    px[i][j] += px[i-1][j];
                    py[i][j] += py[i-1][j];
                }

                if(j>0){
                    px[i][j] += px[i][j-1];
                    py[i][j] += py[i][j-1];
                }

                if(i>0 && j>0){
                    px[i][j] -= px[i-1][j-1];
                    py[i][j] -= py[i-1][j-1];
                }

                if(px[i][j] == py[i][j] && px[i][j] > 0)
                    count++;
            }
        }

        return count;
    }
};

int main(){

    int m,n;

    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    vector<vector<char>> grid(m, vector<char>(n));

    cout<<"Enter grid (X/Y/.):\n";

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    Solution sol;

    cout<<"Valid submatrices: "
        << sol.numberOfSubmatrices(grid)
        << endl;

    return 0;
}