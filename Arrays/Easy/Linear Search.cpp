#include<vector>
using namespace std;
class Solution{
    public:
        int linearSearch(vector<int>& arr, int num){
            for(size_t i = 0; i < arr.size(); i++){
                if(arr[i] == num){
                    return i;
                }
            }
            return -1;
        }
};