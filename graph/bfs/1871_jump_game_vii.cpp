#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        queue<int> q;

        q.push(0);

        int farthestVisited = 1;

        while (!q.empty()) {

            int index = q.front();
            q.pop();

            if (index == n - 1) {
                return true;
            }

            int start =
                max(index + minJump,
                    farthestVisited);

            int end =
                min(index + maxJump,
                    n - 1);

            for (int j = start; j <= end; j++) {

                if (s[j] == '0') {
                    q.push(j);
                }
            }

            farthestVisited =
                max(farthestVisited,
                    index + maxJump + 1);
        }

        return false;
    }
};

int main() {

    Solution obj;

    string s = "011010";

    int minJump = 2;
    int maxJump = 3;

    if (obj.canReach(s, minJump, maxJump)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}