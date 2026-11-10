class Solution {
public:
    int countGoodStrings(long long n) {
        using ll = long long;
        constexpr int MOD(1000000007);
        auto fib{[&](this auto&& fib , ll n) -> pair<ll , ll>{
            if(!n) return {0LL , 1LL};
            const auto [a , b]{fib(n / 2)};
            ll c{a * (2 * b % MOD - a + MOD) % MOD};
            ll d{(a * a % MOD + b * b % MOD) % MOD};
            return n % 2 ? make_pair(d , (c + d) % MOD) : make_pair(c , d);
            }
        };

        return fib(n).first * 2 % MOD;
    }
};