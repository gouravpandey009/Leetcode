#define ll long long
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
    ll n = nums.size();
        unordered_set<ll> s;
        for(ll i = 0 ; i < n ; i++){
            for(ll j = i ; j < n ; j++){
                s.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<ll>ans;
        for(ll i = 0 ; i < n; i++){
            for(ll x : s){
                ans.insert(x ^ nums[i]);
            }
        }

        return ans.size();
    }
};