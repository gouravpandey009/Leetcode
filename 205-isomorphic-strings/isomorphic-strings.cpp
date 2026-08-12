class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }


        vector<pair<char , char>> mp;

        for(int i = 0 ; i < s.size() ; i++){
            char a = s[i];
            char b = t[i];

            bool found = false;
            

            for(int j = 0 ; j < mp.size() ; j++){
                if (mp[j].first == a){
                    found = true;



                    if(mp[j].second != b){
                        return false;
                    }
                }

                if(mp[j].second == b && mp[j].first != a){
                    return false;
                }
            }

            if(!found) {
                 mp.push_back({ a , b});
            }
        }

        return true;
    }
};