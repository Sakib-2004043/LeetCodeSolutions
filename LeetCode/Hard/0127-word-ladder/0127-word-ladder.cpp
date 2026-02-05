class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int ans = 0;
        unordered_map<string, bool> visited;
        queue<string> bfsQ;
        bfsQ.push(beginWord);
        sort(wordList.begin(), wordList.end());
        while (!bfsQ.empty()) {
            int sz = bfsQ.size();
            ans++;
            while (sz--) {
                string currWord = bfsQ.front();
                bfsQ.pop();
                if (currWord == endWord) {
                    return ans;
                }
                for (int i = 0; i < currWord.size(); i++) {
                    string tempWord = currWord;
                    for (char c = 'a'; c <= 'z'; c++) {
                        tempWord[i] = c;
                        bool found = binary_search(wordList.begin(),
                                                   wordList.end(), tempWord);
                        if (found && !visited[tempWord]) {
                            bfsQ.push(tempWord);
                            visited[tempWord] = true;
                        }
                    }
                }
            }
        }
        return 0;
    }
};