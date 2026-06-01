#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& candies) {
        sort(candies.rbegin(), candies.rend());

        int cost = 0;

        for (int i = 0; i < candies.size(); i++) {
            if ((i + 1) % 3 != 0) {
                cost += candies[i];
            }
        }

        return cost;
    }
};

int main() {
    Solution obj;

    vector<int> candies = {6, 5, 7, 9, 2, 2};

    cout << obj.minimumCost(candies);

    return 0;
}