class Solution {
public:
    string minWindow(string s, string t) {

        int need[128] = {};
        int have[128] = {};

        for(char c : t)
            need[c]++;

            int left = 0;
            int count = 0;

            int start = 0;

            int len = s.size() + 1; // INT_MAX

            for(int right = 0 ; right < s.size(); right++) {
                //curr char window add

                char c = s[right];
                have[c]++;

                if(have[c] <= need[c])
                count++;

                //find min window

                while(count == t.size()){

                    if(right - left + 1 < len){
                        len = right - left + 1;

                        start = left;


                    }

                    //left char window remove

                    char c = s[left];
                    have[c]--;

                    if(have[c] < need[c])
                    count--;
                    left++;

                }
            }

            if(len == s.size() + 1)
            return "";

            return s.substr(start , len);
        }
        
};