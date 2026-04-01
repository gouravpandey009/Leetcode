#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        // {position, health, direction, original_index}
        vector<tuple<int, int, char, int>> robots;

        for (int i = 0; i < n; i++) {
            robots.push_back(make_tuple(positions[i], healths[i], directions[i], i));
        }

        // Sort by position
        sort(robots.begin(), robots.end());

        stack<int> st; // Stores indices of robots moving 'R'

        for (int i = 0; i < n; i++) {
            if (get<2>(robots[i]) == 'R') {
                st.push(i);
                continue;
            }

            // Robot is moving 'L', handle collisions with 'R' robots in stack
            while (!st.empty() && get<1>(robots[i]) > 0) {
                int j = st.top();
                
                if (get<1>(robots[j]) < get<1>(robots[i])) {
                    // 'R' robot destroyed
                    get<1>(robots[j]) = 0;
                    get<1>(robots[i]) -= 1;
                    st.pop();
                } else if (get<1>(robots[j]) > get<1>(robots[i])) {
                    // 'L' robot destroyed
                    get<1>(robots[i]) = 0;
                    get<1>(robots[j]) -= 1;
                } else {
                    // Both destroyed
                    get<1>(robots[i]) = 0;
                    get<1>(robots[j]) = 0;
                    st.pop();
                }
            }
        }

        // Collect survivors and sort by original index
        vector<pair<int, int>> survivors;
        for (const auto& r : robots) {
            if (get<1>(r) > 0) {
                survivors.push_back({get<3>(r), get<1>(r)});
            }
        }

        sort(survivors.begin(), survivors.end());

        vector<int> ans;
        for (const auto& p : survivors) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    if (!(cin >> n)) return 0;

    vector<int> pos(n), health(n);
    string dir;

    cout << "Enter positions: ";
    for (int i = 0; i < n; i++) cin >> pos[i];
    cout << "Enter healths: ";
    for (int i = 0; i < n; i++) cin >> health[i];
    cout << "Enter directions string: ";
    cin >> dir;

    Solution sol;
    vector<int> res = sol.survivedRobotsHealths(pos, health, dir);

    cout << "Survivors' Health: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
