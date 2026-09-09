class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n = customers.size();

        //cus already satisfied

        int base = 0;

        for(int i = 0 ; i < n ; i++){
            if(grumpy[i] == 0){
                base += customers[i];
            }
        }

        //extra customers technique

        int extra = 0;

        for(int i = 0 ; i < minutes ; i++){
            if(grumpy[i] == 1){
                extra += customers[i];
            }
        }

        int maxExtra = extra;

        for(int i = minutes ; i < n ; i++){

            //remove old element
            if(grumpy[i - minutes] == 1){


                extra -= customers[i - minutes];
            }


            //add new element

            if(grumpy[i] ==  1) {
                extra += customers[i];
            }

            maxExtra = max(maxExtra , extra);
        }

        return base + maxExtra;
        
    }
};