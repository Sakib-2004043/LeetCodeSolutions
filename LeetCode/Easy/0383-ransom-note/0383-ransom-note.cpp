class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazineWord;
        for (int i = 0; i < magazine.size(); i++) {
            magazineWord[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (!magazineWord[ransomNote[i]]) {
                return false;
            }
            magazineWord[ransomNote[i]]--;
        }
        return true;
    }
};