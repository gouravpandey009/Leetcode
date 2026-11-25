class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = speed.size();
        int groups = 1;
        int curSpeed = speed[n - 1];
        for(int i = n - 1 ; i > 0 ; i--){
            if(speed[i - 1] <= curSpeed && position[i] - position[i - 1] > distance){
                groups++;
                curSpeed = speed[i - 1];
            }
        }

        return groups;
    }
};