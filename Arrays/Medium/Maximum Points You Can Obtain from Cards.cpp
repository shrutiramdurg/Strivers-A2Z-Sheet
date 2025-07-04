class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for (int i = 0; i < k; ++i)
            total += cardPoints[i]; 
        
        int maxScore = total;
        for (int i = 1; i <= k; ++i) {
        
            total = total - cardPoints[k - i] + cardPoints[n - i];
            maxScore = max(maxScore, total);
        }
        return maxScore;
    }
};
