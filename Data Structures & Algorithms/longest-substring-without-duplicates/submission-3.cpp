class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left,right = 0;
        int max_length =1;
        for(int i =0 ; i< s.length();i++){
            if(s[i] != s[left]){
                for (int j = left+1 ; j<i;j++){
                    if (s[j] == s[i]){
                        left = j+1;
                        break;
                    }
                }
                max_length = max_length > (i-left+1)?max_length:(i-left+1);
            } else {
                if(i >0){
                    left++;
                }
            }
        }
        if(s.length() == 0){
            return 0;
        }
        return max_length;
    }
};
