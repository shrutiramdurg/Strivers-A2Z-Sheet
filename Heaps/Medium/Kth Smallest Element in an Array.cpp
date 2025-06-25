#include <bits/stdc++.h>
using namespace std;

class Solution{
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;  

        for (int num : nums) {
            maxHeap.push(num);
            if (maxHeap.size() > k) {
                maxHeap.pop(); // Remove largest among the k+1 elements
            }
        }

        return maxHeap.top(); // Kth smallest
    }
};