class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> i, vector<int> j){
            if(i[0]==j[0]) return i[1]>j[1];
            return i[0]<j[0];
        });

        
        int maxi = 0 , cnt = 0;
        for(auto v : intervals){
            int l = v[0] , r = v[1];
            if(r > maxi){
                cnt++;
                maxi = r;
            }
        }

        return cnt;
    }
};