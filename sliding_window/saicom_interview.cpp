#include <iostream>
#include <unordered_map>
using namespace std;

char firstNonRepeating(string s){
    unordered_map<char , int> freq;

    for(char ch : s){
        freq[ch]++;
    }

    for(char ch : s){
        if(freq[ch] == 1){
            return ch;
        }
    }

    return 0;
}

int main() {
    string s = "loveleetcode";
    cout << firstNonRepeating(s);
    return 0;
}

