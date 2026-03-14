#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int n, string &curr, vector<string> &res){

        if(curr.size() == n){
            res.push_back(curr);
            return;
        }

        for(char ch : {'a','b','c'}){

            if(!curr.empty() && curr.back() == ch)
                continue;

            curr.push_back(ch);
            solve(n, curr, res);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k){

        vector<string> res;
        string curr;

        solve(n, curr, res);

        if(k > res.size())
            return "";

        return res[k-1];
    }
};

int main(){

    int n,k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    Solution sol;

    cout << sol.getHappyString(n,k) << endl;

    return 0;
}