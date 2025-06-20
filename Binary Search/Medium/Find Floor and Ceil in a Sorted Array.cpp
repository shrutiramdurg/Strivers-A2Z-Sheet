#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> arr, int n, int target){
    int low = 0;
    int high = n - 1;
    int ans;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] <= target){
            ans = arr[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(vector<int> arr, int n, int target){
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] >= target){
            ans = arr[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> findFloorCeil(vector<int> arr, int n, int target){
    int f = findFloor(arr, n, target);
    int c = findCeil(arr, n, target);
    return make_pair(f, c);
}