class WordDictionary {
private:
    struct TrieNode {
        bool isEnd = false;
        TrieNode* child[26] = {nullptr};
    };
    TrieNode* root = NULL;
    bool dfs(string& word, int idx, TrieNode* node) {
        if (node == nullptr) {
            return false;
        }
        if (word.size() == idx) {
            return node->isEnd;
        }
        bool ans = false;
        if (word[idx] != '.') {
            ans = dfs(word, idx + 1, node->child[word[idx] - 'a']);
        } else {
            for (auto nextNode : node->child) {
                ans |= dfs(word, idx + 1, nextNode);
            }
        }
        return ans;
    }

public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* curNode = root;
        for (auto& c : word) {
            if (curNode->child[c - 'a'] == nullptr) {
                curNode->child[c - 'a'] = new TrieNode();
            }
            curNode = curNode->child[c - 'a'];
        }
        curNode->isEnd = true;
    }

    bool search(string word) { return dfs(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */