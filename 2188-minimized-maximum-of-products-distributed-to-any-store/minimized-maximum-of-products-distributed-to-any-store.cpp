class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {

        int low = 1;
        int high = *max_element(q.begin() , q.end());

        while(low < high){
            int mid = low + (high - low) /2;

            int stores = 0;

            for(int x : q){
                stores += (x + mid - 1) / mid;
            }

            if(stores <= n){
                high = mid;
            }

            else {
                low = mid + 1;
            }
        }

        return low;
    }
};