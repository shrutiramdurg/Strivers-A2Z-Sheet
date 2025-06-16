#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateArr(vector<int>& arr){
    int a = arr[0];
    for(size_t i = 0; i < arr.size() - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[arr.size() - 1] = a;
    for(int i : arr){
        cout<<i<<"\t";
    }
    cout<<"\n";
}