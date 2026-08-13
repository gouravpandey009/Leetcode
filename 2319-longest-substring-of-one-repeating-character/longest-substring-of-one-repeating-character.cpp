class Solution {

    private:
        struct Node{
            int maxLen;
            int ll;
            int lr;
            int len;
            char cl;
            char cr;
        };

        vector<Node> tree;

        void merge(int i) {
            Node &parent = tree[i];
            Node &left = tree[2 * i];
            Node &right = tree[2 * i + 1];

            parent.cl = left.cl;
            parent.cr = right.cr;
            parent.len = left.len + right.len;

            parent.ll = left.ll;
            parent.lr = right.lr;



            parent.maxLen = max(left.maxLen  , right.maxLen);


            if(left.cr == right.cl){
                int bridgeLen = left.lr + right.ll;
                parent.maxLen = max(parent.maxLen , bridgeLen);

            if(left.ll == left.len){
                parent.ll = left.len + right.ll;
            }
            

            if(right.lr == right.len){
                parent.lr = right.len + left.lr;
            }
        }

        }

        void build(const string &s , int i , int start , int end){
            if(start == end){
                tree[i] = {1 , 1 , 1 , 1 , s[start] , s[start]};
                return;
            }

            int mid = start + (end - start) / 2;
            build(s , 2 * i , start , mid);
            build(s , 2 * i + 1 , mid + 1 , end);
            merge(i);
        }

        void update(int i ,int start  , int end ,int idx ,char ch){
            if(start == end){
                tree[i].cl = ch;
                tree[i].cr = ch;
                return;
            }

            int mid = start + (end - start) / 2;
            if(idx <= mid){
                update(2 * i , start , mid , idx , ch);
            } else {
                update(2 * i + 1 , mid + 1 ,end , idx ,ch);
            }

            merge(i);
        }


public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();

        tree.resize(4 * n);
        build(s , 1,0 , n - 1);

        vector<int> result(k);
        for(int i = 0 ; i < k ; i++){
            update(1 , 0 , n - 1 , queryIndices[i] , queryCharacters[i]);
            result[i] = tree[1].maxLen;
        }

        return result;
    }
};