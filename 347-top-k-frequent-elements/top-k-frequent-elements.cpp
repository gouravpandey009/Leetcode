class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int , int> freq;


        for(int number : nums){
            freq[number]++;
        }

        //make a min heap - pair store(freq , number)

        priority_queue<pair<int ,int> ,
        vector<pair<int, int>> , greater<pair<int ,int>>> minHeap;

        for(auto& pair : freq){
            int number = pair.first;
            int count = pair.second;

            minHeap.push({count , number});

            // if k value is larger 

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> answer;

        while(!minHeap.empty()){
            answer.push_back(minHeap.top().second);

            minHeap.pop();
        };
        
        return answer;
    }
};