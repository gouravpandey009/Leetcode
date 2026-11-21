class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for(int x = 1 ; x < n ; ++x)
        children[parent[x]].push_back(x);
        vector<int> size(n , 1) , above(n);
        array<int, 26> last;
        last.fill(-1);
        vector<int> stack{0};
        while(!stack.empty()){
            int x =  stack.back();
            stack.pop_back();
            if(x >= 0){
                int c = s[x] - 'a';
                above[x] = last[c];
                last[c] = x;
                stack.push_back(~x);
                stack.insert(stack.end() , children[x].begin() , children[x].end());
            }

            else {
                x = ~x;
                last[s[x] - 'a'] = above[x];
                if(x)
                size[above[x] >= 0 ? above[x] : parent[x]] += size[x];
            }
        }

        return size;
    }
};