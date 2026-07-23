class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        int n = a.size();
        int ans = 0;
        int min_diff = INT_MAX;
        sort(a.begin(), a.end());


        for(int i =0;i<n-2;i++){
            int left = i+1;
            int right = n-1;
        
            while(left<right){
                int sum = a[i] + a[left] + a[right];
                int diff = abs(sum - target);

                if(diff<min_diff){
                    min_diff = diff;
                    ans = sum;
                }
                if(sum<target){
                    left++;
                }
                else if(sum> target){
                    right--;
                }
                else{
                    return sum;
                }
            }
                
        }
        return ans;

    }
};