#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(), costs.end());

        int count = 0;

        for (int cost : costs) {

            if (coins < cost)
                break;

            coins -= cost;
            count++;
        }

        return count;
    }
};

int main() {

    vector<int> costs = {1,3,2,4,1};
    int coins = 7;

    Solution obj;

    cout << obj.maxIceCream(costs, coins);

    return 0;
}