class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);        
    int maxLen = 0, left = 0;

    for (int right = 0; right < s.size(); ++right) {
        unsigned char ch = s[right];
        if (last[ch] >= left)         // duplicate inside window
            left = last[ch] + 1;      // move left pointer

        last[ch] = right;             // update last seen index
        maxLen   = max(maxLen, right - left + 1);
    }
    return maxLen;
    }
};