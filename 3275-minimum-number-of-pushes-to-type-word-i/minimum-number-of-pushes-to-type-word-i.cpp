class Solution {
public:
    int minimumPushes(string G ){
        auto q = G.size() >> 3 , r = G.size() & 7;
        return ((q << 2) + r) * (q + 1);
    }
};