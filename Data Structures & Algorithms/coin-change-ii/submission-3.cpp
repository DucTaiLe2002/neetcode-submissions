class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;

        int size = coins.size();
        vector<int>dp(amount+1,0);
        dp[0] = 1;
        for(int i=0;i<size;i++){
            for (int j = coins[i]; j <= amount; j++) {
                // Số cách mới = Số cách cũ + Số cách tạo ra phần tiền còn lại
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};
