class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minElidx = min_element(begin(nums) , end(nums)) - begin(nums);
        int maxElidx = max_element(begin(nums) , end(nums)) - begin(nums);
        int left = min(minElidx , maxElidx);
        int right = max(minElidx , maxElidx);

        return min({n-left , right +1 , left+1+n-right});
    }
};