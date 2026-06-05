#include "string.h"
using namespace std;
class Solution {
public:
  string longestPalindrome(string s) {
    int size = s.length();
    string longest_sub = "";
    if (size == 1)
      return s;
    if (size == 2) {
      if (s[0] != s[1]) {
        return s.substr(0, 1);
      } else {
        return s;
      }
    }
    int l, r = 0;
    if (s[0] == s[1])
      longest_sub = s.substr(0, 2);
    for (int i = 1; i < size; i++) {
      int mid_flag = 0;
      l = i;
      r = i;
      while (l >= 0 && r < size) {
        if (s[i] == s[i+1] && mid_flag == 0) {
            if (s.substr(i, 1).length() > longest_sub.length()) {
              longest_sub = s.substr(i, 1);
              cout<<"if 1: "<<longest_sub<<endl;
            }
            mid_flag = 1;
            r++;
            continue;
        } else if (s[l] == s[r]) {
          if (s.substr(l, r - l + 1).length() > longest_sub.length()) {
            longest_sub = s.substr(l, r - l + 1);
            cout<<"if 2: "<<longest_sub<<endl;
          }
          l--;
          r++;
          continue;
        }  
        r = size;
      }
      l =i;
      r =i;
      while (l >= 0 && r < size) {
        if (s[l] == s[r]) {
          if (s.substr(l, r - l + 1).length() > longest_sub.length()) {
            longest_sub = s.substr(l, r - l + 1);
            cout<<"if 3: "<<longest_sub<<endl;
          }
          l--;
          r++;
          
        } else{
            r = size;
        } 
      }
    }
    return longest_sub;
  }

};
