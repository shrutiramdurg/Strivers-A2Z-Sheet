#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int target){
    int low = 0;
    int high = arr.size() - 1;
    int idx = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= target){
            idx = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return idx;
}