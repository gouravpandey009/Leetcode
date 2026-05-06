#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();

    vector<vector<char>> res(n, vector<char>(m));

    // Rotate
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[j][m - 1 - i] = box[i][j];
        }
    }

    // Gravity
    for (int col = 0; col < m; col++) {
        int emptyRow = n - 1;

        for (int row = n - 1; row >= 0; row--) {
            if (res[row][col] == '*') {
                emptyRow = row - 1;
            } 
            else if (res[row][col] == '#') {
                swap(res[row][col], res[emptyRow][col]);
                emptyRow--;
            }
        }
    }

    return res;
}

int main() {
    vector<vector<char>> box = {
        {'#', '.', '#'}
    };

    auto res = rotateTheBox(box);

    for (auto &row : res) {
        for (auto &ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}