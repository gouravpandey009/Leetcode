class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {

        int n = types.size();
        stack<vector<int>>st;

        for(int i = 0 ; i < n ; i++){
            int t = types[i];
            int c = colors[i];

            if(!st.empty() && st.top()[0] == t && st.top()[1] == c){
                st.top()[2]++;
            }

            else{
                st.push({t , c , 1});
            }

            if(st.top()[2] == groupSize[t]){
                st.pop();
            }
        }

        return st.empty();
        
    }
};