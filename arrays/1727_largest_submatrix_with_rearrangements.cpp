#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> getBiggestThree(vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();

        set<int> sums;

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){

                sums.insert(grid[r][c]);

                for(int k = 1; r + 2*k < m && c-k >= 0 && c+k < n; k++){

                    int sum = 0;

                    int x = r, y = c;

                    for(int i=0;i<k;i++)
                        sum += grid[x+i][y+i];

                    x = r+k; y = c+k;

                    for(int i=0;i<k;i++)
                        sum += grid[x+i][y-i];

                    x = r+2*k; y = c;

                    for(int i=0;i<k;i++)
                        sum += grid[x-i][y-i];

                    x = r+k; y = c-k;

                    for(int i=0;i<k;i++)
                        sum += grid[x-i][y+i];

                    sums.insert(sum);
                }
            }
        }

        vector<int> res;

        auto it = sums.rbegin();

        for(int i=0;i<3 && it!=sums.rend();i++,it++)
            res.push_back(*it);

        return res;
    }
};

int main(){

    int m,n;

    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout<<"Enter grid values:\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    Solution sol;

    vector<int> ans = sol.getBiggestThree(grid);

    cout<<"Top rhombus sums:\n";

    for(int x: ans)
        cout<<x<<" ";

    cout<<endl;

    return 0;
}