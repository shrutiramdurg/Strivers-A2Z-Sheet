class Solution {
public:
    int countAtMostK(vector<int>& nums, int k) {
        int left = 0, count = 0, oddCount = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 == 1) oddCount++;

            while (oddCount > k) {
                if (nums[left] % 2 == 1) oddCount--;
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);
    }
};
