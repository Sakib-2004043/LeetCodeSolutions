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
            map<char, lli> m;
            for (j = i; j < n; j++) {
                if (m[s[j]] == 1) {
                    mx = max(mx, j - i);
                    break;
                }
                m[s[j]]++;
            }
            if (j == n) {
                mx = max(mx, j - i);
            }
        }
        return mx;
    }
};