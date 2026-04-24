#include <bits/stdc++.h>
using namespace std;

int furthestDistanceFromOrigin(string moves) {
    int l = 0, r = 0, u = 0;

    for(char c : moves) {
        if(c == 'L') l++;
        else if(c == 'R') r++;
        else u++;
    }

    return abs(l - r) + u;
}

int main() {
    string moves = "L_RL__R";

    cout << furthestDistanceFromOrigin(moves) << endl;

    return 0;
}