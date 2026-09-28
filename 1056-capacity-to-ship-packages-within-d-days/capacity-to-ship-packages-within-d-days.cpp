class Solution {
public:

    bool canShip(vector<int>&weights , int days , int capacity){
        int usedDays = 1;
        int currentWeight = 0;

        for(int weight : weights){
            if(currentWeight + weight > capacity){
                //move to the next day
                usedDays++;

                //new day

                currentWeight = 0;
            }

            //package ship

            currentWeight += weight;
        }

        return usedDays <= days;
    }


    int shipWithinDays(vector<int>& weights, int days) {

        //find min possible capacity

        int low = *max_element(weights.begin(), weights.end());

        int high = accumulate(weights.begin() , weights.end() , 0);

        //apply binary search on possible capacity

        while(low < high){
            int mid = low + (high - low) / 2;

            if(canShip(weights , days , mid)){
                high = mid;
            }
             else{
                low = mid + 1;
             }
        }

        return low;
        
    }
};