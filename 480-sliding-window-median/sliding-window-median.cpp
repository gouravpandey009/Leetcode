class Solution {
public:

    // Smaller half ke liye max heap
    priority_queue<int> small;

    // Larger half ke liye min heap
    priority_queue<int, vector<int>, greater<int>> large;

    // Jo elements delete karne hain
    unordered_map<int, int> delayed;

    // Valid elements ki count
    int smallSize = 0;
    int largeSize = 0;


    // Heap ke top par jo element already delete hona chahiye
    // usko remove karo
    void removeInvalid() {

        while (!small.empty() &&
               delayed[small.top()] > 0) {

            delayed[small.top()]--;
            small.pop();
        }

        while (!large.empty() &&
               delayed[large.top()] > 0) {

            delayed[large.top()]--;
            large.pop();
        }
    }


    // Heaps ka size balance karo
    void balance() {

        // small mein large se 2 zyada ho gaye
        if (smallSize > largeSize + 1) {

            large.push(small.top());
            small.pop();

            smallSize--;
            largeSize++;
        }

        // large mein small se zyada ho gaye
        else if (smallSize < largeSize) {

            small.push(large.top());
            large.pop();

            largeSize--;
            smallSize++;
        }

        // Top par deleted elements ho sakte hain
        removeInvalid();
    }


    // New number add karo
    void add(int num) {

        if (small.empty() || num <= small.top()) {

            small.push(num);
            smallSize++;
        }
        else {

            large.push(num);
            largeSize++;
        }

        balance();
    }


    // Number ko remove karo
    void remove(int num) {

        // Bas delete ke liye mark karo
        delayed[num]++;

        // Ye number small side mein hai
        if (!small.empty() && num <= small.top()) {
            smallSize--;
        }
        else {
            largeSize--;
        }

        // Agar top deleted hai to remove karo
        removeInvalid();

        // Size balance karo
        balance();
    }


    // Median find karo
    double getMedian(int k) {

        // Odd
        if (k % 2 == 1) {
            return small.top();
        }

        // Even
        return ((double)small.top() +
                (double)large.top()) / 2.0;
    }


    vector<double> medianSlidingWindow(
        vector<int>& nums, int k) {

        vector<double> answer;

        // First window add karo
        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }

        // First median
        answer.push_back(getMedian(k));


        // Window slide karo
        for (int i = k; i < nums.size(); i++) {

            // Purana element remove
            remove(nums[i - k]);

            // Naya element add
            add(nums[i]);

            // Median
            answer.push_back(getMedian(k));
        }

        return answer;
    }
};