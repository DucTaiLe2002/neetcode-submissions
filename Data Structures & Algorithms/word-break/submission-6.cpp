class Solution {
public:
    bool tree_search(string s, vector<string>& wordDict, int start, vector<int>& nemo){
        if(start == s.size()) return true;
        
        // Kiểm tra memo
        if (nemo[start] != -1) return nemo[start]; 

        for (int i = start; i < s.size(); i++) {
            string sub = s.substr(start, (i - start + 1));
            
            for(int j = 0; j < wordDict.size(); j++) {
                if(sub == wordDict[j]) {
                    // Truyền i + 1 trực tiếp, KHÔNG gán lại vào start hay index
                    if(tree_search(s, wordDict, i + 1, nemo)) {
                        return nemo[start] = 1;
                    }
                }
            }
        }

        return nemo[start] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return false;
        // Khởi tạo size + 1 để an toàn khi index chạm mốc cuối
        vector<int> nemo(s.size() + 1, -1); 
        return tree_search(s, wordDict, 0, nemo);
    }
};