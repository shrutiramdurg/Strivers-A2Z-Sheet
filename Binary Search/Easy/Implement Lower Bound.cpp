#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int k){
    int low = 0;
    int high = arr.size() - 1;
    int idx = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] >= k){
            idx = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return idx;
}