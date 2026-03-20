#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minimumDeletions(string word, int k){

        vector<int> freq(26, 0);

        for(char c : word)
            freq[c - 'a']++;

        int ans = INT_MAX;

        for(int x = 0; x <= 100; x++){

            int deletions = 0;

            for(int f : freq){

                if(f == 0)
                    continue;

                if(f < x)
                    deletions += f;
                else if(f > x + k)
                    deletions += (f - (x + k));
            }

            ans = min(ans, deletions);
        }

        return ans;
    }
};

int main(){

    string word;
    int k;

    cout<<"Enter string: ";
    cin>>word;

    cout<<"Enter k: ";
    cin>>k;

    Solution sol;

    cout<<"Minimum deletions: "
        << sol.minimumDeletions(word, k)
        << endl;

    return 0;
}