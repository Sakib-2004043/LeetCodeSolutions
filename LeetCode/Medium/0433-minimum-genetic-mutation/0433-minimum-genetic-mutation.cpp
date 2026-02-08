class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> genes = {'A', 'C', 'G', 'T'};
        unordered_set<string> geneSet(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string> bfsQ;
        bfsQ.push(startGene);
        int ans = 0;
        while (!bfsQ.empty()) {
            int sz = bfsQ.size();
            while (sz--) {
                string curGene = bfsQ.front();
                bfsQ.pop();
                if (curGene == endGene) {
                    return ans;
                }
                for (int i = 0; i < 8; i++) {
                    char originalGene = curGene[i];
                    for (auto gene : genes) {
                        curGene[i] = gene;
                        if (geneSet.count(curGene) && !visited.count(curGene)) {
                            bfsQ.push(curGene);
                            visited.insert(curGene);
                        }
                    }
                    curGene[i] = originalGene;
                }
            }
            ans++;
        }
        return -1;
    }
};