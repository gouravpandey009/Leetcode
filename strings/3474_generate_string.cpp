#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        string res(n + m - 1, '?');

        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                    if(res[i + j] == '?' || res[i + j] == str2[j]) {
                        res[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        for(int i = 0; i < res.size(); i++) {
            if(res[i] == '?') {
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    res[i] = ch;

                    bool ok = true;

                    for(int k = 0; k < n; k++) {
                        if(str1[k] == 'F') {
                            bool match = true;
                            for(int j = 0; j < m; j++) {
                                if(res[k + j] != str2[j]) {
                                    match = false;
                                    break;
                                }
                            }
                            if(match) {
                                ok = false;
                                break;
                            }
                        }
                    }

                    if(ok) break;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            bool match = true;
            for(int j = 0; j < m; j++) {
                if(res[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }

            if((str1[i] == 'T' && !match) ||
               (str1[i] == 'F' && match)) {
                return "";
            }
        }

        return res;
    }
};

int main() {

    string str1, str2;
    cout << "Enter str1 and str2: ";
    cin >> str1 >> str2;

    Solution sol;
    cout << sol.generateString(str1, str2) << endl;

    return 0;
}