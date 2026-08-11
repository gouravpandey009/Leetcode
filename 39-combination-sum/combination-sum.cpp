class Solution {
public:

    vector<vector<int>> answer;
    vector<int> current;

    void backtrack(vector<int>& candidates, int target, int index) {

        // Target 0 ho gaya
        // Matlab valid combination mil gaya
        if (target == 0) {
            answer.push_back(current);
            return;
        }

        // Saare candidates check karo
        for (int i = index; i < candidates.size(); i++) {

            // Agar current number target se bada hai
            // to isko choose nahi kar sakte
            if (candidates[i] > target) {
                continue;
            }

            // Choose
            current.push_back(candidates[i]);

            // Same i se dobara start
            // kyunki same number ko reuse kar sakte hain
            backtrack(candidates,
                      target - candidates[i],
                      i);

            // Undo / Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                        int target) {

        backtrack(candidates, target, 0);

        return answer;
    }
};