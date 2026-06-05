class Solution {
public:
    

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int size = coins.size();
        int max_val = amount + 1;
       vector<int> dp(amount + 1, max_val);
        dp[0] = 0;

        if(amount == 0) return 0;

        for(int i=1;i<=amount;i++){
            for(int j=0;j<size;j++){
                if(i < coins[j]) break;
                else{
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};
