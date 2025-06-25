class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count[3] = {0, 0, 0};  // count of 'a', 'b', 'c'
        int res = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            count[s[end] - 'a']++;

            // shrink window from left if it contains at least one of each character
            while (count[0] && count[1] && count[2]) {
                res += n - end;  // all substrings starting from start to n-1
                count[s[start] - 'a']--;
                start++;
            }
        }
        return res;
    }
};
