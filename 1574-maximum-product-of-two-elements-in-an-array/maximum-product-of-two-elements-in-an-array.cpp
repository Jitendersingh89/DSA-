class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();

        int x = nums[n-1];
        int m = nums[n-2];

        return(x-1)*(m-1);

        
    }
};