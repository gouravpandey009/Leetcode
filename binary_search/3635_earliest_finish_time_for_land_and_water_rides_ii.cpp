#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long calFinishTime(vector<int>& ls , vector<int>& ld , vector<int>& ws , vector<int>& wd){
        long long mini = LLONG_MAX;

        // Find the earliest finish time for the first ride type
        for(size_t i = 0 ; i < ls.size() ;  i++){
            mini = min(mini, (long long)ls[i] + ld[i]);
        }

        long long ans = LLONG_MAX;

        // Calculate the finish time for the second ride type
        for(size_t i = 0 ; i < ws.size() ; i++){
            long long startTimeForSecond = max(mini, (long long)ws[i]);
            ans = min(ans, startTimeForSecond + wd[i]);
        }

        return ans;
    }
    
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            calFinishTime(landStartTime , landDuration, waterStartTime , waterDuration) ,
            calFinishTime(waterStartTime , waterDuration , landStartTime , landDuration)
        );
    }
};

int main() {
    Solution solver;

    vector<int> landStartTime = {1, 4};
    vector<int> landDuration = {3, 2};
    vector<int> waterStartTime = {2, 5};
    vector<int> waterDuration = {4, 1};

    int result = solver.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    
    cout << "Earliest Finish Time: " << result << endl;

    return 0;
}
