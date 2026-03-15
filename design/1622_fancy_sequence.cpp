#include <bits/stdc++.h>
using namespace std;

class Fancy {
public:

    const long long MOD = 1000000007;

    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modInverse(long long x){
        long long res = 1, p = MOD - 2;

        while(p){
            if(p & 1)
                res = (res * x) % MOD;

            x = (x * x) % MOD;
            p >>= 1;
        }

        return res;
    }

    void append(int val){

        long long normalized = (val - add + MOD) % MOD;
        normalized = (normalized * modInverse(mul)) % MOD;

        arr.push_back(normalized);
    }

    void addAll(int inc){
        add = (add + inc) % MOD;
    }

    void multAll(int m){
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx){

        if(idx >= arr.size())
            return -1;

        return (arr[idx] * mul + add) % MOD;
    }
};

int main(){

    Fancy fancy;

    fancy.append(2);
    fancy.addAll(3);
    fancy.append(7);
    fancy.multAll(2);

    cout << fancy.getIndex(0) << endl;
    cout << fancy.getIndex(1) << endl;

    return 0;
}