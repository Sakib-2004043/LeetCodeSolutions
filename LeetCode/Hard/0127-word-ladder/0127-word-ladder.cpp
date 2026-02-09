class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) {
            return 0;
        }
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return steps;
                }
                for (int j = 0; j < word.size(); j++) {
                    char originalChar = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (wordSet.count(word) && !visited.count(word)) {
                            q.push(word);
                            visited.insert(word);
                        }
                    }
                    word[j] = originalChar;
                }
            }
            steps++;
        }
        return 0;
    }
};
