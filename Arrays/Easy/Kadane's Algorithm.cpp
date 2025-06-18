class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur  = nums[0];   // best ending at i
        int best = nums[0];   // best overall

        for (size_t i = 1; i < nums.size(); ++i) {
            cur  = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};
