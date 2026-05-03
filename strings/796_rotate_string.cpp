#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;
    return (s + s).find(goal) != string::npos;
}

int main() {
    string s = "abcde";
    string goal = "cdeab";

    if (rotateString(s, goal)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}