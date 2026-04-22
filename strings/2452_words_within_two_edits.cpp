#include <bits/stdc++.h>
using namespace std;

vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> res;

    for(auto &q : queries) {
        for(auto &w : dictionary) {
            int diff = 0;

            for(int i = 0; i < q.size(); i++) {
                if(q[i] != w[i]) {
                    diff++;
                    if(diff > 2) break;
                }
            }

            if(diff <= 2) {
                res.push_back(q);
                break;
            }
        }
    }

    return res;
}

int main() {
    vector<string> queries = {"word","note","ants","wood"};
    vector<string> dictionary = {"wood","joke","moat"};

    vector<string> ans = twoEditWords(queries, dictionary);

    for(auto &s : ans) cout << s << " ";
    cout << endl;

    return 0;
}