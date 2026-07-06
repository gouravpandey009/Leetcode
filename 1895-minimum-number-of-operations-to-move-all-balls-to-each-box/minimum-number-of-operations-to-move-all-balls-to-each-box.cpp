class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> answer(n);

        for(int target = 0 ; target < n ; target++){
            int operations = 0;

            for(int current = 0 ; current < n; current++)
            {
                if(boxes[current] == '1'){
                    operations += abs(target - current);
                }
            }

            answer[target] = operations;
        }

        return answer;
    }
};