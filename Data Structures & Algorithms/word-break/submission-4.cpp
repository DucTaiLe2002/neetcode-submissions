class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true; // Gốc: chuỗi rỗng ngắt được

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // Nếu đoạn trước [0, j] ngắt được VÀ đoạn [j, i] nằm trong dict
            if (dp[j]) {
                string word = s.substr(j, i - j);
                if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[n];
    }
};
