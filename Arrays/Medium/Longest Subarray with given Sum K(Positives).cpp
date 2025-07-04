#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); 

    int left = 0, right = 0; 
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {

        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

       
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}
