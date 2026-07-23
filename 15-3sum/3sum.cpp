class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> arr;
        int n = a.size();
        sort(a.begin(), a.end());

        for(int i = 0;i<n-2;i++){
            if(i>0 && a[i]==a[i-1]){
                continue;
            }
            int left = i+1;
            int right = n-1;
            int target = -1*a[i];
            while(left<right){
                int sum = a[left] + a[right];

                if(sum == target){
                    arr.push_back({a[i] , a[left] , a[right]});
                    left++;
                    right--;
                
                    while(left<n && a[left] == a[left-1]){
                    left++;
                    }
                    while(left<right && a[right] == a[right+1]){
                    right--;
                    }   
                }
                else if(sum < target){
                    left++;
                }
                else{
                    right--;
                }

            }
        }
      

        return arr;
    }
};