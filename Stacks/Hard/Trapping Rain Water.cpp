class Solution {

public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> pref(n);
        vector<int> suff(n);
        pref[0] = height[0];
        suff[n-1] = height[n-1];
        for(int i=1; i<n; i++)
        pref[i] = max(height[i], pref[i-1]);
        for(int i=n-2; i>=0; i--)
        suff[i] = max(suff[i+1], height[i]);
        int ans = 0;
        for(int i=1; i<n-1; i++){
            int m1 = pref[i-1];
            int m2 = suff[i+1];
            
            ans += max((min(m1,m2) - height[i]),0);
        }
         
        return ans;
    }
};