class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> list1;
        vector<int> list2;
        list1.push_back(nums[0]);
        list2.push_back(nums[1]);

        for(int i = 2 ; i < n ; i++){
            if(list1.back() > list2.back()){
                list1.push_back(nums[i]);
            }
            else{
                list2.push_back(nums[i]);
            }
        }
        vector<int> res;
        res.reserve(n);
         for (int num : list1) {
            res.push_back(num);
        }

        for (int num : list2) {
            res.push_back(num);
        }

        return res;
    }
};
