class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int src0 = source[0];
        int src1 = source[1];

        int trg0 = target[0];
        int trg1 = target[1];

        if(src0 == trg0 && src1 == trg1)
        return 0;
        if((src0 + src1) % 2 != (trg0 + trg1) % 2)
        return -1;

        if(abs(src0 - trg0) == abs(src1 - trg1))
        return 1;

        return 2;
    }
};