class Trie {
private:
    unordered_map<string, bool> words;

public:
    void insert(string word) { words[word] = true; }

    bool search(string word) { return words.count(word); }

    bool startsWith(string prefix) {
        for (auto word : words) {
            if (word.first.starts_with(prefix)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */