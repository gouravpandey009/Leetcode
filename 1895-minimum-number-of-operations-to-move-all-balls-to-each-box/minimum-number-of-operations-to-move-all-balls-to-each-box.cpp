class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size();
        vector<int>answer(n , 0);

        int leftBalls = 0;
        int leftCost = 0;

        for(int index = 0 ; index < n ; index++){
            answer[index] += leftCost;

            if(boxes[index] == '1')
            {
                leftBalls++;
            }

            leftCost += leftBalls;
            
        }


        int rightBalls = 0;
        int rightCost = 0;

        for(int index = n - 1 ; index >= 0 ; index--){
            answer[index] += rightCost;

            if(boxes[index] == '1')
            {
                rightBalls++;
            }

            rightCost += rightBalls;
        }

        return answer;
    }
};