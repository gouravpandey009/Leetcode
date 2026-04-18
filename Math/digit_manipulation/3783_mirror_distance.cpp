#include <iostream>
#include <unordered_map>
using namespace std;

int mirrorDistance(int n) {
    unordered_map<int, int> mp = {
        {0,0},{1,1},{2,5},{5,2},{6,9},{8,8},{9,6}
    };

    int original = n;
    long long mirror = 0;

    while(n > 0){
        int d = n % 10;

        if(mp.find(d) == mp.end()) return -1;

        mirror = mirror * 10 + mp[d];
        n /= 10;
    }

    return abs(original - (int)mirror);
}

int main() {
    cout << mirrorDistance(12) << endl; // Example
}