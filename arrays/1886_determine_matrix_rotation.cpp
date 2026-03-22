#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        vector<bool> flag(4, true);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(mat[i][j] != target[i][j])
                    flag[0] = false;

                if(mat[i][j] != target[j][n - i - 1])
                    flag[1] = false;

                if(mat[i][j] != target[n - i - 1][n - j - 1])
                    flag[2] = false;

                if(mat[i][j] != target[n - j - 1][i])
                    flag[3] = false;
            }
        }

        return flag[0] || flag[1] || flag[2] || flag[3];
    }
};

int main() {
    int n;
    cout << "Enter size of matrix (n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    vector<vector<int>> target(n, vector<int>(n));

    cout << "Enter matrix:" << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    cout << "Enter target matrix:" << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> target[i][j];

    Solution sol;
    bool result = sol.findRotation(mat, target);

    cout << (result ? "True" : "False") << endl;

    return 0;
}