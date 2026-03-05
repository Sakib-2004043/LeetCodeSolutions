class Solution {
private:
    struct Trie {
        bool isEnd = false;
        Trie* child[26] = {nullptr};
    };
    void makeTrie(string word, Trie* node) {
        for (auto w : word) {
            if (node->child[w - 'a'] == nullptr) {
                node->child[w - 'a'] = new Trie();
            }
            node = node->child[w - 'a'];
        }
        node->isEnd = true;
    }
    void dfs(vector<string>& ans, Trie* node, string word) {
        if (!node || ans.size() == 3) {
            return;
        }
        if (node->isEnd) {
            ans.push_back(word);
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (node->child[c - 'a'] != nullptr) {
                dfs(ans, node->child[c - 'a'], word + c);
            }
        }
    }
    vector<string> findWord(string word, Trie* node) {
        for (auto w : word) {
            if (node == nullptr) {
                return {};
            }
            node = node->child[w - 'a'];
        }
        vector<string> ans;
        dfs(ans, node, word);
        return ans;
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        Trie* root = new Trie();
        for (auto product : products) {
            makeTrie(product, root);
        }
        int n = searchWord.size();
        vector<vector<string>> ans;
        for (int i = 1; i <= n; i++) {
            vector<string> row;
            row = findWord(searchWord.substr(0, i), root);
            ans.push_back(row);
        }
        return ans;
    }
};