#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

int closetTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size();
    int ans = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(words[i] == target) {
            int forward = (i - startIndex + n) % n;
            int backward = (startIndex - i + n) % n;
            ans = min(ans, min(forward, backward));
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<string> words = {"hello","i","am","leetcode","hello"};
    string target = "hello";
    int startIndex = 1;
    cout << closetTarget(words, target, startIndex) << endl;
    return 0;
}
