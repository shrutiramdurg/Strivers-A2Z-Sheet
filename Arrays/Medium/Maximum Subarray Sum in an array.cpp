#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> maxSubArrayWithElements(const vector<int>& arr) {
    int n = arr.size();
    int curSum   = arr[0], bestSum  = arr[0];
    int curStart = 0,      bestL    = 0, bestR = 0;

    for (int i = 1; i < n; ++i) {
        if (curSum + arr[i] < arr[i]) {
            curSum   = arr[i];
            curStart = i;
        } else {
            curSum += arr[i];
        }

        if (curSum > bestSum) {
            bestSum = curSum;
            bestL   = curStart;
            bestR   = i;
        }
    }

    
    vector<int> sub(arr.begin() + bestL, arr.begin() + bestR + 1);
    return {bestSum, sub};
}
