class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq;
        vector<string> ans;
        
        if (s.length() < 10) return ans;

        for (int i = 0; i <= s.length() - 10; ++i) {
            string sub = s.substr(i, 10);
            freq[sub]++;
        }

        for (auto& entry : freq) {
            if (entry.second > 1)
                ans.push_back(entry.first);
        }

        return ans;
    }
};
