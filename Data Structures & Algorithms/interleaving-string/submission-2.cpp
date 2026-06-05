#include <cstring>
class Solution {
public:
    int memo[101][101];
    bool tree(string &s1,string &s2,string &s3,int i1,int i2,int i3){
        if(i3 == s3.size()) return true;
        if(i1 == s1.size() && i2 == s2.size()) return false;

        if(memo[i1][i2] != 0) return memo[i1][i2] == 1;

        // cout<<"s = "<<s<<endl;
        bool ans = false;
        if(i1 < s1.size()){
            if(s1[i1] == s3[i3]){
                ans = tree(s1,s2,s3,i1+1,i2,i3+1);
            }
        }
        if(i2 < s2.size() && ans == false){
            if(s2[i2] == s3[i3]){
                ans = tree(s1,s2,s3,i1,i2+1,i3+1);
            }
        }

        memo[i1][i2] = ans ? 1 : 2;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3 < s1+s2) return false;
        if(s1 == "" && s2 == "" && s3 == "") return true;

        memset(memo,0,sizeof(memo));
        return tree(s1,s2,s3,0,0,0);
    }
};
