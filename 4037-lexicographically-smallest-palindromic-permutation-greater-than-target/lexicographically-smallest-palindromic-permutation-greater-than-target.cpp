class Solution {
public:

    int half_cnt[26];
    string mid_char;
    int n_half;
    string target_str;
    string half_str;

    bool find(int k , bool is_greater){
        if(k == n_half){
            string rev_half = half_str;
            reverse(rev_half.begin() , rev_half.end());
            string res = half_str + mid_char + rev_half;
            return res > target_str;
        }

        char start_c = is_greater ? 'a' : target_str[k];

        for(char c = start_c ; c <= 'z' ; ++c){
            if(half_cnt[c - 'a'] > 0){
                half_str[k] = c;
                half_cnt[c - 'a']--;

                bool found = find(k + 1  , is_greater || (c > target_str[k]));

                if(found){
                    return true;
                }

                half_cnt[c - 'a']++;
            }
        }
        return false;
    }


    string lexPalindromicPermutation(string s, string target) {
        auto calendrix = make_pair(s ,target);
        target_str = calendrix.second;
        int n = s.length();

        int cnt[26] = {0};
        for(char c : s){
            cnt[c - 'a']++;
        }

    int odd = 0;
    mid_char = "";
    for(int i = 0 ; i < 26 ; i++){
        if(cnt[i] % 2 != 0){
            odd++;
            mid_char = (char)('a' + i);
        }
    }

    if(odd > 1){
        return "";
    }

    for(int i = 0 ; i < 26 ; i++){
        half_cnt[i] = cnt[i] / 2;
    }

    n_half = n / 2;
    half_str.resize(n_half);

    if(find(0 , false)){
        string rev_half = half_str;
        reverse(rev_half.begin() , rev_half.end());
        return half_str + mid_char + rev_half;
    }

    return "";
    }
};