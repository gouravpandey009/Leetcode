class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        ranges::sort(arr2);
        arr2.push_back(INT_MAX);

        auto far = [&](int a){
            return *ranges::lower_bound(arr2 , a - d) > a + d;
        };

        return ranges::count_if(arr1 , far);
        
    }
};