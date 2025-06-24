class Solution{
    public:
        int findCoins(int v){
            vector<int> ans;
            int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
            int n = 9;
            for (int i = n - 1; i >= 0; i--) {
                while (v >= coins[i]) {
                v -= coins[i];
                ans.push_back(coins[i]);
                }
            }
        }
};