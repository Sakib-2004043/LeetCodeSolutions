class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        unordered_map<char, int> firstWord, secondWord;
        vector<int>vec1,vec2;
        for(int i=0;i<word1.size();i++){
            firstWord[word1[i]]++;
            secondWord[word2[i]]++;
        }
        for(auto x:firstWord){
            if(!secondWord.count(x.first)){
                return false;
            }
            vec1.push_back(x.second);
        }
        for(auto x:secondWord){
            if(!firstWord.count(x.first)){
                return false;
            }
            vec2.push_back(x.second);
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());

        return vec1 == vec2;
    }
};