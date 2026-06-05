class Solution {
public:

    /* first solutions*/
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());

    //     return (s == t) ? true : false;
    // }
    /* Second solutions*/

    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        std:: unordered_map<char,int> count;

        for(int i =0;i<s.size();i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        for(char c:s){
            if(count[c] != 0) return false;
        }

        return true;
    }
};
