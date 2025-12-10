#include <bits/stdc++.h>
typedef long long lli;
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        lli i, j, n, mx;
        n = s.size();
        mx = 0;
        for (i = 0; i < n; i++) {
            unordered_map<char, bool> visited;
            for (j = i; j < n; j++) {
                if (visited[s[j]]) {
                    mx = max(mx, j - i);
                    break;
                }
                visited[s[j]] = true;
            }
            if (j == n) {
                mx = max(mx, j - i);
            }
        }
        return mx;
    }
};