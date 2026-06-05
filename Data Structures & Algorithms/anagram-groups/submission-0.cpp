class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<string>> ans;
        unordered_map<string,vector<string>> map;
        // sort(strs.begin(),strs.end());

        for(const auto& s : strs){
            vector<int> count(26,0);
            for(char c : s){
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for(int i=1;i<26;i++){
                key+=','+ to_string(count[i]);
            }
            map[key].push_back(s);
        }

        for(const auto& pair : map){
            ans.push_back(pair.second);
        }

        return ans;
    }
};
