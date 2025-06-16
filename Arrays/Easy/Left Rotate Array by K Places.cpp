 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 
 void rotateArray(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(size_t i = 0; i < nums.size(); i++){
            if(i - k < 0){
                temp[(i + nums.size()) - 2] = nums[i];
            }
            else if( i - k => 0){
                temp[i-k] = nums[i];
            }
        }
        for(size_t i = 0; i < temp.size(); i++){
            cout<<temp[i]<<"\t";
        }
        cout<<"\n";
    }