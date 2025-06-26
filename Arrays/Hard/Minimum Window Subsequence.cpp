class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        int minLen = INT_MAX, start = -1;

        for (int i = 0; i < m; ++i) {
            if (S[i] == T[0]) {
                int sIdx = i, tIdx = 0;

                
                while (sIdx < m && tIdx < n) {
                    if (S[sIdx] == T[tIdx]) tIdx++;
                    sIdx++;
                }

                if (tIdx == n) {
                    
                    int end = sIdx - 1;
                    tIdx = n - 1;
                    while (sIdx >= i) {
                        if (S[sIdx] == T[tIdx]) {
                            tIdx--;
                            if (tIdx < 0) break;
                        }
                        sIdx--;
                    }

                    if ((end - sIdx) < minLen) {
                        minLen = end - sIdx;
                        start = sIdx;
                    }
                }
            }
        }

        return start == -1 ? "" : S.substr(start, minLen + 1);
    }
};
