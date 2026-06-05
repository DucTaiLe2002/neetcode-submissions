class Solution {
public:
    int countSubstrings(string s) {
        int size = s.length();

        int l,r = 0;
        int count_sub = 0;

        for(int i=0;i<size;i++){
            l = i;
            r = i;
            int mid_flag = 0;
            // count_sub++;
            while(l>=0 && r < size){
                if(s[i] == s[i+1] && mid_flag == 0){
                    count_sub++;
                    mid_flag = 1;
                    r+=2;
                    l--;
                }else if(s[r] == s[l] && mid_flag == 1){
                    count_sub++;
                    l--;
                    r++;
                }else{
                    break;
                }
            }
            l = i;
            r = i;
            while(l >= 0 && r < size){
                if(s[l] == s[r]){
                    count_sub++;
                    l--;
                    r++;
                }else{
                    break;
                }
            }
        }

        return count_sub;
    }
};
