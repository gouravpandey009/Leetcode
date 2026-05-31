#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool asteroidsDestroyed(int mass,
                            vector<int>& asteroids) {

        sort(asteroids.begin(),
             asteroids.end());

        long long currentMass = mass;

        for (int asteroid : asteroids) {

            if (currentMass < asteroid) {
                return false;
            }

            currentMass += asteroid;
        }

        return true;
    }
};

int main() {

    Solution obj;

    int mass = 10;

    vector<int> asteroids = {3, 9, 19};

    cout << boolalpha
         << obj.asteroidsDestroyed(
                mass,
                asteroids);

    return 0;
}