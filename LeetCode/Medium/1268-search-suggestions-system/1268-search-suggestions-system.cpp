class Solution {
private:
    struct Trie {
        bool isEnd = false;
        Trie* child[26] = {nullptr};
    };
    void insert(string& word, Trie* node) {
        for (char c : word) {
            if (!node->child[c - 'a']) {
                node->child[c - 'a'] = new Trie();
            }
            node = node->child[c - 'a'];
        }
        node->isEnd = true;
    }
    void dfs(Trie* node, string& current, vector<string>& ans) {
        if (!node || ans.size() == 3) {
            return;
        }
        if (node->isEnd) {
            ans.push_back(current);
        }
        for (char c = 'a'; c <= 'z'; c++) {
            Trie* next = node->child[c - 'a'];
            if (next) {
                current.push_back(c);
                dfs(next, current, ans);
                current.pop_back();
            }
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        Trie* root = new Trie();
        for (auto& p : products) {
            insert(p, root);
        }
        vector<vector<string>> ans;
        Trie* node = root;
        string prefix = "";
        for (char c : searchWord) {
            prefix += c;
            if (node) {
                node = node->child[c - 'a'];
            }
            vector<string> row;
            string temp = prefix;
            dfs(node, temp, row);
            ans.push_back(row);
        }
        return ans;
    }
};
