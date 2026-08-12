class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }


        vector<int> sToT(256  , -1);
        vector<int> tToS(256 , -1);

        for(int i = 0 ; i < s.size() ; i++){
            int a  = s[i];
            int b = t[i];


            if(sToT[a] != -1 && sToT[a] != b){
                return false;
            }

            if(tToS[b] != -1 && tToS[b] != a){
                return false;
            }

            //store mapping in both directions

            sToT[a] = b;
            tToS[b] = a;
        }


        return true;

        
    }
};