#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateArr(vector<int>& arr){
    vector<int> temp(arr.size());
    for(size_t i = 0; i < arr.size(); i++){
        if(i + 2 < arr.size()){
            temp[i + 2] = arr[i];
        }
        else{
            temp[(i+2)%arr.size()] = arr[i];
        }
    }
    for(size_t i = 0; i < temp.size(); i++){
        cout<<temp[i]<<"\t";
    }
    cout<<"\n";
}