#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    string findTheString(vector<vector<int>>& lcp) {

        int n = lcp.size();

        for(int i = 0; i < n; i++) {
            if(lcp[i][i] != n - i)
                return "";
            for(int j = 0; j < n; j++) {
                if(lcp[i][j] != lcp[j][i])
                    return "";
            }
        }

        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(lcp[i][j] > 0) {
                    unite(i, j);
                }
            }
        }

        string res(n, '#');
        char ch = 'a';

        unordered_map<int, char> mp;

        for(int i = 0; i < n; i++) {
            int p = find(i);
            if(mp.count(p) == 0) {
                if(ch > 'z') return "";
                mp[p] = ch++;
            }
            res[i] = mp[p];
        }

        vector<vector<int>> check(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(res[i] == res[j]) {
                    if(i == n - 1 || j == n - 1)
                        check[i][j] = 1;
                    else
                        check[i][j] = 1 + check[i+1][j+1];
                }
            }
        }

        if(check != lcp) return "";

        return res;
    }
};

int main() {

    int n;
    cout << "Enter size n: ";
    cin >> n;
    
    vector<vector<int>> lcp(n, vector<int>(n));

    cout << "Enter LCP matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> lcp[i][j];

    Solution sol;

    string ans = sol.findTheString(lcp);

    cout << "Result: " << ans << endl;

    return 0;
}