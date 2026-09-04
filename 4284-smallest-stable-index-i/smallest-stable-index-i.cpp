class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minFromIndex(n);
        int minEL = INT_MAX;
        for(int i = n-1 ; i >= 0 ; i--){
            minEL = min(minEL , nums[i]);
            minFromIndex[i] = minEL;
        }

        int maxEL = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            maxEL = max(maxEL , nums[i]);
            

            if(maxEL - minFromIndex[i] <= k){
                return i;
            }
        }
        return -1;
    
    }
};