class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       int n = nums.size();

       if(n==1){
        return 1;
       }

       unordered_set<int> pairXOR;
       unordered_set<int> ans;

       for(int i = 0 ; i<n ; i++){
        for(int j=0; j<n ; j++){
            pairXOR.insert(nums[i] ^ nums[j]);

        }
       }
       for(int x: pairXOR){
        for( int num: nums){
            ans.insert(x^num);
        }
       }
       return ans.size();
    }
    
};