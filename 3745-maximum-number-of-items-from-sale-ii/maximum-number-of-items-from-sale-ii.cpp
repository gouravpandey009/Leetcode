class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size() , cheapest = INT_MAX;
        vector<int> have(n + 1);
        for(auto& item : items){
            have[item[0]]++;
            cheapest = min(cheapest , item[1]);
        }


        vector<int> deals(n + 1 , -1);
        vector<pair<int,int>>worth;
        for(auto& item : items)
        if(item[1] < 2 * cheapest) worth.emplace_back(item[1] , item[0]);
        priority_queue heap(greater<>() , std::move(worth));
        int copies = 0;
        while(!heap.empty() && heap.top().first <= budget){
            auto[price , factor] = heap.top();
            heap.pop();
            if(deals[factor] < 0)
            for(int multiple = factor ; multiple <= n ; multiple += factor)
            deals[factor] += have[multiple];
            int pairs = min(deals[factor] , budget / price);
            copies += 2 * pairs;
            budget -= pairs * price;
        }

        return copies + budget / cheapest;
    }
};