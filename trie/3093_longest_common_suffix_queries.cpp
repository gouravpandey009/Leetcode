#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    struct Node {

        int child[26];

        int best_idx;

        Node() {

            fill(begin(child),
                 end(child),
                 -1);

            best_idx = -1;
        }
    };

    vector<Node> trie;

    vector<string> container;

    void updateIndex(int node_id,
                     int new_idx) {

        int current_best =
            trie[node_id].best_idx;

        if (current_best == -1) {

            trie[node_id].best_idx =
                new_idx;

            return;
        }

        if (container[new_idx].size() <
            container[current_best].size()) {

            trie[node_id].best_idx =
                new_idx;
        }
        else if (container[new_idx].size() ==
                 container[current_best].size()) {

            if (new_idx < current_best) {

                trie[node_id].best_idx =
                    new_idx;
            }
        }
    }

    void insert(const string& word,
                int word_idx) {

        int node_id = 0;

        updateIndex(node_id, word_idx);

        for (int i = word.size() - 1;
             i >= 0;
             --i) {

            int c = word[i] - 'a';

            if (trie[node_id].child[c] == -1) {

                trie[node_id].child[c] =
                    trie.size();

                trie.emplace_back();
            }

            node_id =
                trie[node_id].child[c];

            updateIndex(node_id, word_idx);
        }
    }

    int search(const string& query) {

        int node_id = 0;

        for (int i = query.size() - 1;
             i >= 0;
             --i) {

            int c = query[i] - 'a';

            if (trie[node_id].child[c] == -1) {
                break;
            }

            node_id =
                trie[node_id].child[c];
        }

        return trie[node_id].best_idx;
    }

    vector<int> stringIndices(
        vector<string>& wordsContainer,
        vector<string>& wordsQuery) {

        trie.clear();

        trie.reserve(1000000);

        container = wordsContainer;

        trie.emplace_back();

        for (int i = 0;
             i < wordsContainer.size();
             i++) {

            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        ans.reserve(wordsQuery.size());

        for (const string& query :
             wordsQuery) {

            ans.push_back(search(query));
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<string> wordsContainer =
        {"abcd", "bcd", "xbcd"};

    vector<string> wordsQuery =
        {"cd", "bcd", "xyz"};

    vector<int> ans =
        obj.stringIndices(wordsContainer,
                          wordsQuery);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}