class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> neg;
        vector<int> pos;

        for(int i = 0 ; i<n ;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }

        }

        if(neg.size() == 0){
            for(int i=0;i<pos.size();i++){
                pos[i] = pos[i]*pos[i];
                
            }
            return pos;
        }
        if(pos.size()==0){
            for(int i=0;i<neg.size();i++){
                neg[i] = neg[i]*neg[i];
              
            }
            reverse(neg.begin(), neg.end());
            return neg;
        }
        int i = 0 , j = 0;
        int id = 0;
        int x = neg.size();
        int y = pos.size();
        vector<int> res(x+y);
        for(int i=0;i<x;i++){
            neg[i] = neg[i]*neg[i];
        }
        ;

        reverse(neg.begin(), neg.end());

        for(int i = 0;i<y;i++){
             pos[i] = pos[i] * pos[i];
        }
       
        while(i<x && j<y){
            if(neg[i]<=pos[j]){
                res[id] = neg[i];
                
                i++;
            }
            else{
                res[id]=pos[j];
                
                j++;
            }
            id++;
        }
        while(j<y){
            res[id] = pos[j];
            id++;
            j++;
        }
        while(i<x){
            res[id] = neg[i];
            id++;
            i++;
        }

        return res;

    }
};