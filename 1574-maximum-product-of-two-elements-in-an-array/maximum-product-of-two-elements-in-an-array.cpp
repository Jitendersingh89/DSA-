class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int largest = 0;
        int second = 0;

        for(int num : nums){
            if(num > largest){
                second = largest;
                largest = num;
            }
            else if(num > second){
                second = num;
            }
        }
        return(largest -1)*(second-1);
    }
};