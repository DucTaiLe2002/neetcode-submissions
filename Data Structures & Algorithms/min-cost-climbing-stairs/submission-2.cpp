class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if(size == 1) return 0;
        size+=1;
        int dp[size] = {0};
        dp[0] = 0;
        dp[1] = 0;
        int i =2;
        while(i < size){
            if(dp[i-1]+cost[i-1] <dp[i-2]+cost[i-2]){
                dp[i] = dp[i-1]+cost[i-1];
            } else{
                dp[i] = dp[i-2]+cost[i-2];
            }
            i++;
        }

        return dp[size-1];
    }
};
