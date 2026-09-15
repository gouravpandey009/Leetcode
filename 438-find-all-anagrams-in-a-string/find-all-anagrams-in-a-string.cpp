class Solution {
public:

    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int k= p.size();
        int n= s.size();

        vector<int>freqp(26,0);
        vector<int>freqs(26,0);

        if(n<k){
            return ans;
        }

        for(int i=0;i<k;i++){
            freqp[p[i]-'a']++;
            freqs[s[i]-'a']++;
        }
        if(freqs== freqp){
            ans.push_back(0);
        }

        for(int i=k;i<n;i++){
            freqs[s[i]-'a']++;
            freqs[s[i-k]-'a']--;

            if(freqs== freqp){
                ans.push_back(i-k+1);
            }
        }
        return ans;
 
               
    }
};