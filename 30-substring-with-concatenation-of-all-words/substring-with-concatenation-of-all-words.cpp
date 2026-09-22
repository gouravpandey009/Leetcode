class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int len = words[0].size();
        int n = words.size();

        unordered_map<string ,int> need;

        //har word kitni baar aya
        
        for(string word : words)
         need[word]++;

         //different alignment

         for(int start = 0 ; start < len ; start++){
            unordered_map<string , int> have;

            int left = start;
            int count = 0;

            //one by one word read

            for(int right = start ; right + len <= s.size() ; right += len){
                //required word or not

                string word = s.substr(right , len);

                if(!need.count(word)){
                    have.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }

                have[word]++;
                count++;

                //word window add 

                while(have[word] > need[word]){
                    string old  = s.substr(left , len);
                    have[old]--;
                    left += len;
                    count--;
                }

                if(count == n){
                    ans.push_back(left);

                    string old = s.substr(left , len);
                    have[old]--;
                    left += len;
                    count--;
                }
            }
         }

         return ans;
        
    }
};