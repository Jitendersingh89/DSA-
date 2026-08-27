class Solution {
public:
    int find(vector<int> & a){
        int maxc = -1;
        for(int i = 0 ; i< 256 ; i++){
            maxc = max(maxc , a[i]);
        }
        return maxc;
    }
    int characterReplacement(string s, int k) {
        vector<int> f (256 , 0);
        int n = s.length();

        int low = 0 ;
        int high = 0;
        int res = INT_MIN;

        for(high = 0 ; high < n ; high ++){
            f[s[high]]++;

            int len = high - low + 1;
            int max_count = find(f);
            int diff = len - max_count;

            while(diff > k){
                f[s[low]]--;
                low++ ; 
                len = high - low +1;
                max_count = find(f);
                diff = len - max_count;

            }
            len = high - low + 1;
            res = max(res , len);
        }
        return res;
        
    }
};