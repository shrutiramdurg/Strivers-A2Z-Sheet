#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> freqT;
        for (char ch : t) freqT[ch]++;

        unordered_map<char, int> window;
        int required = freqT.size();
        int formed = 0;

        int l = 0, r = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (r < s.size()) {
            char ch = s[r];
            window[ch]++;
            
            if (freqT.count(ch) && window[ch] == freqT[ch])
                formed++;

            while (l <= r && formed == required) {
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char removeChar = s[l];
                window[removeChar]--;
                if (freqT.count(removeChar) && window[removeChar] < freqT[removeChar])
                    formed--;

                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
