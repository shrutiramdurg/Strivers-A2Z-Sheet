class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int prev2 = 0;  
        int prev1 = 0;  

        for (int i = 1; i < n; i++) {
            int oneStep = prev1 + abs(height[i] - height[i - 1]);
            int twoStep = INT_MAX;
            if (i > 1) {
                twoStep = prev2 + abs(height[i] - height[i - 2]);
            }
            int curr = min(oneStep, twoStep);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
