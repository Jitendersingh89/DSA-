class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> frequency(26 , 0);

        for(int c : s){
            frequency[c-'a']++;
        }
        string left = "";
        string mid = "";

        for(int i = 0;i <26;i++){
            left.append(frequency[i]/2 , char('a' + i));

            if(frequency[i]%2 ==1){
                mid = char('a' + i);
            }
        }
        string right = left;
        reverse(right.begin() , right.end());
        return left + mid + right;
    }
};