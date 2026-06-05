class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = (std::accumulate(nums.begin(), nums.end(), 0));
        if(sum%2 != 0){
            return false;
        }else{
            sum = sum/2;
        }
        int size = nums.size();
        vector<int>dp(sum+1,0);
        dp[0] = 1;
        if(sum < nums[size-1]) return false;
        for(int i = 0;i<size;i++){
            for(int j =sum;j>= nums[i];j--){
                if (dp[j - nums[i]]) {
                    dp[j] = 1;
                }
            }
            if (dp[sum]) return true;
        }
        if(dp[sum] == 0) return false;

        return true;

    }
};
