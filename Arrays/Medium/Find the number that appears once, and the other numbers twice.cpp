#include<bits/stdc++.h>
class Solution{
    public:
        int findNum(vector<int> &arr){
            int n = arr.size();
            int xorr = 0;
            for(int i = 0; i < n; i++){
                xorr = xorr ^ arr[i];
            }
            return xorr;
        }
};